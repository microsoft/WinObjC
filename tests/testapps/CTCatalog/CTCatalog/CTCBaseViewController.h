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
//*****************************************************************************

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

// Convenience macro to create and add rows for unimplemented methods to the table
#define ADD_UNIMPLEMENTED(ARRAY, METHOD_NAME, WIDTH) [ARRAY addObject:createTextCell(METHOD_NAME, @"UNIMPLEMENTED", WIDTH)]

// Creates a table cell with title and text value
UITableViewCell* createTextCell(NSString* title, NSString* value, CGFloat width);

@interface CTCBaseViewController : UIViewController

@end
