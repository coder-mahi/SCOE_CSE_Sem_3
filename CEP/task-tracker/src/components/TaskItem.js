import React from 'react';
import '../css/TaskItem.css';

const TaskItem = ({ task, onDelete }) => {
    return (
        <div className="task-item">
            <h3>{task.title}</h3> 
            <p>{task.description}</p> 
            <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
            <button className="delete-btn" onClick={() => onDelete(task._id)}>
                Delete
            </button>
        </div>
    );
};

export default TaskItem;
