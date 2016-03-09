//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <TestFramework.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <UTTypeInternalMap.h>

TEST(MobileCoreServices, MobileCoreServices_UTTypeCreatePreferredIdentifierForTag) {
    LOG_INFO("MobileCoreServices UTTypeCreatePreferredIdentifierForTag test: ");

    //
    // kUTTagClassFilenameExtension tag tests.
    //

    // Query for a valid file name extension.
    CFStringRef UTIIsValidForFileExtension =
        UTTypeCreatePreferredIdentifierForTag(kUTTagClassFilenameExtension, static_cast<CFStringRef>(@".dll"), NULL);
    ASSERT_OBJCEQ_MSG(@"com.microsoft.windows-​dynamic-link-library",
                      static_cast<NSString*>(UTIIsValidForFileExtension),
                      "Expected a valid UTI for file extension '.dll'!");

    // Query for an invalid file name extension.
    CFStringRef UTIIsNullForFileExtension =
        UTTypeCreatePreferredIdentifierForTag(kUTTagClassFilenameExtension, static_cast<CFStringRef>(@".12345"), NULL);
    EXPECT_TRUE_MSG((UTIIsNullForFileExtension == NULL), "Did not expect a valid UTI for file extension '.12345'!");

    //
    // kUTTagClassMIMEType tag tests.
    //

    // Query for a valid MIME type.
    CFStringRef UTIIsValidForMimeType =
        UTTypeCreatePreferredIdentifierForTag(kUTTagClassMIMEType, static_cast<CFStringRef>(@"video/x-mpeg"), NULL);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(kUTTypeMPEG),
                      static_cast<NSString*>(UTIIsValidForMimeType),
                      "Expected a valid UTI for MIME 'video/x-mpeg'!");

    // Query for an invalid MIME type.
    CFStringRef UTIIsNullForMimeType =
        UTTypeCreatePreferredIdentifierForTag(kUTTagClassFilenameExtension, static_cast<CFStringRef>(@"ABC/DEF"), NULL);
    EXPECT_TRUE_MSG((UTIIsNullForMimeType == NULL), "Did not expect a valid UTI for MIME 'ABC/DEF'!");

    //
    // Invalid tag tests.
    //

    // Query for an invalid tag.
    CFStringRef UTIIsNullForInvalidTag =
        UTTypeCreatePreferredIdentifierForTag(static_cast<CFStringRef>(@"XYZ"), static_cast<CFStringRef>(@".html"), NULL);
    EXPECT_TRUE_MSG((UTIIsNullForInvalidTag == NULL), "Did not expect a valid UTI for tag 'XYZ'!");
}

TEST(MobileCoreServices, MobileCoreServices_UTTypeCreateAllIdentifiersForTag) {
    LOG_INFO("MobileCoreServices UTTypeCreateAllIdentifiersForTag test: ");

    //
    // kUTTagClassFilenameExtension tag tests.
    //

    // Query for a valid file name extension.
    CFArrayRef UTIsValidForFileExtension =
        UTTypeCreateAllIdentifiersForTag(kUTTagClassFilenameExtension, static_cast<CFStringRef>(@".aiff"), NULL);
    CFIndex UTICountForFileExtension = CFArrayGetCount(UTIsValidForFileExtension);
    EXPECT_TRUE_MSG((UTICountForFileExtension == 2), "Expected to get two UTIs mapped to '.aiff' file extension!");

    // Note for the below checks to pass the order in the static map in UTType+InternalMap.mm is important.
    ASSERT_OBJCEQ_MSG(@"public.aifc-audio",
                      static_cast<NSString*>(const_cast<void*>(CFArrayGetValueAtIndex(UTIsValidForFileExtension, 0))),
                      "Expected the obtained UTI from index 0 to match!");
    ASSERT_OBJCEQ_MSG(@"public.aiff-audio",
                      static_cast<NSString*>(const_cast<void*>(CFArrayGetValueAtIndex(UTIsValidForFileExtension, 1))),
                      "Expected the obtained UTI from index 1 to match!");

    // Query for an invalid file name extension.
    CFArrayRef UTIsIsNullForFileExtension =
        UTTypeCreateAllIdentifiersForTag(kUTTagClassFilenameExtension, static_cast<CFStringRef>(@".ABCXYZ"), NULL);
    EXPECT_TRUE_MSG((UTIsIsNullForFileExtension == NULL), "Did not expect valid UTIs for file extension '.ABCXYZ'!");

    //
    // kUTTagClassMIMEType tag tests.
    //

    // Query for a valid MIME type.
    CFArrayRef UTIsIsValidForMimeType =
        UTTypeCreateAllIdentifiersForTag(kUTTagClassMIMEType, static_cast<CFStringRef>(@"image/x-quicktime"), NULL);
    CFIndex UTICountForMimeType = CFArrayGetCount(UTIsIsValidForMimeType);
    EXPECT_TRUE_MSG((UTICountForMimeType == 2), "Expected to get two UTIs mapped to 'image/x-quicktime' MIME type!");

    // Note for the below checks to pass the order in the static map in UTType+InternalMap.mm is important.
    ASSERT_OBJCEQ_MSG(@"public.xbitmap-image",
                      static_cast<NSString*>(const_cast<void*>(CFArrayGetValueAtIndex(UTIsIsValidForMimeType, 0))),
                      "Expected the obtained UTI from index 0 to match!");
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(kUTTypeQuickTimeImage),
                      static_cast<NSString*>(const_cast<void*>(CFArrayGetValueAtIndex(UTIsIsValidForMimeType, 1))),
                      "Expected the obtained UTI from index 1 to match!");

    // Query for an invalid MIME type.
    CFArrayRef UTIsIsNullForMimeType =
        UTTypeCreateAllIdentifiersForTag(kUTTagClassFilenameExtension, static_cast<CFStringRef>(@"123/789"), NULL);
    EXPECT_TRUE_MSG((UTIsIsNullForMimeType == NULL), "Did not expect a valid UTI for MIME '123/789'!");

    //
    // Invalid tag tests.
    //

    // Query for an invalid tag.
    CFArrayRef UTIIsNullForInvalidTag =
        UTTypeCreateAllIdentifiersForTag(static_cast<CFStringRef>(@"555"), static_cast<CFStringRef>(@"A1B2/C3D4E5"), NULL);
    EXPECT_TRUE_MSG((UTIIsNullForInvalidTag == NULL), "Did not expect a valid UTI for tag 'A1B2/C3D4E5'!");
}

