// src/components/DefaultPage.js
import React from 'react';
import { Link } from 'react-router-dom'; // Import Link for navigation
import '../css/DefaultPage.css';
import LottieAnimation from './LottieAnimation'; // Import the LottieAnimation component

const DefaultPage = () => {
  return (
    <div className="default-page">
      <LottieAnimation className="lottie-animation" src="https://lottie.host/73845b23-814b-47f5-be75-d6bf9db46ac5/vdh0XxKrJo.json" />
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
