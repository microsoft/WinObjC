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

#import <GamePlayKit/GKRuleSystem.h>

@implementation GKRuleSystem
/**
 @Status Stub
 @Notes
*/
- (instancetype)init {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addRule:(GKRule*)rule {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addRulesFromArray:(NSArray*)rules {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllRules {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)evaluate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)reset {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)assertFact:(id<NSObject>)fact {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)assertFact:(id<NSObject>)fact grade:(float)grade {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)retractFact:(id<NSObject>)fact {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)retractFact:(id<NSObject>)fact grade:(float)grade {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (float)gradeForFact:(id<NSObject>)fact {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (float)minimumGradeForFacts:(NSArray*)facts {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (float)maximumGradeForFacts:(NSArray*)facts {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
