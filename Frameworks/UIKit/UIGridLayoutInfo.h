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

@interface UIGridLayoutInfo : NSObject {
@public
    BOOL _horizontal;
    float _dimension;
    idretain _rowAlignmentOptions;
    idretaintype(NSMutableArray) _sections;
    BOOL _isValid;
    CGSize _contentSize;
}
- (float)dimension;
- (BOOL)horizontal;
- (CGSize)contentSize;
/* annotate with type */ -(id)setHorizontal : (BOOL)horizontal;
/* annotate with type */ -(id)setDimension : (float)dimension;
/* annotate with type */ -(id)setRowAlignmentOptions : (id)options;
/* annotate with type */ -(id)init;
/* annotate with type */ -(id)sections;
/* annotate with type */ -(id)addSection;
/* annotate with type */ -(id)invalidate : (BOOL)arg;
/* annotate with type */ -(id)setContentSize : (CGSize)size;
@end
