import React from 'react';

function DeleteTask({ taskId, onDelete }) {
  const handleDelete = async () => {
    await fetch(`http://localhost:5000/api/tasks/${taskId}`, {
      method: 'DELETE',
    });
    onDelete(taskId); // Callback to remove the task from UI
  };

  return (
    <button onClick={handleDelete}>Delete Task</button>
  );
}

export default DeleteTask;
