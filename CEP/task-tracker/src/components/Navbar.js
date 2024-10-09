// // src/components/Navbar.js
// import React from 'react';
// import { Link } from 'react-router-dom';
// import '../css/Navbar.css'; // Import CSS for Navbar

// const Navbar = () => {
//     return (
//         <nav className="navbar">
//             <div className="navbar-logo">Task Tracker</div>
//             <ul className="navbar-links">
//                 <li><Link to="/home">Home</Link></li>
//                 <li><Link to="/signup">Signup</Link></li>
//                 <li><Link to="/login">Login</Link></li>
//                 <li><Link to="/profile">Profile</Link></li>
//             </ul>
//         </nav>
//     );
// };

// export default Navbar;


// src/components/Navbar.js
import React from 'react';
import { Link } from 'react-router-dom';
import '../css/Navbar.css'; // Import CSS for Navbar

const Navbar = ({ isLoggedIn, onLogout }) => {
    return (
        <nav className="navbar">
            <div className="navbar-logo">Task Tracker</div>
            <ul className="navbar-links">
                <li><Link to="/">Home</Link></li>
                {isLoggedIn ? (
                    <>
                        <li><Link to="/profile">Profile</Link></li>
                        <li>
                            <button className="logout-btn" onClick={onLogout}>Logout</button>
                        </li>
                    </>
                ) : (
                    <>
                        <li><Link to="/signup">Signup</Link></li>
                        <li><Link to="/login">Login</Link></li>
                    </>
                )}
            </ul>
        </nav>
    );
};

export default Navbar;
