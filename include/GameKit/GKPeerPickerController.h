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

#ifndef _GKPEERPICKERCONTROLLER_H_
#define _GKPEERPICKERCONTROLLER_H_

#include <stdint.h>
#import <Foundation/NSObject.h>

enum {
    GKPeerPickerConnectionTypeOnline = 1,
    GKPeerPickerConnectionTypeNearby = 2
};
typedef uint32_t GKPeerPickerConnectionType;

@protocol GKPeerPickerControllerDelegate <NSObject>
@end

@interface GKPeerPickerController : NSObject

@property(nonatomic, assign) id<GKPeerPickerControllerDelegate> delegate;

- (void)dismiss;
- (void)show;

@property (nonatomic, assign) GKPeerPickerConnectionType connectionTypesMask;

@end

#endif // _GKPEERPICKERCONTROLLER_H_