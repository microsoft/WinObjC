//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import "UIKit/NSAttributedString+UIKitAdditions.h"
#import "UIKit/UIFont.h"
#import "UIKit/UIFontDescriptor.h"
#import "Starboard.h"
#import <libxml/HTMLparser.h>
#import <map>

NSString* const NSFontAttributeName = (NSString * const) @"NSFont";
NSString* const NSParagraphStyleAttributeName = (NSString * const) @"NSParagraphStyle";
NSString* const NSForegroundColorAttributeName = (NSString * const) @"NSForegroundColor";
NSString* const NSBackgroundColorAttributeName = (NSString * const) @"NSBackgroundColor";
NSString* const NSLigatureAttributeName = (NSString * const) @"NSLigature";
NSString* const NSKernAttributeName = (NSString * const) @"NSKern";
NSString* const NSStrikethroughStyleAttributeName = (NSString * const) @"NSStrikethroughStyle";
NSString* const NSUnderlineStyleAttributeName = (NSString * const) @"NSUnderline";
NSString* const NSStrokeColorAttributeName = (NSString * const) @"NSStrokeColor";
NSString* const NSStrokeWidthAttributeName = (NSString * const) @"NSStrokeWidth";
NSString* const NSShadowAttributeName = (NSString * const) @"NSShadow";
NSString* const NSTextEffectAttributeName = (NSString * const) @"NSTextEffect";
NSString* const NSAttachmentAttributeName = (NSString * const) @"NSAttachment";
NSString* const NSLinkAttributeName = (NSString * const) @"NSLink";
NSString* const NSBaselineOffsetAttributeName = (NSString * const) @"NSBaselineOffset";
NSString* const NSUnderlineColorAttributeName = (NSString * const) @"NSUnderlineColor";
NSString* const NSStrikethroughColorAttributeName = (NSString * const) @"NSStrikethroughColor";
NSString* const NSObliquenessAttributeName = (NSString * const) @"NSObliqueness";
NSString* const NSExpansionAttributeName = (NSString * const) @"NSExpansion";
NSString* const NSWritingDirectionAttributeName = (NSString * const) @"NSWritingDirection";
NSString* const NSVerticalGlyphFormAttributeName = (NSString * const) @"NSVerticalGlyphForm";

NSString* const NSPlainTextDocumentType = (NSString * const) @"NSPlainTextDocumentType";
NSString* const NSRTFTextDocumentType = (NSString * const) @"NSRTFTextDocumentType";
NSString* const NSRTFDTextDocumentType = (NSString * const) @"NSRTFDTextDocumentType";
NSString* const NSHTMLTextDocumentType = (NSString * const) @"NSHTMLTextDocumentType";

NSString* const NSDocumentTypeDocumentAttribute = (NSString * const) @"DocumentType";
NSString* const NSCharacterEncodingDocumentAttribute = (NSString * const) @"CharacterEncoding";
NSString* const NSDefaultAttributesDocumentAttribute = (NSString * const) @"DefaultAttributes";
NSString* const NSPaperSizeDocumentAttribute = (NSString * const) @"PaperSize";
NSString* const NSPaperMarginDocumentAttribute = (NSString * const) @"PaperMargin";
NSString* const NSViewSizeDocumentAttribute = (NSString * const) @"ViewSize";
NSString* const NSViewZoomDocumentAttribute = (NSString * const) @"ViewZoom";
NSString* const NSViewModeDocumentAttribute = (NSString * const) @"ViewMode";
NSString* const NSReadOnlyDocumentAttribute = (NSString * const) @"ReadOnly";
NSString* const NSBackgroundColorDocumentAttribute = (NSString * const) @"BackgroundColor";
NSString* const NSHyphenationFactorDocumentAttribute = (NSString * const) @"HypernationFactor";
NSString* const NSDefaultTabIntervalDocumentAttribute = (NSString * const) @"DefaultTabInterval";
NSString* const NSTextLayoutSectionsAttribute = (NSString * const) @"NSTextLayoutSectionsAttribute";

NSString* const NSTextLayoutSectionOrientation = (NSString * const) @"NSTextLayoutSectionOrientation";
NSString* const NSTextLayoutSectionRange = (NSString * const) @"NSTextLayoutSectionRange";

NSString* const NSTextEffectLetterpressStyle = (NSString * const) @"NSTextEffectLetterpressStyle";

