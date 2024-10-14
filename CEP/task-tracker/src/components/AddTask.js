// import React, { useState } from 'react';
// import '../css/AddTask.css';

// const AddTask = ({ onAdd }) => {
//   const [title, setTitle] = useState('');
//   const [description, setDescription] = useState('');
//   const [reminder, setReminder] = useState(''); // New state for reminder

//   const onSubmit = (e) => {
//     e.preventDefault();

//     if (!title || !description || !reminder) {
//       alert('Please add a title, description, and reminder for the task!');
//       return;
//     }

//     // Pass reminderTime as reminder
//     onAdd({ title, description, reminderTime: reminder }); // Include reminderTime in the task
//     setTitle('');
//     setDescription('');
//     setReminder(''); // Reset reminder field
//   };

//   return (
//     <form className="add-task-form" onSubmit={onSubmit}>
//       <input
//         type="text"
//         placeholder="Add task title..."
//         value={title}
//         onChange={(e) => setTitle(e.target.value)}
//       />
//       <textarea
//         placeholder="Add task description..."
//         value={description}
//         onChange={(e) => setDescription(e.target.value)}
//       />
//       <input
//         type="datetime-local" // Input for datetime
//         value={reminder}
//         onChange={(e) => setReminder(e.target.value)}
//       />
//       <button type="submit">Add Task</button>
//     </form>
//   );
// };

// export default AddTask;






import React, { useState } from 'react';
import '../css/AddTask.css';

const AddTask = () => {
  const [title, setTitle] = useState('');
  const [description, setDescription] = useState('');
  const [reminder, setReminder] = useState(''); // State for reminder
  const [error, setError] = useState(''); // State for error message
  const token = localStorage.getItem('token'); // Get the JWT token from local storage

  const onSubmit = async (e) => {
    e.preventDefault();

    if (!title || !description || !reminder) {
      setError('Please add a title, description, and reminder for the task!');
      return;
    }

    const taskData = { title, description, reminderTime: reminder };

    try {
      const response = await fetch('http://localhost:5000/addtask', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
          Authorization: `Bearer ${token}`, // Include the token in the headers
        },
        body: JSON.stringify(taskData),
      });

      if (!response.ok) {
        throw new Error('Failed to add task');
      }

      const result = await response.json();
      console.log('Task added successfully:', result);
      
      // Reset form fields
      setTitle('');
      setDescription('');
      setReminder('');
      setError('');
    } catch (error) {
      console.error('Error adding task:', error);
      setError(error.message);
    }
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
      {error && <p className="error-message">{error}</p>} {/* Display error message */}
    </form>
  );
};

export default AddTask;
