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

#import <CoreText/CTFontCollection.h>
#import <StubReturn.h>

const CFStringRef kCTFontCollectionRemoveDuplicatesOption = static_cast<CFStringRef>(@"kCTFontCollectionRemoveDuplicatesOption");

/**
 @Status Stub
 @Notes
*/
CTFontCollectionRef CTFontCollectionCreateFromAvailableFonts(CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontCollectionRef CTFontCollectionCreateWithFontDescriptors(CFArrayRef queryDescriptors, CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontCollectionRef CTFontCollectionCreateCopyWithFontDescriptors(CTFontCollectionRef original,
                                                                  CFArrayRef queryDescriptors,
                                                                  CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCollectionCreateMatchingFontDescriptors(CTFontCollectionRef collection) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCollectionCreateMatchingFontDescriptorsSortedWithCallback(CTFontCollectionRef collection,
                                                                           CTFontCollectionSortDescriptorsCallback sortCallback,
                                                                           void* refCon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTFontCollectionGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
