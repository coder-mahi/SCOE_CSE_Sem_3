// // src/context/TaskContext.js
// import React, { createContext, useEffect, useState } from 'react';

// // Create the TaskContext
// export const TaskContext = createContext();

// // Create a provider component
// export const TaskProvider = ({ children }) => {
//     const [tasks, setTasks] = useState([]);
//     const token = localStorage.getItem('token'); // Get JWT token from local storage

//     useEffect(() => {
//         const fetchTasks = async () => {
//             if (!token) return; // Return if no token found

//             try {
//                 const response = await fetch('http://localhost:5000/gettasks', {
//                     method: 'GET',
//                     headers: {
//                         Authorization: `Bearer ${token}`, // Include the token in the headers
//                     },
//                 });

//                 if (!response.ok) {
//                     throw new Error('Failed to fetch tasks');
//                 }

//                 const data = await response.json();
//                 setTasks(data); // Assuming the API returns an array of tasks
//             } catch (error) {
//                 console.error('Error fetching tasks:', error);
//             }
//         };

//         fetchTasks();
//     }, [token]);

//     return (
//         <TaskContext.Provider value={{ tasks }}>
//             {children}
//         </TaskContext.Provider>
//     );
// };


import React, { createContext, useEffect, useState } from 'react';

// Create the TaskContext
export const TaskContext = createContext();

// Create a provider component
export const TaskProvider = ({ children }) => {
    const [tasks, setTasks] = useState([]);
    const token = localStorage.getItem('token'); // Get JWT token from local storage

    useEffect(() => {
        const fetchTasks = async () => {
            if (!token) return; // Return if no token found

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
            }
        };

        fetchTasks();
    }, [token]);

    return (
        <TaskContext.Provider value={{ tasks }}>
            {children}
        </TaskContext.Provider>
    );
};
