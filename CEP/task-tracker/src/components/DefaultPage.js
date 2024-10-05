// src/components/DefaultPage.js
import React from 'react';
import { Link } from 'react-router-dom'; // Import Link for navigation
import '../css/DefaultPage.css';
const DefaultPage = () => {
  return (
    <div className="default-page">
      <h1>Welcome to Task Tracker!</h1>
      <p>Your personal task management tool.</p>
      <p>
        <Link to="/signup">Create a New Account</Link> {/* Link to signup */}
      </p>
      <p>
        <Link to="/login">Sign In</Link> {/* Link to login */}
      </p>
    </div>
  );
};

export default DefaultPage;
