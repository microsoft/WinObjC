//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the Lesser General Public License.
// See ThirdPartyNotices.txt for more information.
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

#include <AutoLayout.h>
#include <UIKit/UILayoutGuide.h>
#include <NSLayoutConstraint+AutoLayout.h>
#include <UIView+AutoLayout.h>

#define CL_NO_IO
#define CL_NO_ID

#include <cassowary-0.60/ClSimplexSolver.h>
#include <cassowary-0.60/ClLinearEquation.h>

enum AutoLayoutDirection {
    Horizontal,
    Vertical,

    NumDirections
};

static ClSimplexSolver c_solver;

// Just to ensure linkage
extern "C" bool InitializeAutoLayout() {
    return true;
}

class AutoLayoutProperties {
public:
    AutoLayoutProperties()
        : _contentHuggingConstraint{ ClLinearInequality(ClLinearExpression()), ClLinearInequality(ClLinearExpression()) },
          _contentCompressionResistanceConstraint{ ClLinearInequality(ClLinearExpression()), ClLinearInequality(ClLinearExpression()) },
          _stays{ ClStayConstraint(_vars[Left], ClsStrong()),
                  ClStayConstraint(_vars[Right], ClsStrong()),
                  ClStayConstraint(_vars[Top], ClsStrong()),
                  ClStayConstraint(_vars[Bottom], ClsStrong()) } {
        _staysAdded = false;
        _associatedConstraints = [NSMutableArray new];
    }

    ~AutoLayoutProperties() {
        RemoveStays();
        for (int i = 0; i < NumDirections; i++) {
            if (_contentHuggingConstraint[i].FIsInSolver()) {
                c_solver.RemoveConstraint(&_contentHuggingConstraint[i]);
                c_solver.RemoveConstraint(&_contentCompressionResistanceConstraint[i]);
            }
        }
        [_associatedConstraints release];
        _associatedConstraints = nil;
    }

    void AddStays() {
        if (!_staysAdded) {
            _staysAdded = true;

            // In the paper all stays should be weak, but I don't think we're using them the same way.
            // If they're weak, they just end up getting pushed around by the edit vars.
            c_solver.AddConstraint(_stays[Left]);
            c_solver.AddConstraint(_stays[Right]);
            c_solver.AddConstraint(_stays[Top]);
            c_solver.AddConstraint(_stays[Bottom]);
        }
    }

    void RemoveStays() {
        if (_staysAdded) {
            _staysAdded = false;
            c_solver.RemoveConstraint(&_stays[Left]);
            c_solver.RemoveConstraint(&_stays[Right]);
            c_solver.RemoveConstraint(&_stays[Top]);
            c_solver.RemoveConstraint(&_stays[Bottom]);
        }
    }

    enum {
        Left,
        Right,
        Top,
        Bottom,
    };

    ClVariable _vars[4];
    ClStayConstraint _stays[4];
    bool _staysAdded;
    ClLinearInequality _contentHuggingConstraint[NumDirections];
    ClLinearInequality _contentCompressionResistanceConstraint[NumDirections];

    NSMutableArray* _associatedConstraints;
};

// Since categories can't have ivars, we bundle up a couple C++ classes in NSObjects and associate them to the UIView/UILayoutGuide/NSLayoutConstraint
@protocol _AutoLayoutProperties
@property (readonly) AutoLayoutProperties* _autoLayoutProperties;
@end

@interface _AutoLayoutStorage : NSObject {
@public
    AutoLayoutProperties _autoLayoutProperties;
}
@end

@implementation _AutoLayoutStorage
@end 

@interface _NSLayoutConstraintStorage : NSObject {
@public
    ClConstraint* _constraint;
}
@end

@implementation _NSLayoutConstraintStorage
@end 

@interface UIView (AutoLayoutProperties) <_AutoLayoutProperties>
@end

@interface UILayoutGuide (AutoLayoutProperties) <_AutoLayoutProperties>
@end

