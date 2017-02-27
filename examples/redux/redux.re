module Store = {
  type t 'action 'state = {
    mutable state: 'state,
    mutable reducer: 'state => 'action => 'state,
    mutable listeners: list (unit => unit),
    customDispatcher: option (t 'action 'state => ('action => unit) => 'action => unit)
  };
  let create ::reducer ::preloadedState ::enhancer=? () =>
    switch (preloadedState, enhancer, reducer) {
    | (preloadedState, None, reducer) => {
        state: preloadedState,
        listeners: [],
        reducer,
        customDispatcher: None
      }
    | (preloadedState, Some enhancer, reducer) => {
        state: preloadedState,
        listeners: [],
        reducer,
        customDispatcher: Some enhancer
      }
    };
  let unsubscribe store listener () =>
    store.listeners = List.filter (fun l => listener !== l) store.listeners;
  let subscribe store listener => {
    store.listeners = [listener, ...store.listeners];
    unsubscribe store listener
  };
  let nativeDispatch store action => {
    store.state = store.reducer store.state action;
    List.iter (fun listener => listener ()) store.listeners
  };
  let dispatch store action =>
    switch store.customDispatcher {
    | Some customDispatcher => customDispatcher store (nativeDispatch store) action
    | None => nativeDispatch store action
    };
  let getState store => store.state;
  let replaceReducer store reducer => store.reducer = reducer;
};

module MakeProvider (SStore: {type state; type action;}) => {
  module Provider = {
    include ReactRe.Component.Stateful.InstanceVars;
    type props = {
      store: Store.t SStore.action SStore.state,
      component:
        state::SStore.state =>
        dispatch::(SStore.action => unit) =>
        children::list ReactRe.reactElement =>
        ref::(ReactRe.reactRef => unit)? =>
        key::string? =>
        unit =>
        ReactRe.reactElement
    };
    type state = option SStore.state;
    type instanceVars = {mutable unsubscribe: option (unit => unit)};
    let name = "Provider";
    let getInstanceVars _ => {unsubscribe: None};
    let getInitialState _ => None;
    let update {props} () => Some (Some (Store.getState props.store));
    let componentDidMount {props, instanceVars, updater} => {
      instanceVars.unsubscribe = Some (Store.subscribe props.store (updater update));
      None
    };
    let componentWillUnmount {instanceVars} =>
      switch instanceVars.unsubscribe {
      | Some unsubscribe => unsubscribe ()
      | None => ()
      };
    let dispatch {props} action => {
      Store.dispatch props.store action;
      None
    };
    let render {props, state, updater} =>
      switch state {
      | None => ReactRe.nullElement
      | Some state => props.component ::state dispatch::(updater dispatch) children::[] ()
      };
  };
  include ReactRe.CreateComponent Provider;
  let createElement ::store ::component => wrapProps {store, component};
};


/** These are all visible apis of Redux with explainations about how to achieve the same thing in Reason */
let compose _ =>
  ()
  [@ocaml.deprecated
    {|
Use the |> as an infix operator to chain the
result of one function into another:

`compose(f, g, h)(x)`
in JS goes to
`x |> h |> g |> f`
in Reason.
|}
  ];

let combineReducers _ =>
  ()
  [@ocaml.deprecated
    {|
combineReducers uses some introspection to determine
the shape of your state. Instead, consider a pattern like:

type counterAction =
| Increment
| Decrement;
type stringAction =
| A
| B;
type action =
| StringAction stringAction
| CounterAction counterAction;
type state = {string, counter};

let combinedReducer state action => {
| StringAction action => {...state, string: stringReducer state action}
| CounterAction action => {...state, counter: counterReducer state action}
};

this pattern gives you full control over the shape of your state.
|}
  ];

let applyMiddleware _ =>
  ()
  [@ocaml.deprecated
    {|
The enhancer attribute in Redux essentially allows you
to provide a custom dispatch method (to perform more
actions before or after the dispatch function). You can simply pass in
a function directly which handles the exact actions you're looking for.
|}
  ];

let bindActionCreators actions dispatch =>
  List.map
  (fun action () => dispatch action)
  actions
  [@ocaml.deprecated
    {|
bindActionCreators is not as useful in Reason,
since action creators are types, not functions.
The code is implemented as:

let bindActionCreators actions dispatch =>
List.map (fun action () => dispatch action) actions;

Instead - you are free to build the action data type at dispatch time.
|}
  ];
