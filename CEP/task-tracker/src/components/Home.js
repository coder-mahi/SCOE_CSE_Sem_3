// src/components/Home.js
import '../css/Home.css';
import React, { useEffect, useState } from 'react';
import axios from 'axios';
import { useNavigate } from 'react-router-dom';

const Home = () => {
  const [message, setMessage] = useState('');
  const navigate = useNavigate();

  useEffect(() => {
    const fetchHomeData = async () => {
      const token = localStorage.getItem('token');

      if (!token) {
        navigate('/login'); // Redirect to login if no token is found
        return;
      }

      try {
        const response = await axios.get('http://localhost:5000/home', {
          headers: {
            Authorization: token, // Send token in Authorization header
          },
        });
        setMessage(response.data.message);
      } catch (error) {
        console.error(error);
        navigate('/login'); // Redirect to login if there is an error
      }
    };

    fetchHomeData();
  }, [navigate]);

  return (
    <div>
      <h2>Home</h2>
      <p>{message}</p>
      {/* Removed TaskCalendar */}
    </div>
  );
};

export default Home;
