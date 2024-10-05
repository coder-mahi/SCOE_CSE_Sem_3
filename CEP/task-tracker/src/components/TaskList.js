// src/components/TaskList.js
import React from 'react';
import TaskItem from './TaskItem'; // Import the TaskItem component
import '../css/TaskList.css'; // Import CSS for TaskList

const TaskList = ({ tasks, onDelete }) => {
    return (
        <div className="task-list">
            <h2>Task List</h2>
            {tasks.length === 0 ? (
                <p>No tasks to show</p>
            ) : (
                tasks.map((task) => (
                    <TaskItem key={task.id} task={task} onDelete={onDelete} />
                ))
            )}
        </div>
    );
};

export default TaskList;
