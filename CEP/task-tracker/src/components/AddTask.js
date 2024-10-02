import { useState } from 'react';
import '../css/AddTask.css';

function AddTask() {
  const [task, setTask] = useState('');
  const [description, setDescription] = useState('');

  const handleSubmit = (e) => {
    e.preventDefault();
    // Handle adding task logic
    console.log({ task, description });
    setTask('');
    setDescription('');
  };

  return (
    <div className="addtask-container">
      <h2>Add New Task</h2>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          placeholder="Task Title"
          value={task}
          onChange={(e) => setTask(e.target.value)}
          required
        />
        <textarea
          placeholder="Task Description"
          value={description}
          onChange={(e) => setDescription(e.target.value)}
          required
        ></textarea>
        <button type="submit">Add Task</button>
      </form>
    </div>
  );
}

export default AddTask;
