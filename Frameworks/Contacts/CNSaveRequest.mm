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

#import <Contacts/CNSaveRequest.h>
#import <StubReturn.h>

@implementation CNSaveRequest
/**
 @Status Stub
 @Notes
*/
- (void)addContact:(CNMutableContact*)contact toContainerWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateContact:(CNMutableContact*)contact {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteContact:(CNMutableContact*)contact {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addGroup:(CNMutableGroup*)group toContainerWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateGroup:(CNMutableGroup*)group {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteGroup:(CNMutableGroup*)group {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addMember:(CNContact*)contact toGroup:(CNGroup*)group {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeMember:(CNContact*)contact fromGroup:(CNGroup*)group {
    UNIMPLEMENTED();
}

@end
