let unsubscribe =
  Redux.Store.subscribe
    SimpleStore.store (fun () => Js.log (Redux.Store.getState SimpleStore.store));

let unsubscribe2 =
  Redux.Store.subscribe
    SimpleStore.store (fun () => Js.log "Redux.Store.getState SimpleStore.store");

let dispatch = Redux.Store.dispatch SimpleStore.store;

dispatch Increment;

dispatch Increment;

dispatch Decrement;

dispatch Increment;

Redux.Store.replaceReducer SimpleStore.store SimpleStore.doubleCounter;

/* this won't work because types are different :) */
/* Redux.Store.replaceReducer store notACounter; */
dispatch Increment;

unsubscribe ();

dispatch Increment;

dispatch Increment;

dispatch Increment;

dispatch Increment;

dispatch Increment;

dispatch Increment;

module Blah =
  Redux.MakeProvider {
    type state = ComplexStore.appState;
    type action = ComplexStore.appActions;
  };

ReactDOMRe.render
  <Blah store=ComplexStore.store component=DataRenderer.createElement /> (ReasonJs.Document.getElementById "index");

Redux.Store.subscribe
  ComplexStore.store (fun () => Js.log (Redux.Store.getState ComplexStore.store));

Redux.Store.dispatch ComplexStore.store (StringAction A);

Redux.Store.dispatch ComplexStore.store (StringAction B);

Redux.Store.dispatch ComplexStore.store (CounterAction Increment);
