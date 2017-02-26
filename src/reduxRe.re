/* type state;

type action;

type store = {
  getState: unit => state,
  dispatch: action => unit,
  subscribe: (unit => unit) => unit
};

let listeners = [];

let createStore reducer initialState => {
  let currentState = initialState;
  let getState () => currentState;
  let subscribe listener => {
    listeners = [listener, ...listeners];
    let unsubscribe () => List.filter (fun l => l === listener) listeners;
    unsubscribe
  };
  let dispatch action => {
    currentState = reducer (currentState, action);
    List.iter (fun listener => listener ())
  } {
    getState,
    dispatch,
    subscribe
  };
  ()
};
/*

 // getState, dispatch, subscribe

 function createStore(reducer, initialState) {



   // actions are just objects with a type field
   // { type: 'SHOW_MODAL' }
   function dispatch(action) {
     currentState = reducer(currentState, action)

     listeners.forEach(listener => {
       listener()
     });
   }

   return {
     getState,
     dispatch,
     subscribe,
   };
 } */ */
