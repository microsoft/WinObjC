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

#include "Starboard.h"

#include "UIKit/UIView.h"
#include "UIViewInternal.h"
#include "AutoLayout.h"

#include <regex>
#include <list>
#include <sstream>
#include <regex>
#include <string>

#import "UIKit/NSLayoutConstraint.h"

using namespace std;

struct Predicate {
    Predicate(string targ = "0", string rel = "==", string prio = "1000") : relation(rel), target(targ), priority(prio) {
    }
    string relation; // >=, <=, ==
    string target; // constant or item
    string priority; // +0-1000
};

typedef vector<Predicate> PredicateList;

struct Constraint {
    Constraint(PredicateList preds, string targ) : predicates(preds), target(targ) {
    }
    PredicateList predicates; // Targets are explicit, ie not defined by their position in the visual language string.
    string target;
};

typedef vector<Constraint> ConstraintList;

bool parsePredicates(string line, PredicateList& predicates) {
    // Should this be parsed differently between connectors and constraints?
    vector<string> predStr;

    // Trim parens
    if (line.length() > 2 && line[0] == '(') {
        if (*line.rbegin() != ')') {
            EbrDebugLog("Syntax error! %s\n", line.c_str());
            return false;
        }
        line = line.substr(1, line.length() - 2);
    }

    stringstream ss(line);
    string val;

    // Doesn't catch "one,two,three,,"
    while (getline(ss, val, ',')) {
        predStr.push_back(val);
    }

    for (int i = 0; i < predStr.size(); i++) {
        regex rex = regex::basic_regex("^\\s*(==|>=|<=)?([\\w.]+)(@([\\w]+))?\\s*$");
        smatch m;
        if (!regex_search(predStr[i], m, rex)) {
            EbrDebugLog("Syntax Error! %s\n", predStr[i].c_str());
            return false;
        } else {
#ifdef DEBUG_VISUAL_FORMAT
            EbrDebugLog("Relation: %s, Constant: %s, priority: %s\n", m[1].str().c_str(), m[2].str().c_str(), m[4].str().c_str());
#endif
            predicates.push_back(Predicate(m[2].str(), m[1].str(), m[4].str()));
        }
    }
    return true;
}

