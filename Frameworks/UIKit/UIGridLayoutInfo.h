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
- (id)setHorizontal:(BOOL)horizontal;
- (id)setDimension:(float)dimension;
- (id)setRowAlignmentOptions:(id)options;
- (id)init;
- (id)sections;
- (id)addSection;
- (id)invalidate:(BOOL)arg;
- (id)setContentSize:(CGSize)size;
@end
