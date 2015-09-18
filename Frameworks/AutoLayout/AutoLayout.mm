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

#define CL_NO_IO
#define CL_NO_ID

#include <cassowary-0.60/ClSimplexSolver.h>
#include <cassowary-0.60/ClLinearEquation.h>

ClSimplexSolver gSolver;

class ConstraintProperties
{
public:
    ConstraintProperties() 
        : _constraint(NULL)
    {
    }
    ClConstraint* _constraint;
};

class AutoLayoutProperties
{
public:
    AutoLayoutProperties(UIView* view)  :
        _view(view),
        _contentHuggingConstraint{ ClLinearInequality(ClLinearExpression()), ClLinearInequality(ClLinearExpression()) },
        _contentCompressionResistanceConstraint{ ClLinearInequality(ClLinearExpression()), ClLinearInequality(ClLinearExpression()) }
    {
        _staysAdded = false;
        _inSolution = false;
    }

    ~AutoLayoutProperties() 
    {
        // TODO: Do we need to remove stays? How would we do that?
        for(int i = 0; i < 2; i++) {
            if(_contentHuggingConstraint[i].FIsInSolver()) {
                gSolver.RemoveConstraint(&_contentHuggingConstraint[i]);
                gSolver.RemoveConstraint(&_contentCompressionResistanceConstraint[i]);
            }
        }
    }

    void AddStays()
    {
        if(!_staysAdded) {
            for(int i = 0; i < 4; i++) {
                gSolver.AddStay(_vars[i], ClsWeak(), 1000.0);
            }
            _staysAdded = true;
        }
    }

    enum {
        Left,
        Right,
        Top,
        Bottom
    };

    UIView* _view;
    ClVariable _vars[4];
    bool _staysAdded;
    bool _inSolution;
    ClLinearInequality _contentHuggingConstraint[2];
    ClLinearInequality _contentCompressionResistanceConstraint[2];
};


@implementation NSLayoutConstraint(AutoLayout)
-(void)autoLayoutAlloc {
    [self _privateState]->_constraints = new ConstraintProperties();
}