// Returns nil if failed
NSArray* constraintsFromPredicates(PredicateList& predicates,
                                   UIView* item1,
                                   UIView* item2,
                                   NSDictionary* views,
                                   NSDictionary* metrics,
                                   bool vertical,
                                   NSLayoutFormatOptions direction) {
    static NSNumberFormatter* formatter = [NSNumberFormatter new];
    NSMutableArray* ret = [NSMutableArray new];
    NSLayoutAttribute item1Attribute;
    NSLayoutAttribute item2Attribute;

    switch (direction) {
        case NSLayoutFormatDirectionLeadingToTrailing: // default (0)
            item1Attribute = NSLayoutAttributeTrailing;
            item2Attribute = NSLayoutAttributeLeading;
            break;
        case NSLayoutFormatDirectionLeftToRight:
            item1Attribute = NSLayoutAttributeRight;
            item2Attribute = NSLayoutAttributeLeft;
            break;
        case NSLayoutFormatDirectionRightToLeft:
            item1Attribute = NSLayoutAttributeLeft;
            item2Attribute = NSLayoutAttributeRight;
            break;
        default:
            EbrDebugLog("Unknown format direction: %d\n", direction);
            return nil;
    }

    for (int i = 0; i < predicates.size(); i++) {
        UIView* target = nil;
        CGFloat priority = 1000.0;
        NSLayoutRelation relation;
        CGFloat constant = 0;

        // Connector target predicates cannot be objects.
        if (predicates[i].target != "") {
            NSString* targStr = [NSString stringWithUTF8String:predicates[i].target.c_str()];
            NSNumber* metric = [metrics objectForKey:targStr];
            target = (UIView*)[views objectForKey:targStr];

            // If item2 is nil, this is a size constraint
            if (target && item2) {
                EbrDebugLog("Connectors cannot have targets.\n");
                [ret release];
                return nil;
            }

            if ([targStr isEqual:@"default"]) { // Should this just be ""?
                if (!item2) {
                    EbrDebugLog("Default connector value requires a second target\n");
                    [ret release];
                    return nil;
                } else {
                    if ([item1 superview] == [item2 superview]) {
                        constant = 8.0f;
                    } else {
                        constant = 20.0f;
                    }
                }
            } else {
                if (metric) {
                    constant = metric.floatValue;
                } else {
                    NSNumber* num = [formatter numberFromString:targStr];
                    if (!num) {
                        if (!target) {
                            EbrDebugLog("Cannot parse number from target string: %s\n", predicates[i].target.c_str());
                            [ret release];
                            return nil;
                        }
                    } else {
                        constant = num.floatValue;
                    }
                }
            }
        }

        if (predicates[i].priority != "") {
            NSString* prioStr = [NSString stringWithUTF8String:predicates[i].priority.c_str()];
            NSNumber* metric = [metrics objectForKey:prioStr];

            if (metric) {
                priority = metric.floatValue;
            } else {
                NSNumber* num = [formatter numberFromString:prioStr];
                if (!num) {
                    EbrDebugLog("Cannot parse number from priority string: %s\n", predicates[i].priority.c_str());
                    [ret release];
                    return nil;
                }
                priority = num.floatValue;
            }
            if (priority < 0.0f || priority > 1000.0f) {
                EbrDebugLog("Priority out of range: %f\n", priority);
                [ret release];
                return nil;
            }
        }

        if (predicates[i].relation == "" || predicates[i].relation == "==") {
            relation = NSLayoutRelationEqual;
        } else if (predicates[i].relation == "<=") {
            relation = NSLayoutRelationLessThanOrEqual;
        } else if (predicates[i].relation == ">=") {
            relation = NSLayoutRelationGreaterThanOrEqual;
        } else {
            EbrDebugLog("Unknown relation string: \"%s\"\n", predicates[i].relation.c_str());
            [ret release];
            return nil;
        }

        if (item2) {
            NSLayoutAttribute a1 = vertical ? NSLayoutAttributeBottom : item1Attribute;
            NSLayoutAttribute a2 = vertical ? NSLayoutAttributeTop : item2Attribute;
            if (item1 == [item2 superview]) {
                a1 = vertical ? NSLayoutAttributeTop : item2Attribute;
            } else if (item2 == [item1 superview]) {
                a2 = vertical ? NSLayoutAttributeBottom : item1Attribute;
            }
            NSLayoutConstraint* c = [NSLayoutConstraint constraintWithItem:item1
                                                                 attribute:a1
                                                                 relatedBy:relation
                                                                    toItem:item2
                                                                 attribute:a2
                                                                multiplier:1.0f
                                                                  constant:-constant];
            c.priority = priority;
            [ret addObject:c];
        } else {
            NSLayoutConstraint* c = [NSLayoutConstraint constraintWithItem:item1
                                                                 attribute:vertical ? NSLayoutAttributeHeight : NSLayoutAttributeWidth
                                                                 relatedBy:relation
                                                                    toItem:target
                                                                 attribute:vertical ? NSLayoutAttributeHeight : NSLayoutAttributeWidth
                                                                multiplier:1.0f
                                                                  constant:constant];
            c.priority = priority;
            [ret addObject:c];
        }
    }
    return ret;
}

const char* relationType(NSLayoutRelation relation) {
    switch (relation) {
        case NSLayoutRelationEqual:
            return "==";
        case NSLayoutRelationLessThanOrEqual:
            return "<=";
        case NSLayoutRelationGreaterThanOrEqual:
            return ">=";
        default:
            return "None";
    }
}

const char* constraintType(NSLayoutAttribute attribute) {
    switch (attribute) {
        case NSLayoutAttributeLeft:
            return "NSLayoutAttributeLeft";
            break;
        case NSLayoutAttributeRight:
            return "NSLayoutAttributeRight";
            break;
        case NSLayoutAttributeTop:
            return "NSLayoutAttributeTop";
            break;
        case NSLayoutAttributeBottom:
            return "NSLayoutAttributeBottom";
            break;
        case NSLayoutAttributeLeading:
            return "NSLayoutAttributeLeading";
            break;
        case NSLayoutAttributeTrailing:
            return "NSLayoutAttributeRight";
            break;
        case NSLayoutAttributeWidth:
            return "NSLayoutAttributeWidth";
            break;
        case NSLayoutAttributeHeight:
            return "NSLayoutAttributeHeight";
            break;
        case NSLayoutAttributeCenterX:
            return "NSLayoutAttributeCenterX";
            break;
        case NSLayoutAttributeCenterY:
            return "NSLayoutAttributeCenterY";
            break;
        case NSLayoutAttributeBaseline:
            return "NSLayoutAttributeBaseline";
            break;
        case NSLayoutAttributeFirstBaseline:
            return "NSLayoutAttributeFirstBaseline";
            break;
        case NSLayoutAttributeLeftMargin:
            return "NSLayoutAttributeLeftMargin";
            break;
        case NSLayoutAttributeRightMargin:
            return "NSLayoutAttributeRightMargin";
            break;
        case NSLayoutAttributeTopMargin:
            return "NSLayoutAttributeTopMargin";
            break;
        case NSLayoutAttributeBottomMargin:
            return "NSLayoutAttributeBottomMargin";
            break;
        case NSLayoutAttributeLeadingMargin:
            return "NSLayoutAttributeLeadingMargin";
            break;
        case NSLayoutAttributeTrailingMargin:
            return "NSLayoutAttributeTrailingMargin";
            break;
        case NSLayoutAttributeCenterXWithinMargins:
            return "NSLayoutAttributeCenterXWithinMargins";
            break;
        case NSLayoutAttributeCenterYWithinMargins:
            return "NSLayoutAttributeCenterYWithinMargins";
            break;

        default:
            return "None";
            break;
    }
}