@implementation NSLayoutConstraint (AutoLayout)

- (_NSLayoutConstraintStorage*)_constraintStorage {
    return ((_NSLayoutConstraintStorage*)objc_getAssociatedObject(self, @selector(_constraintStorage)));
}

- (void)autoLayoutAlloc {
    objc_setAssociatedObject(self, @selector(_constraintStorage), [_NSLayoutConstraintStorage new], OBJC_ASSOCIATION_RETAIN);
}

- (void)autoLayoutConstraintAddedToView:(UIView*)view {
    assert(self.firstItem);

    _NSLayoutConstraintStorage* constraintStorage = [self _constraintStorage];

    if (!constraintStorage->_constraint) {
        // TODO: Care about reading direction.
        ClLinearExpression lex[2];
        UIView* items[] = { self.firstItem, self.secondItem };
        int attributes[] = { self.firstAttribute, self.secondAttribute };

        for (int n = 0; n < 2; n++) {
            UIView* item = items[n];
            int attribute = attributes[n];

            if (item == nil) {
                continue;
            }

            switch (attribute) {
                case NSLayoutAttributeBaseline:
                case NSLayoutAttributeFirstBaseline: // TODO, NSLayoutAttributeLastBaseline
                    item = [(UIView*)item viewForBaselineLayout];
                    break;
                default:
                    break;
            }

            auto layoutProps = item._autoLayoutProperties;

            switch (attribute) {
                case NSLayoutAttributeLeading:
                case NSLayoutAttributeLeft:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Left]);
                    break;
                case NSLayoutAttributeTrailing:
                case NSLayoutAttributeRight:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Right]);
                    break;
                case NSLayoutAttributeTop:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Top]);
                    break;
                case NSLayoutAttributeBottom:
                case NSLayoutAttributeBaseline:
                case NSLayoutAttributeFirstBaseline: // TODO, NSLayoutAttributeLastBaseline
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom]);
                    break;
                case NSLayoutAttributeWidth:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Right]) -
                             layoutProps->_vars[AutoLayoutProperties::Left];
                    break;
                case NSLayoutAttributeHeight:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom]) -
                             layoutProps->_vars[AutoLayoutProperties::Top];
                    break;
                case NSLayoutAttributeCenterX:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Right]) * 0.5 +
                             ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Left]) * 0.5;
                    break;
                case NSLayoutAttributeCenterY:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom]) * 0.5 +
                             ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Top]) * 0.5;
                    break;

                // TODO
                case NSLayoutAttributeLeadingMargin:
                case NSLayoutAttributeLeftMargin:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Left]);
                    break;
                case NSLayoutAttributeTrailingMargin:
                case NSLayoutAttributeRightMargin:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Right]);
                    break;
                case NSLayoutAttributeTopMargin:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Top]);
                    break;
                case NSLayoutAttributeBottomMargin:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom]);
                    break;
                case NSLayoutAttributeCenterXWithinMargins:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Right]) * 0.5 +
                             ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Left]) * 0.5;
                    break;
                case NSLayoutAttributeCenterYWithinMargins:
                    lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom]) * 0.5 +
                             ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Top]) * 0.5;
                    break;

                default:
                    assert(0);
                    break;
            }

            // This is to facilitate autoresizing masks. Whenever an auto-resizing happens due to a constraint changing a
            // frame, we need to poke the other views that may have been affected. This is in place until we actually
            // translate autoresize masks to constraints.
            [layoutProps->_associatedConstraints addObject:self];
        }

        if (self.secondItem == nil) {
            lex[1] = ClLinearExpression(self.constant);
        } else {
            lex[1] = lex[1].MultiplyMe(self.multiplier).Plus(self.constant);
        }

        const ClStrength* strength = &ClsWeak();

        // TODO: Changing priorities after installing: Read the docs on this one!
        if (self.priority == UILayoutPriorityRequired) {
            strength = &ClsMedium();
        }

        switch (self.relation) {
            case NSLayoutRelationEqual:
                constraintStorage->_constraint = new ClLinearEquation(lex[0], lex[1], *strength, self.priority);
                break;
            case NSLayoutRelationGreaterThanOrEqual:
                constraintStorage->_constraint = new ClLinearInequality(lex[0], cnGEQ, lex[1], *strength, self.priority);
                break;
            case NSLayoutRelationLessThanOrEqual:
                constraintStorage->_constraint = new ClLinearInequality(lex[0], cnLEQ, lex[1], *strength, self.priority);
                break;
            default:
                assert(0);
        }

        c_solver.AddConstraint(constraintStorage->_constraint);

    }
}