-(void)autoLayoutConstraintAddedToView:(UIView*)view {
    assert(self.firstItem);
    //assert([self.firstItem isKindOfClass:[UIView class]]);
    //if(self.secondItem) assert([self.secondItem isKindOfClass:[UIView class]]);

    if(![self _privateState]->_constraints->_constraint) {
        // TODO: Care about reading direction.
        ClLinearExpression lex[2];
        UIView* items[] = { self.firstItem, self.secondItem };
        int attributes[] = { self.firstAttribute, self.secondAttribute };

        for(int n = 0; n < 2; n++) {
            UIView* item = items[n];
            int attribute = attributes[n];

            if(item == nil) {
                continue;
            }

            [item initPriv];

            auto layoutProps = [item _privateState]->layoutProperties;
            layoutProps->_inSolution = true;
            
            switch(attribute) {
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
                lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom]);
                break;
            case NSLayoutAttributeWidth:
                lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Right])-layoutProps->_vars[AutoLayoutProperties::Left];
                break;
            case NSLayoutAttributeHeight:
                lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom])-layoutProps->_vars[AutoLayoutProperties::Top];
                break;
            case NSLayoutAttributeCenterX:
                lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Right])*0.5+ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Left])*0.5;
                break;
            case NSLayoutAttributeCenterY:
                lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom])*0.5+ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Top])*0.5;
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
                lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Right])*0.5+ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Left])*0.5;
                break;
            case NSLayoutAttributeCenterYWithinMargins:
                lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom])*0.5+ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Top])*0.5;
                break;

            case NSLayoutAttributeBaseline:
            case NSLayoutAttributeFirstBaseline: // TODO
                {
                    if(![item respondsToSelector:@selector(viewForBaselineLayout)]) {
                        // TODO: This should probably be handled in NSLayoutConstraint
                        EbrDebugLog("Baseline requested for non-UIView item.\n");
                        lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom]);
                    } else {
                        UIView* baseline = [(UIView*)item viewForBaselineLayout];
                        lex[n] = ClLinearExpression(layoutProps->_vars[AutoLayoutProperties::Bottom]);
                    }
                }
                break;
            default:
                assert(0);
                break;
            }

        }

        ClStrength strength(self.priority >= NSLayoutPriorityRequired ? ClsRequired() : ClsWeak());
        float constant = self.constant;
        UIView* item1 = self.firstItem;
        UIView* item2 = self.secondItem;

        if((id)item2 != nil) {
            if([item1 _privateState]->superview == [item2 _privateState]->superview) {
                // Siblings shouldn't set stays.
                [item1 _privateState]->_constrained = true;
            } else if([item2 _privateState]->superview == item1) {
                [item2 _privateState]->_constrained = true;
            } else if([item1 _privateState]->superview == item2) {
                [item1 _privateState]->_constrained = true;
            } else {
                EbrDebugLog("Constraint set between items that don't share a direct relationship. This might be an error.\n");
            }
        } else {
            if(self.firstAttribute == NSLayoutAttributeWidth || self.firstAttribute == NSLayoutAttributeHeight) {
                [item1 _privateState]->_constrained = true;
            }
        }

        if(item2 == nil) {
            lex[1] = ClLinearExpression(constant);
        } else {
            lex[1] = lex[1].MultiplyMe(self.multiplier).Plus(constant);
        }

        switch(self.relation) {
        case NSLayoutRelationEqual:
            [self _privateState]->_constraints->_constraint = new ClLinearEquation(lex[0], lex[1], strength, self.priority);
            break;
        case NSLayoutRelationGreaterThanOrEqual:
            [self _privateState]->_constraints->_constraint = new ClLinearInequality(lex[0], cnGEQ, lex[1], strength, self.priority);
            break;
        case NSLayoutRelationLessThanOrEqual:
            [self _privateState]->_constraints->_constraint = new ClLinearInequality(lex[0], cnLEQ, lex[1], strength, self.priority);
            break;
        default:
            assert(0);
        }

        gSolver.AddConstraint([self _privateState]->_constraints->_constraint);
    }
}

-(void) autoLayoutConstraintRemovedFromView {
    if([self _privateState]->_constraints->_constraint) {
        if([self _privateState]->_constraints->_constraint->FIsInSolver()) {
            gSolver.RemoveConstraint([self _privateState]->_constraints->_constraint);
        }
        delete [self _privateState]->_constraints->_constraint;
        [self _privateState]->_constraints->_constraint = NULL;
    }
}

-(void) autoLayoutDealloc {
    [self autoLayoutConstraintRemovedFromView];
    delete [self _privateState]->_constraints;
}
@end

@implementation UIView(AutoLayout)
- (void)autoLayoutAlloc {
    if(![self _privateState]->layoutProperties) {
        [self _privateState]->layoutProperties = new AutoLayoutProperties(self);
    }
}

- (void)autoLayoutLayoutSubviews {
    for(int i = 0; i < [self.subviews count]; i++) {
        UIView* child = (UIView*)[self.subviews objectAtIndex:i];

        // XXX: translatesAutoresizingMaskIntoConstraints is kind of cheated here. We merely apply bounds 
        // (which should be subject to autolayout) to the solution, and hope for the best.
        if([child _privateState]->layoutProperties->_inSolution && 
           [child _privateState]->_constrained && 
           ![child _privateState]->translatesAutoresizingMaskIntoConstraints ) {
            CGRect newFrame;
            CGPoint newPoint;
            CGPoint oldPoint;
            UIViewPrivateState* topView = [self _privateState];

            oldPoint.x = (float)[child _privateState]->layoutProperties->_vars[AutoLayoutProperties::Left].Value();
            oldPoint.y = (float)[child _privateState]->layoutProperties->_vars[AutoLayoutProperties::Top].Value();
            
            // We assume the solution to be in the topmost unconstrained item's coordinates. 
            while(topView->parent) {
                if(topView->_constrained) {
                    topView = topView->parent;
                } else {
                    break;
                }
            }

            newPoint = [self convertPoint:oldPoint fromView:topView->self];

            newFrame.size.width = (float)([child _privateState]->layoutProperties->_vars[AutoLayoutProperties::Right].Value() -
                    [child _privateState]->layoutProperties->_vars[AutoLayoutProperties::Left].Value());
            newFrame.size.height = (float)([child _privateState]->layoutProperties->_vars[AutoLayoutProperties::Bottom].Value() -
                        [child _privateState]->layoutProperties->_vars[AutoLayoutProperties::Top].Value());
            newFrame.origin.x = newPoint.x;
            newFrame.origin.y = newPoint.y;

            [(id)child setFrame:newFrame];
        } else {
            EbrDebugLog("Not autolaying out %s\n", [[child description] UTF8String]);
        }
    }
}

