import { useState } from 'react';
import { BrowserRouter as Router, Routes, Route, Navigate } from 'react-router-dom';
import Home from './components/Home';
import Login from './components/Login';
import Signup from './components/Signup';
import AddTask from './components/AddTask';
import TaskList from './components/TaskList';
import TaskDetail from './components/TaskDetail';
import Navbar from './components/Navbar';

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
      </Routes>
    </Router>
  );
}

export default App;
