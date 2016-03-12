//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <CoreMedia/CMTextMarkup.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

const CFStringRef kCMTextMarkupAttribute_ForegroundColorARGB = static_cast<CFStringRef>(@"CMForegroundColorARGB");
const CFStringRef kCMTextMarkupAttribute_BackgroundColorARGB = static_cast<CFStringRef>(@"CMBackgroundColorARGB");
const CFStringRef kCMTextMarkupAttribute_CharacterBackgroundColorARGB = static_cast<CFStringRef>(@"CMCharacterBackgroundColorARGB");
const CFStringRef kCMTextMarkupAttribute_BoldStyle = static_cast<CFStringRef>(@"CMBoldStyle");
const CFStringRef kCMTextMarkupAttribute_ItalicStyle = static_cast<CFStringRef>(@"CMItalicStyle");
const CFStringRef kCMTextMarkupAttribute_UnderlineStyle = static_cast<CFStringRef>(@"CMUnderlineStyle");
const CFStringRef kCMTextMarkupAttribute_FontFamilyName = static_cast<CFStringRef>(@"CMFontFamilyName");
const CFStringRef kCMTextMarkupAttribute_GenericFontFamilyName = static_cast<CFStringRef>(@"CMGenericFontFamilyName");
const CFStringRef kCMTextMarkupAttribute_BaseFontSizePercentageRelativeToVideoHeight =
    static_cast<CFStringRef>(@"CMBaseFontSizePercentage");
const CFStringRef kCMTextMarkupAttribute_RelativeFontSize = static_cast<CFStringRef>(@"CMRelativeFontSize");
const CFStringRef kCMTextMarkupAttribute_VerticalLayout = static_cast<CFStringRef>(@"CMVerticalLayout");
const CFStringRef kCMTextMarkupAttribute_Alignment = static_cast<CFStringRef>(@"CMWritingDirectionAlignment");
const CFStringRef kCMTextMarkupAttribute_TextPositionPercentageRelativeToWritingDirection =
    static_cast<CFStringRef>(@"CMWritingDirectionTextPositionPercentage");
const CFStringRef kCMTextMarkupAttribute_OrthogonalLinePositionPercentageRelativeToWritingDirection =
    static_cast<CFStringRef>(@"CMWritingDirectionOrthogonalLinePositionPercentage");
const CFStringRef kCMTextMarkupAttribute_WritingDirectionSizePercentage = static_cast<CFStringRef>(@"CMWritingDirectionSizePercentage");
const CFStringRef kCMTextMarkupAttribute_CharacterEdgeStyle = static_cast<CFStringRef>(@"CMCharacterEdgeStyle");
const CFStringRef kCMTextMarkupGenericFontName_Default = static_cast<CFStringRef>(@"CMGenericFontName_Default");
const CFStringRef kCMTextMarkupGenericFontName_Serif = static_cast<CFStringRef>(@"CMGenericFontName_Serif");
const CFStringRef kCMTextMarkupGenericFontName_SansSerif = static_cast<CFStringRef>(@"CMGenericFontName_SansSerif");
const CFStringRef kCMTextMarkupGenericFontName_Monospace = static_cast<CFStringRef>(@"CMGenericFontName_Monospace");
const CFStringRef kCMTextMarkupGenericFontName_ProportionalSerif = static_cast<CFStringRef>(@"CMGenericFontName_ProportionalSerif");
const CFStringRef kCMTextMarkupGenericFontName_ProportionalSansSerif = static_cast<CFStringRef>(@"CMGenericFontName_ProportionalSansSerif");
const CFStringRef kCMTextMarkupGenericFontName_MonospaceSerif = static_cast<CFStringRef>(@"CMGenericFontName_MonospaceSerif");
const CFStringRef kCMTextMarkupGenericFontName_MonospaceSansSerif = static_cast<CFStringRef>(@"CMGenericFontName_MonospaceSansSerif");
const CFStringRef kCMTextMarkupGenericFontName_Casual = static_cast<CFStringRef>(@"CMGenericFontName_Casual");
const CFStringRef kCMTextMarkupGenericFontName_Cursive = static_cast<CFStringRef>(@"CMGenericFontName_Cursive");
const CFStringRef kCMTextMarkupGenericFontName_Fantasy = static_cast<CFStringRef>(@"CMGenericFontName_Fantasy");
const CFStringRef kCMTextMarkupGenericFontName_SmallCapital = static_cast<CFStringRef>(@"CMGenericFontName_SmallCapital");
const CFStringRef kCMTextVerticalLayout_LeftToRight = static_cast<CFStringRef>(@"CMVerticalLayout_LeftToRight");
const CFStringRef kCMTextVerticalLayout_RightToLeft = static_cast<CFStringRef>(@"CMVerticalLayout_RightToLeft");
const CFStringRef kCMTextMarkupAlignmentType_Start = static_cast<CFStringRef>(@"CMWDA_start");
const CFStringRef kCMTextMarkupAlignmentType_Middle = static_cast<CFStringRef>(@"CMWDA_middle");
const CFStringRef kCMTextMarkupAlignmentType_End = static_cast<CFStringRef>(@"CMWDA_end");
const CFStringRef kCMTextMarkupAlignmentType_Left = static_cast<CFStringRef>(@"CMWDA_left");
const CFStringRef kCMTextMarkupAlignmentType_Right = static_cast<CFStringRef>(@"CMWDA_right");
const CFStringRef kCMTextMarkupCharacterEdgeStyle_None = static_cast<CFStringRef>(@"CMCharacterEdgeStyle_None");
const CFStringRef kCMTextMarkupCharacterEdgeStyle_Raised = static_cast<CFStringRef>(@"CMCharacterEdgeStyle_Raised");
const CFStringRef kCMTextMarkupCharacterEdgeStyle_Depressed = static_cast<CFStringRef>(@"CMCharacterEdgeStyle_Depressed");
const CFStringRef kCMTextMarkupCharacterEdgeStyle_Uniform = static_cast<CFStringRef>(@"CMCharacterEdgeStyle_Uniform");
const CFStringRef kCMTextMarkupCharacterEdgeStyle_DropShadow = static_cast<CFStringRef>(@"CMCharacterEdgeStyle_DropShadow");