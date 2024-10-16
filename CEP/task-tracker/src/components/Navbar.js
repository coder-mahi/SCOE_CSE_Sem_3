// src/components/Navbar.js
import React from 'react';
import { Link } from 'react-router-dom';
import '../css/Navbar.css'; // Import CSS for Navbar

const Navbar = ({ isLoggedIn, onLogout }) => {
    return (
        <nav className="navbar">
            <div className="navbar-logo">Task Tracker</div>
            <ul className="navbar-links">
                <li><Link to={isLoggedIn ? "/home" : "/defaultpage"}>Home</Link></li>
                {isLoggedIn && <li><Link to="/addtask">Add Task</Link></li>}
                {isLoggedIn && <li><Link to="/calendar">Task Calendar</Link></li>} {/* Added Task Calendar link */}
                {isLoggedIn && <li><Link to="/task-report">Task Report</Link></li>} {/* New Menu Item */}
                {isLoggedIn ? (
                    <>
                        <li><Link to="/profile">Profile</Link></li>
                        <li>
                            <button className="logout-btn" onClick={onLogout}>Logout</button>
                        </li>
                    </>
                ) : (
                    <>
                        <li><Link to="/signup">Signup</Link></li>
                        <li><Link to="/login">Login</Link></li>
                    </>
                )}
            </ul>
        </nav>
    );
};

export default Navbar;
