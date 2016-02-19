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

#import <CoreText/CTParagraphStyle.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
CTParagraphStyleRef CTParagraphStyleCreate(const CTParagraphStyleSetting* settings, size_t settingCount) {
    UNIMPLEMENTED();
    return (CTParagraphStyleRef)[NSObject new];
}

/**
 @Status Stub
 @Notes
*/
CTParagraphStyleRef CTParagraphStyleCreateCopy(CTParagraphStyleRef paragraphStyle) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CTParagraphStyleGetValueForSpecifier(CTParagraphStyleRef paragraphStyle,
                                          CTParagraphStyleSpecifier spec,
                                          size_t valueBufferSize,
                                          void* valueBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTParagraphStyleGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
