import React, { useEffect, useState } from 'react';
import axios from 'axios';
import '../css/Profile.css'; // Import CSS for Profile
import profileImage from '../assets/profile.png'; // Adjust path according to your structure

const Profile = () => {
    const [username, setUsername] = useState('');
    const [email, setEmail] = useState('');
    const [profilePicture, setProfilePicture] = useState('');
    const [error, setError] = useState('');
    const [loading, setLoading] = useState(true); // Loading state

    useEffect(() => {
        const fetchUserProfile = async () => {
            try {
                const response = await axios.get('http://localhost:5000/api/user/profile', {
                    headers: {
                        'Authorization': `Bearer ${localStorage.getItem('token')}` // Pass the token in the header
                    }
                });
                setUsername(response.data.username);
                setEmail(response.data.email); // Set email from the API response
                setProfilePicture(response.data.profilePicture || profileImage); // Use local image if no profile picture
                setLoading(false); // Set loading to false after fetching
            } catch (error) {
                setLoading(false); // Set loading to false on error
                if (error.response) {
                    setError(error.response.data.error);
                } else {
                    setError('Error fetching user profile');
                }
            }
        };

        fetchUserProfile();
    }, []);

    const handleLogout = () => {
        localStorage.removeItem('token'); // Clear token on logout
        window.location.href = '/login'; // Example redirect
    };

    return (
        <div className="profile-container">
            <h1>User Profile</h1>
            {error && <p style={{ color: 'red' }}>{error}</p>}
            {loading ? (
                <p>Loading...</p>
            ) : (
                <div className="profile-info">
                    <img src={profilePicture} alt="Profile" className="profile-picture" />
                    <p>Welcome, {username}!</p>
                    <p>Email: {email}</p> {/* Display email here */}
                    <button onClick={handleLogout} className="logout-button">Logout</button>
                </div>
            )}
        </div>
    );
};

export default Profile;
