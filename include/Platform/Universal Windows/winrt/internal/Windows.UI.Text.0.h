// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Text {

struct FontWeight;

}

namespace Windows::UI::Text {

using FontWeight = ABI::Windows::UI::Text::FontWeight;

}

namespace ABI::Windows::UI::Text {

struct IFontWeights;
struct IFontWeightsStatics;
struct ITextCharacterFormat;
struct ITextConstantsStatics;
struct ITextDocument;
struct ITextParagraphFormat;
struct ITextRange;
struct ITextSelection;
struct FontWeights;

}

namespace Windows::UI::Text {

struct IFontWeights;
struct IFontWeightsStatics;
struct ITextCharacterFormat;
struct ITextConstantsStatics;
struct ITextDocument;
struct ITextParagraphFormat;
struct ITextRange;
struct ITextSelection;
struct FontWeights;
struct TextConstants;

}

namespace Windows::UI::Text {

template <typename T> struct impl_IFontWeights;
template <typename T> struct impl_IFontWeightsStatics;
template <typename T> struct impl_ITextCharacterFormat;
template <typename T> struct impl_ITextConstantsStatics;
template <typename T> struct impl_ITextDocument;
template <typename T> struct impl_ITextParagraphFormat;
template <typename T> struct impl_ITextRange;
template <typename T> struct impl_ITextSelection;

}

