// // src/components/TaskList.js
// import React, { useEffect, useState } from 'react';
// import { Link } from 'react-router-dom'; 
// import '../css/TaskList.css';

// const TaskList = () => {
//     const [tasks, setTasks] = useState([]);
//     const [error, setError] = useState('');
//     const token = localStorage.getItem('token'); 

//     useEffect(() => {
//         const fetchTasks = async () => {
//             if (!token) {
//                 setError('No token found. Please log in.');
//                 return;
//             }

//             try {
//                 const response = await fetch('http://localhost:5000/gettasks', {
//                     method: 'GET',
//                     headers: {
//                         Authorization: `Bearer ${token}`,
//                     },
//                 });

//                 if (!response.ok) {
//                     throw new Error('Failed to fetch tasks');
//                 }

//                 const data = await response.json();
//                 setTasks(data);
//             } catch (error) {
//                 console.error('Error fetching tasks:', error);
//                 setError(error.message);
//             }
//         };

//         fetchTasks();
//     }, [token]);

//     const onDelete = async (taskId) => {
//         try {
//             const response = await fetch(`http://localhost:5000/deletetask/${taskId}`, {
//                 method: 'DELETE',
//                 headers: {
//                     Authorization: `Bearer ${token}`,
//                 },
//             });

//             if (!response.ok) {
//                 const errorText = await response.text();
//                 throw new Error(`Failed to delete task: ${errorText}`);
//             }

//             setTasks((prevTasks) => prevTasks.filter((task) => task._id !== taskId));
//         } catch (error) {
//             console.error('Error deleting task:', error.message);
//             setError(error.message);
//         }
//     };

//     return (
//         <div className="task-list">
//             <h2>Your Tasks</h2>
//             {error && <p className="error-message">{error}</p>} 
//             {tasks.length === 0 ? (
//                 <p>No tasks available. Add a new task!</p>
//             ) : (
//                 tasks.map((task) => (
//                     <div key={task._id} className="task"> 
//                         <h3>{task.title}</h3>
//                         <p>{task.description}</p>
//                         <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
//                         <button onClick={() => onDelete(task._id)}>Delete</button>
//                     </div>
//                 ))
//             )}
//             <Link to="/calendar">View Tasks on Calendar</Link>
//         </div>
//     );
// };

// export default TaskList;

// src/components/TaskList.js
import React, { useEffect, useState } from 'react';
import { Link } from 'react-router-dom'; 
import '../css/TaskList.css';

const TaskList = () => {
    const [tasks, setTasks] = useState([]);
    const [error, setError] = useState('');
    const token = localStorage.getItem('token'); 

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
                        Authorization: `Bearer ${token}`,
                    },
                });

                if (!response.ok) {
                    throw new Error('Failed to fetch tasks');
                }

                const data = await response.json();
                setTasks(data);
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
                const errorText = await response.text();
                throw new Error(`Failed to delete task: ${errorText}`);
            }

            setTasks((prevTasks) => prevTasks.filter((task) => task._id !== taskId));
        } catch (error) {
            console.error('Error deleting task:', error.message);
            setError(error.message);
        }
    };

    return (
        <div className="task-list">
            <h2>Your Tasks</h2>
            {error && <p className="error-message">{error}</p>} 
            {tasks.length === 0 ? (
                <p>No tasks available. Add a new task!</p>
            ) : (
                tasks.map((task) => (
                    <div key={task._id} className="task"> 
                        <h3>{task.title}</h3>
                        <p>{task.description}</p>
                        <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
                        <button onClick={() => onDelete(task._id)}>Delete</button>
                    </div>
                ))
            )}
            <Link to="/calendar">View Tasks on Calendar</Link>
        </div>
    );
};

export default TaskList;
