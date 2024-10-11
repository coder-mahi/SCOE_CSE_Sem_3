// import React, { useEffect, useState } from 'react';
// import axios from 'axios';
// import '../css/Profile.css'; // Import CSS for Profile

// const Profile = () => {
//     const [username, setUsername] = useState('');
//     const [error, setError] = useState('');

//     useEffect(() => {
//         const fetchUserProfile = async () => {
//             try {
//                 const response = await axios.get('http://localhost:5000/api/user/profile', {
//                     headers: {
//                         'Authorization': `Bearer ${localStorage.getItem('token')}` // Pass the token in the header
//                     }
//                 });
//                 setUsername(response.data.username);
//             } catch (error) {
//                 if (error.response) {
//                     setError(error.response.data.error);
//                 } else {
//                     setError('Error fetching user profile');
//                 }
//             }
//         };

//         fetchUserProfile();
//     }, []);

//     return (
//         <div className="profile-container">
//             <h1>User Profile</h1>
//             {error && <p style={{ color: 'red' }}>{error}</p>}
//             {username ? (
//                 <p>Welcome, {username}!</p>
//             ) : (
//                 <p>Loading...</p>
//             )}
//             {/* Add more profile-related information here */}
//         </div>
//     );
// };

// export default Profile;


import React, { useEffect, useState } from 'react';
import axios from 'axios';
import '../css/Profile.css'; // Import CSS for Profile

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
                setEmail(response.data.email); // Assume email is returned from the API
                setProfilePicture(response.data.profilePicture); // Assume profile picture URL is returned
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
        // Redirect to login or home page (implement redirect as needed)
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
                    {profilePicture && (
                        <img src={profilePicture} alt="Profile" className="profile-picture" />
                    )}
                    <p>Welcome, {username}!</p>
                    <p>Email: {email}</p>
                    <button onClick={handleLogout} className="logout-button">Logout</button>
                </div>
            )}
        </div>
    );
};

export default Profile;
