//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsUIText.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Text.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIText.h"
#include "WindowsUIText_priv.h"

@implementation WUTITextDocument

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::ITextDocument> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCaretType)caretType {
    ABI::Windows::UI::Text::CaretType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_CaretType(&unmarshalledReturn));
    return (WUTCaretType)unmarshalledReturn;
}

- (void)setCaretType:(WUTCaretType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->put_CaretType((ABI::Windows::UI::Text::CaretType)value));
}

- (float)defaultTabStop {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultTabStop(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDefaultTabStop:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultTabStop(value));
}

- (RTObject<WUTITextSelection>*)selection {
    ComPtr<ABI::Windows::UI::Text::ITextSelection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_Selection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextSelection>(unmarshalledReturn.Get());
}

- (unsigned int)undoLimit {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_UndoLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setUndoLimit:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->put_UndoLimit(value));
}

- (BOOL)canCopy {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CanCopy(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canPaste {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CanPaste(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canRedo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CanRedo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canUndo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CanUndo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)applyDisplayUpdates {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->ApplyDisplayUpdates(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)batchDisplayUpdates {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->BatchDisplayUpdates(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)beginUndoGroup {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->BeginUndoGroup());
}

- (void)endUndoGroup {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->EndUndoGroup());
}

- (RTObject<WUTITextCharacterFormat>*)getDefaultCharacterFormat {
    ComPtr<ABI::Windows::UI::Text::ITextCharacterFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->GetDefaultCharacterFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextCharacterFormat>(unmarshalledReturn.Get());
}

- (RTObject<WUTITextParagraphFormat>*)getDefaultParagraphFormat {
    ComPtr<ABI::Windows::UI::Text::ITextParagraphFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->GetDefaultParagraphFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextParagraphFormat>(unmarshalledReturn.Get());
}

- (RTObject<WUTITextRange>*)getRange:(int)startPosition endPosition:(int)endPosition {
    ComPtr<ABI::Windows::UI::Text::ITextRange> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->GetRange(startPosition, endPosition, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextRange>(unmarshalledReturn.Get());
}

- (RTObject<WUTITextRange>*)getRangeFromPoint:(WFPoint*)point options:(WUTPointOptions)options {
    ComPtr<ABI::Windows::UI::Text::ITextRange> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->GetRangeFromPoint(*[point internalStruct],
                                                   (ABI::Windows::UI::Text::PointOptions)options,
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextRange>(unmarshalledReturn.Get());
}

- (void)getText:(WUTTextGetOptions)options value:(NSString**)value {
    HSTRING valueOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->GetText((ABI::Windows::UI::Text::TextGetOptions)options, &valueOutUnmarshaled));
    *value = hstrToNSStr(valueOutUnmarshaled);
}

- (void)loadFromStream:(WUTTextSetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->LoadFromStream((ABI::Windows::UI::Text::TextSetOptions)options,
                                                _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (void)redo {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->Redo());
}

- (void)saveToStream:(WUTTextGetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->SaveToStream((ABI::Windows::UI::Text::TextGetOptions)options,
                                              _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (void)setDefaultCharacterFormat:(RTObject<WUTITextCharacterFormat>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->SetDefaultCharacterFormat(_getRtInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(value).Get()));
}

- (void)setDefaultParagraphFormat:(RTObject<WUTITextParagraphFormat>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->SetDefaultParagraphFormat(_getRtInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(value).Get()));
}

- (void)setText:(WUTTextSetOptions)options value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->SetText((ABI::Windows::UI::Text::TextSetOptions)options, nsStrToHstr(value).Get()));
}

- (void)undo {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextDocument>(self);
    THROW_NS_IF_FAILED(_comInst->Undo());
}

@end

@implementation WUTITextRange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::ITextRange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (wchar_t)character {
    wchar_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Character(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCharacter:(wchar_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_Character(value));
}

- (RTObject<WUTITextCharacterFormat>*)characterFormat {
    ComPtr<ABI::Windows::UI::Text::ITextCharacterFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharacterFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextCharacterFormat>(unmarshalledReturn.Get());
}

- (void)setCharacterFormat:(RTObject<WUTITextCharacterFormat>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharacterFormat(_getRtInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(value).Get()));
}

- (RTObject<WUTITextRange>*)formattedText {
    ComPtr<ABI::Windows::UI::Text::ITextRange> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormattedText(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextRange>(unmarshalledReturn.Get());
}

- (void)setFormattedText:(RTObject<WUTITextRange>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_FormattedText(_getRtInterface<ABI::Windows::UI::Text::ITextRange>(value).Get()));
}

- (int)endPosition {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setEndPosition:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_EndPosition(value));
}

- (WUTRangeGravity)gravity {
    ABI::Windows::UI::Text::RangeGravity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gravity(&unmarshalledReturn));
    return (WUTRangeGravity)unmarshalledReturn;
}

- (void)setGravity:(WUTRangeGravity)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gravity((ABI::Windows::UI::Text::RangeGravity)value));
}

