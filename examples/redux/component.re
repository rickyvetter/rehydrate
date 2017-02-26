type action =
  | Increment
  | Decrement;

type stringAction =
  | A
  | B;

let counter state action =>
  switch action {
  | Increment => state + 1
  | Decrement => state - 1
  };

let doubleCounter state action =>
  switch action {
  | Increment => state + 2
  | Decrement => state - 2
  };

let notACounter state action =>
  switch action {
  | Increment => state ^ "a"
  | Decrement => state ^ "b"
  };

let stringReduce state action =>
  switch action {
  | A => state ^ "a"
  | B => state ^ "b"
  };

type appActions =
  | StringAction stringAction
  | Action action;

type appState = {counter: int, notACounter: string};

let appReducter state action =>
  switch action {
  | StringAction action => {...state, notACounter: stringReduce state.notACounter action}
  | Action action => {...state, counter: counter state.counter action}
  };

/* let a = Redux.compose appReducter; */
let store = Redux.Store.create counter 0;

Redux.Store.subscribe store (fun () => Js.log (Redux.Store.getState store));

let dispatch = Redux.Store.dispatch store;

dispatch Increment;

dispatch Increment;

dispatch Decrement;

dispatch Increment;

Redux.Store.replaceReducer store doubleCounter;

/* this won't work because types are different :) */
/* Redux.Store.replaceReducer store notACounter; */
dispatch Increment;

dispatch Increment;

let store2 = Redux.Store.create appReducter {counter: 0, notACounter: ""};

Redux.Store.subscribe store2 (fun () => Js.log (Redux.Store.getState store2));

Redux.Store.dispatch store2 (StringAction A);
Redux.Store.dispatch store2 (StringAction B);
Redux.Store.dispatch store2 (Action Increment);
