import React, { useEffect, useState } from 'react';
import axios from 'axios';
import '../css/Profile.css'; // Import CSS for Profile

const Profile = () => {
    const [username, setUsername] = useState('');
    const [error, setError] = useState('');

    useEffect(() => {
        const fetchUserProfile = async () => {
            try {
                const response = await axios.get('http://localhost:5000/api/user/profile', {
                    headers: {
                        'Authorization': `Bearer ${localStorage.getItem('token')}` // Pass the token in the header
                    }
                });
                setUsername(response.data.username);
            } catch (error) {
                if (error.response) {
                    setError(error.response.data.error);
                } else {
                    setError('Error fetching user profile');
                }
            }
        };

        fetchUserProfile();
    }, []);

    return (
        <div className="profile-container">
            <h1>User Profile</h1>
            {error && <p style={{ color: 'red' }}>{error}</p>}
            {username ? (
                <p>Welcome, {username}!</p>
            ) : (
                <p>Loading...</p>
            )}
            {/* Add more profile-related information here */}
        </div>
    );
};

export default Profile;
