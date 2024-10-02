const express = require('express');
const bcrypt = require('bcrypt'); // Make sure to require bcrypt
const router = express.Router();
const User = require('../models/User'); // Ensure this points to your user model

// Signup Route
router.post('/signup', async (req, res) => {
    const { name, email, password } = req.body;

    // Validate input (you might want to add more validation)
    if (!name || !email || !password) {
        return res.status(400).json({ message: 'Please provide name, email, and password' });
    }

    try {
        // Check if user already exists
        const existingUser = await User.findOne({ email });
        if (existingUser) {
            return res.status(400).json({ message: 'User already exists' });
        }

        // Hash the password
        const hashedPassword = await bcrypt.hash(password, 10);

        // Create a new user
        const newUser = new User({
            name,
            email,
            password: hashedPassword
        });

        await newUser.save();
        res.status(201).json({ message: 'User created successfully!' });
    } catch (error) {
        console.error(error);
        res.status(500).json({ message: 'Server error' });
    }
});

// Export the router
module.exports = router;