TEST(MobileCoreServices, MobileCoreServices_UTTypeCopyPreferredTagWithClass) {
    LOG_INFO("MobileCoreServices UTTypeCopyPreferredTagWithClass test: ");

    //
    // kUTTagClassFilenameExtension tag tests.
    //

    // Query for a valid file name extension.
    CFStringRef validFileExtension = UTTypeCopyPreferredTagWithClass(kUTTypeJPEG, kUTTagClassFilenameExtension);
    // Note only the first matching value from the map (vector) in UTType+InternalMap.mm will be returned.
    ASSERT_OBJCEQ_MSG(@".jpg", static_cast<NSString*>(validFileExtension), "Expected a valid UTI for UTI '@kUTTypeJPEG'!");

    // Query for a invalid file name extension.
    CFStringRef inValidFileExtension = UTTypeCopyPreferredTagWithClass(static_cast<CFStringRef>(@"MY-123"), kUTTagClassFilenameExtension);
    EXPECT_TRUE_MSG((inValidFileExtension == NULL), "Did not expect valid UTIs for my tag 'MyTag-123'!");

    //
    // kUTTagClassMIMEType tag tests.
    //

    // Query for a valid MIME type.
    CFStringRef validMIMEType = UTTypeCopyPreferredTagWithClass(static_cast<CFStringRef>(@"public.php-script"), kUTTagClassMIMEType);
    // Note only the first matching value from the map (vector) in UTType+InternalMap.mm will be returned.
    ASSERT_OBJCEQ_MSG(@"text/x-php-script", static_cast<NSString*>(validMIMEType), "Expected a valid UTI for UTI 'public.php-script'!");

    // Query for a invalid file name extension.
    CFStringRef inValidMimeType = UTTypeCopyPreferredTagWithClass(static_cast<CFStringRef>(@"XYZ-UTI"), kUTTagClassFilenameExtension);
    EXPECT_TRUE_MSG((inValidMimeType == NULL), "Did not expect valid UTIs for my tag 'XYZ-UTI'!");

    //
    // Invalid tag tests.
    //
    // Query for a invalid tag.
    CFStringRef inValidTag = UTTypeCopyPreferredTagWithClass(kUTTypeXML, static_cast<CFStringRef>(@"MyTag"));
    EXPECT_TRUE_MSG((inValidTag == NULL), "Did not expect valid UTIs for my tag 'MyTag'!");
}

TEST(MobileCoreServices, MobileCoreServices_UTTypeEqual) {
    LOG_INFO("MobileCoreServices UTTypeEqual test: ");

    //
    // Note: The test does not verify conformance as that is not supported today.
    //

    EXPECT_TRUE_MSG(UTTypeEqual(kUTTypeMPEG4, kUTTypeMPEG4), "Expected UTTypeEqual to return true!");
    EXPECT_FALSE_MSG(UTTypeEqual(kUTTypeRTF, kUTTypeQuickTimeMovie), "Expected UTTypeEqual to return false!");
}

TEST(MobileCoreServices, MobileCoreServices_UTTypeConformsTo) {
    LOG_INFO("MobileCoreServices UTTypeConformsTo test: ");

    //
    // Note: The test only very equals as conformance is not supported today.
    //

    EXPECT_TRUE_MSG(UTTypeEqual(kUTTypePNG, kUTTypePNG), "Expected UTTypeConformsTo to return true!");
    EXPECT_FALSE_MSG(UTTypeEqual(kUTTypeHTML, kUTTypePlainText), "Expected UTTypeConformsTo to return false!");
}

TEST(MobileCoreServices, MobileCoreServices_ValidateAPIUsage) {
    LOG_INFO("MobileCoreServices API usage test: ");

    // Query for a valid file name extension.
    CFStringRef UTI = UTTypeCreatePreferredIdentifierForTag(kUTTagClassFilenameExtension, static_cast<CFStringRef>(@".ph4"), NULL);
    // Query for MIME type for the obtained UTI.
    CFStringRef MIMEType = UTTypeCopyPreferredTagWithClass(UTI, kUTTagClassMIMEType);
    // Verify we got the expected result.
    ASSERT_OBJCEQ_MSG(@"text/x-php-script", static_cast<NSString*>(MIMEType), "Expected a valid UTI for file extension '.ph4'!");
}