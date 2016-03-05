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
#import <CoreGraphics/CGShading.h>

/**
 @Status Stub
 @Notes
*/
CGShadingRef CGShadingCreateAxial(
    CGColorSpaceRef space, CGPoint start, CGPoint end, CGFunctionRef function, bool extendStart, bool extendEnd) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGShadingRef CGShadingCreateRadial(CGColorSpaceRef space,
                                   CGPoint start,
                                   CGFloat startRadius,
                                   CGPoint end,
                                   CGFloat endRadius,
                                   CGFunctionRef function,
                                   bool extendStart,
                                   bool extendEnd) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGShadingRef CGShadingRetain(CGShadingRef shading) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGShadingRelease(CGShadingRef shading) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGShadingGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
