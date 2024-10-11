// src/components/LottieAnimation.js
import React from 'react';

const LottieAnimation = ({ src, width = '300px', height = '300px', loop = true, autoplay = true }) => {
  return (
    <div className="lottie-animation">
      <script src="https://unpkg.com/@lottiefiles/lottie-player@latest/dist/lottie-player.js"></script>
      <lottie-player 
        src={src} 
        background="#ffffff" 
        speed="1" 
        style={{ width, height }} 
        loop={loop} 
        autoplay={autoplay} 
        direction="1" 
        mode="normal">
      </lottie-player>
    </div>
  );
};

export default LottieAnimation;
