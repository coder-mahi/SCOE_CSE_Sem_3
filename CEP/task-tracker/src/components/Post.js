import React, { useState } from 'react';

const Post = ({ post }) => {
  const [likes, setLikes] = useState(post.likes);
  const [comments, setComments] = useState(post.comments);

  const handleLike = () => {
    // Call API to like the post
  };

  const handleComment = (comment) => {
    // Call API to create a new comment
  };

  return (
    <div>
      <h2>{post.title}</h2>
      <p>{post.content}</p>
      <button onClick={handleLike}>Like ({likes})</button>
      <ul>
        {comments.map((comment) => (
          <li key={comment.id}>{comment.content}</li>
        ))}
      </ul>
      <form onSubmit={handleComment}>
        <input type="text" placeholder="Add a comment" />
        <button type="submit">Comment</button>
      </form>
    </div>
  );
};

export default Post;