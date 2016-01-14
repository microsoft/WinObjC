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

#include "Foundation/NSPropertyList.h"

@interface NSPropertyListSerialization : NSObject {
@public
}
+ (id)propertyListFromData:(NSData*)data
          mutabilityOption:(unsigned)mutability
                    format:(NSPropertyListFormat*)formatOut
          errorDescription:(NSString**)error;
+ (id)propertyListWithData:(NSData*)data options:(unsigned)options format:(NSPropertyListFormat*)formatOut error:(NSError**)error;
+ (NSData*)dataFromPropertyList:(id)plist format:(NSPropertyListFormat)format errorDescription:(NSString**)error;
@end