static NSDictionary* _defaultAttributes() {
    // TODO 5237845: need to add paragraph style, etc, once there is support
    // Default attributes ought to look like the following:
    // {
    //     NSColor = "UIDeviceRGBColorSpace 0 0 0 1";
    //     NSFont = "<UICTFont: 0x7fac9bd853e0> font-family: \"Times New Roman\"; font-weight: normal; font-style: normal; font-size:
    //     12.00pt";
    //     NSKern = 0;
    //     NSParagraphStyle = "Alignment 4, LineSpacing 0, ParagraphSpacing 0, ParagraphSpacingBefore 0, HeadIndent 0, TailIndent 0,
    //     FirstLineHeadIndent 0, LineHeight 15/0, LineHeightMultiple 0, LineBreakMode 0, Tabs (\n), DefaultTabInterval 36, Blocks (\n),
    //     Lists (\n), BaseWritingDirection 0, HyphenationFactor 0, TighteningForTruncation NO, HeaderLevel 0";
    //     NSStrokeColor = "UIDeviceRGBColorSpace 0 0 0 1";
    //     NSStrokeWidth = 0;
    // }
    return @{ NSFontAttributeName : [UIFont defaultFont] };
}

static NSMutableDictionary* _handleFontTraits(NSMutableAttributedString* self,
                                              NSDictionary* attributes,
                                              UIFontDescriptorSymbolicTraits traits) {
    NSMutableDictionary* ret = [NSMutableDictionary dictionaryWithDictionary:attributes];
    UIFont* font = reinterpret_cast<UIFont*>([ret objectForKey:NSFontAttributeName]);
    if (!font) {
        font = [UIFont defaultFont];
    }
    UIFontDescriptor* fontDes = [font fontDescriptor];

    fontDes = [fontDes fontDescriptorWithSymbolicTraits:([fontDes symbolicTraits] | traits)];
    UIFont* newFont = [UIFont fontWithDescriptor:fontDes size:0];
    [ret setObject:newFont forKey:NSFontAttributeName];
    assert(![newFont isEqual:font]);
    return ret;
}

static NSMutableDictionary* _handleBold(NSMutableAttributedString* self, NSDictionary* attributes) {
    return _handleFontTraits(self, attributes, UIFontDescriptorTraitBold);
}

static NSMutableDictionary* _handleItalic(NSMutableAttributedString* self, NSDictionary* attributes) {
    return _handleFontTraits(self, attributes, UIFontDescriptorTraitItalic);
}

static NSMutableDictionary* _handleUnderline(NSMutableAttributedString* self, NSDictionary* attributes) {
    NSMutableDictionary* ret = [NSMutableDictionary dictionaryWithDictionary:attributes];
    [ret setObject:@(NSUnderlineStyleSingle) forKey:NSUnderlineStyleAttributeName];
    return ret;
}

static NSMutableDictionary* _handleBreak(NSMutableAttributedString* self, NSDictionary* attributes) {
    [self replaceCharactersInRange:{ [self length], 0 } withString:@"\r\n"];
    return nil;
}

static NSMutableDictionary* _doNothing(NSMutableAttributedString* self, NSDictionary* attributes) {
    // For tags with no corresponding Attribute
    return nil;
}

// Comparator for const char*
struct char_cmp {
    bool operator()(const char* a, const char* b) const {
        return strcmp(a, b) < 0;
    }
};

// Map of HTML tags to handling functions
// TODO: Add more handling functions as more UIKit features get implemented
static std::map<const char*, decltype(&_handleBold), char_cmp> _tagHandlers = { { "b", &_handleBold },      { "i", &_handleItalic },
                                                                                { "u", &_handleUnderline }, { "br", &_handleBreak },
                                                                                { "html", &_doNothing },    { "body", &_doNothing },
                                                                                { "!--", &_doNothing } };

