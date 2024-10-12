// // src/components/TaskList.js
// import React from 'react';
// import '../css/TaskList.css';

// const TaskList = ({ tasks, onDelete }) => {
//   return (
//     <div className="task-list">
//       <h2>Your Tasks</h2>
//       {tasks.length === 0 ? (
//         <p>No tasks available. Add a new task!</p>
//       ) : (
//         tasks.map((task) => (
//           <div key={task.id} className="task">
//             <h3>{task.title}</h3>
//             <p>{task.description}</p>
//             <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
//             <button onClick={() => onDelete(task.id)}>Delete</button>
//           </div>
//         ))
//       )}
//     </div>
//   );
// };

// export default TaskList;


import React from 'react';
import '../css/TaskList.css';

const TaskList = ({ tasks, onDelete }) => {
  return (
    <div className="task-list">
      <h2>Your Tasks</h2>
      {tasks.length === 0 ? (
        <p>No tasks available. Add a new task!</p>
      ) : (
        tasks.map((task) => (
          <div key={task.id} className="task">
            <h3>{task.title}</h3>
            <p>{task.description}</p>
            <p><strong>Reminder:</strong> {new Date(task.reminderTime).toLocaleString()}</p>
            <button onClick={() => onDelete(task.id)}>Delete</button>
          </div>
        ))
      )}
    </div>
  );
};

export default TaskList;
