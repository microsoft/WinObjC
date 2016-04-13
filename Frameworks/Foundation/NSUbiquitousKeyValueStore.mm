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

#import <StubReturn.h>
#import <Foundation/NSUbiquitousKeyValueStore.h>

FOUNDATION_EXPORT NSString* const NSUbiquitousKeyValueStoreChangeReasonKey = @"NSUbiquitousKeyValueStoreChangeReasonKey";
FOUNDATION_EXPORT NSString* const NSUbiquitousKeyValueStoreChangedKeysKey = @"NSUbiquitousKeyValueStoreChangedKeysKey";

@implementation NSUbiquitousKeyValueStore
/**
 @Status Stub
 @Notes
*/
+ (NSUbiquitousKeyValueStore*)defaultStore {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)arrayForKey:(NSString*)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)boolForKey:(NSString*)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSData*)dataForKey:(NSString*)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDictionary*)dictionaryForKey:(NSString*)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (double)doubleForKey:(NSString*)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (long long)longLongForKey:(NSString*)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)objectForKey:(NSString*)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)stringForKey:(NSString*)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setArray:(NSArray*)anArray forKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setBool:(BOOL)value forKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setData:(NSData*)aData forKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDictionary:(NSDictionary*)aDictionary forKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDouble:(double)value forKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setLongLong:(long long)value forKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setObject:(id)anObject forKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setString:(NSString*)aString forKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)synchronize {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectForKey:(NSString*)aKey {
    UNIMPLEMENTED();
}

@end
