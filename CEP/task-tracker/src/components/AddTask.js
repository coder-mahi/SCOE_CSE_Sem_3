// src/components/AddTask.js
import React, { useState } from 'react';
import '../css/AddTask.css';

const AddTask = ({ onAdd }) => {
  const [title, setTitle] = useState('');
  const [description, setDescription] = useState('');

  const onSubmit = (e) => {
    e.preventDefault();

    if (!title || !description) {
      alert('Please add a title and description for the task!');
      return;
    }
    onAdd({ title, description }); 
    setTitle('');
    setDescription('');
  };

  return (
    <form className="add-task-form" onSubmit={onSubmit}>
      <input
        type="text"
        placeholder="Add task title..."
        value={title}
        onChange={(e) => setTitle(e.target.value)}
      />
      <textarea
        placeholder="Add task description..."
        value={description}
        onChange={(e) => setDescription(e.target.value)}
      />
      <button type="submit">Add Task</button>
    </form>
  );
};

export default AddTask;