- (int)length {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)link {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Link(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLink:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_Link(nsStrToHstr(value).Get()));
}

- (RTObject<WUTITextParagraphFormat>*)paragraphFormat {
    ComPtr<ABI::Windows::UI::Text::ITextParagraphFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParagraphFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextParagraphFormat>(unmarshalledReturn.Get());
}

- (void)setParagraphFormat:(RTObject<WUTITextParagraphFormat>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_ParagraphFormat(_getRtInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(value).Get()));
}

- (int)startPosition {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStartPosition:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartPosition(value));
}

- (int)storyLength {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_StoryLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (BOOL)canPaste:(int)format {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->CanPaste(format, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)changeCase:(WUTLetterCase)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->ChangeCase((ABI::Windows::UI::Text::LetterCase)value));
}

- (void)collapse:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Collapse((boolean)value));
}

- (void)Copy {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Copy());
}

- (void)cut {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Cut());
}

- (int)Delete:(WUTTextRangeUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Delete((ABI::Windows::UI::Text::TextRangeUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)endOf:(WUTTextRangeUnit)unit extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->EndOf((ABI::Windows::UI::Text::TextRangeUnit)unit, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)expand:(WUTTextRangeUnit)unit {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Expand((ABI::Windows::UI::Text::TextRangeUnit)unit, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)findText:(NSString*)value scanLength:(int)scanLength options:(WUTFindOptions)options {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindText(nsStrToHstr(value).Get(), scanLength, (ABI::Windows::UI::Text::FindOptions)options, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getCharacterUtf32:(unsigned int*)value offset:(int)offset {
    unsigned int valueOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetCharacterUtf32(&valueOutUnmarshaled, offset));
    *value = valueOutUnmarshaled;
}

- (RTObject<WUTITextRange>*)getClone {
    ComPtr<ABI::Windows::UI::Text::ITextRange> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetClone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextRange>(unmarshalledReturn.Get());
}

- (int)getIndex:(WUTTextRangeUnit)unit {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetIndex((ABI::Windows::UI::Text::TextRangeUnit)unit, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getPoint:(WUTHorizontalCharacterAlignment)horizontalAlign
    verticalAlign:(WUTVerticalCharacterAlignment)verticalAlign
          options:(WUTPointOptions)options
            point:(WFPoint**)point {
    ABI::Windows::Foundation::Point pointOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetPoint((ABI::Windows::UI::Text::HorizontalCharacterAlignment)horizontalAlign,
                                          (ABI::Windows::UI::Text::VerticalCharacterAlignment)verticalAlign,
                                          (ABI::Windows::UI::Text::PointOptions)options,
                                          &pointOutUnmarshaled));
    *point = WFPoint_create(pointOutUnmarshaled);
}

- (void)getRect:(WUTPointOptions)options rect:(WFRect**)rect hit:(int*)hit {
    ABI::Windows::Foundation::Rect rectOutUnmarshaled;
    int hitOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetRect((ABI::Windows::UI::Text::PointOptions)options, &rectOutUnmarshaled, &hitOutUnmarshaled));
    *rect = WFRect_create(rectOutUnmarshaled);
    *hit = hitOutUnmarshaled;
}

- (void)getText:(WUTTextGetOptions)options value:(NSString**)value {
    HSTRING valueOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetText((ABI::Windows::UI::Text::TextGetOptions)options, &valueOutUnmarshaled));
    *value = hstrToNSStr(valueOutUnmarshaled);
}

- (void)getTextViaStream:(WUTTextGetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetTextViaStream((ABI::Windows::UI::Text::TextGetOptions)options,
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (BOOL)inRange:(RTObject<WUTITextRange>*)range {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->InRange(_getRtInterface<ABI::Windows::UI::Text::ITextRange>(range).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)insertImage:(int)width
             height:(int)height
             ascent:(int)ascent
      verticalAlign:(WUTVerticalCharacterAlignment)verticalAlign
      alternateText:(NSString*)alternateText
              value:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->InsertImage(width,
                                             height,
                                             ascent,
                                             (ABI::Windows::UI::Text::VerticalCharacterAlignment)verticalAlign,
                                             nsStrToHstr(alternateText).Get(),
                                             _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (BOOL)inStory:(RTObject<WUTITextRange>*)range {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->InStory(_getRtInterface<ABI::Windows::UI::Text::ITextRange>(range).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)IsEqual:(RTObject<WUTITextRange>*)range {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->IsEqual(_getRtInterface<ABI::Windows::UI::Text::ITextRange>(range).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)move:(WUTTextRangeUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Move((ABI::Windows::UI::Text::TextRangeUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveEnd:(WUTTextRangeUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->MoveEnd((ABI::Windows::UI::Text::TextRangeUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveStart:(WUTTextRangeUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->MoveStart((ABI::Windows::UI::Text::TextRangeUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)paste:(int)format {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Paste(format));
}

- (void)scrollIntoView:(WUTPointOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView((ABI::Windows::UI::Text::PointOptions)value));
}

- (void)matchSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->MatchSelection());
}

- (void)setIndex:(WUTTextRangeUnit)unit index:(int)index extend:(BOOL)extend {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetIndex((ABI::Windows::UI::Text::TextRangeUnit)unit, index, (boolean)extend));
}

- (void)setPoint:(WFPoint*)point options:(WUTPointOptions)options extend:(BOOL)extend {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetPoint(*[point internalStruct], (ABI::Windows::UI::Text::PointOptions)options, (boolean)extend));
}

- (void)setRange:(int)startPosition endPosition:(int)endPosition {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetRange(startPosition, endPosition));
}

- (void)setText:(WUTTextSetOptions)options value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetText((ABI::Windows::UI::Text::TextSetOptions)options, nsStrToHstr(value).Get()));
}

- (void)setTextViaStream:(WUTTextSetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetTextViaStream((ABI::Windows::UI::Text::TextSetOptions)options,
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (int)startOf:(WUTTextRangeUnit)unit extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->StartOf((ABI::Windows::UI::Text::TextRangeUnit)unit, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUTITextSelection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::ITextSelection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTSelectionOptions)options {
    ABI::Windows::UI::Text::SelectionOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Options(&unmarshalledReturn));
    return (WUTSelectionOptions)unmarshalledReturn;
}

- (void)setOptions:(WUTSelectionOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Options((ABI::Windows::UI::Text::SelectionOptions)value));
}

- (WUTSelectionType)type {
    ABI::Windows::UI::Text::SelectionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUTSelectionType)unmarshalledReturn;
}

- (int)endKey:(WUTTextRangeUnit)unit extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->EndKey((ABI::Windows::UI::Text::TextRangeUnit)unit, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)homeKey:(WUTTextRangeUnit)unit extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->HomeKey((ABI::Windows::UI::Text::TextRangeUnit)unit, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveDown:(WUTTextRangeUnit)unit count:(int)count extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->MoveDown((ABI::Windows::UI::Text::TextRangeUnit)unit, count, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveLeft:(WUTTextRangeUnit)unit count:(int)count extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->MoveLeft((ABI::Windows::UI::Text::TextRangeUnit)unit, count, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveRight:(WUTTextRangeUnit)unit count:(int)count extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->MoveRight((ABI::Windows::UI::Text::TextRangeUnit)unit, count, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveUp:(WUTTextRangeUnit)unit count:(int)count extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->MoveUp((ABI::Windows::UI::Text::TextRangeUnit)unit, count, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)typeText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextSelection>(self);
    THROW_NS_IF_FAILED(_comInst->TypeText(nsStrToHstr(value).Get()));
}

- (wchar_t)character {
    wchar_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Character(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCharacter:(wchar_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_Character(value));
}

- (RTObject<WUTITextCharacterFormat>*)characterFormat {
    ComPtr<ABI::Windows::UI::Text::ITextCharacterFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharacterFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextCharacterFormat>(unmarshalledReturn.Get());
}

- (void)setCharacterFormat:(RTObject<WUTITextCharacterFormat>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharacterFormat(_getRtInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(value).Get()));
}

- (RTObject<WUTITextRange>*)formattedText {
    ComPtr<ABI::Windows::UI::Text::ITextRange> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormattedText(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextRange>(unmarshalledReturn.Get());
}

- (void)setFormattedText:(RTObject<WUTITextRange>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_FormattedText(_getRtInterface<ABI::Windows::UI::Text::ITextRange>(value).Get()));
}

- (int)endPosition {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setEndPosition:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_EndPosition(value));
}

- (WUTRangeGravity)gravity {
    ABI::Windows::UI::Text::RangeGravity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gravity(&unmarshalledReturn));
    return (WUTRangeGravity)unmarshalledReturn;
}

- (void)setGravity:(WUTRangeGravity)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gravity((ABI::Windows::UI::Text::RangeGravity)value));
}

- (int)length {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)link {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Link(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLink:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_Link(nsStrToHstr(value).Get()));
}

- (RTObject<WUTITextParagraphFormat>*)paragraphFormat {
    ComPtr<ABI::Windows::UI::Text::ITextParagraphFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParagraphFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextParagraphFormat>(unmarshalledReturn.Get());
}

- (void)setParagraphFormat:(RTObject<WUTITextParagraphFormat>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_ParagraphFormat(_getRtInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(value).Get()));
}

- (int)startPosition {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStartPosition:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartPosition(value));
}

- (int)storyLength {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_StoryLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (BOOL)canPaste:(int)format {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->CanPaste(format, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)changeCase:(WUTLetterCase)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->ChangeCase((ABI::Windows::UI::Text::LetterCase)value));
}

- (void)collapse:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Collapse((boolean)value));
}

- (void)Copy {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Copy());
}

- (void)cut {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Cut());
}

