// src/models/Task.js

class Task {
    constructor(title, description, dueDate, assignedTo) {
      this.title = title;
      this.description = description;
      this.dueDate = dueDate;
      this.assignedTo = assignedTo; // User ID or reference
      this.completed = false;
      this.createdAt = new Date();
      this.updatedAt = new Date();
    }
  }
  
  export default Task;
  