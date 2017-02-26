module Store = {
  type t 'action 'state = {
    mutable state: 'state,
    mutable reducer: 'state => 'action => 'state,
    mutable listeners: list (unit => unit)
  };
  let create reducer preloadedState => {state: preloadedState, listeners: [], reducer};
  let subscribe store listener => store.listeners = [listener, ...store.listeners];
  let dispatch store action => {
    store.state = store.reducer store.state action;
    List.iter (fun listener => listener ()) store.listeners
  };
  let getState store => store.state;
  let replaceReducer store reducer => store.reducer = reducer;
};

let compose _ => ();

let combineReducers _ => ();
