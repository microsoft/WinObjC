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

#import <Foundation/Foundation.h>

@implementation NSObject (NSCoding)
/**
 @Status Interoperable
*/
- (Class)classForCoder {
    return [self class];
}

/**
 @Status Interoperable
*/
- (id)replacementObjectForCoder:(NSCoder*)coder {
    return self;
}

/**
 @Status Interoperable
*/
- (id)awakeAfterUsingCoder:(NSCoder*)coder {
    return self;
}
@end

@implementation NSObject (NSArchiver)
/**
 @Status Interoperable
*/
- (Class)classForArchiver {
    return [self classForCoder];
}

/**
 @Status Interoperable
*/
- (id)replacementObjectForArchiver:(NSArchiver*)archiver {
    return [self replacementObjectForCoder:archiver];
}
@end

@implementation NSObject (NSKeyedArchiver)
/**
 @Status Interoperable
*/
- (Class)classForKeyedArchiver {
    return [self classForCoder];
}

/**
 @Status Interoperable
 @Notes During keyed unarchival, instances of the receiving class will be decoded as the returned class.
*/
+ (Class)classForKeyedUnarchiver {
    return self;
}

/**
 @Status Caveat
 @Notes The keyed archival implementation will ignore the provided fallback classes.
*/
+ (NSArray*)classFallbacksForKeyedArchiver {
    return nil;
}

/**
 @Status Interoperable
*/
- (id)replacementObjectForKeyedArchiver:(NSKeyedArchiver*)archiver {
    return [self replacementObjectForCoder:archiver];
}
@end

__attribute__((constructor)) static void _ForceTUInclusion() { }