// import React, { useState } from 'react';
// import { useNavigate } from 'react-router-dom';
// import '../css/Signup.css';

// function Signup({ setIsAuthenticated }) {
//   const [username, setUsername] = useState('');
//   const [email, setEmail] = useState(''); // Email state
//   const [password, setPassword] = useState('');
//   const [confirmPassword, setConfirmPassword] = useState('');
//   const [error, setError] = useState('');
//   const navigate = useNavigate();

//   const handleSignup = async (e) => {
//     e.preventDefault();

//     if (password !== confirmPassword) {
//         setError('Passwords do not match!');
//         return;
//     }

//     try {
//         const response = await fetch('http://localhost:5000/api/users/signup', { 
//             method: 'POST',
//             headers: {
//                 'Content-Type': 'application/json',
//             },
//             body: JSON.stringify({ name: username, email, username, password }), 
//      });

//         const data = await response.json();
//         if (response.ok) {
//             setIsAuthenticated(true);
//             navigate('/tasks');
//         } else {
//             setError(data.message || 'Signup failed!');
//         }
//     } catch (error) {
//         console.error('Error during signup:', error);
//         setError('Signup failed! Please try again.');
//     }
// };


//   return (
//     <div className="signup-container">
//       <form onSubmit={handleSignup}>
//         <h2>Signup</h2>
//         <input 
//           type="text" 
//           placeholder="Username" 
//           value={username} 
//           onChange={(e) => setUsername(e.target.value)} 
//           required 
//         />
//         <input 
//           type="email" // Set the input type to email
//           placeholder="Email" 
//           value={email} 
//           onChange={(e) => setEmail(e.target.value)} 
//           required 
//         />
//         <input 
//           type="password" 
//           placeholder="Password" 
//           value={password} 
//           onChange={(e) => setPassword(e.target.value)} 
//           required 
//         />
//         <input 
//           type="password" 
//           placeholder="Confirm Password" 
//           value={confirmPassword} 
//           onChange={(e) => setConfirmPassword(e.target.value)} 
//           required 
//         />
//         <button type="submit">Signup</button>
//         {error && <p className="error">{error}</p>} {/* Display error message */}
//       </form>
//     </div>
//   );
// }

// export default Signup;


// import React, { useState } from 'react';
// import { useNavigate } from 'react-router-dom';
// import '../css/Signup.css';

// function Signup({ setIsAuthenticated }) {
//   const [name, setName] = useState(''); // New state for name
//   const [username, setUsername] = useState('');
//   const [email, setEmail] = useState('');
//   const [password, setPassword] = useState('');
//   const [confirmPassword, setConfirmPassword] = useState('');
//   const [error, setError] = useState('');
//   const navigate = useNavigate();

//   const handleSignup = async (e) => {
//     e.preventDefault();

//     if (password !== confirmPassword) {
//         setError('Passwords do not match!');
//         return;
//     }

//     try {
//         const response = await fetch('http://localhost:5000/api/users/signup', { 
//             method: 'POST',
//             headers: {
//                 'Content-Type': 'application/json',
//             },
//             body: JSON.stringify({ name, email, username, password }), // Send name and username separately
//      });

//         const data = await response.json();
//         if (response.ok) {
//             setIsAuthenticated(true);
//             navigate('/tasks');
//         } else {
//             setError(data.message || 'Signup failed!');
//         }
//     } catch (error) {
//         console.error('Error during signup:', error);
//         setError('Signup failed! Please try again.');
//     }
// };


//   return (
//     <div className="signup-container">
//       <form onSubmit={handleSignup}>
//         <h2>Signup</h2>
//         <input 
//           type="text" 
//           placeholder="Name" // New field for the name
//           value={name} 
//           onChange={(e) => setName(e.target.value)} 
//           required 
//         />
//         <input 
//           type="text" 
//           placeholder="Username" 
//           value={username} 
//           onChange={(e) => setUsername(e.target.value)} 
//           required 
//         />
//         <input 
//           type="email" 
//           placeholder="Email" 
//           value={email} 
//           onChange={(e) => setEmail(e.target.value)} 
//           required 
//         />
//         <input 
//           type="password" 
//           placeholder="Password" 
//           value={password} 
//           onChange={(e) => setPassword(e.target.value)} 
//           required 
//         />
//         <input 
//           type="password" 
//           placeholder="Confirm Password" 
//           value={confirmPassword} 
//           onChange={(e) => setConfirmPassword(e.target.value)} 
//           required 
//         />
//         <button type="submit">Signup</button>
//         {error && <p className="error">{error}</p>} {/* Display error message */}
//       </form>
//     </div>
//   );
// }

// export default Signup;


// last code
import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import '../css/Signup.css';

function Signup({ setIsAuthenticated }) {
  const [username, setUsername] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [confirmPassword, setConfirmPassword] = useState('');
  const [error, setError] = useState('');
  const navigate = useNavigate();

//   const handleSignup = async (e) => {
//     e.preventDefault();

//     if (password !== confirmPassword) {
//         setError('Passwords do not match!');
//         return;
//     }

//     try {
//         const response = await fetch('http://localhost:5000/api/users/signup', { 
//             method: 'POST',
//             headers: {
//                 'Content-Type': 'application/json',
//             },
//             body: JSON.stringify({ username, email, password }), // Only username, email, and password
//         });

//         const data = await response.json();
//         if (response.ok) {
//             setIsAuthenticated(true);
//             navigate('/tasks');
//         } else {
//             setError(data.message || 'Signup failed!');
//         }
//     } catch (error) {
//         console.error('Error during signup:', error);
//         setError('Signup failed! Please try again.');
//     }
//   };

////working
const handleSignup = async (e) => {
    e.preventDefault();

    try {
        const response = await fetch('http://localhost:5000/api/users/signup', { 
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                username, // Only username, email, and password
                email,
                password
            }), 
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

  return (
    <div className="signup-container">
      <form onSubmit={handleSignup}>
        <h2>Signup</h2>
        <input 
          type="text" 
          placeholder="Username" 
          value={username} 
          onChange={(e) => setUsername(e.target.value)} 
          required 
        />
        <input 
          type="email"
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
        <button type="submit">Signup</button>
        {error && <p className="error">{error}</p>}
      </form>
    </div>
  );
}

export default Signup;