// Todo: Be more descriptive.
void printConstraint(NSLayoutConstraint* constraint) {
    if (constraint.firstItem != nil) {
        CGRect itmBounds;
        EbrDebugLog("%s from (%s) Type: %s\n",
                    [[[constraint class] description] UTF8String],
                    [[constraint.firstItem description] UTF8String],
                    constraintType(constraint.firstAttribute));
        itmBounds = [constraint.firstItem bounds];
        EbrDebugLog("Bounds (%f)(%f), (%f)(%f)\n", itmBounds.origin.x, itmBounds.origin.y, itmBounds.size.width, itmBounds.size.height);
    } else {
        EbrDebugLog("%s from (NONE) Type: %s\n", [[[constraint class] description] UTF8String], constraintType(constraint.firstAttribute));
    }
    if (constraint.secondItem != nil) {
        CGRect itmBounds;
        EbrDebugLog("%s to   (%s) Type: %s\n",
                    [[[constraint class] description] UTF8String],
                    [[constraint.secondItem description] UTF8String],
                    constraintType(constraint.secondAttribute));
        itmBounds = [constraint.secondItem bounds];
        EbrDebugLog("Bounds (%f)(%f), (%f)(%f)\n", itmBounds.origin.x, itmBounds.origin.y, itmBounds.size.width, itmBounds.size.height);
    } else {
        EbrDebugLog("%s to   (NONE) Type: %s\n", [[[constraint class] description] UTF8String], constraintType(constraint.secondAttribute));
    }
    EbrDebugLog("Details: mult(%f) const(%f), priority(%f)\n", constraint.multiplier, constraint.constant, constraint.priority);
}

void printConstraints(id constraints) {
    int count = [constraints count];
    if (count) {
        for (int i = 0; i < count; i++) {
            NSLayoutConstraint* constraint = [(id)constraints objectAtIndex:i];
            printConstraint(constraint);
        }
    }
}

UIView* viewForString(string target, NSDictionary* items, UIView* superview) {
    UIView* item = nil;

    if (target == "|") {
        if (!superview) {
            EbrDebugLog("No item has a superview in view map.\n");
            return nil;
        } else {
            item = superview;
        }
    } else {
        item = (UIView*)[items objectForKey:[NSString stringWithUTF8String:target.c_str()]];
    }

    if (!item) {
        EbrDebugLog("No target matching \"%s\" in map.\n", target.c_str());
    }

    return item;
}

@implementation NSLayoutConstraint

// Constraints are interleaved with predicates. There should be one more constraint than predicate.

