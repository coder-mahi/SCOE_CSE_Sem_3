import { useParams } from 'react-router-dom';
import '../css/TaskDetail.css';

function TaskDetail() {
  const { id } = useParams();
  // Dummy task detail
  const task = {
    id,
    title: `Task ${id} Title`,
    description: `This is the description for task ${id}.`,
  };

  return (
    <div className="taskdetail-container">
      <h2>{task.title}</h2>
      <p>{task.description}</p>
    </div>
  );
}

export default TaskDetail;
