require('dotenv').config(); // Load environment variables from .env file
const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');

const app = express();
const port = 5000;

app.use(express.json());
app.use(cors());

// MongoDB connection without deprecated options
mongoose.connect(process.env.MONGODB_URI)
  .then(() => console.log('Connected to MongoDB'))
  .catch(err => console.error('MongoDB connection error:', err));

// Mongoose Schema and Model
const userSchema = new mongoose.Schema({
  username: { type: String, required: true },
  email: { type: String, unique: true, required: true },
  password: { type: String, required: true },
});

const User = mongoose.model('User', userSchema);

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

    if (!process.env.JWT_SECRET) {
      return res.status(500).json({ error: 'JWT secret is not configured' });
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



app.get('/api/user/profile', async (req, res) => {
  const token = req.headers.authorization?.split(" ")[1]; // Get token after "Bearer"

  if (!token) {
      return res.status(401).json({ error: 'Unauthorized' });
  }

  try {
      const decoded = jwt.verify(token, process.env.JWT_SECRET);
      const user = await User.findById(decoded.id).select('-password');

      if (!user) {
          return res.status(404).json({ error: 'User not found' });
      }

      res.status(200).json({ username: user.username });
  } catch (err) {
      console.error('Error fetching user profile:', err);
      res.status(401).json({ error: 'Invalid token' });
  }
});



app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});

console.log('MONGODB_URI:', process.env.MONGODB_URI); // This will show if it's set correctly

