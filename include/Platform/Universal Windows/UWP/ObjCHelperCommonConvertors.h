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

#pragma once

#include "RTHelpers.h"
#import <Foundation/Foundation.h>

namespace CommonConvertors {
    OBJCWINRT_EXPORT_FN
        Microsoft::WRL::ComPtr<IInspectable> convertNSDictionaryToPropertySet(id obj);
    OBJCWINRT_EXPORT_FN
        Microsoft::WRL::ComPtr<IInspectable> convertNSErrorToPropertySet(id obj);
    OBJCWINRT_EXPORT_FN
        id convertPropertySetToNSDictionary(Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IMapView<HSTRING, IInspectable*>> ip);
    OBJCWINRT_EXPORT_FN
        ComPtr<ABI::Windows::Foundation::IPropertyValueStatics> propertyValueCreator();

    // NSDate to IPropertyValue for DateTime.
    OBJCWINRT_EXPORT_FN
        ABI::Windows::Foundation::DateTime convertNSDateToWinRT(NSDate* obj);

    // IReference<DateTime> to NSDate
    OBJCWINRT_EXPORT_FN
        NSDate* convertWinRTToNSDate(ABI::Windows::Foundation::DateTime dt);

    // NSURL Convertors
    OBJCWINRT_EXPORT_FN
        ComPtr<ABI::Windows::Storage::IStorageFile> convertNSURLToWinRTStorageFile(NSURL* obj);
    OBJCWINRT_EXPORT_FN
        ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> convertNSURLToWinRTUri(NSURL* obj);
    OBJCWINRT_EXPORT_FN
        NSURL* convertWinRTStorageFileToNSURL(const ComPtr<ABI::Windows::Storage::IStorageFile> storageFile);
    OBJCWINRT_EXPORT_FN
        NSURL* convertWinRTUriToNSURL(const ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> uri);
    OBJCWINRT_EXPORT_FN
        ComPtr<IInspectable> convertNSNumberToPropertyValue(NSNumber* obj);
    OBJCWINRT_EXPORT_FN
        ComPtr<IInspectable> convertNSStringToPropertyValue(NSString* obj);
}
