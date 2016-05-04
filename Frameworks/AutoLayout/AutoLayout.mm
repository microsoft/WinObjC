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

#include <Starboard.h>
#include <AutoLayout.h>
#include <NSLayoutConstraint+AutoLayout.h>
#include <UIView+AutoLayout.h>
#include <UIViewInternal.h>

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

class ConstraintProperties {
public:
    ConstraintProperties() : _constraint(NULL) {
    }
    ClConstraint* _constraint;
};

extern "C" bool InitializeAutoLayout() {
    return true;
}

class AutoLayoutProperties {
public:
    AutoLayoutProperties(UIView* view)
        : _view(view),
          _contentHuggingConstraint{ ClLinearInequality(ClLinearExpression()), ClLinearInequality(ClLinearExpression()) },
          _contentCompressionResistanceConstraint{ ClLinearInequality(ClLinearExpression()), ClLinearInequality(ClLinearExpression()) },
          _stays{ ClStayConstraint(_vars[0], ClsStrong()),
                  ClStayConstraint(_vars[1], ClsStrong()),
                  ClStayConstraint(_vars[2], ClsStrong()),
                  ClStayConstraint(_vars[3], ClsStrong()) } {
        _staysAdded = false;
    }

    ~AutoLayoutProperties() {
        // TODO: Do we need to remove stays? How would we do that?
        for (int i = 0; i < NumDirections; i++) {
            if (_contentHuggingConstraint[i].FIsInSolver()) {
                c_solver.RemoveConstraint(&_contentHuggingConstraint[i]);
                c_solver.RemoveConstraint(&_contentCompressionResistanceConstraint[i]);
            }
        }
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

    UIView* _view;
    ClVariable _vars[4];
    ClStayConstraint _stays[4];
    bool _staysAdded;
    ClLinearInequality _contentHuggingConstraint[NumDirections];
    ClLinearInequality _contentCompressionResistanceConstraint[NumDirections];
};

@implementation NSLayoutConstraint (AutoLayout)
- (void)autoLayoutAlloc {
    [self _privateState]->_constraints = new ConstraintProperties();
}

- (void)autoLayoutConstraintAddedToView:(UIView*)view {
    assert(self.firstItem);

    if (![self _privateState]->_constraints->_constraint) {
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

            [item _initPriv];

            auto layoutProps = [item _privateState]->layoutProperties;

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
            if ([item respondsToSelector:@selector(_privateState)]) {
                [[item _privateState]->associatedConstraints addObject:self];
            }
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
                [self _privateState]->_constraints->_constraint = new ClLinearEquation(lex[0], lex[1], *strength, self.priority);
                break;
            case NSLayoutRelationGreaterThanOrEqual:
                [self _privateState]->_constraints->_constraint =
                    new ClLinearInequality(lex[0], cnGEQ, lex[1], *strength, self.priority);
                break;
            case NSLayoutRelationLessThanOrEqual:
                [self _privateState]->_constraints->_constraint =
                    new ClLinearInequality(lex[0], cnLEQ, lex[1], *strength, self.priority);
                break;
            default:
                assert(0);
        }

        c_solver.AddConstraint([self _privateState]->_constraints->_constraint);

    }
}

- (void)autoLayoutConstraintRemovedFromView {
    [self _removeFromSolver];

    if (self.firstItem != nil && [self.firstItem respondsToSelector:@selector(_privateState)]) {
        [[self.firstItem _privateState]->associatedConstraints removeObject:self];
        if (![[self.firstItem _privateState]->associatedConstraints count]) {
            [self.firstItem _privateState]->layoutProperties->RemoveStays();
        }
    }
    if (self.secondItem != nil && [self.secondItem respondsToSelector:@selector(_privateState)]) {
        [[self.secondItem _privateState]->associatedConstraints removeObject:self];
        if (![[self.secondItem _privateState]->associatedConstraints count]) {
            [self.secondItem _privateState]->layoutProperties->RemoveStays();
        }
    }
}

- (void)autoLayoutDealloc {
    [self _removeFromSolver];
    delete[self _privateState]->_constraints;
}

- (void)_removeFromSolver {
    if ([self _privateState]->_constraints->_constraint) {
        if ([self _privateState]->_constraints->_constraint->FIsInSolver()) {
            c_solver.RemoveConstraint([self _privateState]->_constraints->_constraint);
        }
        delete[self _privateState]->_constraints->_constraint;
        [self _privateState]->_constraints->_constraint = NULL;
    }
}
@end

