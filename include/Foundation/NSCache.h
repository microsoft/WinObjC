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

#import <Foundation/NSObject.h>

@protocol NSCacheDelegate <NSObject>
@end

@interface NSCache : NSObject

- (id<NSCacheDelegate>)delegate;
- (NSUInteger)countLimit;
- (NSUInteger)totalCostLimit;

- (void)setDelegate:(id<NSCacheDelegate>)del;
- (void)setCountLimit:(NSUInteger)lim;
- (void)setTotalCostLimit:(NSUInteger)lim;
- (void)setObject:(id)obj forKey:(id)key;
- (id)objectForKey:(id)key;
- (NSString*)name;
- (void)setName:(NSString*)cacheName;
- (void)setObject:(id)obj forKey:(id)key cost:(NSUInteger)num;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;

@end
