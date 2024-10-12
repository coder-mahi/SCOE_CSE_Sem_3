import React, { useState } from 'react';
import '../css/AddTask.css';

const AddTask = ({ onAdd }) => {
  const [title, setTitle] = useState('');
  const [description, setDescription] = useState('');
  const [reminder, setReminder] = useState(''); // New state for reminder

  const onSubmit = (e) => {
    e.preventDefault();

    if (!title || !description || !reminder) {
      alert('Please add a title, description, and reminder for the task!');
      return;
    }

    // Pass reminderTime as reminder
    onAdd({ title, description, reminderTime: reminder }); // Include reminderTime in the task
    setTitle('');
    setDescription('');
    setReminder(''); // Reset reminder field
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
      <input
        type="datetime-local" // Input for datetime
        value={reminder}
        onChange={(e) => setReminder(e.target.value)}
      />
      <button type="submit">Add Task</button>
    </form>
  );
};

export default AddTask;
