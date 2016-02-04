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

#import <Contacts/CNContactFormatter.h>
#import <StubReturn.h>

@implementation CNContactFormatter
/**
 @Status Stub
 @Notes
*/
+ (NSAttributedString*)attributedStringFromContact:(CNContact*)contact
                                             style:(CNContactFormatterStyle)style
                                 defaultAttributes:(NSDictionary*)attributes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSString*)stringFromContact:(CNContact*)contact style:(CNContactFormatterStyle)style {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)stringFromContact:(CNContact*)contact {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSAttributedString*)attributedStringFromContact:(CNContact*)contact defaultAttributes:(NSDictionary*)attributes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSString*)delimiterForContact:(CNContact*)contact {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CNContactDisplayNameOrder)nameOrderForContact:(CNContact*)contact {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
