import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import '../css/Signup.css';

function Signup({ setIsAuthenticated }) {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [confirmPassword, setConfirmPassword] = useState('');
  const [error, setError] = useState('');
  const navigate = useNavigate();

  const handleSignup = (e) => {
    e.preventDefault();
    
    // Check if passwords match
    if (password !== confirmPassword) {
      setError('Passwords do not match!');
      return;
    }

    // Here you would typically send a request to your server to create an account.
    // For this example, we'll simply authenticate and navigate to the tasks page.
    setIsAuthenticated(true);
    navigate('/tasks');
  };

  return (
    <div className="signup-container">
      <h2>Sign Up</h2>
      {error && <p className="error-message">{error}</p>}
      <form onSubmit={handleSignup}>
        <input
          type="text"
          placeholder="Username"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
          required
        />
        <input
          type="password"
          placeholder="Password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
          required
        />
        <input
          type="password"
          placeholder="Confirm Password"
          value={confirmPassword}
          onChange={(e) => setConfirmPassword(e.target.value)}
          required
        />
        <button type="submit">Sign Up</button>
      </form>
      <p className="login-redirect">
        Already have an account? <a href="/login">Log In</a>
      </p>
    </div>
  );
}

export default Signup;