- (int)Delete:(WUTTextRangeUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Delete((ABI::Windows::UI::Text::TextRangeUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)endOf:(WUTTextRangeUnit)unit extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->EndOf((ABI::Windows::UI::Text::TextRangeUnit)unit, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)expand:(WUTTextRangeUnit)unit {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Expand((ABI::Windows::UI::Text::TextRangeUnit)unit, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)findText:(NSString*)value scanLength:(int)scanLength options:(WUTFindOptions)options {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindText(nsStrToHstr(value).Get(), scanLength, (ABI::Windows::UI::Text::FindOptions)options, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getCharacterUtf32:(unsigned int*)value offset:(int)offset {
    unsigned int valueOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetCharacterUtf32(&valueOutUnmarshaled, offset));
    *value = valueOutUnmarshaled;
}

- (RTObject<WUTITextRange>*)getClone {
    ComPtr<ABI::Windows::UI::Text::ITextRange> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetClone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextRange>(unmarshalledReturn.Get());
}

- (int)getIndex:(WUTTextRangeUnit)unit {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetIndex((ABI::Windows::UI::Text::TextRangeUnit)unit, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getPoint:(WUTHorizontalCharacterAlignment)horizontalAlign
    verticalAlign:(WUTVerticalCharacterAlignment)verticalAlign
          options:(WUTPointOptions)options
            point:(WFPoint**)point {
    ABI::Windows::Foundation::Point pointOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetPoint((ABI::Windows::UI::Text::HorizontalCharacterAlignment)horizontalAlign,
                                          (ABI::Windows::UI::Text::VerticalCharacterAlignment)verticalAlign,
                                          (ABI::Windows::UI::Text::PointOptions)options,
                                          &pointOutUnmarshaled));
    *point = WFPoint_create(pointOutUnmarshaled);
}

- (void)getRect:(WUTPointOptions)options rect:(WFRect**)rect hit:(int*)hit {
    ABI::Windows::Foundation::Rect rectOutUnmarshaled;
    int hitOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetRect((ABI::Windows::UI::Text::PointOptions)options, &rectOutUnmarshaled, &hitOutUnmarshaled));
    *rect = WFRect_create(rectOutUnmarshaled);
    *hit = hitOutUnmarshaled;
}

- (void)getText:(WUTTextGetOptions)options value:(NSString**)value {
    HSTRING valueOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetText((ABI::Windows::UI::Text::TextGetOptions)options, &valueOutUnmarshaled));
    *value = hstrToNSStr(valueOutUnmarshaled);
}

- (void)getTextViaStream:(WUTTextGetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->GetTextViaStream((ABI::Windows::UI::Text::TextGetOptions)options,
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (BOOL)inRange:(RTObject<WUTITextRange>*)range {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->InRange(_getRtInterface<ABI::Windows::UI::Text::ITextRange>(range).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)insertImage:(int)width
             height:(int)height
             ascent:(int)ascent
      verticalAlign:(WUTVerticalCharacterAlignment)verticalAlign
      alternateText:(NSString*)alternateText
              value:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->InsertImage(width,
                                             height,
                                             ascent,
                                             (ABI::Windows::UI::Text::VerticalCharacterAlignment)verticalAlign,
                                             nsStrToHstr(alternateText).Get(),
                                             _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (BOOL)inStory:(RTObject<WUTITextRange>*)range {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->InStory(_getRtInterface<ABI::Windows::UI::Text::ITextRange>(range).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)IsEqual:(RTObject<WUTITextRange>*)range {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->IsEqual(_getRtInterface<ABI::Windows::UI::Text::ITextRange>(range).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)move:(WUTTextRangeUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Move((ABI::Windows::UI::Text::TextRangeUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveEnd:(WUTTextRangeUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->MoveEnd((ABI::Windows::UI::Text::TextRangeUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveStart:(WUTTextRangeUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->MoveStart((ABI::Windows::UI::Text::TextRangeUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)paste:(int)format {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->Paste(format));
}

- (void)scrollIntoView:(WUTPointOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView((ABI::Windows::UI::Text::PointOptions)value));
}

- (void)matchSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->MatchSelection());
}

- (void)setIndex:(WUTTextRangeUnit)unit index:(int)index extend:(BOOL)extend {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetIndex((ABI::Windows::UI::Text::TextRangeUnit)unit, index, (boolean)extend));
}

- (void)setPoint:(WFPoint*)point options:(WUTPointOptions)options extend:(BOOL)extend {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetPoint(*[point internalStruct], (ABI::Windows::UI::Text::PointOptions)options, (boolean)extend));
}

- (void)setRange:(int)startPosition endPosition:(int)endPosition {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetRange(startPosition, endPosition));
}

- (void)setText:(WUTTextSetOptions)options value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetText((ABI::Windows::UI::Text::TextSetOptions)options, nsStrToHstr(value).Get()));
}

- (void)setTextViaStream:(WUTTextSetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->SetTextViaStream((ABI::Windows::UI::Text::TextSetOptions)options,
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (int)startOf:(WUTTextRangeUnit)unit extend:(BOOL)extend {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextRange>(self);
    THROW_NS_IF_FAILED(_comInst->StartOf((ABI::Windows::UI::Text::TextRangeUnit)unit, (boolean)extend, &unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUTITextCharacterFormat

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::ITextCharacterFormat> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTFormatEffect)allCaps {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllCaps(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setAllCaps:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllCaps((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(*[value internalStruct]));
}

- (WUTFormatEffect)bold {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bold(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setBold:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bold((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUTFontStretch)fontStretch {
    ABI::Windows::UI::Text::FontStretch unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontStretch(&unmarshalledReturn));
    return (WUTFontStretch)unmarshalledReturn;
}

- (void)setFontStretch:(WUTFontStretch)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontStretch((ABI::Windows::UI::Text::FontStretch)value));
}

- (WUTFontStyle)fontStyle {
    ABI::Windows::UI::Text::FontStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontStyle(&unmarshalledReturn));
    return (WUTFontStyle)unmarshalledReturn;
}

- (void)setFontStyle:(WUTFontStyle)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontStyle((ABI::Windows::UI::Text::FontStyle)value));
}

- (WUColor*)foregroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setForegroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundColor(*[value internalStruct]));
}

- (WUTFormatEffect)hidden {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Hidden(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setHidden:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Hidden((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUTFormatEffect)italic {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Italic(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setItalic:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Italic((ABI::Windows::UI::Text::FormatEffect)value));
}

- (float)kerning {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kerning(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setKerning:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Kerning(value));
}

- (NSString*)languageTag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_LanguageTag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguageTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_LanguageTag(nsStrToHstr(value).Get()));
}

- (WUTLinkType)linkType {
    ABI::Windows::UI::Text::LinkType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinkType(&unmarshalledReturn));
    return (WUTLinkType)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (WUTFormatEffect)outline {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Outline(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setOutline:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Outline((ABI::Windows::UI::Text::FormatEffect)value));
}

- (float)position {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPosition:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(value));
}

- (WUTFormatEffect)protectedText {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectedText(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setProtectedText:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProtectedText((ABI::Windows::UI::Text::FormatEffect)value));
}

- (float)size {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSize:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Size(value));
}

- (WUTFormatEffect)smallCaps {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmallCaps(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setSmallCaps:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmallCaps((ABI::Windows::UI::Text::FormatEffect)value));
}

- (float)spacing {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Spacing(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpacing:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Spacing(value));
}

- (WUTFormatEffect)strikethrough {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Strikethrough(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setStrikethrough:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Strikethrough((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUTFormatEffect)subscript {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subscript(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setSubscript:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subscript((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUTFormatEffect)superscript {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Superscript(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setSuperscript:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Superscript((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUTTextScript)textScript {
    ABI::Windows::UI::Text::TextScript unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextScript(&unmarshalledReturn));
    return (WUTTextScript)unmarshalledReturn;
}

- (void)setTextScript:(WUTTextScript)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextScript((ABI::Windows::UI::Text::TextScript)value));
}

- (WUTUnderlineType)underline {
    ABI::Windows::UI::Text::UnderlineType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Underline(&unmarshalledReturn));
    return (WUTUnderlineType)unmarshalledReturn;
}

- (void)setUnderline:(WUTUnderlineType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Underline((ABI::Windows::UI::Text::UnderlineType)value));
}

- (int)weight {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Weight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setWeight:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Weight(value));
}

- (void)setClone:(RTObject<WUTITextCharacterFormat>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->SetClone(_getRtInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(value).Get()));
}

- (RTObject<WUTITextCharacterFormat>*)getClone {
    ComPtr<ABI::Windows::UI::Text::ITextCharacterFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->GetClone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextCharacterFormat>(unmarshalledReturn.Get());
}

- (BOOL)IsEqual:(RTObject<WUTITextCharacterFormat>*)format {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(self);
    THROW_NS_IF_FAILED(_comInst->IsEqual(_getRtInterface<ABI::Windows::UI::Text::ITextCharacterFormat>(format).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUTITextParagraphFormat

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::ITextParagraphFormat> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTParagraphAlignment)alignment {
    ABI::Windows::UI::Text::ParagraphAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Alignment(&unmarshalledReturn));
    return (WUTParagraphAlignment)unmarshalledReturn;
}

- (void)setAlignment:(WUTParagraphAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Alignment((ABI::Windows::UI::Text::ParagraphAlignment)value));
}

- (float)firstLineIndent {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstLineIndent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUTFormatEffect)keepTogether {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeepTogether(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setKeepTogether:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeepTogether((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUTFormatEffect)keepWithNext {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeepWithNext(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setKeepWithNext:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeepWithNext((ABI::Windows::UI::Text::FormatEffect)value));
}

- (float)leftIndent {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_LeftIndent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)lineSpacing {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineSpacing(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUTLineSpacingRule)lineSpacingRule {
    ABI::Windows::UI::Text::LineSpacingRule unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineSpacingRule(&unmarshalledReturn));
    return (WUTLineSpacingRule)unmarshalledReturn;
}

- (WUTMarkerAlignment)listAlignment {
    ABI::Windows::UI::Text::MarkerAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListAlignment(&unmarshalledReturn));
    return (WUTMarkerAlignment)unmarshalledReturn;
}

- (void)setListAlignment:(WUTMarkerAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListAlignment((ABI::Windows::UI::Text::MarkerAlignment)value));
}

- (int)listLevelIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListLevelIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setListLevelIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListLevelIndex(value));
}

- (int)listStart {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListStart(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setListStart:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListStart(value));
}

- (WUTMarkerStyle)listStyle {
    ABI::Windows::UI::Text::MarkerStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListStyle(&unmarshalledReturn));
    return (WUTMarkerStyle)unmarshalledReturn;
}

- (void)setListStyle:(WUTMarkerStyle)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListStyle((ABI::Windows::UI::Text::MarkerStyle)value));
}

- (float)listTab {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListTab(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setListTab:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListTab(value));
}

- (WUTMarkerType)listType {
    ABI::Windows::UI::Text::MarkerType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListType(&unmarshalledReturn));
    return (WUTMarkerType)unmarshalledReturn;
}

- (void)setListType:(WUTMarkerType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListType((ABI::Windows::UI::Text::MarkerType)value));
}

- (WUTFormatEffect)noLineNumber {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_NoLineNumber(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setNoLineNumber:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_NoLineNumber((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUTFormatEffect)pageBreakBefore {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageBreakBefore(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setPageBreakBefore:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_PageBreakBefore((ABI::Windows::UI::Text::FormatEffect)value));
}

- (float)rightIndent {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_RightIndent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRightIndent:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_RightIndent(value));
}

- (WUTFormatEffect)rightToLeft {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_RightToLeft(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setRightToLeft:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_RightToLeft((ABI::Windows::UI::Text::FormatEffect)value));
}

- (WUTParagraphStyle)style {
    ABI::Windows::UI::Text::ParagraphStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Style(&unmarshalledReturn));
    return (WUTParagraphStyle)unmarshalledReturn;
}

- (void)setStyle:(WUTParagraphStyle)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Style((ABI::Windows::UI::Text::ParagraphStyle)value));
}

- (float)spaceAfter {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpaceAfter(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpaceAfter:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpaceAfter(value));
}

- (float)spaceBefore {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpaceBefore(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpaceBefore:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpaceBefore(value));
}

- (WUTFormatEffect)widowControl {
    ABI::Windows::UI::Text::FormatEffect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_WidowControl(&unmarshalledReturn));
    return (WUTFormatEffect)unmarshalledReturn;
}

- (void)setWidowControl:(WUTFormatEffect)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->put_WidowControl((ABI::Windows::UI::Text::FormatEffect)value));
}

