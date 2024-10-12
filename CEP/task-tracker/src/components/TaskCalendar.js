// src/components/TaskCalendar.js

import React, { useState, useEffect } from 'react';
import Calendar from 'react-calendar';
import 'react-calendar/dist/Calendar.css';
import '../css/TaskCalendar.css'; // Create this CSS file for custom styles

const TaskCalendar = ({ tasks }) => {
  const [value, setValue] = useState(new Date()); // State to hold the selected date
  const [markedDates, setMarkedDates] = useState({}); // State to hold marked dates

  // Effect to prepare marked dates based on tasks
  useEffect(() => {
    const dates = {};
    tasks.forEach((task) => {
      const date = new Date(task.reminderTime).toLocaleDateString();
      dates[date] = (dates[date] || 0) + 1; // Count tasks for the date
    });
    setMarkedDates(dates);
  }, [tasks]);

  const tileClassName = ({ date, view }) => {
    if (view === 'month') {
      const dateString = date.toLocaleDateString();
      return markedDates[dateString] ? 'marked' : null; // Apply class if tasks exist for the date
    }
  };

  return (
    <div className="task-calendar">
      <h2>Task Calendar</h2>
      <Calendar
        onChange={setValue}
        value={value}
        tileClassName={tileClassName} // Use the function to set tile classes
      />
      <div className="task-details">
        <h3>Tasks on {value.toLocaleDateString()}:</h3>
        <ul>
          {tasks
            .filter((task) => new Date(task.reminderTime).toLocaleDateString() === value.toLocaleDateString())
            .map((task) => (
              <li key={task.id}>
                {task.title} <span className="tick">✔️</span>
              </li>
            ))}
        </ul>
      </div>
    </div>
  );
};

export default TaskCalendar;
