import React, { useContext, useEffect, useState } from 'react';
import { jsPDF } from 'jspdf';
import { TaskContext } from '../context/TaskContext';
import '../css/TaskReport.css';

const TaskReport = () => {
    const { tasks, updateTask } = useContext(TaskContext);
    const [todayTasks, setTodayTasks] = useState([]);
    const [selectedTaskIds, setSelectedTaskIds] = useState([]); // State to track selected task IDs

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
            const status = task.completed ? 'Completed' : 'Incomplete';
            doc.text(`${index + 1}. ${task.title} - ${new Date(task.reminderTime).toLocaleTimeString()} - ${status}`, 10, 30 + (index * 10));
        });

        doc.save('task_report.pdf');
    };

    // Function to handle checkbox change
    const handleCheckboxChange = (taskId) => {
        setSelectedTaskIds((prevSelected) => {
            if (prevSelected.includes(taskId)) {
                // If the task is already selected, remove it
                return prevSelected.filter((id) => id !== taskId);
            } else {
                // Otherwise, add it to the selected IDs
                return [...prevSelected, taskId];
            }
        });
    };

    // Function to mark selected tasks as completed/incomplete
    const handleUpdateSelectedTasks = async () => {
        await Promise.all(selectedTaskIds.map(updateTask)); // Update each selected task
        setSelectedTaskIds([]); // Clear the selected tasks after update
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
                        {todayTasks.map((task) => (
                            <li key={task.id}>
                                <input
                                    type="checkbox"
                                    checked={selectedTaskIds.includes(task.id)}
                                    onChange={() => handleCheckboxChange(task.id)}
                                />
                                {task.title} - {new Date(task.reminderTime).toLocaleTimeString()}
                            </li>
                        ))}
                    </ul>
                    <button onClick={handleUpdateSelectedTasks}>Update Selected Tasks</button>
                    <button onClick={generatePDF}>Download PDF</button>
                </>
            ) : (
                <p>No tasks for today!</p>
            )}
        </div>
    );
};

export default TaskReport;
