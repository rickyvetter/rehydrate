type edgeInset = {top: float, left: float, bottom: float, right: float};

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

type fontStyle =
  | Normal
  | Italic;

type fontWeight =
  | Normal
  | Bold
  | One
  | Two
  | Three
  | Four
  | Five
  | Six
  | Seven
  | Eight
  | Nine;

type fontVariant =
  | SmallCaps
  | OldstyleNums
  | LiningNums
  | TabularNums
  | ProportionalNums;

type textAlign =
  | Auto
  | Left
  | Right
  | Center
  | Justify;

type textDecorationLine =
  | None
  | Underline
  | LineThrough
  | UnderlineLineThrough;

type textAlignVertical =
  | Auto
  | Left
  | Right
  | Center;

type textDecorationStyle =
  | Solid
  | Double
  | Dotted
  | Dashed;

type writingDirection =
  | Auto
  | LTR
  | RTL;

type offset = {width: float, height: float};

type textStyleProps = {
  color,
  fontFamily: string,
  fontSize: float,
  fontStyle,
  fontWeight,
  fontVariant,
  textShadowOffset: offset,
  textShadowRadius: float,
  textShadowColor: color,
  /**
   * @platform ios
   */
  letterSpacing: float,
  lineHeight: float,
  /**
   * Specifies text alignment. The value 'justify' is only supported on iOS and
   * fallbacks to `left` on Android.
   */
  textAlign,
  textAlignVertical,
  textDecorationLine,
  textDecorationStyle,
  textDecorationColor: color,
  writingDirection
};
