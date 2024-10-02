// const express = require('express');
// const bcrypt = require('bcrypt');
// const User = require('../models/User');
// const router = express.Router();

// router.post('/signup', async (req, res) => {
//     const { name, email, username, password } = req.body; // Include username here

//     try {
//         // Check if the user already exists
//         const existingUser = await User.findOne({ email }); // Check based on email
//         if (existingUser) {
//             return res.status(400).json({ message: 'User already exists!' });
//         }

//         // Hash the password
//         const hashedPassword = await bcrypt.hash(password, 10);

//         // Create a new user
//         const newUser = new User({
//             name,
//             email,
//             username, // Ensure this is populated
//             password: hashedPassword
//         });

//         await newUser.save();
//         res.status(201).json({ message: 'User created successfully!' });
//     } catch (error) {
//         console.error(error);
//         res.status(500).json({ message: 'Server error' });
//     }
// });


// module.exports = router;

// prev comment
// const express = require('express');
// const bcrypt = require('bcrypt');
// const User = require('../models/User');
// const router = express.Router();

// router.post('/signup', async (req, res) => {
//     const { name, email, username, password } = req.body;

//     // Validate input
//     if (!name || !email || !username || !password) {
//         return res.status(400).json({ message: 'All fields are required!' });
//     }

//     try {
//         // Check if the user already exists by email or username
//         const existingUserByEmail = await User.findOne({ email });
//         const existingUserByUsername = await User.findOne({ username });

//         if (existingUserByEmail) {
//             return res.status(400).json({ message: 'Email already exists!' });
//         }

//         if (existingUserByUsername) {
//             return res.status(400).json({ message: 'Username already exists!' });
//         }

//         // Hash the password
//         const hashedPassword = await bcrypt.hash(password, 10);

//         // Create a new user
//         const newUser = new User({
//             name,
//             email,
//             username,
//             password: hashedPassword
//         });

//         // Save the user to the database
//         await newUser.save();
//         res.status(201).json({ message: 'User created successfully!' });
//     } catch (error) {
//         console.error('Error creating user:', error);
//         res.status(500).json({ message: 'Server error' });
//     }
// });

// module.exports = router;



// const express = require('express');
// const bcrypt = require('bcrypt');
// const User = require('../models/User');
// const router = express.Router();

// // router.post('/signup', async (req, res) => {
// //     const { username, email, password } = req.body;

// //     // Validate input
// //     if (!username || !email || !password) {
// //         return res.status(400).json({ message: 'All fields are required!' });
// //     }
// //     try {
// //         // Check if the user already exists by email or username
// //         const existingUserByEmail = await User.findOne({ email });
// //         const existingUserByUsername = await User.findOne({ username });

// //         if (existingUserByEmail) {
// //             return res.status(400).json({ message: 'Email already exists!' });
// //         }

// //         if (existingUserByUsername) {
// //             return res.status(400).json({ message: 'Username already exists!' });
// //         }

// //         // Hash the password
// //         const hashedPassword = await bcrypt.hash(password, 10);

// //         // Create a new user
// //         const newUser = new User({
// //             username,
// //             email,
// //             password: hashedPassword,
// //         });

// //         // Save the user to the database
// //         await newUser.save();
// //         res.status(201).json({ message: 'User created successfully!' });
// //     } catch (error) {
// //         console.error('Error creating user:', error);
// //         res.status(500).json({ message: 'Server error' });
// //     }
// // });

// router.post('/signup', async (req, res) => {
//     const { username, email, password } = req.body; // No 'name' field here

//     // Basic validation to check if username, email, and password are present
//     if (!username || !email || !password) {
//         return res.status(400).json({ message: 'Please provide username, email, and password' });
//     }

//     try {
//         // Check if the user already exists
//         const existingUser = await User.findOne({ email });
//         if (existingUser) {
//             return res.status(400).json({ message: 'User already exists!' });
//         }

//         // Hash the password
//         const hashedPassword = await bcrypt.hash(password, 10);

//         // Create a new user
//         const newUser = new User({
//             username,
//             email,
//             password: hashedPassword
//         });

//         await newUser.save();
//         res.status(201).json({ message: 'User created successfully!' });
//     } catch (error) {
//         console.error('Error during signup:', error);
//         res.status(500).json({ message: 'Server error' });
//     }
// });


// module.exports = router;








const express = require('express');
const bcrypt = require('bcrypt');
const User = require('../models/User');
const router = express.Router();

router.post('/signup', async (req, res) => {
    console.log(req.body); // Log the incoming request body

    const { username, email, password } = req.body;

    // Basic validation to check if username, email, and password are present
    if (!username || !email || !password) {
        return res.status(400).json({ message: 'Please provide username, email, and password' });
    }

    try {
        // Check if the user already exists
        const existingUser = await User.findOne({ email });
        if (existingUser) {
            return res.status(400).json({ message: 'User already exists!' });
        }

        // Hash the password
        const hashedPassword = await bcrypt.hash(password, 10);

        // Create a new user
        const newUser = new User({
            username,
            email,
            password: hashedPassword
        });

        await newUser.save();
        res.status(201).json({ message: 'User created successfully!' });
    } catch (error) {
        console.error('Error during signup:', error);
        res.status(500).json({ message: 'Server error' });
    }
});

module.exports = router;
