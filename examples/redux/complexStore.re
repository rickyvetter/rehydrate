open SimpleStore;

type stringAction =
  | A
  | B;

let stringReduce state action =>
  switch action {
  | A => state ^ "a"
  | B => state ^ "b"
  };

type appActions =
  | StringAction stringAction
  | CounterAction action;

type appState = {counter: int, notACounter: string};

let appReducter state action =>
  switch action {
  | StringAction action => {...state, notACounter: stringReduce state.notACounter action}
  | CounterAction action => {...state, counter: counter state.counter action}
  };

let logger store next action => {
  Js.log "will dispatch";
  Js.log action;
  let returnValue = next action;
  Js.log "state after dispatch";
  Js.log (Redux.Store.getState store);
  returnValue
};

/* let a = Redux.compose appReducter; */
let store =
  Redux.Store.create
    reducer::appReducter preloadedState::{counter: 0, notACounter: ""} enhancer::logger ();
