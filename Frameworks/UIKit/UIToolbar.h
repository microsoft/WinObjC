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

@interface UIToolbar : UIView {
@public
}
- (id)sizeThatFits:(CGSize)curSize;
- (id)initWithCoder:(id)coder;
- (id)initWithFrame:(CGRect)frame;
- (id)setDelegate:(id)delegateAddr;
- (id)setBarStyle:(DWORD)style;
- (id)setButtonBarTrackingMode:(DWORD)mode;
- (id)viewWithTag:(DWORD)tag;
- (id)showSelectionForButton:(DWORD)button;
- (id)registerButtonGroup:(DWORD)group withButtons:(DWORD)withButtons withCount:(DWORD)withCount;
- (id)showButtonGroup:(DWORD)group withDuration:(DWORD)withDuration;
- (id)buttonClicked:(DWORD)button;
- (id)setItems:(id)items;
- (id)setTranslucent:(BOOL)translucent;
- (id)setTintColor:(id)color;
- (id)tintColor;
- (id)items;
- (id)setItems:(id)items animated:(BOOL)animated;
- (id)setFrame:(CGRect)frame;
- (id)dealloc;
- (id)setBackgroundImage:(id)image forToolbarPosition:(DWORD)position barMetrics:(DWORD)metrics;
- (id)setBarTintColor:(id)color;
@end
