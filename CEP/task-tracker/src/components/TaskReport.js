// import React, { useContext, useEffect, useState, useCallback } from 'react';
// import { jsPDF } from 'jspdf';
// import { TaskContext } from '../context/TaskContext';
// import '../css/TaskReport.css';

// const TaskReport = () => {
//     const { tasks } = useContext(TaskContext);
//     const [todayTasks, setTodayTasks] = useState([]);

//     // Function to get tasks for today
//     const getTodayTasks = useCallback(() => {
//         const today = new Date().toDateString();
//         return tasks.filter((task) => new Date(task.reminderTime).toDateString() === today);
//     }, [tasks]);

//     // Function to generate PDF report
//     const generatePDF = () => {
//         const doc = new jsPDF();
//         doc.text('Task Report for ' + new Date().toDateString(), 10, 10);
//         doc.text('===========================', 10, 20);

//         todayTasks.forEach((task, index) => {
//             doc.text(`${index + 1}. ${task.title} - ${new Date(task.reminderTime).toLocaleTimeString()}`, 10, 30 + (index * 10));
//         });

//         doc.save('task_report.pdf');
//     };

//     useEffect(() => {
//         const todayTasksList = getTodayTasks();
//         setTodayTasks(todayTasksList);
//     }, [getTodayTasks]);

//     return (
//         <div className='TaskReport-container'>
//             <h2>Today's Task Report</h2>
//             {todayTasks.length > 0 ? (
//                 <>
//                     <ul className="task-list">
//                         {todayTasks.map((task, index) => (
//                             <li key={index} className="task-item">
//                                 {task.title} - {new Date(task.reminderTime).toLocaleTimeString()}
//                             </li>
//                         ))}
//                     </ul>
//                     <button className="download-button" onClick={generatePDF}>Download PDF</button>
//                 </>
//             ) : (
//                 <p>No tasks for today!</p>
//             )}
//         </div>
//     );
// };

// export default TaskReport;


import React, { useContext, useEffect, useState, useCallback } from 'react';
import { jsPDF } from 'jspdf';
import { TaskContext } from '../context/TaskContext';
import '../css/TaskReport.css';

const TaskReport = () => {
    const { tasks } = useContext(TaskContext);
    const [todayTasks, setTodayTasks] = useState([]);

    // Function to get tasks for today
    const getTodayTasks = useCallback(() => {
        const today = new Date().toDateString();
        return tasks.filter((task) => new Date(task.reminderTime).toDateString() === today);
    }, [tasks]);

    // Function to generate PDF report
    const generatePDF = () => {
        const doc = new jsPDF();
        doc.text('Task Report for ' + new Date().toDateString(), 10, 10);
        doc.text('===========================', 10, 20);

        todayTasks.forEach((task, index) => {
            const status = task.completed ? "Completed" : "Not Completed"; // Check completion status
            doc.text(`${index + 1}. ${task.title} - ${new Date(task.reminderTime).toLocaleTimeString()} - ${status}`, 10, 30 + (index * 10));
        });

        doc.save('task_report.pdf');
    };

    useEffect(() => {
        const todayTasksList = getTodayTasks();
        setTodayTasks(todayTasksList);
    }, [getTodayTasks]);

    return (
        <div className='TaskReport-container'>
            <h2>Today's Task Report</h2>
            {todayTasks.length > 0 ? (
                <>
                    <ul className="task-list">
                        {todayTasks.map((task, index) => (
                            <li key={index} className="task-item">
                                {task.title} - {new Date(task.reminderTime).toLocaleTimeString()} - 
                                <span className={task.completed ? "completed" : "not-completed"}>
                                    {task.completed ? " Completed" : " Not Completed"}
                                </span>
                            </li>
                        ))}
                    </ul>
                    <button className="download-button" onClick={generatePDF}>Download PDF</button>
                </>
            ) : (
                <p>No tasks for today!</p>
            )}
        </div>
    );
};

export default TaskReport;
