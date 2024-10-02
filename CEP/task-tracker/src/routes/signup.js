// src/routes/signup.js

const express = require('express');
const bcrypt = require('bcrypt');
const User = require('../models/User'); // Adjust the path if needed
const router = express.Router();

router.post('/signup', async (req, res) => {
    // Log the request body for debugging
    console.log("Request body: ", req.body);

    const { username, email, password } = req.body;

    // Check if all fields are present
    if (!username || !email || !password) {
        return res.status(400).json({ message: 'Please provide username, email, and password' });
    }

    try {
        // Check if the user already exists by email or username
        const existingUser = await User.findOne({ $or: [{ email }, { username }] });
        if (existingUser) {
            return res.status(400).json({ message: 'User with this email or username already exists!' });
        }

        // Hash the password
        const hashedPassword = await bcrypt.hash(password, 10);

        // Create a new user
        const newUser = new User({
            username,
            email,
            password: hashedPassword
        });

        // Save the new user in the database
        await newUser.save();
        return res.status(201).json({ message: 'User created successfully!' });

    } catch (error) {
        console.error('Error during signup:', error);
        return res.status(500).json({ message: 'Server error during signup' });
    }
});

module.exports = router;
