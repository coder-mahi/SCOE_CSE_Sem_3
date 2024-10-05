import React, { useState } from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom'; // Import Router, Route, and Routes
import Header from './components/Header';
import AddTask from './components/AddTask';
import TaskList from './components/TaskList';
import Footer from './components/Footer';
import Signup from './components/Signup'; // Import Signup component
import Login from './components/Login';   // Import Login component
import Home from './components/Home';     // Import Home component

const App = () => {
  const [tasks, setTasks] = useState([]);

  const addTask = (task) => {
    const id = Math.floor(Math.random() * 10000) + 1;
    const newTask = { id, ...task };
    setTasks([...tasks, newTask]);
  };

  const deleteTask = (id) => {
    setTasks(tasks.filter((task) => task.id !== id));
  };

  return (
    <Router>
      <div className="container">
        <Header />
        <Routes>
          <Route path="/signup" element={<Signup />} />
          <Route path="/login" element={<Login />} />
          <Route path="/home" element={<Home />} />
          <Route path="/" element={<AddTask onAdd={addTask} />} /> {/* Default Route */}
        </Routes>
        <TaskList tasks={tasks} onDelete={deleteTask} />
        <Footer />
      </div>
    </Router>
  );
};

export default App;
