import { Link } from 'react-router-dom';
import '../css/TaskList.css';

function TaskList() {
  // Dummy task data
  const tasks = [
    { id: 1, title: 'Complete React Project' },
    { id: 2, title: 'Review CSS Grid' },
  ];

  return (
    <div className="tasklist-container">
      <h2>Your Tasks</h2>
      <ul>
        {tasks.map((task) => (
          <li key={task.id}>
            <Link to={`/task/${task.id}`}>{task.title}</Link>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default TaskList;
