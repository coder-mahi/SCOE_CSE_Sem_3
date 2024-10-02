import { useState } from 'react';
import { BrowserRouter as Router, Routes, Route, Navigate } from 'react-router-dom';
import Home from './components/Home';
import Login from './components/Login';
import Signup from './components/Signup';
import AddTask from './components/AddTask';
import TaskList from './components/TaskList';
import TaskDetail from './components/TaskDetail';
import Navbar from './components/Navbar';
import UserProfile from './components/UserProfile';
import Notification from './components/Notification';
import EditTask from './components/EditTask';

function App() {
  const [isAuthenticated, setIsAuthenticated] = useState(false);

  return (
    <Router>
      <Navbar isAuthenticated={isAuthenticated} setIsAuthenticated={setIsAuthenticated} />
      <Routes>
        <Route path="/" element={!isAuthenticated ? <Home /> : <Navigate to="/tasks" />} />
        <Route path="/login" element={<Login setIsAuthenticated={setIsAuthenticated} />} />
        <Route path="/signup" element={<Signup />} />
        {isAuthenticated && (
          <>
            <Route path="/addtask" element={<AddTask />} />
            <Route path="/tasks" element={<TaskList />} />
            <Route path="/task/:id" element={<TaskDetail />} />
          </>
        )}
        <Route path="*" element={<Navigate to={isAuthenticated ? "/tasks" : "/"} />} />
        <Route path="/edit-task/:id" element={<EditTask />} />
        <Route path="/profile" element={<UserProfile />} />
        <Route path="/notification" element={<Notification />} />

      </Routes>
    </Router>
  );
}

export default App;
