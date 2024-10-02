// // // src/server.js

// const express = require('express');
// const mongoose = require('mongoose');
// const cors = require('cors');
// const dotenv = require('dotenv'); // Require dotenv to load environment variables
// const userRoutes = require('./routes/users'); // Adjust the path if necessary
// dotenv.config(); // Load environment variables from .env file
// const bodyParser = require('body-parser');

// const app = express();
// const PORT = process.env.PORT || 5000;

// // Middleware to parse JSON data
// // Middleware to parse JSON bodies
// app.use(express.json());
// app.use('/api/users', require('./routes/signup'));

// // Connect to MongoDB and start server...
// app.use(bodyParser.json()); 
// app.use(bodyParser.urlencoded({ extended: true }));


// // Middleware
// app.use(cors({
//     origin:'http://localhost:3000'
// }));

// app.use(express.json());

// // app.post('/api/users/signup',(req,res)=>{

// // });

// mongoose.connect(process.env.MONGODB_URI)
//     .then(() => console.log('MongoDB connected'))
//     .catch(err => console.error('MongoDB connection error:', err));

// // Routes
// app.use('/api/users', userRoutes); // Use your users route

// app.listen(PORT, () => {
//     console.log(`Server is running on http://localhost:${PORT}`);
// });


// // const express = require('express');
// // const mongoose = require('mongoose');
// // const cors = require('cors');
// // const userRoutes = require('./routes/users');

// // const app = express();
// // const PORT = process.env.PORT || 5000;

// // // Middleware
// // app.use(cors());
// // app.use(express.json()); // For parsing application/json

// // // MongoDB Connection
// // mongoose.connect(process.env.MONGODB_URI, { useNewUrlParser: true, useUnifiedTopology: true })
// //     .then(() => console.log('MongoDB connected!'))
// //     .catch(err => console.error('MongoDB connection error:', err));

// // // Routes
// // app.use('/api/users', userRoutes); // Use your users route

// // app.listen(PORT, () => {
// //     console.log(`Server is running on http://localhost:${PORT}`);
// // });




// src/server.js

const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
const dotenv = require('dotenv'); 
const userRoutes = require('./routes/users'); // Import user-related routes
dotenv.config(); // Load environment variables from .env file

const app = express();
const PORT = process.env.PORT || 5000;

// Middleware
app.use(cors({
    origin: 'http://localhost:3000', // Allow requests from your React frontend
}));
app.use(express.json()); // Use express's built-in body parser

// Routes
app.use('/api/users', userRoutes); // User routes (for signup, login, etc.)

// MongoDB Connection
mongoose.connect(process.env.MONGODB_URI, { 
    useNewUrlParser: true, 
    useUnifiedTopology: true 
})
    .then(() => console.log('MongoDB connected'))
    .catch(err => console.error('MongoDB connection error:', err));

// Start the server
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
