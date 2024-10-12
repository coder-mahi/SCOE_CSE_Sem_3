// import React, { useState, useEffect } from 'react';
// import { BrowserRouter as Router, Route, Routes, Navigate } from 'react-router-dom';
// import AddTask from './components/AddTask';
// import TaskList from './components/TaskList';
// import Footer from './components/Footer';
// import Signup from './components/Signup';
// import Login from './components/Login';
// import Navbar from './components/Navbar';
// import DefaultPage from './components/DefaultPage';
// import './App.css';
// import Profile from './components/Profile';
// import TaskCalendar from './components/TaskCalendar';

// const App = () => {
//     const [tasks, setTasks] = useState([]); // State to store tasks
//     const [isLoggedIn, setIsLoggedIn] = useState(false); // State to manage login status

//     // Function to add a task
//     const addTask = (task) => {
//         const id = Math.floor(Math.random() * 10000) + 1; // Generate a random ID for the task
//         const newTask = { 
//             id, 
//             ...task, 
//             createdAt: new Date().toLocaleString() // Add the current date and time as task creation time
//         };
//         setTasks([...tasks, newTask]); // Update the tasks state
//     };

//     // Function to delete a task
//     const deleteTask = (id) => {
//         setTasks(tasks.filter((task) => task.id !== id)); // Filter out the deleted task
//     };

//     // Check for due reminders every minute
//     useEffect(() => {
//         const intervalId = setInterval(() => {
//             const now = new Date();
//             tasks.forEach((task) => {
//                 const reminderTime = new Date(task.reminderTime);
//                 if (now >= reminderTime && !task.notified) {
//                     alert(`Reminder: ${task.title} is due now!`);
//                     task.notified = true; // Mark the task as notified
//                 }
//             });
//         }, 60000); // Check every minute

//         return () => clearInterval(intervalId); // Cleanup interval on component unmount
//     }, [tasks]);

//     // Function to handle login
//     const handleLogin = () => {
//         setIsLoggedIn(true); // Set login status to true
//     };

//     // Function to handle logout
//     const handleLogout = () => {
//         setIsLoggedIn(false); // Set login status to false
//         localStorage.removeItem('token'); // Remove token from local storage
//     };

//     return (
//         <Router>
//             <div className="container">
//                 {/* Pass props to Navbar */}
//                 <Navbar isLoggedIn={isLoggedIn} onLogout={handleLogout} />

//                 <Routes>
//                     <Route path="/defaultpage" element={isLoggedIn ? <Navigate to="/home" /> : <DefaultPage />} />
//                     <Route path="/signup" element={isLoggedIn ? <Navigate to="/home" /> : <Signup onSignup={handleLogin} />} />
//                     <Route path="/login" element={isLoggedIn ? <Navigate to="/home" /> : <Login onLogin={handleLogin} />} />
//                     <Route path="/home" element={isLoggedIn ? (
//                         <>
//                             <TaskList tasks={tasks} onDelete={deleteTask} />
//                             <Footer />
//                         </>
//                     ) : (
//                         <Navigate to="/defaultpage" />
//                     )} />
//                     <Route path="/addtask" element={isLoggedIn ? <AddTask onAdd={addTask} /> : <Navigate to="/defaultpage" />} />
//                     <Route path="*" element={<Navigate to={isLoggedIn ? "/home" : "/defaultpage"} />} />
//                     <Route path='/profile' element={<Profile/>}></Route>

//                     <Route path="/calendar" element={isLoggedIn ? <TaskCalendar tasks={tasks} /> : <Navigate to="/defaultpage" />} />
//                     <Route path="*" element={<Navigate to={isLoggedIn ? "/home" : "/defaultpage"} />} />
//                 </Routes>
//             </div>
//         </Router>
//     );
// };

// export default App;

// src/App.js
import React, { useState, useEffect } from 'react';
import { BrowserRouter as Router, Route, Routes, Navigate } from 'react-router-dom';
import AddTask from './components/AddTask';
import TaskList from './components/TaskList';
import Footer from './components/Footer';
import Signup from './components/Signup';
import Login from './components/Login';
import Navbar from './components/Navbar';
import DefaultPage from './components/DefaultPage';
import './App.css';
import Profile from './components/Profile';
import TaskCalendar from './components/TaskCalendar';

