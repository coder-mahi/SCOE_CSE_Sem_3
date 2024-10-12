import React, { useState } from 'react';
import '../css/AddTask.css';

const AddTask = ({ onAdd }) => {
  const [title, setTitle] = useState('');
  const [description, setDescription] = useState('');
  const [reminderTime, setReminderTime] = useState('');

  const onSubmit = (e) => {
    e.preventDefault();

    if (!title || !description || !reminderTime) {
      alert('Please fill out all fields!');
      return;
    }

    onAdd({ title, description, reminderTime });
    setTitle('');
    setDescription('');
    setReminderTime('');
  };

  return (
    <form className="add-task-form" onSubmit={onSubmit}>
      <input
        type="text"
        placeholder="Task Title"
        value={title}
        onChange={(e) => setTitle(e.target.value)}
      />
      <textarea
        placeholder="Task Description"
        value={description}
        onChange={(e) => setDescription(e.target.value)}
      />
      <label>Reminder Time:</label>
      <input
        type="datetime-local"
        value={reminderTime}
        onChange={(e) => setReminderTime(e.target.value)}
      />
      <button type="submit">Add Task</button>
    </form>
  );
};

export default AddTask;
