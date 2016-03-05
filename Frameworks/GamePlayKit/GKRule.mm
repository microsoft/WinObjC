//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <StubReturn.h>

#import <GamePlayKit/GKRule.h>

@implementation GKRule
/**
 @Status Stub
 @Notes
*/
+ (instancetype)ruleWithPredicate:(NSPredicate*)pred assertingFact:(id<NSObject>)fact grade:(float)grade {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)ruleWithPredicate:(NSPredicate*)pred retractingFact:(id<NSObject>)fact grade:(float)grade {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)ruleWithBlockPredicate:(BOOL (^)(GKRuleSystem*))pred action:(void (^)(GKRuleSystem*))action {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)evaluatePredicateWithSystem:(GKRuleSystem*)sys {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)performActionWithSystem:(GKRuleSystem*)sys {
    UNIMPLEMENTED();
}

@end
