const express = require('express');
const app = express();
const postRoutes = require('./routes/postRoutes');
const commentRoutes = require('./routes/commentRoutes');

app.use(express.json());
app.use('/api/posts', postRoutes);
app.use('/api/comments', commentRoutes);

app.listen(3000, () => {
  console.log('Server started on port 3000');
});