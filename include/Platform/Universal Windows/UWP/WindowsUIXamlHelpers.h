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

#import <UWP/InteropBase.h>
#import <UWP/WindowsUIXaml.h>

// Class names are appended with Obj to differentiate them from delegate names.

WINRT_EXPORT
@interface WUXDoubleTappedEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIDoubleTappedEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXHoldingEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIHoldingEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXKeyEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIKeyEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXManipulationCompletedEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIManipulationCompletedEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXManipulationDeltaEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIManipulationDeltaEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXManipulationInertiaStartingEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIManipulationInertiaStartingEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXManipulationStartedEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIManipulationStartedEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXManipulationStartingEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIManipulationStartingEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXPointerEventHandlerObj : RTObject
+ (instancetype)makeWith : (WUXIPointerEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXRightTappedEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXIRightTappedEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WUXTappedEventHandlerObj : RTObject
+ (instancetype)makeWith:(WUXITappedEventHandler)value ACTIVATOR;
@end

WINRT_EXPORT
@interface WXDragEventHandlerObj : RTObject
+ (instancetype)makeWith:(WXDragEventHandler)value ACTIVATOR;
@end
