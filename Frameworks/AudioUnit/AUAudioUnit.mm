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
#import <AudioUnit/AUAudioUnit.h>

@implementation AUAudioUnit
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithComponentDescription:(AudioComponentDescription)componentDescription error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();

    if (outError) {
        *outError = nil;
    }

    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithComponentDescription:(AudioComponentDescription)componentDescription
                                     options:(AudioComponentInstantiationOptions)options
                                       error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();

    if (outError) {
        *outError = nil;
    }

    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (void)instantiateWithComponentDescription:(AudioComponentDescription)componentDescription
                                    options:(AudioComponentInstantiationOptions)options
                          completionHandler:(void (^)(AUAudioUnit*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)allocateRenderResourcesAndReturnError:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();

    if (outError) {
        *outError = nil;
    }

    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)deallocateRenderResources {
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
- (NSInteger)tokenByAddingRenderObserver:(AURenderObserver)observer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeRenderObserver:(NSInteger)token {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)parametersForOverviewWithCount:(NSInteger)count {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)startHardwareAndReturnError:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();

    if (outError) {
        *outError = nil;
    }

    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopHardware {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)registerSubclass:(Class)cls
  asComponentDescription:(AudioComponentDescription)componentDescription
                    name:(NSString*)name
                 version:(UInt32)version {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)shouldChangeToFormat:(AVAudioFormat*)format forBus:(AUAudioUnitBus*)bus {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setRenderResourcesAllocated:(BOOL)flag {
    UNIMPLEMENTED();
}

@end