- (void)autoLayoutConstraintRemovedFromView {
    [self _removeFromSolver];
    AutoLayoutProperties* firstItemProps = ((id<_AutoLayoutProperties>)self.firstItem)._autoLayoutProperties;
    AutoLayoutProperties* secondItemProps = ((id<_AutoLayoutProperties>)self.secondItem)._autoLayoutProperties;

    if (self.firstItem != nil) {
        [firstItemProps->_associatedConstraints removeObject:self];
        if (![firstItemProps->_associatedConstraints count]) {
            firstItemProps->RemoveStays();
        }
    }
    if (self.secondItem != nil) {
        [secondItemProps->_associatedConstraints removeObject:self];
        if (![secondItemProps->_associatedConstraints count]) {
            secondItemProps->RemoveStays();
        }
    }
}

- (void)autoLayoutDealloc {
    [self _removeFromSolver];
}

- (void)_removeFromSolver {
    _NSLayoutConstraintStorage* constraintStorage = [self _constraintStorage];
    if (constraintStorage->_constraint) {
        if (constraintStorage->_constraint->FIsInSolver()) {
            c_solver.RemoveConstraint(constraintStorage->_constraint);
        }
        delete constraintStorage->_constraint;
        constraintStorage->_constraint = NULL;
    }
}
@end

@implementation UILayoutGuide (AutoLayout)

- (void)autoLayoutAlloc {
    objc_setAssociatedObject(self, @selector(_autoLayoutProperties), [_AutoLayoutStorage new], OBJC_ASSOCIATION_RETAIN);
}

- (CGRect)autoLayoutGetRect {
    AutoLayoutProperties* autoLayoutProperties = self._autoLayoutProperties;

    float left = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Left].Value();
    float top = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Top].Value();
    float right = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Right].Value();
    float bottom = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Bottom].Value();

    return CGRectMake(top, left, right - left, bottom - top);
}

- (AutoLayoutProperties*)_autoLayoutProperties {
    _AutoLayoutStorage* storage = (_AutoLayoutStorage*)objc_getAssociatedObject(self, @selector(_autoLayoutProperties));
    return &storage->_autoLayoutProperties;
}

- (void)autoLayoutDealloc {
}

@end

@implementation UIView (AutoLayout)

- (CGRect)autoLayoutGetRect {
    AutoLayoutProperties* autoLayoutProperties = self._autoLayoutProperties;

    float left = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Left].Value();
    float top = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Top].Value();
    float right = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Right].Value();
    float bottom = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Bottom].Value();

    return CGRectMake(top, left, right - left, bottom - top);
}

- (AutoLayoutProperties*)_autoLayoutProperties {
    _AutoLayoutStorage* storage = (_AutoLayoutStorage*)objc_getAssociatedObject(self, @selector(_autoLayoutProperties));
    return &storage->_autoLayoutProperties;
}

- (void)autoLayoutAlloc {
    objc_setAssociatedObject(self, @selector(_autoLayoutProperties), [_AutoLayoutStorage new], OBJC_ASSOCIATION_RETAIN);
}