- (int)tabCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_TabCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)addTab:(float)position align:(WUTTabAlignment)align leader:(WUTTabLeader)leader {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->AddTab(position, (ABI::Windows::UI::Text::TabAlignment)align, (ABI::Windows::UI::Text::TabLeader)leader));
}

- (void)clearAllTabs {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAllTabs());
}

- (void)deleteTab:(float)position {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteTab(position));
}

- (RTObject<WUTITextParagraphFormat>*)getClone {
    ComPtr<ABI::Windows::UI::Text::ITextParagraphFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->GetClone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTITextParagraphFormat>(unmarshalledReturn.Get());
}

- (void)getTab:(int)index position:(float*)position align:(WUTTabAlignment*)align leader:(WUTTabLeader*)leader {
    float positionOutUnmarshaled;
    ABI::Windows::UI::Text::TabAlignment alignOutUnmarshaled;
    ABI::Windows::UI::Text::TabLeader leaderOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->GetTab(index, &positionOutUnmarshaled, &alignOutUnmarshaled, &leaderOutUnmarshaled));
    *position = positionOutUnmarshaled;
    *align = (WUTTabAlignment)alignOutUnmarshaled;
    *leader = (WUTTabLeader)leaderOutUnmarshaled;
}

- (BOOL)IsEqual:(RTObject<WUTITextParagraphFormat>*)format {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->IsEqual(_getRtInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(format).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setClone:(RTObject<WUTITextParagraphFormat>*)format {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->SetClone(_getRtInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(format).Get()));
}

- (void)setIndents:(float)start left:(float)left right:(float)right {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->SetIndents(start, left, right));
}

