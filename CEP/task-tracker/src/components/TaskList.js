// // // src/components/TaskList.js
// // import React, { useEffect, useState } from 'react';
// // import '../css/TaskList.css';

// // const TaskList = () => {
// //   const [tasks, setTasks] = useState([]);
// //   const [error, setError] = useState('');
// //   const token = localStorage.getItem('token'); // Get the JWT token from local storage

// //   useEffect(() => {
// //     const fetchTasks = async () => {
// //       if (!token) {
// //         setError('No token found. Please log in.');
// //         return;
// //       }

// //       try {
// //         const response = await fetch('http://localhost:5000/gettasks', {
// //           method: 'GET',
// //           headers: {
// //             Authorization: `Bearer ${token}`, // Include the token in the headers
// //           },
// //         });

// //         if (!response.ok) {
// //           throw new Error('Failed to fetch tasks');
// //         }

// //         const data = await response.json();
// //         setTasks(data); // Assuming the API returns an array of tasks
// //       } catch (error) {
// //         console.error('Error fetching tasks:', error);
// //         setError(error.message);
// //       }
// //     };

// //     fetchTasks();
// //   }, [token]);

// //   const onDelete = async (taskId) => {
// //     try {
// //       const response = await fetch(`http://localhost:5000/deletetask/${taskId}`, {
// //         method: 'DELETE',
// //         headers: {
// //           Authorization: `Bearer ${token}`, 
// //         },
// //       });

// //       if (!response.ok) {
// //         throw new Error('Failed to delete task');
// //       }

// //       setTasks(tasks.filter((task) => task._id !== taskId)); // Adjust if task ID is _id
// //     } catch (error) {
// //       console.error('Error deleting task:', error);
// //       setError(error.message);
// //     }
// //   };

// //   return (
// //     <div className="task-list">
// //       <h2>Your Tasks</h2>
// //       {error && <p className="error-message">{error}</p>} {/* Display error message */}
// //       {tasks.length === 0 ? (
// //         <p>No tasks available. Add a new task!</p>
// //       ) : (
// //         tasks.map((task) => (
// //           <div key={task._id} className="task"> {/* Use _id if that's the field */}
// //             <h3>{task.title}</h3>
// //             <p>{task.description}</p>
// //             <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
// //             <button onClick={() => onDelete(task._id)}>Delete</button>
// //           </div>
// //         ))
// //       )}
// //     </div>
// //   );
// // };

// // export default TaskList;


// // src/components/TaskList.js
// import React, { useEffect, useState } from 'react';
// import '../css/TaskList.css';
// import TaskCalendar from './TaskCalendar'; // Import the TaskCalendar component

// const TaskList = () => {
//   const [tasks, setTasks] = useState([]);
//   const [error, setError] = useState('');
//   const token = localStorage.getItem('token'); // Get the JWT token from local storage

//   useEffect(() => {
//     const fetchTasks = async () => {
//       if (!token) {
//         setError('No token found. Please log in.');
//         return;
//       }

//       try {
//         const response = await fetch('http://localhost:5000/gettasks', {
//           method: 'GET',
//           headers: {
//             Authorization: `Bearer ${token}`, // Include the token in the headers
//           },
//         });

//         if (!response.ok) {
//           throw new Error('Failed to fetch tasks');
//         }

//         const data = await response.json();
//         setTasks(data); // Assuming the API returns an array of tasks
//       } catch (error) {
//         console.error('Error fetching tasks:', error);
//         setError(error.message);
//       }
//     };

//     fetchTasks();
//   }, [token]);

//   const onDelete = async (taskId) => {
//     try {
//       const response = await fetch(`http://localhost:5000/deletetask/${taskId}`, {
//         method: 'DELETE',
//         headers: {
//           Authorization: `Bearer ${token}`, 
//         },
//       });

//       if (!response.ok) {
//         throw new Error('Failed to delete task');
//       }

//       setTasks(tasks.filter((task) => task._id !== taskId)); // Adjust if task ID is _id
//     } catch (error) {
//       console.error('Error deleting task:', error);
//       setError(error.message);
//     }
//   };

//   return (
//     <div className="task-list">
//       <h2>Your Tasks</h2>
//       {error && <p className="error-message">{error}</p>} {/* Display error message */}
//       {tasks.length === 0 ? (
//         <p>No tasks available. Add a new task!</p>
//       ) : (
//         tasks.map((task) => (
//           <div key={task._id} className="task"> {/* Use _id if that's the field */}
//             <h3>{task.title}</h3>
//             <p>{task.description}</p>
//             <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
//             <button onClick={() => onDelete(task._id)}>Delete</button>
//           </div>
//         ))
//       )}

//       {/* Render TaskCalendar and pass the fetched tasks as props */}
//       <TaskCalendar tasks={tasks} />
//     </div>
//   );
// };

// export default TaskList;


// src/components/TaskList.js
import React, { useEffect, useState } from 'react';
import { Link } from 'react-router-dom'; // Import Link for navigation
import '../css/TaskList.css';

const TaskList = () => {
  const [tasks, setTasks] = useState([]);
  const [error, setError] = useState('');
  const token = localStorage.getItem('token'); // Get the JWT token from local storage

  useEffect(() => {
    const fetchTasks = async () => {
      if (!token) {
        setError('No token found. Please log in.');
        return;
      }

      try {
        const response = await fetch('http://localhost:5000/gettasks', {
          method: 'GET',
          headers: {
            Authorization: `Bearer ${token}`, // Include the token in the headers
          },
        });

        if (!response.ok) {
          throw new Error('Failed to fetch tasks');
        }

        const data = await response.json();
        setTasks(data); // Assuming the API returns an array of tasks
      } catch (error) {
        console.error('Error fetching tasks:', error);
        setError(error.message);
      }
    };

    fetchTasks();
  }, [token]);

  const onDelete = async (taskId) => {
    try {
      const response = await fetch(`http://localhost:5000/deletetask/${taskId}`, {
        method: 'DELETE',
        headers: {
          Authorization: `Bearer ${token}`, 
        },
      });

      if (!response.ok) {
        throw new Error('Failed to delete task');
      }

      setTasks(tasks.filter((task) => task._id !== taskId)); // Adjust if task ID is _id
    } catch (error) {
      console.error('Error deleting task:', error);
      setError(error.message);
    }
  };

  return (
    <div className="task-list">
      <h2>Your Tasks</h2>
      {error && <p className="error-message">{error}</p>} {/* Display error message */}
      {tasks.length === 0 ? (
        <p>No tasks available. Add a new task!</p>
      ) : (
        tasks.map((task) => (
          <div key={task._id} className="task"> {/* Use _id if that's the field */}
            <h3>{task.title}</h3>
            <p>{task.description}</p>
            <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
            <button onClick={() => onDelete(task._id)}>Delete</button>
          </div>
        ))
      )}

      {/* Provide a link to the calendar page */}
      <Link to="/calendar">View Tasks on Calendar</Link>
    </div>
  );
};

export default TaskList;
