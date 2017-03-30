//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <CoreText/CTFontCollection.h>
#import <StubReturn.h>

const CFStringRef kCTFontCollectionRemoveDuplicatesOption = CFSTR("kCTFontCollectionRemoveDuplicatesOption");

/**
 @Status NotInPlan
 @Notes font collection support can be added as needed.
*/
CTFontCollectionRef CTFontCollectionCreateFromAvailableFonts(CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes font collection support can be added as needed.
*/
CTFontCollectionRef CTFontCollectionCreateWithFontDescriptors(CFArrayRef queryDescriptors, CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes font collection support can be added as needed.
*/
CTFontCollectionRef CTFontCollectionCreateCopyWithFontDescriptors(CTFontCollectionRef original,
                                                                  CFArrayRef queryDescriptors,
                                                                  CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes font collection support can be added as needed.
*/
CFArrayRef CTFontCollectionCreateMatchingFontDescriptors(CTFontCollectionRef collection) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes font collection support can be added as needed.
*/
CFArrayRef CTFontCollectionCreateMatchingFontDescriptorsSortedWithCallback(CTFontCollectionRef collection,
                                                                           CTFontCollectionSortDescriptorsCallback sortCallback,
                                                                           void* refCon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes not applicable (no type)
*/
CFTypeID CTFontCollectionGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
