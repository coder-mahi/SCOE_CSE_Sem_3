require('dotenv').config(); // Load environment variables
const mongoose = require('mongoose');

// Connect to MongoDB
const connectDB = async () => {
    try {
        const uri = process.env.MONGODB_URI; // Use your connection string
        await mongoose.connect(uri);
        console.log('MongoDB Connected...');
    } catch (err) {
        console.error(err.message);
        process.exit(1);
    }
};

// Define User schema and model
const userSchema = new mongoose.Schema({
    name: String,
    email: String,
    password: String,
    // Add other fields as necessary
});

const User = mongoose.model('User', userSchema);

// Function to update users
const updateUsers = async () => {
    await connectDB();

    try {
        // Example: Update user with a specific email
        const result = await User.updateMany(
            { email: 'example@example.com' }, // Filter criteria
            { $set: { name: 'New Name' } } // Fields to update
        );

        console.log('Updated Users:', result);
    } catch (error) {
        console.error('Error updating users:', error);
    } finally {
        mongoose.connection.close(); // Close the connection
    }
};

// Call the update function
updateUsers();
