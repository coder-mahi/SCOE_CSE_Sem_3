// server/server.js
const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const app = express();
const PORT = 5000;

app.use(cors());
app.use(bodyParser.json());

let tasks = [];
let taskId = 1;

// Get all tasks
app.get('/api/tasks', (req, res) => {
  res.json(tasks);
});

// Create a new task
app.post('/api/tasks', (req, res) => {
  const newTask = { id: taskId++, title: req.body.title };
  tasks.push(newTask);
  res.json(newTask);
});

// Dummy user authentication
app.post('/api/login', (req, res) => {
  const { username, password } = req.body;
  // Implement actual authentication logic
  if (username === 'test' && password === 'password') {
    res.json({ message: 'Login successful' });
  } else {
    res.status(401).json({ message: 'Invalid credentials' });
  }
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
