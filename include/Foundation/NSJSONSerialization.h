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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

enum {
    NSJSONWritingPrettyPrinted = 1,
};
typedef uint32_t NSJSONWritingOptions;

enum {
    NSJSONReadingMutableContainers = 1,
    NSJSONReadingMutableLeaves = 2,
    NSJSONReadingAllowFragments = 4,
};
typedef uint32_t NSJSONReadingOptions;

@class NSData;
@class NSError;

FOUNDATION_EXPORT_CLASS
@interface NSJSONSerialization : NSObject

+ (NSData*)dataWithJSONObject:(id)obj options:(NSJSONWritingOptions)opt error:(NSError**)error;
+ (id)JSONObjectWithData:(NSData*)data options:(NSJSONReadingOptions)opt error:(NSError**)error;

@end