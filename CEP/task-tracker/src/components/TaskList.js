// src/components/TaskList.js
import React from 'react';
import '../css/TaskList.css';

const TaskList = ({ tasks, onDelete }) => {
    return (
        <div className="task-list">
            {tasks.length > 0 ? (
                tasks.map((task) => (
                    <div className="task" key={task.id}>
                        <h3>{task.title}</h3>
                        <p>{task.description}</p>
                        <p><strong>Created At:</strong> {task.createdAt}</p> {/* Display task creation time */}
                        <button onClick={() => onDelete(task.id)}>Delete</button>
                    </div>
                ))
            ) : (
                <p>No tasks available</p>
            )}
        </div>
    );
};

export default TaskList;
