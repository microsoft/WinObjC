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
#import <AudioUnit/AUParameterTree.h>

@implementation AUParameterTree
/**
 @Status Stub
 @Notes
*/
- (AUParameter*)parameterWithAddress:(AUParameterAddress)address {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (AUParameter*)parameterWithID:(AudioUnitParameterID)paramID scope:(AudioUnitScope)scope element:(AudioUnitElement)element {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (AUParameter*)createParameterWithIdentifier:(NSString*)identifier
                                         name:(NSString*)name
                                      address:(AUParameterAddress)address
                                          min:(AUValue)min
                                          max:(AUValue)max
                                         unit:(AudioUnitParameterUnit)unit
                                     unitName:(NSString*)unitName
                                        flags:(AudioUnitParameterOptions)flags
                                 valueStrings:(NSArray*)valueStrings
                          dependentParameters:(NSArray*)dependentParameters {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (AUParameterGroup*)createGroupWithIdentifier:(NSString*)identifier name:(NSString*)name children:(NSArray*)children {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (AUParameterGroup*)createGroupTemplate:(NSArray*)children {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (AUParameterGroup*)createGroupFromTemplate:(AUParameterGroup*)templateGroup
                                  identifier:(NSString*)identifier
                                        name:(NSString*)name
                               addressOffset:(AUParameterAddress)addressOffset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (AUParameterTree*)createTreeWithChildren:(NSArray*)children {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