@implementation UIView (AutoLayout)
- (void)autoLayoutAlloc {
    if (![self _privateState]->layoutProperties) {
        [self _privateState]->layoutProperties = new AutoLayoutProperties(self);
    }
}

- (void)autoLayoutSetFrameToView:(UIView*)toView fromView:(UIView*)fromView {
    UIViewPrivateState* viewPriv = [self _privateState];
    CGRect newFrame;
    CGPoint newPointTL;
    CGPoint newPointBR;
    CGPoint oldPointTL;
    CGPoint oldPointBR;

    oldPointTL.x = (float)viewPriv->layoutProperties->_vars[AutoLayoutProperties::Left].Value();
    oldPointTL.y = (float)viewPriv->layoutProperties->_vars[AutoLayoutProperties::Top].Value();
    oldPointBR.x = (float)viewPriv->layoutProperties->_vars[AutoLayoutProperties::Right].Value();
    oldPointBR.y = (float)viewPriv->layoutProperties->_vars[AutoLayoutProperties::Bottom].Value();

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
        UIViewPrivateState* childPriv = [child _privateState];

        if ([childPriv->associatedConstraints count] && !childPriv->translatesAutoresizingMaskIntoConstraints) {
            // Constraints that rely on autoresizing behaviour don't always follow a top-down layout order.
            // Baseline views can be autoresized, and are not always siblings to other constrained views.
            // We have to update them first, and this potentially can happen recursively. Ie, a view
            // constrained to a button's baseline, constrained to a segment's baseline, etc.
            // To facilitate this, we update frames for views we depend on (and thus their autosizing, and
            // constraints) before setting our own.
            // TODO: last baseline
            for (NSLayoutConstraint* constraint in(NSArray*)childPriv->associatedConstraints) {
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
    UIViewPrivateState* privState = [self _privateState];
    AutoLayoutProperties* layoutProperties = privState->layoutProperties;
    CGSize contentSize = [self intrinsicContentSize];

    if (contentSize.width == -1.0f /*UIViewNoIntrinsicMetric*/ || contentSize.width == 0) {
        if (layoutProperties->_contentHuggingConstraint[Horizontal].FIsInSolver()) {
            c_solver.RemoveConstraint(&layoutProperties->_contentHuggingConstraint[Horizontal]);
            c_solver.RemoveConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Horizontal]);
        }
    } else {
        if (layoutProperties->_contentHuggingConstraint[Horizontal].FIsInSolver()) {
            if (contentSize.width != layoutProperties->_contentHuggingConstraint[Horizontal].Expression().Constant()) {
                layoutProperties->_contentHuggingConstraint[Horizontal].ChangeConstant(contentSize.width);
                layoutProperties->_contentCompressionResistanceConstraint[Horizontal].ChangeConstant(contentSize.width);
            }
            if (privState->_contentHuggingPriority.width != layoutProperties->_contentHuggingConstraint[Horizontal].weight()) {
                c_solver.ChangeWeight(&layoutProperties->_contentHuggingConstraint[Horizontal], privState->_contentHuggingPriority.width);
            }
            if (privState->_contentCompressionResistancePriority.width !=
                layoutProperties->_contentCompressionResistanceConstraint[Horizontal].weight()) {
                c_solver.ChangeWeight(&layoutProperties->_contentCompressionResistanceConstraint[Horizontal],
                                     privState->_contentCompressionResistancePriority.width);
            }
        }
        if (!layoutProperties->_contentHuggingConstraint[Horizontal].FIsInSolver()) {
            layoutProperties->_contentHuggingConstraint[Horizontal] =
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Right]) -
                                       layoutProperties->_vars[AutoLayoutProperties::Left],
                                   cnLEQ,
                                   contentSize.width,
                                   ClsWeak(),
                                   privState->_contentHuggingPriority.width);
            layoutProperties->_contentCompressionResistanceConstraint[Horizontal] =
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Right]) -
                                       layoutProperties->_vars[AutoLayoutProperties::Left],
                                   cnGEQ,
                                   contentSize.width,
                                   ClsWeak(),
                                   privState->_contentCompressionResistancePriority.width);
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
                layoutProperties->_contentHuggingConstraint[Vertical].ChangeConstant(contentSize.height);
                layoutProperties->_contentCompressionResistanceConstraint[Vertical].ChangeConstant(contentSize.height);
            }
            if (privState->_contentHuggingPriority.height != layoutProperties->_contentHuggingConstraint[Vertical].weight()) {
                c_solver.ChangeWeight(&layoutProperties->_contentHuggingConstraint[Vertical], privState->_contentHuggingPriority.height);
            }
            if (privState->_contentCompressionResistancePriority.height !=
                layoutProperties->_contentCompressionResistanceConstraint[Vertical].weight()) {
                c_solver.ChangeWeight(&layoutProperties->_contentCompressionResistanceConstraint[Vertical],
                                     privState->_contentCompressionResistancePriority.height);
            }
        }
        if (!layoutProperties->_contentHuggingConstraint[Vertical].FIsInSolver()) {
            layoutProperties->_contentHuggingConstraint[Vertical] =
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Bottom]) -
                                       layoutProperties->_vars[AutoLayoutProperties::Top],
                                   cnLEQ,
                                   contentSize.height,
                                   ClsWeak(),
                                   privState->_contentHuggingPriority.height);
            layoutProperties->_contentCompressionResistanceConstraint[Vertical] =
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Bottom]) -
                                       layoutProperties->_vars[AutoLayoutProperties::Top],
                                   cnGEQ,
                                   contentSize.height,
                                   ClsWeak(),
                                   privState->_contentCompressionResistancePriority.height);
            c_solver.AddConstraint(&layoutProperties->_contentHuggingConstraint[Vertical]);
            c_solver.AddConstraint(&layoutProperties->_contentCompressionResistanceConstraint[Vertical]);
        }
    }
}

