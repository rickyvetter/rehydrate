type edgeInset = {top: int, left: int, bottom: int, right: int};

type color =
  | RGB int int int
  | RGBA int int int float
  | HSL int float float
  | HSLA int float float float
  | Keyword string
  | HEX int;

type ellipsizeMode =
  | Head
  | Middle
  | Tail
  | Clip;

type numberOfLines = int;

type textBreakStrategy =
  | Simple
  | HighQuality
  | Balanced;

module Text = {
  include ReactRe.Component;
  let name = "Text";
  type props = {
    children: string,
    ellipsizeMode,
    numberOfLines,
    textBreakStrategy,
    onLayout: ReactRe.event => unit,
    onPress: ReactRe.event => unit,
    onLongPress: ReactRe.event => unit,
    pressRetentionOffset: edgeInset,
    selectable: bool,
    selectionColor: color,
    suppressHighlighting: bool,
    style: Props.textStyleProps,
    testID: string,
    allowFontScaling: bool,
    accessible: bool,
    adjustsFontSizeToFit: bool,
    minimumFontScale: float
  };
  let render {props} => <span> (ReactRe.stringToElement props.children) </span>;
};

include ReactRe.CreateComponent Text;

let createElement
    ::ellipsizeMode
    ::numberOfLines
    ::textBreakStrategy
    ::onLayout
    ::onPress
    ::onLongPress
    ::pressRetentionOffset
    ::selectable
    ::selectionColor
    ::suppressHighlighting
    ::style
    ::testID
    ::allowFontScaling
    ::accessible
    ::adjustsFontSizeToFit
    ::minimumFontScale
    ::children =>
  wrapProps {
    ellipsizeMode,
    numberOfLines,
    textBreakStrategy,
    onLayout,
    onPress,
    onLongPress,
    pressRetentionOffset,
    selectable,
    selectionColor,
    suppressHighlighting,
    style,
    testID,
    allowFontScaling,
    accessible,
    adjustsFontSizeToFit,
    minimumFontScale,
    children
  };
