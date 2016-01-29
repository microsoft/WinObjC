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
#import <CoreData/NSMergePolicy.h>

/** @Status Stub */
const id NSErrorMergePolicy = StubConstant();

/** @Status Stub */
const id NSMergeByPropertyStoreTrumpMergePolicy = StubConstant();

/** @Status Stub */
const id NSMergeByPropertyObjectTrumpMergePolicy = StubConstant();

/** @Status Stub */
const id NSOverwriteMergePolicy = StubConstant();

/** @Status Stub */
const id NSRollbackMergePolicy = StubConstant();

@implementation NSMergePolicy
/**
@Status Stub
@Notes
*/
- (id)initWithMergeType:(NSMergePolicyType)ty {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)resolveConflicts:(NSArray*)list error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
