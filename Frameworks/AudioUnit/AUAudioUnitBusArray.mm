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
#import <AudioUnit/AUAudioUnitBusArray.h>

@implementation AUAudioUnitBusArray
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithAudioUnit:(AUAudioUnit*)owner busType:(AUAudioUnitBusType)busType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithAudioUnit:(AUAudioUnit*)owner busType:(AUAudioUnitBusType)busType busses:(NSArray*)busArray {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (AUAudioUnitBus*)objectAtIndexedSubscript:(NSUInteger)index {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)setBusCount:(NSUInteger)count error:(NSError* _Nullable*)outError {
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
- (void)addObserverToAllBusses:(NSObject*)observer
                    forKeyPath:(NSString*)keyPath
                       options:(NSKeyValueObservingOptions)options
                       context:(void*)context {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObserverFromAllBusses:(NSObject*)observer forKeyPath:(NSString*)keyPath context:(void*)context {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)replaceBusses:(NSArray*)busArray {
    UNIMPLEMENTED();
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
