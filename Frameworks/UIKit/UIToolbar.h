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
/* annotate with type */ -(id)sizeThatFits : (CGSize)curSize;
/* annotate with type */ -(id)initWithCoder : (id)coder;
/* annotate with type */ -(id)initWithFrame : (CGRect)frame;
/* annotate with type */ -(id)setDelegate : (id)delegateAddr;
/* annotate with type */ -(id)setBarStyle : (DWORD)style;
/* annotate with type */ -(id)setButtonBarTrackingMode : (DWORD)mode;
/* annotate with type */ -(id)viewWithTag : (DWORD)tag;
/* annotate with type */ -(id)showSelectionForButton : (DWORD)button;
/* annotate with type */ -(id)registerButtonGroup : (DWORD)group withButtons : (DWORD)withButtons withCount : (DWORD)withCount;
/* annotate with type */ -(id)showButtonGroup : (DWORD)group withDuration : (DWORD)withDuration;
/* annotate with type */ -(id)buttonClicked : (DWORD)button;
/* annotate with type */ -(id)setItems : (id)items;
/* annotate with type */ -(id)setTranslucent : (BOOL)translucent;
/* annotate with type */ -(id)setTintColor : (id)color;
/* annotate with type */ -(id)tintColor;
/* annotate with type */ -(id)items;
/* annotate with type */ -(id)setItems : (id)items animated : (BOOL)animated;
/* annotate with type */ -(id)setFrame : (CGRect)frame;
/* annotate with type */ -(id)dealloc;
/* annotate with type */ -(id)setBackgroundImage : (id)image forToolbarPosition : (DWORD)position barMetrics : (DWORD)metrics;
/* annotate with type */ -(id)setBarTintColor : (id)color;
@end
