// src/components/TaskCalendar.js
import React, { useEffect, useState, useContext } from 'react';
import { Calendar, dateFnsLocalizer } from 'react-big-calendar';
import format from 'date-fns/format';
import parse from 'date-fns/parse';
import startOfWeek from 'date-fns/startOfWeek';
import getDay from 'date-fns/getDay';
import 'react-big-calendar/lib/css/react-big-calendar.css';
import enUS from 'date-fns/locale/en-US';
import { TaskContext } from '../context/TaskContext'; // Import the TaskContext

const locales = {
    'en-US': enUS,
};

const localizer = dateFnsLocalizer({
    format,
    parse,
    startOfWeek,
    getDay,
    locales,
});

const TaskCalendar = () => {
    const { tasks } = useContext(TaskContext); // Access tasks from context
    const [events, setEvents] = useState([]);

    useEffect(() => {
        // Map tasks to calendar events
        const mappedEvents = tasks.map((task) => ({
            title: task.title,
            start: new Date(task.reminderTime), // Ensure correct date format
            end: new Date(task.reminderTime), // Assuming single-day task
            allDay: true,
        }));

        setEvents(mappedEvents); // Update the calendar with mapped events
    }, [tasks]); // Re-run when tasks change

    return (
        <div>
            <h2>Task Calendar</h2>
            <Calendar
                localizer={localizer}
                events={events}
                startAccessor="start"
                endAccessor="end"
                style={{ height: 500 }}
            />
        </div>
    );
};

export default TaskCalendar;
