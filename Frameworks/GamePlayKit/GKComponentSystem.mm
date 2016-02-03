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

#import <GamePlayKit/GKComponentSystem.h>

@implementation GKComponentSystem
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithComponentClass:(Class)classObj {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addComponent:(GKComponent*)component {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addComponentWithEntity:(GKEntity*)entity {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeComponent:(GKComponent*)component {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeComponentWithEntity:(GKEntity*)entity {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateWithDeltaTime:(NSTimeInterval)seconds {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (GKComponent*)objectAtIndexedSubscript:(NSUInteger)idx {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id _Nonnull[])stackbuf count:(NSUInteger)len {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