/**
 @Status Caveat
 @Notes Layout guides are poorly implemented.
*/
+ (NSArray*)constraintsWithVisualFormat:(NSString*)format
                                options:(NSLayoutFormatOptions)opts
                                metrics:(NSDictionary*)metrics
                                  views:(NSDictionary*)views {
    UIView* superview = nil;
    NSArray* items = views.allValues;

    // It's possibly okay to have no superview if someone is adding a width constraint before adding it to its
    // superview.
    // TODO: Top and bottom superview might point to topLayoutGuide and bottomLayoutGuide
    for (int i = 0; i < [items count]; i++) {
        UIView* lSuper = [(UIView*)[items objectAtIndex:i] superview];
        if (!superview) {
            superview = lSuper;
        } else if (lSuper && lSuper != superview) {
            EbrDebugLog("All views must share the same superview.\n");
        }
    }

    string line([format UTF8String]);
    bool vertical = false;
    vector<PredicateList> predicates;
    ConstraintList constraints;

    // Match constraint direction
    // ([VH]:)
    regex vertizontalRex = regex::basic_regex("^([VH]:).*$");
    smatch vertizontalMatch;
    if (regex_match(line, vertizontalMatch, vertizontalRex)) {
        if (vertizontalMatch[0].str()[0] == 'V') {
            vertical = true;
        }
        line = line.substr(2);
    }

    // Match all "]-(1,2,3)-["
    regex connectorRex = regex::basic_regex("(\\]|\\|)([^\\[]*)?(\\[|\\|)");
    sregex_iterator connectorIt(line.begin(), line.end(), connectorRex);
    sregex_iterator end;

    while (connectorIt != end) {
        string conStr = (*connectorIt)[2].str();
#ifdef DEBUG_VISUAL_FORMAT
        EbrDebugLog("Connector: %s\n", conStr.c_str());
#endif
        if (conStr == "") {
            PredicateList predList;
            predList.push_back(Predicate());
            predicates.push_back(predList);
        } else if (conStr == "-") {
            PredicateList predList;
            predList.push_back(Predicate("default")); // Based on relationship between items.
            predicates.push_back(predList);
        } else {
            if (*conStr.begin() != '-' || *conStr.rbegin() != '-' || conStr.length() < 3) {
                EbrDebugLog("Syntax error! %s\n", conStr.c_str());
            } else {
                PredicateList predList;
                if (!parsePredicates(conStr.substr(1, conStr.length() - 2), predList)) {
                    return nil;
                }
                predicates.push_back(predList);
            }
        }
        connectorIt++;
    }

    // Match all "[one(>=two,three@4)]" or "|"
    regex constraintRex = regex::basic_regex("(\\[([^\\]]*)\\]|\\|)");
    sregex_iterator constraintIt(line.begin(), line.end(), constraintRex);
    size_t matchEnd = 0;

    if (constraintIt->position() != 0) {
        EbrDebugLog("Syntax error! %s\n", line.substr(0, constraintIt->position()).c_str());
        return nil;
    }

    while (constraintIt != end) {
        string conStr = constraintIt->str();
#ifdef DEBUG_VISUAL_FORMAT
        EbrDebugLog("Constraint: %s\n", conStr.c_str());
#endif
        regex rex = regex::basic_regex("^\\[([\\w]+)(\\(.*\\))?\\]$");
        smatch m;
        if (!regex_search(conStr, m, rex)) {
            if (conStr == "|") {
                constraints.push_back(Constraint(PredicateList(), conStr));
            } else {
                EbrDebugLog("Syntax Error! %s\n", conStr.c_str());
                return nil;
            }
        } else {
            string targStr = m[1].str();
            string predStr = m[2].str();
            PredicateList localPredicates;
#ifdef DEBUG_VISUAL_FORMAT
            EbrDebugLog("Target: %s, Predicates: %s\n", m[1].str().c_str(), predStr.c_str());
#endif
            if (targStr == "") {
                EbrDebugLog("Syntax error! No target item specified.\n");
                return nil;
            }
            if (predStr.length()) {
                if (*predStr.begin() != '(' || *predStr.rbegin() != ')' || predStr.length() < 3) {
                    EbrDebugLog("Syntax error! %s\n", predStr.c_str());
                    return nil;
                }
                if (!parsePredicates(predStr, localPredicates)) {
                    return nil;
                }
            }
            constraints.push_back(Constraint(localPredicates, targStr));
        }
        matchEnd = constraintIt->position() + constraintIt->length();
        constraintIt++;
    }

    if (matchEnd != line.length()) {
        EbrDebugLog("Syntax error! %s\n", line.substr(matchEnd).c_str());
        return nil;
    }

    // Now add all constraints
    if (predicates.size() != constraints.size() - 1) {
        EbrDebugLog("Dangling connector, ensure your format string is complete.\n");
        return nil;
    }

    if (!constraints.size()) {
        EbrDebugLog("No constraints specified in visual format.\n");
        return nil;
    }

    UIView* first = viewForString(constraints[0].target, views, superview);
    if (!first) {
        return nil;
    }

    NSArray* predAry =
        constraintsFromPredicates(constraints[0].predicates, first, nil, views, metrics, vertical, opts & NSLayoutFormatDirectionMask);

    if (!predAry) {
        return nil;
    }

    NSMutableArray* nsConstraints = [NSMutableArray new];

    [nsConstraints addObjectsFromArray:predAry];

    [predAry release];

    for (int i = 0; i < predicates.size(); i++) {
        UIView* item1 = viewForString(constraints[i].target, views, superview);
        UIView* item2 = viewForString(constraints[i + 1].target, views, superview);

        if (!item1 || !item2) {
            [nsConstraints release];
            return nil;
        }

        predAry = constraintsFromPredicates(predicates[i], item1, item2, views, metrics, vertical, opts & NSLayoutFormatDirectionMask);

        if (!predAry) {
            [nsConstraints release];
            return nil;
        }

        [nsConstraints addObjectsFromArray:predAry];

        [predAry release];

        predAry = constraintsFromPredicates(
            constraints[i + 1].predicates, item2, nil, views, metrics, vertical, opts & NSLayoutFormatDirectionMask);

        if (!predAry) {
            [nsConstraints release];
            return nil;
        }

        [nsConstraints addObjectsFromArray:predAry];

        [predAry release];
    }

    if (opts && constraints.size()) {
        switch (opts & NSLayoutFormatAlignmentMask) {
            case NSLayoutFormatAlignAllLeft:
            case NSLayoutFormatAlignAllRight:
            case NSLayoutFormatAlignAllLeading:
            case NSLayoutFormatAlignAllTrailing:
            case NSLayoutFormatAlignAllCenterX:
                if (!vertical) {
                    EbrDebugLog("Horizontal alignment option should not be specified with horizontal visual format!\n");
                    [nsConstraints release];
                    return nil;
                }
                break;
            case NSLayoutFormatAlignAllTop:
            case NSLayoutFormatAlignAllBottom:
            case NSLayoutFormatAlignAllCenterY:
            case NSLayoutFormatAlignAllBaseline:
                if (vertical) {
                    EbrDebugLog("Vertical alignment option should not be specified with vertical visual format!\n");
                    [nsConstraints release];
                    return nil;
                }
                break;
            default:
                EbrDebugLog("Unknown NSLayoutFormat option: %d\n", opts & NSLayoutFormatAlignmentMask);
                [nsConstraints release];
                return nil;
        }
        for (int i = 0; i < constraints.size() - 1; i++) {
            UIView* item1 = viewForString(constraints[i].target, views, superview);
            UIView* item2 = viewForString(constraints[i + 1].target, views, superview);

            NSLayoutConstraint* alignConst = [NSLayoutConstraint constraintWithItem:item1
                                                                          attribute:(NSLayoutAttribute)(opts & NSLayoutFormatAlignmentMask)
                                                                          relatedBy:NSLayoutRelationEqual
                                                                             toItem:item2
                                                                          attribute:(NSLayoutAttribute)(opts & NSLayoutFormatAlignmentMask)
                                                                         multiplier:1.0f
                                                                           constant:0];
            [nsConstraints addObject:alignConst];
        }
    }

    return [nsConstraints autorelease];
}

