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

#pragma once

#import <Foundation/Foundation.h>

// LifetimeCounting is a class that tracks its reference counting behaviour.
// It is intended to be used in reference counting tests. 
//
// Seeing as Clang with ARC on will refuse to emit -retain, -release,
// -dealloc, and -retainCount, the property accessors have to have rather silly names.
@interface LifetimeCounting : NSObject {
    unsigned arcSafeRetainCount;
    unsigned arcSafeReleaseCount;
}
- (unsigned)arcSafeRetainCount;
- (unsigned)arcSafeReleaseCount;
- (void)destroy /* ARC escape hatch */;
@end
