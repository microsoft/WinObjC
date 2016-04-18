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

#import <AVFoundation/AVFoundation.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

@implementation AVQueuePlayer
/**
@Status Stub
@Notes
*/
- (AVQueuePlayer*)initWithItems:(NSArray*)items {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (instancetype)queuePlayerWithItems:(NSArray*)items {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)advanceToNextItem {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)canInsertItem:(AVPlayerItem*)item afterItem:(AVPlayerItem*)afterItem {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)insertItem:(AVPlayerItem*)item afterItem:(AVPlayerItem*)afterItem {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)items {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)removeAllItems {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)removeItem:(AVPlayerItem*)item {
    UNIMPLEMENTED();
}

@end
