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
#import <CoreGraphics/CGFunction.h>

/**
 @Status Stub
 @Notes
*/
CGFunctionRef CGFunctionCreate(void* info,
                               size_t domainDimension,
                               const CGFloat* domain,
                               size_t rangeDimension,
                               const CGFloat* range,
                               const CGFunctionCallbacks* callbacks) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGFunctionRelease(CGFunctionRef function) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CGFunctionRef CGFunctionRetain(CGFunctionRef function) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGFunctionGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