- (void)setLineSpacing:(WUTLineSpacingRule)rule spacing:(float)spacing {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::ITextParagraphFormat>(self);
    THROW_NS_IF_FAILED(_comInst->SetLineSpacing((ABI::Windows::UI::Text::LineSpacingRule)rule, spacing));
}

@end

@implementation WUTTextConstants

ComPtr<ABI::Windows::UI::Text::ITextConstantsStatics> WUTITextConstantsStatics_inst() {
    ComPtr<ABI::Windows::UI::Text::ITextConstantsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Text.TextConstants").Get(), &inst));
    return inst;
}

+ (WUColor*)autoColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUTITextConstantsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutoColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (int)minUnitCount {
    int unmarshalledReturn;
    auto _comInst = WUTITextConstantsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinUnitCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)maxUnitCount {
    int unmarshalledReturn;
    auto _comInst = WUTITextConstantsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxUnitCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (WUColor*)undefinedColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUTITextConstantsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UndefinedColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (float)undefinedFloatValue {
    float unmarshalledReturn;
    auto _comInst = WUTITextConstantsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UndefinedFloatValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)undefinedInt32Value {
    int unmarshalledReturn;
    auto _comInst = WUTITextConstantsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UndefinedInt32Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (WUTFontStretch)undefinedFontStretch {
    ABI::Windows::UI::Text::FontStretch unmarshalledReturn;
    auto _comInst = WUTITextConstantsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UndefinedFontStretch(&unmarshalledReturn));
    return (WUTFontStretch)unmarshalledReturn;
}

+ (WUTFontStyle)undefinedFontStyle {
    ABI::Windows::UI::Text::FontStyle unmarshalledReturn;
    auto _comInst = WUTITextConstantsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UndefinedFontStyle(&unmarshalledReturn));
    return (WUTFontStyle)unmarshalledReturn;
}

@end

@implementation WUTFontWeights

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::IFontWeights> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Text::IFontWeightsStatics> WUTIFontWeightsStatics_inst() {
    ComPtr<ABI::Windows::UI::Text::IFontWeightsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Text.FontWeights").Get(), &inst));
    return inst;
}

+ (WUTFontWeight*)black {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Black(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)bold {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bold(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)extraBlack {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExtraBlack(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)extraBold {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExtraBold(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)extraLight {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExtraLight(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)light {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Light(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)medium {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Medium(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)normal {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Normal(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)semiBold {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SemiBold(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)semiLight {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SemiLight(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

+ (WUTFontWeight*)thin {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = WUTIFontWeightsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Thin(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

@end

@implementation WUTFontWeight {
    ABI::Windows::UI::Text::FontWeight structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Text::FontWeight)s {
    WUTFontWeight* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Text::FontWeight*)internalStruct {
    return &structVal;
}
- (unsigned short)weight {
    return structVal.Weight;
}
- (void)setWeight:(unsigned short)val {
    structVal.Weight = val;
}
@end
