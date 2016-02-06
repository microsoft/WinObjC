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

#import <UIKit/UIKit.h>
#import <StubReturn.h>

@implementation UITextChecker
/**
 @Status Stub
 @Notes
*/
- (NSRange)rangeOfMisspelledWordInString:(NSString*)stringToCheck
                                   range:(NSRange)range
                              startingAt:(NSInteger)startingOffset
                                    wrap:(BOOL)wrapFlag
                                language:(NSString*)language {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)guessesForWordRange:(NSRange)range inString:(NSString*)string language:(NSString*)language {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)completionsForPartialWordRange:(NSRange)range inString:(NSString*)string language:(NSString*)language {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)ignoreWord:(NSString*)wordToIgnore {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)ignoredWords {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setIgnoredWords:(NSArray*)words {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)learnWord:(NSString*)word {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)unlearnWord:(NSString*)word {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)hasLearnedWord:(NSString*)word {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)availableLanguages {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
