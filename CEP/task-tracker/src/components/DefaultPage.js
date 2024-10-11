// // src/components/DefaultPage.js
// import React from 'react';
// import { Link } from 'react-router-dom'; // Import Link for navigation
// import '../css/DefaultPage.css';

// const DefaultPage = () => {
//   return (
//     <div className="default-page">
//       <img 
//         src="https://example.com/path-to-your-gif.gif" // Replace with your GIF URL
//         alt="Task Management GIF" 
//         className="welcome-gif" 
//       />
//       <h1>Welcome to Task Tracker!</h1>
//       <p>Your personal task management tool.</p>
//       <p>Efficiently organize your tasks, set reminders, and stay productive.</p>
//       <p>Join our community of task enthusiasts and take control of your productivity!</p>
//       <p>
//         <Link to="/signup">Create a New Account</Link> {/* Link to signup */}
//       </p>
//       <p>
//         <Link to="/login">Sign In</Link> {/* Link to login */}
//       </p>
//     </div>
//   );
// };

// export default DefaultPage;


// src/components/DefaultPage.js
import React from 'react';
import { Link } from 'react-router-dom'; // Import Link for navigation
import '../css/DefaultPage.css';
import LottieAnimation from './LottieAnimation'; // Import the LottieAnimation component

const DefaultPage = () => {
  return (
    <div className="default-page">
      <LottieAnimation src="https://lottie.host/73845b23-814b-47f5-be75-d6bf9db46ac5/vdh0XxKrJo.json" />
      <h1>Welcome to Task Tracker!</h1>
      <p>Your personal task management tool.</p>
      <p>Efficiently organize your tasks, set reminders, and stay productive.</p>
      <p>Join our community of task enthusiasts and take control of your productivity!</p>
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
