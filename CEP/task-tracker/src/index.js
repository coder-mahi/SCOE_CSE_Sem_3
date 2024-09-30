import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import store from './store';
import store from './store/store'; 

ReactDOM.render(
  <React.StrictMode>
    <App store={store} />
  </React.StrictMode>,
  document.getElementById('root')
);