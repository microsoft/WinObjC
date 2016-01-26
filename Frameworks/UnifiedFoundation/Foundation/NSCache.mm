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
#import <Foundation/NSCache.h>

@implementation NSCache
/**
 @Status Stub
 @Notes
*/
- (id)objectForKey:(id)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setObject:(id)obj forKey:(id)key {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setObject:(id)obj forKey:(id)key cost:(NSUInteger)num {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectForKey:(id)key {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllObjects {
    UNIMPLEMENTED();
}

@end
