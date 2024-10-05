import React from 'react';
import TaskItem from './TaskItem';
import '../css/styles.css';

const TaskList = ({ tasks, onDelete }) => {
  return (
    <ul className="task-list">
      {tasks.map((task) => (
        <TaskItem key={task.id} task={task} onDelete={onDelete} />
      ))}
    </ul>
  );
};

export default TaskList;
