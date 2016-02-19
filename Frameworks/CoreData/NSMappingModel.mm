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
#import <CoreData/NSMappingModel.h>

@implementation NSMappingModel
/**
@Status Stub
@Notes
*/
+ (NSMappingModel*)mappingModelFromBundles:(NSArray*)bundles
                            forSourceModel:(NSManagedObjectModel*)sourceModel
                          destinationModel:(NSManagedObjectModel*)destinationModel {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSMappingModel*)inferredMappingModelForSourceModel:(NSManagedObjectModel*)source
                                     destinationModel:(NSManagedObjectModel*)destination
                                                error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
