// // src/components/TaskReport.js
// import React, { useContext, useEffect, useState } from 'react';
// import { TaskContext } from '../context/TaskContext';

// const TaskReport = () => {
//     const { tasks } = useContext(TaskContext);
//     const [todayTasks, setTodayTasks] = useState([]);

//     // Function to get tasks for today
//     const getTodayTasks = () => {
//         const today = new Date().toDateString();
//         return tasks.filter((task) => new Date(task.reminderTime).toDateString() === today);
//     };

//     // Trigger the report generation at 6 PM
//     useEffect(() => {
//         const now = new Date();
//         const eveningTime = new Date();
//         eveningTime.setHours(18, 0, 0, 0); // Set to 6 PM

//         const timeToEvening = eveningTime - now; // Time left until 6 PM
//         if (timeToEvening > 0) {
//             const timeoutId = setTimeout(() => {
//                 const todayTasksList = getTodayTasks();
//                 setTodayTasks(todayTasksList);
//             }, timeToEvening);

//             return () => clearTimeout(timeoutId); // Clean up timeout
//         } else {
//             // If it's already past 6 PM, generate the report immediately
//             const todayTasksList = getTodayTasks();
//             setTodayTasks(todayTasksList);
//         }
//     }, [tasks]);

//     return (
//         <div>
//             <h2>Today's Task Report</h2>
//             {todayTasks.length > 0 ? (
//                 <ul>
//                     {todayTasks.map((task, index) => (
//                         <li key={index}>
//                             {task.title} - {new Date(task.reminderTime).toLocaleTimeString()}
//                         </li>
//                     ))}
//                 </ul>
//             ) : (
//                 <p>No tasks for today!</p>
//             )}
//         </div>
//     );
// };

// export default TaskReport;

import React, { useContext, useEffect, useState } from 'react';
import { jsPDF } from 'jspdf';
import { TaskContext } from '../context/TaskContext';
import '../css/TaskReport.css';

const TaskReport = () => {
    const { tasks } = useContext(TaskContext);
    const [todayTasks, setTodayTasks] = useState([]);

    // Function to get tasks for today
    const getTodayTasks = () => {
        const today = new Date().toDateString();
        return tasks.filter((task) => new Date(task.reminderTime).toDateString() === today);
    };

    // Function to generate PDF report
    const generatePDF = () => {
        const doc = new jsPDF();
        doc.text('Task Report for ' + new Date().toDateString(), 10, 10);
        doc.text('===========================', 10, 20);

        todayTasks.forEach((task, index) => {
            doc.text(`${index + 1}. ${task.title} - ${new Date(task.reminderTime).toLocaleTimeString()}`, 10, 30 + (index * 10));
        });

        doc.save('task_report.pdf');
    };

    useEffect(() => {
        const todayTasksList = getTodayTasks();
        setTodayTasks(todayTasksList);
    }, [tasks]);

    return (
        <div className='TaskReport-container'>
            <h2>Today's Task Report</h2>
            {todayTasks.length > 0 ? (
                <>
                    <ul>
                        {todayTasks.map((task, index) => (
                            <li key={index}>
                                {task.title} - {new Date(task.reminderTime).toLocaleTimeString()}
                            </li>
                        ))}
                    </ul>
                    <button onClick={generatePDF}>Download PDF</button>
                </>
            ) : (
                <p>No tasks for today!</p>
            )}
        </div>
    );
};

export default TaskReport;
