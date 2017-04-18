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

#import <Foundation/NSNull.h>
#import <CFFoundationInternal.h>

@implementation NSNull
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-objc-isa-usage"
+ (void)load {
    _CFRuntimeBridgeTypeToClass(CFNullGetTypeID(), self);

    // We have to do this for Objective-C dispatch, but we can't rely on type ID bridging to set it for us
    // because kCFNull already exists.
    static_cast<NSNull*>(kCFNull)->isa = self;
}
#pragma clang diagnostic pop

/**
 @Status Interoperable
*/
+ (instancetype)allocWithZone:(NSZone*)zone {
    return static_cast<NSNull*>(kCFNull);
}

/**
 @Status Interoperable
*/
+ (NSNull*)null {
    return static_cast<NSNull*>(kCFNull);
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    return self;
}

/**
 @Status Interoperable
 @Notes This method encodes nothing as there's nothing to encode.
 */
- (void)encodeWithCoder:(NSCoder*)coder {
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return static_cast<NSNull*>(kCFNull);
}

/**
 @Status Interoperable
*/
- (instancetype)retain {
    return self;
}

/**
 @Status Interoperable
*/
- (oneway void)release {
}

- (NSUInteger)retainCount {
    return NSUIntegerMax;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
/**
 @Status Interoperable
*/
- (void)dealloc {
    // This method was found to be a no-op on the reference platform.
}
#pragma clang diagnostic pop

/**
 @Status Interoperable
*/
- (NSString*)description {
    return @"<null>";
}

- (id)valueForKey:(NSString*)key {
    return self;
}

- (id)valueForKeyPath:(NSString*)keypath {
    return self;
}

- (CFTypeID)_cfTypeId {
    return CFNullGetTypeID();
}
@end
