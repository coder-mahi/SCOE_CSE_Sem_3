// src/components/TaskItem.js
import React from 'react';
import '../css/TaskItem.css'; // Import CSS for TaskItem

const TaskItem = ({ task, onDelete }) => {
    return (
        <div className="task-item">
            <h3>{task.title}</h3> {/* Displaying task title */}
            <p>{task.description}</p> {/* Displaying task description */}
            <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
            <button className="delete-btn" onClick={() => onDelete(task._id)}>
                Delete
            </button>
        </div>
    );
};

export default TaskItem;