-(void) invalidateContentSize {
    AutoLayoutProperties* layoutProperties = [self _privateState]->layoutProperties;
    CGSize contentSize = [self intrinsicContentSize];
    
    if(contentSize.width == -1.0f /*UIViewNoIntrinsicMetric*/ ) {
        if(layoutProperties->_contentHuggingConstraint[0].FIsInSolver()) {
            gSolver.RemoveConstraint(&layoutProperties->_contentHuggingConstraint[0]);
            gSolver.RemoveConstraint(&layoutProperties->_contentCompressionResistanceConstraint[0]);
        }
    } else {
        if(layoutProperties->_contentHuggingConstraint[0].FIsInSolver() && contentSize.width != layoutProperties->_contentHuggingConstraint[0].Expression().Constant()) {
            gSolver.ChangeWeight(&layoutProperties->_contentHuggingConstraint[0], [self _privateState]->_contentHuggingPriority.width);
            gSolver.ChangeWeight(&layoutProperties->_contentCompressionResistanceConstraint[0], [self _privateState]->_contentCompressionResistancePriority.width);
        }
        if(!layoutProperties->_contentHuggingConstraint[0].FIsInSolver()) {
            layoutProperties->_contentHuggingConstraint[0] = 
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Right]) - layoutProperties->_vars[AutoLayoutProperties::Left],
                    cnLEQ, contentSize.width, ClsWeak(), [self _privateState]->_contentHuggingPriority.width);
            layoutProperties->_contentCompressionResistanceConstraint[0] = 
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Right]) - layoutProperties->_vars[AutoLayoutProperties::Left],
                    cnGEQ, contentSize.width, ClsWeak(), [self _privateState]->_contentCompressionResistancePriority.width);
            gSolver.AddConstraint(&layoutProperties->_contentHuggingConstraint[0]);
            gSolver.AddConstraint(&layoutProperties->_contentCompressionResistanceConstraint[0]);
        }
    }
    if(contentSize.height == -1.0f /*UIViewNoIntrinsicMetric*/ ) {
        if(layoutProperties->_contentHuggingConstraint[1].FIsInSolver()) {
            gSolver.RemoveConstraint(&layoutProperties->_contentHuggingConstraint[1]);
            gSolver.RemoveConstraint(&layoutProperties->_contentCompressionResistanceConstraint[1]);
        }
    } else {
        if(layoutProperties->_contentHuggingConstraint[1].FIsInSolver() && contentSize.height != layoutProperties->_contentHuggingConstraint[1].Expression().Constant()) {
            gSolver.ChangeWeight(&layoutProperties->_contentHuggingConstraint[1], [self _privateState]->_contentHuggingPriority.height);
            gSolver.ChangeWeight(&layoutProperties->_contentCompressionResistanceConstraint[1], [self _privateState]->_contentCompressionResistancePriority.height);
        }
        if(!layoutProperties->_contentHuggingConstraint[1].FIsInSolver()) {
            layoutProperties->_contentHuggingConstraint[1] = 
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Bottom]) - layoutProperties->_vars[AutoLayoutProperties::Top],
                    cnLEQ, contentSize.height, ClsWeak(), [self _privateState]->_contentHuggingPriority.height);
            layoutProperties->_contentCompressionResistanceConstraint[1] = 
                ClLinearInequality(ClLinearExpression(layoutProperties->_vars[AutoLayoutProperties::Bottom]) - layoutProperties->_vars[AutoLayoutProperties::Top],
                    cnGEQ, contentSize.height, ClsWeak(), [self _privateState]->_contentCompressionResistancePriority.height);
            gSolver.AddConstraint(&layoutProperties->_contentHuggingConstraint[1]);
            gSolver.AddConstraint(&layoutProperties->_contentCompressionResistanceConstraint[1]);
        }
    }
}

