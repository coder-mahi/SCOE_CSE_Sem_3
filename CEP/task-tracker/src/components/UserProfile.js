import React, { useState, useEffect } from 'react';

function UserProfile() {
  const [user, setUser] = useState({ name: '', email: '' });

  useEffect(() => {
    // Fetch user details
    const fetchUser = async () => {
      const response = await fetch('http://localhost:5000/api/user');
      const data = await response.json();
      setUser(data);
    };

    fetchUser();
  }, []);

  return (
    <div>
      <h2>User Profile</h2>
      <p>Name: {user.name}</p>
      <p>Email: {user.email}</p>
      {/* Include an edit button or functionality */}
    </div>
  );
}

export default UserProfile;