- (void)autoLayoutSetFrameToView:(UIView*)toView fromView:(UIView*)fromView {
    CGRect newFrame;
    CGPoint newPointTL;
    CGPoint newPointBR;
    CGPoint oldPointTL;
    CGPoint oldPointBR;

    AutoLayoutProperties* autoLayoutProperties = self._autoLayoutProperties;

    oldPointTL.x = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Left].Value();
    oldPointTL.y = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Top].Value();
    oldPointBR.x = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Right].Value();
    oldPointBR.y = (float)autoLayoutProperties->_vars[AutoLayoutProperties::Bottom].Value();

    newPointTL = [toView convertPoint:oldPointTL fromView:fromView];
    newPointBR = [toView convertPoint:oldPointBR fromView:fromView];

    newFrame.size.width = newPointBR.x - newPointTL.x;
    newFrame.size.height = newPointBR.y - newPointTL.y;
    newFrame.origin.x = newPointTL.x;
    newFrame.origin.y = newPointTL.y;

    [self setFrame:newFrame];
}

- (void)autoLayoutLayoutSubviews {
    UIView* topView = [self autolayoutRoot];

    for (int i = 0; i < [self.subviews count]; i++) {
        UIView* child = (UIView*)[self.subviews objectAtIndex:i];
        AutoLayoutProperties* childProps = child._autoLayoutProperties;

        if ([childProps->_associatedConstraints count] && !child.translatesAutoresizingMaskIntoConstraints) {
            // Constraints that rely on autoresizing behaviour don't always follow a top-down layout order.
            // Baseline views can be autoresized, and are not always siblings to other constrained views.
            // We have to update them first, and this potentially can happen recursively. Ie, a view
            // constrained to a button's baseline, constrained to a segment's baseline, etc.
            // To facilitate this, we update frames for views we depend on (and thus their autosizing, and
            // constraints) before setting our own.
            // TODO: last baseline
            for (NSLayoutConstraint* constraint in childProps->_associatedConstraints) {
                UIView* item = (UIView*)constraint.firstItem;
                if (item != nil && item != self && constraint.firstAttribute == NSLayoutAttributeBaseline) {
                    [item autoLayoutSetFrameToView:self fromView:topView];
                }
                item = (UIView*)constraint.secondItem;
                if (item != nil && item != self && constraint.secondAttribute == NSLayoutAttributeBaseline) {
                    [item autoLayoutSetFrameToView:self fromView:topView];
                }
            }
            [child autoLayoutSetFrameToView:self fromView:topView];
        }
    }
}