namespace Windows::UI::Text {

enum class CaretType
{
    Normal = 0,
    Null = 1,
};

enum class FindOptions : unsigned
{
    None = 0x0,
    Word = 0x2,
    Case = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(FindOptions)

enum class FontStretch
{
    Undefined = 0,
    UltraCondensed = 1,
    ExtraCondensed = 2,
    Condensed = 3,
    SemiCondensed = 4,
    Normal = 5,
    SemiExpanded = 6,
    Expanded = 7,
    ExtraExpanded = 8,
    UltraExpanded = 9,
};

enum class FontStyle
{
    Normal = 0,
    Oblique = 1,
    Italic = 2,
};

enum class FormatEffect
{
    Off = 0,
    On = 1,
    Toggle = 2,
    Undefined = 3,
};

enum class HorizontalCharacterAlignment
{
    Left = 0,
    Right = 1,
    Center = 2,
};

enum class LetterCase
{
    Lower = 0,
    Upper = 1,
};

enum class LineSpacingRule
{
    Undefined = 0,
    Single = 1,
    OneAndHalf = 2,
    Double = 3,
    AtLeast = 4,
    Exactly = 5,
    Multiple = 6,
    Percent = 7,
};

enum class LinkType
{
    Undefined = 0,
    NotALink = 1,
    ClientLink = 2,
    FriendlyLinkName = 3,
    FriendlyLinkAddress = 4,
    AutoLink = 5,
    AutoLinkEmail = 6,
    AutoLinkPhone = 7,
    AutoLinkPath = 8,
};

enum class MarkerAlignment
{
    Undefined = 0,
    Left = 1,
    Center = 2,
    Right = 3,
};

enum class MarkerStyle
{
    Undefined = 0,
    Parenthesis = 1,
    Parentheses = 2,
    Period = 3,
    Plain = 4,
    Minus = 5,
    NoNumber = 6,
};

enum class MarkerType
{
    Undefined = 0,
    None = 1,
    Bullet = 2,
    Arabic = 3,
    LowercaseEnglishLetter = 4,
    UppercaseEnglishLetter = 5,
    LowercaseRoman = 6,
    UppercaseRoman = 7,
    UnicodeSequence = 8,
    CircledNumber = 9,
    BlackCircleWingding = 10,
    WhiteCircleWingding = 11,
    ArabicWide = 12,
    SimplifiedChinese = 13,
    TraditionalChinese = 14,
    JapanSimplifiedChinese = 15,
    JapanKorea = 16,
    ArabicDictionary = 17,
    ArabicAbjad = 18,
    Hebrew = 19,
    ThaiAlphabetic = 20,
    ThaiNumeric = 21,
    DevanagariVowel = 22,
    DevanagariConsonant = 23,
    DevanagariNumeric = 24,
};

enum class ParagraphAlignment
{
    Undefined = 0,
    Left = 1,
    Center = 2,
    Right = 3,
    Justify = 4,
};

enum class ParagraphStyle
{
    Undefined = 0,
    None = 1,
    Normal = 2,
    Heading1 = 3,
    Heading2 = 4,
    Heading3 = 5,
    Heading4 = 6,
    Heading5 = 7,
    Heading6 = 8,
    Heading7 = 9,
    Heading8 = 10,
    Heading9 = 11,
};

enum class PointOptions : unsigned
{
    None = 0x0,
    IncludeInset = 0x1,
    Start = 0x20,
    ClientCoordinates = 0x100,
    AllowOffClient = 0x200,
    Transform = 0x400,
    NoHorizontalScroll = 0x10000,
    NoVerticalScroll = 0x40000,
};

DEFINE_ENUM_FLAG_OPERATORS(PointOptions)

enum class RangeGravity
{
    UIBehavior = 0,
    Backward = 1,
    Forward = 2,
    Inward = 3,
    Outward = 4,
};

enum class SelectionOptions : unsigned
{
    StartActive = 0x1,
    AtEndOfLine = 0x2,
    Overtype = 0x4,
    Active = 0x8,
    Replace = 0x10,
};

DEFINE_ENUM_FLAG_OPERATORS(SelectionOptions)

enum class SelectionType
{
    None = 0,
    InsertionPoint = 1,
    Normal = 2,
    InlineShape = 7,
    Shape = 8,
};

enum class TabAlignment
{
    Left = 0,
    Center = 1,
    Right = 2,
    Decimal = 3,
    Bar = 4,
};

enum class TabLeader
{
    Spaces = 0,
    Dots = 1,
    Dashes = 2,
    Lines = 3,
    ThickLines = 4,
    Equals = 5,
};

enum class TextGetOptions : unsigned
{
    None = 0x0,
    AdjustCrlf = 0x1,
    UseCrlf = 0x2,
    UseObjectText = 0x4,
    AllowFinalEop = 0x8,
    NoHidden = 0x20,
    IncludeNumbering = 0x40,
    FormatRtf = 0x2000,
};

DEFINE_ENUM_FLAG_OPERATORS(TextGetOptions)

enum class TextRangeUnit
{
    Character = 0,
    Word = 1,
    Sentence = 2,
    Paragraph = 3,
    Line = 4,
    Story = 5,
    Screen = 6,
    Section = 7,
    Window = 8,
    CharacterFormat = 9,
    ParagraphFormat = 10,
    Object = 11,
    HardParagraph = 12,
    Cluster = 13,
    Bold = 14,
    Italic = 15,
    Underline = 16,
    Strikethrough = 17,
    ProtectedText = 18,
    Link = 19,
    SmallCaps = 20,
    AllCaps = 21,
    Hidden = 22,
    Outline = 23,
    Shadow = 24,
    Imprint = 25,
    Disabled = 26,
    Revised = 27,
    Subscript = 28,
    Superscript = 29,
    FontBound = 30,
    LinkProtected = 31,
};

enum class TextScript
{
    Undefined = 0,
    Ansi = 1,
    EastEurope = 2,
    Cyrillic = 3,
    Greek = 4,
    Turkish = 5,
    Hebrew = 6,
    Arabic = 7,
    Baltic = 8,
    Vietnamese = 9,
    Default = 10,
    Symbol = 11,
    Thai = 12,
    ShiftJis = 13,
    GB2312 = 14,
    Hangul = 15,
    Big5 = 16,
    PC437 = 17,
    Oem = 18,
    Mac = 19,
    Armenian = 20,
    Syriac = 21,
    Thaana = 22,
    Devanagari = 23,
    Bengali = 24,
    Gurmukhi = 25,
    Gujarati = 26,
    Oriya = 27,
    Tamil = 28,
    Telugu = 29,
    Kannada = 30,
    Malayalam = 31,
    Sinhala = 32,
    Lao = 33,
    Tibetan = 34,
    Myanmar = 35,
    Georgian = 36,
    Jamo = 37,
    Ethiopic = 38,
    Cherokee = 39,
    Aboriginal = 40,
    Ogham = 41,
    Runic = 42,
    Khmer = 43,
    Mongolian = 44,
    Braille = 45,
    Yi = 46,
    Limbu = 47,
    TaiLe = 48,
    NewTaiLue = 49,
    SylotiNagri = 50,
    Kharoshthi = 51,
    Kayahli = 52,
    UnicodeSymbol = 53,
    Emoji = 54,
    Glagolitic = 55,
    Lisu = 56,
    Vai = 57,
    NKo = 58,
    Osmanya = 59,
    PhagsPa = 60,
    Gothic = 61,
    Deseret = 62,
    Tifinagh = 63,
};

enum class TextSetOptions : unsigned
{
    None = 0x0,
    UnicodeBidi = 0x1,
    Unlink = 0x8,
    Unhide = 0x10,
    CheckTextLimit = 0x20,
    FormatRtf = 0x2000,
    ApplyRtfDocumentDefaults = 0x4000,
};

DEFINE_ENUM_FLAG_OPERATORS(TextSetOptions)

enum class UnderlineType
{
    Undefined = 0,
    None = 1,
    Single = 2,
    Words = 3,
    Double = 4,
    Dotted = 5,
    Dash = 6,
    DashDot = 7,
    DashDotDot = 8,
    Wave = 9,
    Thick = 10,
    Thin = 11,
    DoubleWave = 12,
    HeavyWave = 13,
    LongDash = 14,
    ThickDash = 15,
    ThickDashDot = 16,
    ThickDashDotDot = 17,
    ThickDotted = 18,
    ThickLongDash = 19,
};

enum class VerticalCharacterAlignment
{
    Top = 0,
    Baseline = 1,
    Bottom = 2,
};

}

}
