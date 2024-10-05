import React, { useState } from 'react';
import '../css/AddTask.css';
const AddTask = ({ onAdd }) => {
  const [task, setTask] = useState('');

  const onSubmit = (e) => {
    e.preventDefault();

    if (!task) {
      alert('Please add a task!');
      return;
    }

    onAdd({ task });

    setTask('');
  };

  return (
    <form className="add-task-form" onSubmit={onSubmit}>
      <input
        type="text"
        placeholder="Add new task..."
        value={task}
        onChange={(e) => setTask(e.target.value)}
      />
      <button type="submit">Add Task</button>
    </form>
  );
};

export default AddTask;
