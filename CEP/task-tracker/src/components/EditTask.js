import React, { useState, useEffect } from 'react';
import { useParams } from 'react-router-dom';

function EditTask() {
  const { id } = useParams();
  const [task, setTask] = useState({ title: '', description: '' });

  useEffect(() => {
    // Fetch task by ID and set it in state
    const fetchTask = async () => {
      const response = await fetch(`http://localhost:5000/api/tasks/${id}`);
      const data = await response.json();
      setTask(data);
    };

    fetchTask();
  }, [id]);

  const handleSubmit = async (e) => {
    e.preventDefault();
    await fetch(`http://localhost:5000/api/tasks/${id}`, {
      method: 'PUT',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(task),
    });
    // Redirect or update state
  };

  return (
    <form onSubmit={handleSubmit}>
      <input
        type="text"
        value={task.title}
        onChange={(e) => setTask({ ...task, title: e.target.value })}
        placeholder="Task Title"
      />
      <textarea
        value={task.description}
        onChange={(e) => setTask({ ...task, description: e.target.value })}
        placeholder="Task Description"
      />
      <button type="submit">Update Task</button>
    </form>
  );
}

export default EditTask;
