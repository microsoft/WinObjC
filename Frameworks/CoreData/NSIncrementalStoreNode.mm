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
#import <CoreData/NSIncrementalStoreNode.h>

@implementation NSIncrementalStoreNode
/**
@Status Stub
@Notes
*/
- (instancetype)initWithObjectID:(NSManagedObjectID*)objectID withValues:(NSDictionary*)values version:(uint64_t)version {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)updateWithValues:(NSDictionary*)values version:(uint64_t)version {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (id)valueForPropertyDescription:(NSPropertyDescription*)prop {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
