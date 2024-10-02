import '../css/Home.css';
import React from 'react';
import { Link } from 'react-router-dom';
import TaskList from './TaskList'; // This is for showing tasks after login
import logo from '../assets/logo.png';

function Home({ isAuthenticated }) {
  return (
    <div className="home-container">
      {isAuthenticated ? (
        <>
          <h2>Welcome back! Here are your tasks:</h2>
          <TaskList />
        </>
      ) : (
        <div className="welcome-section">
           <img src={logo} alt="Welcome" className="welcome-logo" />
          <h1>Welcome to the Task Tracker</h1>
          <p>Manage your tasks efficiently and stay organized.</p>
          <p><Link to="/signup">Create an account</Link> or <Link to="/login">login</Link> to get started!</p>
        </div>
      )}
    </div>
  );
}

export default Home;

  