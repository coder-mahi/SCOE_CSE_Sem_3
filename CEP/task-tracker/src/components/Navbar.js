import { Link } from 'react-router-dom';
import '../css/Navbar.css';

function Navbar({ isAuthenticated, setIsAuthenticated }) {
  const handleLogout = () => {
    setIsAuthenticated(false);
  };

  return (
    <nav>
      <ul>
        {!isAuthenticated ? (
          <>
            <li><Link to="/home">Home</Link></li>
            <li><Link to="/login">Login</Link></li>
            <li><Link to="/signup">Signup</Link></li>
          </>
        ) : (
          <>
            <li><Link to="/tasks">Task List</Link></li>
            <li><Link to="/addtask">Add Task</Link></li>
            <li><Link to="/home">Home</Link></li> {/* Show Home only when logged in */}
            <li><button onClick={handleLogout}>Logout</button></li>
          </>
        )}
      </ul>
    </nav>
  );
}

export default Navbar;