+ (instancetype)allocWithZone:(NSZone*)zone {
    NSLayoutConstraint* ret = [super allocWithZone:zone];
    ret->priv = new NSLayoutConstraintPrivateState();
    if ([ret conformsToProtocol:@protocol(AutoLayoutConstraint)]) {
        [ret autoLayoutAlloc];
    }
    return ret;
}

/**
 @Status Caveat
 @Notes First baseline and baseline layouts are poorly implemented.
*/
+ (instancetype)constraintWithItem:(id)view1
                         attribute:(NSLayoutAttribute)attr1
                         relatedBy:(NSLayoutRelation)relation
                            toItem:(id)view2
                         attribute:(NSLayoutAttribute)attr2
                        multiplier:(CGFloat)multiplier
                          constant:(CGFloat)constant {
    // TODO: Parameter and hierarchy checking
    NSLayoutConstraint* constraint = [self new];

    constraint->_firstItem = view1;
    constraint->_secondItem = view2;
    constraint->_firstAttribute = attr1;
    constraint->_secondAttribute = attr2;
    constraint->_multiplier = multiplier;
    constraint->_constant = constant;
    constraint->_relation = relation;
    constraint->_priority = NSLayoutPriorityRequired;
    return [constraint autorelease];
}

- (NSString*)description {
    // Eg, <<NSLayoutConstraint: 0x1234>: <UIView: 0x9876>-(NSLayoutAttributeTop>=NSLayoutAttributeTop*1.0+30@1000)-<_UILayoutGuide:
    // 0xABCD>>
    return [NSString stringWithFormat:@"<%@: %@-(%s%s%s*%g%+g@%g)-%@>",
                                      [super description],
                                      [self.firstItem description],
                                      constraintType(self.firstAttribute),
                                      relationType(self.relation),
                                      constraintType(self.secondAttribute),
                                      self.multiplier,
                                      self.constant,
                                      self.priority,
                                      [self.secondItem description]];
}

