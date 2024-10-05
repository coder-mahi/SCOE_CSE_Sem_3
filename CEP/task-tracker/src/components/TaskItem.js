// src/components/TaskItem.js
import React from 'react';
import '../css/TaskItem.css'; // Import CSS for TaskItem

const TaskItem = ({ task, onDelete }) => {
    return (
        <div className="task-item">
            <h3>{task.title}</h3>
            <p>{task.description}</p>
            <button className="delete-btn" onClick={() => onDelete(task.id)}>
                Delete
            </button>
        </div>
    );
};

export default TaskItem;