// Does a depth-first recursive traversal through a subtree of an html xmlDoc,
// appending strings with attributes appropriately
static void _initForHtmlSubtree(NSMutableAttributedString* self, NSDictionary* parentAttributes, xmlNode* node) {
    for (xmlNode* curNode = node; curNode; curNode = curNode->next) {
        NSMutableDictionary* curAttributes = nil;

        if (curNode->type == XML_TEXT_NODE) {
            // If text, append to the string with the current set of attributes
            // Note that libxml uses UTF8 as its internal encoding, so the decode below ought to be safe
            NSAttributedString* appendString =
                [[NSAttributedString alloc] initWithString:[NSString stringWithUTF8String:reinterpret_cast<char*>(curNode->content)]
                                                attributes:parentAttributes];
            [self appendAttributedString:appendString];

        } else if (curNode->type == XML_ELEMENT_NODE) {
            // Otherwise, attempt to add an appropriate attribute to the current set
            const auto tagHandlerPair = _tagHandlers.find(reinterpret_cast<const char*>(curNode->name));
            if (tagHandlerPair != _tagHandlers.end()) {
                curAttributes = tagHandlerPair->second(self, parentAttributes);
            } else {
                UNIMPLEMENTED_WITH_MSG("NSAttributedString: unhandled html tag %s", reinterpret_cast<const char*>(curNode->name));
            }
        }

        // Recurse on children
        // Pass down additional attributes if there are any, otherwise just pass down the parent attributes
        if (curAttributes) {
            _initForHtmlSubtree(self, curAttributes, curNode->children);
        } else {
            _initForHtmlSubtree(self, parentAttributes, curNode->children);
        }
    }
}

static void _initWithHtml(NSMutableAttributedString* self, NSDictionary* attributes, NSString* htmlString, NSError** error) {
    const char* htmlCString = [htmlString UTF8String];

    xmlDoc* doc = htmlReadDoc(reinterpret_cast<const xmlChar*>(htmlCString),
                              nullptr,
                              nullptr,
                              HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (doc) {
        xmlNode* root = xmlDocGetRootElement(doc);
        [self beginEditing];
        _initForHtmlSubtree(self, attributes, root);
        [self endEditing];
        xmlFreeDoc(doc);

    } else if (error) {
        *error = [NSError errorWithDomain:@"libxml" code:100 userInfo:nil];
    }
}

@implementation NSAttributedString (NSAttributedStringUIKitAdditions)

/**
 @Status Caveat
 @Notes Only implemented for HTML and plaintext currently. NSDocumentType must be specified.
*/
- (NSAttributedString*)initWithData:(NSData*)data
                            options:(NSDictionary*)options
                 documentAttributes:(NSDictionary*)docAttrs // TODO: not sure what docAttrs is used for
                              error:(NSError**)error {
    if (!data) {
        return nil;
    }

    // Get NSCharacterEncoding from options, if it exists
    NSNumber* encodingNumber = [options objectForKey:NSCharacterEncodingDocumentAttribute];
    NSStringEncoding encoding = (encodingNumber) ? [encodingNumber intValue] : [NSString defaultCStringEncoding];
    // Decode the data
    NSString* stringData = [[NSString alloc] initWithData:data encoding:encoding];

    if (stringData) {
        [self init];

        // Get NSDefaultAttributes from options
        NSDictionary* defaultAttributes = [options objectForKey:NSDefaultAttributesDocumentAttribute];
        if (!defaultAttributes) {
            // Use internal default if none was specified
            defaultAttributes = _defaultAttributes();
        }

        // Switch based on NSDocumentType
        id documentType = [options objectForKey:NSDocumentTypeDocumentAttribute];
        if ([documentType isEqual:NSHTMLTextDocumentType]) {
            _initWithHtml(reinterpret_cast<NSMutableAttributedString*>(self), defaultAttributes, stringData, error);

        } else if ([documentType isEqual:NSRTFTextDocumentType]) {
            if (error) {
                *error = [NSError errorWithDomain:@"NSAttributedString" code:100 userInfo:nil];
                UNIMPLEMENTED_WITH_MSG("NSAttributedString: RTF is currently not supported");
            }

        } else if ([documentType isEqual:NSRTFDTextDocumentType]) {
            if (error) {
                *error = [NSError errorWithDomain:@"NSAttributedString" code:100 userInfo:nil];
                UNIMPLEMENTED_WITH_MSG("NSAttributedString: RTFD is currently not supported");
            }

        } else if ([documentType isEqual:NSPlainTextDocumentType]) {
            [self initWithString:stringData];

        } else {
            if (error) {
                *error = [NSError errorWithDomain:@"NSAttributedString" code:100 userInfo:nil];
                UNIMPLEMENTED_WITH_MSG(
                    "NSAttributedString: Auto detection of document type is currently not supported, please specify NSDocumentType in "
                    "options");
            }
        }

    } else if (error) {
        *error = [NSError errorWithDomain:@"NSAttributedString: Unable to decode data" code:100 userInfo:nil];
    }

    return self;
}

/**
 @Status Stub
*/
- (NSData*)dataFromRange:(NSRange)range documentAttributes:(NSDictionary*)dict error:(NSError**)error {
    UNIMPLEMENTED();
    return nil;
}

@end