module Store: {
  type t 'action 'state;
  let create: ('state => 'action => 'state) => 'state => t 'action 'state;
  let subscribe: t 'action 'state => (unit => unit) => unit;
  let dispatch: t 'action 'state => 'action => unit;
  let getState: t 'action 'state => 'state;
  let replaceReducer: t 'action 'state => ('state => 'action => 'state) => unit;
};

let compose:
  _ => unit

    [@@ocaml.deprecated
      {|
Use the |> as an infix operator to chain the
result of one function into another:

`compose(f, g, h)(x)`
in JS goes to
`x |> h |> g |> f`
in Reason.
|}
    ];


let combineReducers:
  _ => unit

    [@@ocaml.deprecated
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


let bindActionCreators:
  list 'action => ('action => unit) => list (unit => unit)

    [@@ocaml.deprecated
      {|
bindActionCreators is not as useful in Reason,
since action creators are types, not functions.
The code is implemented as:

let bindActionCreators actions dispatch =>
  List.map (fun action () => dispatch action) actions;

Instead - you are free to build the action data type at dispatch time.
|}
    ];
