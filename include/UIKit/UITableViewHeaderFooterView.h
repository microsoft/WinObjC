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

#ifndef _UITABLEVIEWHEADERFOOTERVIEW_H_
#define _UITABLEVIEWHEADERFOOTERVIEW_H_

@interface UITableViewHeaderFooterView : UIView

@property(nonatomic, retain) UIView *backgroundView;
@property(nonatomic, readonly, retain) UILabel *textLabel;
@property(nonatomic, readonly, retain) UIView *contentView;

- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier;

@end

#endif /* _UITABLEVIEWHEADERFOOTERVIEW_H_ */