- (void)autoLayoutInvalidateContentSize {
    AutoLayoutProperties* layoutProperties = self._autoLayoutProperties;
    CGSize contentSize = [self intrinsicContentSize];

    if (contentSize.width == -1.0f /*UIViewNoIntrinsicMetric*/ || contentSize.width == 0) {
        if (layoutProperties->_contentHuggingConstraint[Horizontal].FIsInSolver()) {
            c_solver.RemoveConstraint(&layoutProperties->_contentHuggingConstraint[Horizontal]);
            c_solver.RemoveConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Horizontal]);
        }
    } else {
        if (layoutProperties->_contentHuggingConstraint[Horizontal].FIsInSolver()) {
            if (contentSize.width != layoutProperties->_contentHuggingConstraint[Horizontal].Expression().Constant()) {
                // Changing constants on constraints while they're in a solver is ineffectual. Explicitly add/remove.
                c_solver.RemoveConstraint(&layoutProperties->_contentHuggingConstraint[Horizontal]);
                c_solver.RemoveConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Horizontal]);
                layoutProperties->_contentHuggingConstraint[Horizontal].ChangeConstant(contentSize.width);
                layoutProperties->_contentCompressionResistanceConstraint[Horizontal].ChangeConstant(contentSize.width);
                c_solver.AddConstraint(&layoutProperties->_contentHuggingConstraint[Horizontal]);
                c_solver.AddConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Horizontal]);
            }
            if ([self contentHuggingPriorityForAxis:UILayoutConstraintAxisHorizontal] != layoutProperties->_contentHuggingConstraint[Horizontal].weight()) {
                c_solver.ChangeWeight(&layoutProperties->_contentHuggingConstraint[Horizontal], [self contentHuggingPriorityForAxis:UILayoutConstraintAxisHorizontal]);
            }
            if ([self contentCompressionResistancePriorityForAxis:UILayoutConstraintAxisHorizontal] !=
                layoutProperties->_contentCompressionResistanceConstraint[Horizontal].weight()) {
                c_solver.ChangeWeight(&layoutProperties->_contentCompressionResistanceConstraint[Horizontal],
                                     [self contentCompressionResistancePriorityForAxis:UILayoutConstraintAxisHorizontal]);
            }
        }
        if (!layoutProperties->_contentHuggingConstraint[Horizontal].FIsInSolver()) {
            layoutProperties->_contentHuggingConstraint[Horizontal] =
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Right]) -
                                       layoutProperties->_vars[AutoLayoutProperties::Left],
                                   cnLEQ,
                                   contentSize.width,
                                   ClsWeak(),
                                   [self contentHuggingPriorityForAxis:UILayoutConstraintAxisHorizontal]);
            layoutProperties->_contentCompressionResistanceConstraint[Horizontal] =
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Right]) -
                                       layoutProperties->_vars[AutoLayoutProperties::Left],
                                   cnGEQ,
                                   contentSize.width,
                                   ClsWeak(),
                                   [self contentCompressionResistancePriorityForAxis:UILayoutConstraintAxisHorizontal]);
            c_solver.AddConstraint(&layoutProperties->_contentHuggingConstraint[Horizontal]);
            c_solver.AddConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Horizontal]);
        }
    }
    if (contentSize.height == -1.0f /*UIViewNoIntrinsicMetric*/ || contentSize.height == 0) {
        if (layoutProperties->_contentHuggingConstraint[Vertical].FIsInSolver()) {
            c_solver.RemoveConstraint(&layoutProperties->_contentHuggingConstraint[Vertical]);
            c_solver.RemoveConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Vertical]);
        }
    } else {
        if (layoutProperties->_contentHuggingConstraint[Vertical].FIsInSolver()) {
            if (contentSize.height != layoutProperties->_contentHuggingConstraint[Vertical].Expression().Constant()) {
                // Changing constants on constraints while they're in a solver is ineffectual. Explicitly add/remove.
                c_solver.RemoveConstraint(&layoutProperties->_contentHuggingConstraint[Vertical]);
                c_solver.RemoveConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Vertical]);
                layoutProperties->_contentHuggingConstraint[Vertical].ChangeConstant(contentSize.height);
                layoutProperties->_contentCompressionResistanceConstraint[Vertical].ChangeConstant(contentSize.height);
                c_solver.AddConstraint(&layoutProperties->_contentHuggingConstraint[Vertical]);
                c_solver.AddConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Vertical]);
            }
            if ([self contentHuggingPriorityForAxis:UILayoutConstraintAxisVertical] != layoutProperties->_contentHuggingConstraint[Vertical].weight()) {
                c_solver.ChangeWeight(&layoutProperties->_contentHuggingConstraint[Vertical], [self contentHuggingPriorityForAxis:UILayoutConstraintAxisVertical]);
            }
            if ([self contentCompressionResistancePriorityForAxis:UILayoutConstraintAxisVertical] !=
                layoutProperties->_contentCompressionResistanceConstraint[Vertical].weight()) {
                c_solver.ChangeWeight(&layoutProperties->_contentCompressionResistanceConstraint[Vertical],
                                     [self contentCompressionResistancePriorityForAxis:UILayoutConstraintAxisVertical]);
            }
        }
        if (!layoutProperties->_contentHuggingConstraint[Vertical].FIsInSolver()) {
            layoutProperties->_contentHuggingConstraint[Vertical] =
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Bottom]) -
                                       layoutProperties->_vars[AutoLayoutProperties::Top],
                                   cnLEQ,
                                   contentSize.height,
                                   ClsWeak(),
                                   [self contentHuggingPriorityForAxis:UILayoutConstraintAxisVertical]);
            layoutProperties->_contentCompressionResistanceConstraint[Vertical] =
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Bottom]) -
                                       layoutProperties->_vars[AutoLayoutProperties::Top],
                                   cnGEQ,
                                   contentSize.height,
                                   ClsWeak(),
                                   [self contentCompressionResistancePriorityForAxis:UILayoutConstraintAxisVertical]);
            c_solver.AddConstraint(&layoutProperties->_contentHuggingConstraint[Vertical]);
            c_solver.AddConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Vertical]);
        }
    }
}

