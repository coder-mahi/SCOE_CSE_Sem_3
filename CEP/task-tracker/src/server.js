require('dotenv').config(); // Load environment variables from .env file
const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
const nodemailer = require('nodemailer');
const cron = require('node-cron');

const app = express();
const port = 5000;

app.use(express.json());
app.use(cors());

// MongoDB connection
mongoose.connect(process.env.MONGODB_URI)
  .then(() => console.log('Connected to MongoDB'))
  .catch(err => console.error('MongoDB connection error:', err));

// Mongoose Schemas and Models
const userSchema = new mongoose.Schema({
  username: { type: String, required: true },
  email: { type: String, unique: true, required: true },
  password: { type: String, required: true },
  profilePicture: { type: String }, // Optional field for profile picture URL
});

const User = mongoose.model('User', userSchema);

const taskSchema = new mongoose.Schema({
  title: { type: String, required: true },
  description: { type: String, required: true },
  userId: { type: mongoose.Schema.Types.ObjectId, ref: 'User', required: true },
  reminderTime: { type: Date, required: true },
  createdAt: { type: Date, default: Date.now },
});

const Task = mongoose.model('Task', taskSchema);

// Email Transport Configuration
const transporter = nodemailer.createTransport({
  service: 'gmail', // or any other email service
  auth: {
    user: process.env.EMAIL_USER,
    pass: process.env.EMAIL_PASS,
  },
});

// Function to schedule email reminders
const scheduleEmailReminder = (task) => {
  const reminderDate = new Date(task.reminderTime);
  const reminderTime = reminderDate.getTime() - Date.now(); // Calculate delay

  // Schedule the job to run at the reminder time
  if (reminderTime > 0) { // Only schedule if the time is in the future
    const job = cron.schedule(`*/1 * * * *`, async () => {
      const currentTime = Date.now();
      if (currentTime >= reminderDate.getTime()) {
        try {
          // Fetch user email from the database
          const user = await User.findById(task.userId);
          if (!user) {
            console.error('User not found for task:', task._id);
            return; // Exit if user not found
          }

          const mailOptions = {
            from: process.env.EMAIL_USER,
            to: user.email,
            subject: 'Task Reminder',
            text: `Reminder for your task: ${task.title}\nDescription: ${task.description}`,
          };

          await transporter.sendMail(mailOptions);
          console.log('Reminder email sent to:', user.email);
          // Stop the cron job after sending
          job.stop(); // Use job.stop() to stop this specific job
        } catch (error) {
          console.error('Error sending email:', error);
        }
      }
    });
  }
};

// Signup Route
app.post('/signup', async (req, res) => {
  const { username, email, password } = req.body;

  if (!username || !email || !password) {
    return res.status(400).json({ error: 'All fields are required' });
  }

  try {
    const existingUser = await User.findOne({ email });
    if (existingUser) {
      return res.status(400).json({ error: 'Email already in use' });
    }

    const hashedPassword = await bcrypt.hash(password, 10);
    const newUser = new User({ username, email, password: hashedPassword });
    await newUser.save();

    res.status(201).json({ message: 'User registered successfully' });
  } catch (err) {
    console.error('Error during signup:', err);
    res.status(500).json({ error: 'Server error' });
  }
});

// Add Task Route
app.post('/addtask', async (req, res) => {
  const token = req.headers.authorization?.split(" ")[1];

  if (!token) {
    return res.status(401).json({ error: 'Unauthorized' });
  }

  try {
    const decoded = jwt.verify(token, process.env.JWT_SECRET);
    const userId = decoded.id;

    const { title, description, reminderTime } = req.body;

    if (!title || !description || !reminderTime) {
      return res.status(400).json({ error: 'All fields are required' });
    }

    const task = new Task({ title, description, userId, reminderTime });
    await task.save();

    // Schedule the email reminder
    scheduleEmailReminder(task);

    res.status(201).json({ message: 'Task added successfully', task });
  } catch (err) {
    console.error('Error adding task:', err);
    res.status(500).json({ error: 'Server error' });
  }
});

// Login Route
app.post('/login', async (req, res) => {
  const { email, password } = req.body;

  if (!email || !password) {
    return res.status(400).json({ error: 'Email and password are required' });
  }

  try {
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).json({ error: 'Invalid email or password' });
    }

    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) {
      return res.status(400).json({ error: 'Invalid email or password' });
    }

    const token = jwt.sign({ id: user._id }, process.env.JWT_SECRET, { expiresIn: '1h' });
    res.status(200).json({ token });
  } catch (err) {
    console.error('Error during login:', err);
    res.status(500).json({ error: 'Server error' });
  }
});

// Protected Home Route
app.get('/home', (req, res) => {
  const token = req.headers.authorization;

  if (!token) {
    return res.status(401).json({ error: 'Unauthorized' });
  }

  try {
    const decoded = jwt.verify(token, process.env.JWT_SECRET);
    res.status(200).json({ message: `Welcome back, user ${decoded.id}` });
  } catch (err) {
    res.status(401).json({ error: 'Invalid token' });
  }
});

// User Profile Route
app.get('/api/user/profile', async (req, res) => {
  const token = req.headers.authorization?.split(" ")[1];

  if (!token) {
      return res.status(401).json({ error: 'Unauthorized' });
  }

  try {
      const decoded = jwt.verify(token, process.env.JWT_SECRET);
      const user = await User.findById(decoded.id).select('-password');

      if (!user) {
          return res.status(404).json({ error: 'User not found' });
      }

      res.status(200).json({
          username: user.username,
          email: user.email,
          profilePicture: user.profilePicture // Optional field
      });
  } catch (err) {
      console.error('Error fetching user profile:', err);
      res.status(401).json({ error: 'Invalid token' });
  }
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