- (void)encodeWithCoder:(NSCoder*)coder {
    EbrDebugLog("Unsupported attempt to encode an NSLayoutConstraint\n");
}

- (NSLayoutConstraintPrivateState*)_privateState {
    return priv;
}

- (id)initWithCoder:(NSCoder*)coder {
    bool autoSpacing = false;

    _priority = NSLayoutPriorityRequired;
    _multiplier = 1.0f;
    _constant = 0;

    if ([coder containsValueForKey:@"NSPriority"]) {
        _priority = [coder decodeIntForKey:@"NSPriority"];
    }
    if ([coder containsValueForKey:@"NSFirstItem"]) {
        _firstItem = [coder decodeObjectForKey:@"NSFirstItem"];
        assert(_firstItem); // Probably missing a class implementation.
    }
    if ([coder containsValueForKey:@"NSSecondItem"]) {
        _secondItem = [coder decodeObjectForKey:@"NSSecondItem"];
    }
    if ([coder containsValueForKey:@"NSFirstAttribute"]) {
        _firstAttribute = (NSLayoutAttribute)[coder decodeIntForKey:@"NSFirstAttribute"];
    }
    if ([coder containsValueForKey:@"NSSecondAttribute"]) {
        _secondAttribute = (NSLayoutAttribute)[coder decodeIntForKey:@"NSSecondAttribute"];
    }
    if ([coder containsValueForKey:@"NSFirstAttributeV2"]) {
        NSLayoutAttribute v2 = (NSLayoutAttribute)[coder decodeIntForKey:@"NSFirstAttributeV2"];
        if (_firstAttribute != NSLayoutAttributeNotAnAttribute && _firstAttribute != v2) {
            EbrDebugLog("Overwriting attribute: %s\n", constraintType(_firstAttribute));
        }
        _firstAttribute = v2;
    }
    if ([coder containsValueForKey:@"NSSecondAttributeV2"]) {
        NSLayoutAttribute v2 = (NSLayoutAttribute)[coder decodeIntForKey:@"NSSecondAttributeV2"];
        if (_secondAttribute != NSLayoutAttributeNotAnAttribute && _secondAttribute != v2) {
            EbrDebugLog("Overwriting attribute: %s\n", constraintType(_secondAttribute));
        }
        _secondAttribute = v2;
    }

    if ([coder containsValueForKey:@"NSRelation"]) {
        _relation = (NSLayoutRelation)[coder decodeIntForKey:@"NSRelation"];
    }
    if ([coder containsValueForKey:@"NSMultiplier"]) {
        _multiplier = [coder decodeFloatForKey:@"NSMultiplier"];
    }
    if ([coder containsValueForKey:@"NSConstant"]) {
        _constant = [coder decodeFloatForKey:@"NSConstant"];
    } else if ([coder containsValueForKey:@"NSSymbolicConstant"]) {
        autoSpacing = true; // TODO: With "standard" this equals NSTR("NSSpace")...
    }

    // TODO: These V2 options need to be investigated further.
    if ([coder containsValueForKey:@"NSConstantV2"]) {
        if (autoSpacing || _constant) {
            EbrDebugLog("Overwriting constant\n");
            autoSpacing = false;
        }
        _constant = [coder decodeFloatForKey:@"NSConstantV2"];
    }

    // TODO: THIS MAY NOT WORK! The superviews may not have been set up yet!
    if (autoSpacing && _secondItem != nil && (_firstAttribute >= NSLayoutAttributeLeft && _firstAttribute <= NSLayoutAttributeTrailing)) {
        if ([_firstItem superview] == [_secondItem superview]) {
            if (_firstAttribute != _secondAttribute) {
                _constant = 8.0f;
            }
        } else {
            _constant = 20.0f;
        }
    }

    return self;
}

- (void)dealloc {
    EbrDebugLog("Deallocing NSLayoutConstraint\n");
    if ([self conformsToProtocol:@protocol(AutoLayoutConstraint)]) {
        [self autoLayoutDealloc];
    }
    delete self->priv;
    [super dealloc];
}

- (void)printConstraint {
    printConstraint(self);
}

+ (void)printConstraints:(NSArray*)constraints {
    printConstraints(constraints);
}
@end
