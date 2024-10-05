import React from 'react';
import '../css/styles.css';

const TaskItem = ({ task, onDelete }) => {
  return (
    <li className="task-item">
      <span>{task.task}</span>
      <button onClick={() => onDelete(task.id)}>Delete</button>
    </li>
  );
};

export default TaskItem;
