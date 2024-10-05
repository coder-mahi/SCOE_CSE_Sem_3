// src/App.js
import React, { useState } from 'react';
import { BrowserRouter as Router, Route, Routes, Navigate } from 'react-router-dom'; // Import Router, Route, Routes, and Navigate
import AddTask from './components/AddTask'; // Import AddTask component
import TaskList from './components/TaskList'; // Import TaskList component
import Footer from './components/Footer'; // Import Footer component
import Signup from './components/Signup'; // Import Signup component
import Login from './components/Login'; // Import Login component
//import Home from './components/Home'; // Import Home component
import Navbar from './components/Navbar'; // Import Navbar component
import DefaultPage from './components/DefaultPage'; // Import DefaultPage component
import './App.css'; // Import CSS for App

const App = () => {
  const [tasks, setTasks] = useState([]); // State to store tasks
  const [isLoggedIn, setIsLoggedIn] = useState(false); // State to manage login status

  // Function to add a task
  const addTask = (task) => {
    const id = Math.floor(Math.random() * 10000) + 1; // Generate a random ID for the task
    const newTask = { id, ...task }; // Create a new task object
    setTasks([...tasks, newTask]); // Update the tasks state
  };

  // Function to delete a task
  const deleteTask = (id) => {
    setTasks(tasks.filter((task) => task.id !== id)); // Filter out the deleted task
  };

  // Function to handle login
  const handleLogin = () => {
    setIsLoggedIn(true); // Set login status to true
  };

  return (
    <Router>
      <div className="container">
        <Routes>
          {/* Route for the Default Page */}
          <Route path="/" element={<DefaultPage />} />
          
          {/* Route for Signup and Login */}
          <Route path="/signup" element={<Signup onSignup={handleLogin} />} />
          <Route path="/login" element={<Login onLogin={handleLogin} />} />

          {/* Route for Home page */}
          <Route path="/home" element={
            <>
              <Navbar /> {/* Navbar component */}
              <AddTask onAdd={addTask} /> {/* AddTask Component */}
              <TaskList tasks={tasks} onDelete={deleteTask} /> {/* TaskList Component */}
              <Footer /> {/* Footer component */}
            </>
          } />

          {/* Redirect to Home if logged in */}
          <Route path="/signup" element={isLoggedIn ? <Navigate to="/home" /> : <Signup onSignup={handleLogin} />} />
          <Route path="/login" element={isLoggedIn ? <Navigate to="/home" /> : <Login onLogin={handleLogin} />} />
        </Routes>
      </div>
    </Router>
  );
};

export default App;