// Gets the top most view that autolayout is relative to.
- (UIView*)autolayoutRoot {
    UIView* ret = self;
    
    while (ret.translatesAutoresizingMaskIntoConstraints == NO || ([ret.superview viewForBaselineLayout] == ret)) {
        ret = ret.superview;
        if (ret == nil) {
            // Attempt to auto layout outside view hierarchy. May happen if someone adds the constraints out of order.
            return self;
        }
    }

    return ret;
}

- (void)autoLayoutUpdateConstraints {
    AutoLayoutProperties* layoutProperties = self._autoLayoutProperties;

    if (![layoutProperties->_associatedConstraints count]) {
        return;
    }

    // Even if we're not constrained, we're still in the solution, so someone might be using us.
    // Note: translatesAutoresizingMaskIntoConstraints doesn't actually create constraints. We've
    //   opted to allow the autoresize path to run, and simply update the top-level views' variables
    //   in the solution.
    if (self.translatesAutoresizingMaskIntoConstraints) {
        CGRect curBounds = [self bounds];
        CGRect convFrame;

        layoutProperties->AddStays();
            
        convFrame = [self convertRect:curBounds toView:[self autolayoutRoot]];

        if ((layoutProperties->_vars[AutoLayoutProperties::Right].Value() != convFrame.origin.x + convFrame.size.width) ||
            (layoutProperties->_vars[AutoLayoutProperties::Left].Value() != convFrame.origin.x)) {

            c_solver.AddEditVar(layoutProperties->_vars[AutoLayoutProperties::Right], ClsStrong(), 2.0);
            c_solver.AddEditVar(layoutProperties->_vars[AutoLayoutProperties::Left], ClsStrong(), 2.0);

            c_solver.BeginEdit();
            c_solver.SuggestValue(layoutProperties->_vars[AutoLayoutProperties::Right], convFrame.origin.x + convFrame.size.width);
            c_solver.SuggestValue(layoutProperties->_vars[AutoLayoutProperties::Left], convFrame.origin.x);
            c_solver.Resolve();
            c_solver.EndEdit(); // Removes edit constraints.    
        }

        if ((layoutProperties->_vars[AutoLayoutProperties::Bottom].Value() != convFrame.origin.y + convFrame.size.height) ||
            (layoutProperties->_vars[AutoLayoutProperties::Top].Value() != convFrame.origin.y)) {

            c_solver.AddEditVar(layoutProperties->_vars[AutoLayoutProperties::Bottom], ClsStrong(), 2.0);
            c_solver.AddEditVar(layoutProperties->_vars[AutoLayoutProperties::Top], ClsStrong(), 2.0);

            c_solver.BeginEdit();
            c_solver.SuggestValue(layoutProperties->_vars[AutoLayoutProperties::Bottom], convFrame.origin.y + convFrame.size.height);
            c_solver.SuggestValue(layoutProperties->_vars[AutoLayoutProperties::Top], convFrame.origin.y);
            c_solver.Resolve();
            c_solver.EndEdit(); // Removes edit constraints. 
        }
    } else {
        [self autoLayoutInvalidateContentSize];
        layoutProperties->RemoveStays();
    }
}

- (void)autoLayoutDealloc {
}

@end
