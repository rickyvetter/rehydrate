module DataRenderer = {
  include ReactRe.Component;
  type props = {state: ComplexStore.appState, dispatch: ComplexStore.appActions => unit};
  let name = "DataRenderer";
  let handleClick _ _ => {
    Js.log "clicked!";
    None
  };
  let render {props, updater} =>
    <div onClick=(updater handleClick)>
      <div> (ReactRe.stringToElement ("string: " ^ props.state.notACounter)) </div>
      <div> (ReactRe.stringToElement ("counter: " ^ string_of_int props.state.counter)) </div>
      <button onClick=(fun _ => props.dispatch (ComplexStore.CounterAction SimpleStore.Increment))>
        (ReactRe.stringToElement "Increment")
      </button>
      <button onClick=(fun _ => props.dispatch (ComplexStore.CounterAction SimpleStore.Decrement))>
        (ReactRe.stringToElement "Decrement")
      </button>
      <button onClick=(fun _ => props.dispatch (ComplexStore.StringAction ComplexStore.A))>
        (ReactRe.stringToElement "add a")
      </button>
    </div>;
};

include ReactRe.CreateComponent DataRenderer;

let createElement ::state ::dispatch => wrapProps {state, dispatch};
