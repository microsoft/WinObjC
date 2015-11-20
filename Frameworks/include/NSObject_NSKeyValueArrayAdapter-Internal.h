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

#include <Foundation/NSArray.h>

@class _NSMutableKeyProxyArray;

@interface _NSKeyProxyArray: NSArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
- (_NSMutableKeyProxyArray*)_mutableProxy;
@end

@interface _NSMutableKeyProxyArray: NSMutableArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
@end

struct objc_ivar* KVCIvarForPropertyName(NSObject* self, const char* propName);
SEL KVCGetterForPropertyName(NSObject* self, const char* key);
bool KVCGetViaAccessor(NSObject* self, SEL getter, id* ret);
bool KVCGetViaIvar(id self, struct objc_ivar* ivar, id* ret);
SEL KVCSetterForPropertyName(NSObject* self, const char* key);
bool KVCSetViaAccessor(NSObject* self, SEL setter, id value);
bool KVCSetViaIvar(NSObject* self, struct objc_ivar* ivar, id value);
