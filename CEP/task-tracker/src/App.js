import React from 'react';
import { BrowserRouter, Route, Switch } from 'react-router-dom';
import Home from './Home';
import PostDetail from './PostDetail';

const App = () => {
  return (
    <BrowserRouter>
      <Switch>
        <Route path="/" exact component={Home} />
        <Route path="/post/:id" component={PostDetail} />
      </Switch>
    </BrowserRouter>
  );
};

export default App;