const App = () => {
    const [tasks, setTasks] = useState([]); // State to store tasks
    const [isLoggedIn, setIsLoggedIn] = useState(
        localStorage.getItem('isLoggedIn') === 'true' || false
    ); // Persist login status

    // Function to add a task
    const addTask = (task) => {
        const id = Math.floor(Math.random() * 10000) + 1; // Generate a random ID for the task
        const newTask = {
            id,
            ...task,
            createdAt: new Date().toLocaleString(), // Add the current date and time as task creation time
            notified: false, // Initialize notified status
        };
        setTasks((prevTasks) => [...prevTasks, newTask]); // Update the tasks state
    };

    // Function to delete a task
    const deleteTask = (id) => {
        setTasks((prevTasks) => prevTasks.filter((task) => task.id !== id)); // Filter out the deleted task
    };

    // Check for due reminders every minute
    useEffect(() => {
        const intervalId = setInterval(() => {
            setTasks((prevTasks) =>
                prevTasks.map((task) => {
                    const now = new Date();
                    const reminderTime = new Date(task.reminderTime);
                    if (now >= reminderTime && !task.notified) {
                        alert(`Reminder: ${task.title} is due now!`);
                        return { ...task, notified: true }; // Mark the task as notified
                    }
                    return task;
                })
            );
        }, 60000); // Check every minute

        return () => clearInterval(intervalId); // Cleanup interval on component unmount
    }, []);

    // Function to handle login
    const handleLogin = () => {
        setIsLoggedIn(true); // Set login status to true
        localStorage.setItem('isLoggedIn', 'true'); // Save login status to localStorage
    };

    // Function to handle logout
    const handleLogout = () => {
        setIsLoggedIn(false); // Set login status to false
        localStorage.removeItem('isLoggedIn'); // Remove login status from localStorage
        localStorage.removeItem('token'); // Remove token from local storage
    };

    return (
        <Router>
            <div className="container">
                {/* Pass props to Navbar */}
                <Navbar isLoggedIn={isLoggedIn} onLogout={handleLogout} />

                <Routes>
                    <Route
                        path="/defaultpage"
                        element={
                            isLoggedIn ? <Navigate to="/home" /> : <DefaultPage />
                        }
                    />
                    <Route
                        path="/signup"
                        element={
                            isLoggedIn ? (
                                <Navigate to="/home" />
                            ) : (
                                <Signup onSignup={handleLogin} />
                            )
                        }
                    />
                    <Route
                        path="/login"
                        element={
                            isLoggedIn ? (
                                <Navigate to="/home" />
                            ) : (
                                <Login onLogin={handleLogin} />
                            )
                        }
                    />
                    <Route
                        path="/home"
                        element={
                            isLoggedIn ? (
                                <>
                                    <TaskList tasks={tasks} onDelete={deleteTask} />
                                    <Footer />
                                </>
                            ) : (
                                <Navigate to="/defaultpage" />
                            )
                        }
                    />
                    <Route
                        path="/addtask"
                        element={
                            isLoggedIn ? (
                                <AddTask onAdd={addTask} />
                            ) : (
                                <Navigate to="/defaultpage" />
                            )
                        }
                    />
                    <Route
                        path="/calendar"
                        element={
                            isLoggedIn ? (
                                <TaskCalendar tasks={tasks} />
                            ) : (
                                <Navigate to="/defaultpage" />
                            )
                        }
                    />
                    <Route
                        path="/profile"
                        element={
                            isLoggedIn ? (
                                <Profile />
                            ) : (
                                <Navigate to="/defaultpage" />
                            )
                        }
                    />
                    {/* Catch-all route should be defined only once at the end */}
                    <Route
                        path="*"
                        element={
                            isLoggedIn ? (
                                <Navigate to="/home" />
                            ) : (
                                <Navigate to="/defaultpage" />
                            )
                        }
                    />
                </Routes>
            </div>
        </Router>
    );
};

export default App;