- (void)autoLayoutInitWithCoder:(NSCoder*)coder {
    if ([coder containsValueForKey:@"UIViewContentCompressionResistancePriority"]) {
        id sizeObj = [coder decodeObjectForKey:@"UIViewContentCompressionResistancePriority"];
        if ([sizeObj isKindOfClass:[NSString class]]) {
            const char* stretchStr = [sizeObj UTF8String];
            sscanf_s(stretchStr,
                     "{%f, %f}",
                     &[self _privateState]->_contentCompressionResistancePriority.width,
                     &[self _privateState]->_contentCompressionResistancePriority.height);
        } else {
            CGSize* size = (CGSize*)[sizeObj bytes];
            memcpy(&[self _privateState]->_contentCompressionResistancePriority, size, sizeof(CGRect));
        }
    }

    if ([coder containsValueForKey:@"UIViewContentHuggingPriority"]) {
        id sizeObj = [coder decodeObjectForKey:@"UIViewContentHuggingPriority"];
        if ([sizeObj isKindOfClass:[NSString class]]) {
            const char* stretchStr = [(NSString*)sizeObj UTF8String];
            sscanf_s(stretchStr,
                     "{%f, %f}",
                     &[self _privateState]->_contentHuggingPriority.width,
                     &[self _privateState]->_contentHuggingPriority.height);
        } else {
            CGSize* size = (CGSize*)[sizeObj bytes];
            memcpy(&[self _privateState]->_contentHuggingPriority, size, sizeof(CGRect));
        }
    }
}

// Gets the top most view that autolayout is relative to.
- (UIView*)autolayoutRoot {
    UIView* ret = self;
    
    while ([ret _privateState]->translatesAutoresizingMaskIntoConstraints == NO || ([ret.superview viewForBaselineLayout] == ret)) {
        ret = ret.superview;
        if (ret == nil) {
            // Attempt to auto layout outside view hierarchy. May happen if someone adds the constraints out of order.
            return self;
        }
    }

    return ret;
}

- (void)autoLayoutUpdateConstraints {
    AutoLayoutProperties* layoutProperties = [self _privateState]->layoutProperties;

    if (![[self _privateState]->associatedConstraints count]) {
        return;
    }

    // Even if we're not constrained, we're still in the solution, so someone might be using us.
    // Note: translatesAutoresizingMaskIntoConstraints doesn't actually create constraints. We've
    //   opted to allow the autoresize path to run, and simply update the top-level views' variables
    //   in the solution.
    if ([self _privateState]->translatesAutoresizingMaskIntoConstraints) {
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
    [self _privateState]->layoutProperties->RemoveStays();
    delete[self _privateState]->layoutProperties;
    [self _privateState]->layoutProperties = NULL;
}
@end
