import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import axios from 'axios'; // Make sure to install axios if you haven't already
import '../css/Signup.css';

function Signup({ setIsAuthenticated }) {
  const [username, setUsername] = useState('');
  const [email, setEmail] = useState(''); // Add email state
  const [password, setPassword] = useState('');
  const [confirmPassword, setConfirmPassword] = useState('');
  const [error, setError] = useState('');
  const navigate = useNavigate();



  const handleSignup = async (e) => {
    e.preventDefault();

    if (password !== confirmPassword) {
        setError('Passwords do not match!');
        return;
    }

    try {
        const response = await fetch('http://localhost:5000/api/users', { // Use full URL to your API
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ name: username, email: username, password }), // Assuming username is the email
        });

        const data = await response.json();
        if (response.ok) {
            setIsAuthenticated(true);
            navigate('/tasks');
        } else {
            setError(data.message || 'Signup failed!');
        }
    } catch (error) {
        console.error('Error during signup:', error);
        setError('Signup failed! Please try again.');
    }
};




//   const handleSignup = async (e) => {
//     e.preventDefault();
    
//     // Check if passwords match
//     if (password !== confirmPassword) {
//       setError('Passwords do not match!');
//       return;
//     }

//     try {
//       const response = await axios.post('/api/signup', { name: username, email, password });
//       if (response.status === 201) {
//         // Optionally authenticate the user after signup
//         setIsAuthenticated(true);
//         navigate('/tasks');
//       }
//     } catch (err) {
//       setError(err.response?.data?.message || 'Signup failed. Please try again.');
//     }
//   };

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
          type="email" // Change to email type
          placeholder="Email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
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
