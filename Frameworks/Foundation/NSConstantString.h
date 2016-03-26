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
#pragma once
#import <Foundation/NSString.h>
#import "NSStringAdditionsForCF.h"

@interface NSConstantString : NSString <NSStringAdditionsForCF> {
    // NOTE: these two ivars *must* be present to match the compiler expected
    // layout for constant strings.
    char* c_string;
    unsigned int len;
}

- (instancetype)retain;
- (void)release;
- (instancetype)autorelease;
- (void)dealloc;

// NSString overrides
@property (readonly) NSUInteger length;
- (unichar)characterAtIndex:(NSUInteger)index;

// Private function for CF
- (const char*)_fastCStringContents:(CFStringEncoding)encoding;
- (const UniChar*)_fastCharacterContents;
- (Boolean)_encodingCantBeStoredInEightBitCFString;

@end
