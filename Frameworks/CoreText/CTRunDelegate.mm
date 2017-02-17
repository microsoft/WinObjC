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

#import <CoreText/CTRunDelegate.h>
#import <StubReturn.h>

/**
 @Status NotInPlan
 @Notes run delegates cannot be supported easily with dwrite
*/
CTRunDelegateRef CTRunDelegateCreate(const CTRunDelegateCallbacks* callbacks, void* refCon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes run delegates cannot be supported easliy with dwrite
*/
void* CTRunDelegateGetRefCon(CTRunDelegateRef runDelegate) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes this would require us to move to using bridged type implementation, seems of little value at this point
*/
CFTypeID CTRunDelegateGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