- (void)autoLayoutInitWithCoder:(NSCoder*)coder {
    [self autoLayoutSetVars: [self frame]];

    if([coder containsValueForKey:@"UIViewContentCompressionResistancePriority"]) {
        id sizeObj = [coder decodeObjectForKey:@"UIViewContentCompressionResistancePriority"];
        if ( [sizeObj isKindOfClass:[NSString class]] ) {
            const char *stretchStr = [sizeObj UTF8String];
            sscanf(stretchStr, "{%f, %f}", &[self _privateState]->_contentCompressionResistancePriority.width, &[self _privateState]->_contentCompressionResistancePriority.height);
        } else {
            CGSize *size = (CGSize *) [sizeObj bytes];
            memcpy(&[self _privateState]->_contentCompressionResistancePriority, size, sizeof(CGRect));
        }
    }

    if([coder containsValueForKey:@"UIViewContentHuggingPriority"]) {
        id sizeObj = [coder decodeObjectForKey:@"UIViewContentHuggingPriority"];
        if ( [sizeObj isKindOfClass:[NSString class]] ) {
            const char *stretchStr = [(NSString*)sizeObj UTF8String];
            sscanf(stretchStr, "{%f, %f}", &[self _privateState]->_contentHuggingPriority.width, &[self _privateState]->_contentHuggingPriority.height);
        } else {
            CGSize *size = (CGSize *) [sizeObj bytes];
            memcpy(&[self _privateState]->_contentHuggingPriority, size, sizeof(CGRect));
        }
    }
}

- (void)autoLayoutSetVars:(CGRect)bounds {
    [self _privateState]->layoutProperties->_vars[AutoLayoutProperties::Right]->SetValue(bounds.origin.x + bounds.size.width);
    [self _privateState]->layoutProperties->_vars[AutoLayoutProperties::Bottom]->SetValue(bounds.origin.y + bounds.size.height);
    [self _privateState]->layoutProperties->_vars[AutoLayoutProperties::Left]->SetValue((Number)bounds.origin.x);
    [self _privateState]->layoutProperties->_vars[AutoLayoutProperties::Top]->SetValue((Number)bounds.origin.y);
}

-(void)autoLayoutUpdateConstraints {
    AutoLayoutProperties* layoutProperties = [self _privateState]->layoutProperties;
    if(layoutProperties->_inSolution) {
        [self invalidateContentSize];

        // Even if we're not constrained, we're still in the solution, so someone might be using us.
        // XXX: Does translatesAutoresizingMaskIntoConstraints come into play here?
        if(![self _privateState]->_constrained) {
            CGRect bounds = [self bounds];

            layoutProperties->AddStays();

            for(int i = 0; i < 4; i++) {
                gSolver.AddEditVar(layoutProperties->_vars[i]);
            }

            gSolver.BeginEdit();
            gSolver.SuggestValue(layoutProperties->_vars[AutoLayoutProperties::Right], bounds.size.width);
            gSolver.SuggestValue(layoutProperties->_vars[AutoLayoutProperties::Bottom], bounds.size.height);
            gSolver.SuggestValue(layoutProperties->_vars[AutoLayoutProperties::Left], 0); // Note 0
            gSolver.SuggestValue(layoutProperties->_vars[AutoLayoutProperties::Top], 0);
            gSolver.Resolve();
            gSolver.EndEdit(); // Removes edit variables, fyi.
        }
    }
}

-(void) autoLayoutDealloc {
    delete [self _privateState]->layoutProperties;
    [self _privateState]->layoutProperties = NULL;
}
@end
