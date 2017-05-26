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

// WindowsGlobalizationCollation.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Globalization.Collation.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGlobalizationCollation.h"
#include "WindowsGlobalizationCollation_priv.h"

@implementation WGCCharacterGrouping

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::Collation::ICharacterGrouping> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)first {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Collation::ICharacterGrouping>(self);
    THROW_NS_IF_FAILED(_comInst->get_First(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Collation::ICharacterGrouping>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGCCharacterGroupings {
    RTArrayObj<ABI::Windows::Globalization::Collation::ICharacterGrouping*,
               IVectorView<ABI::Windows::Globalization::Collation::CharacterGrouping*>,
               WGCCharacterGrouping,
               ABI::Windows::Globalization::Collation::CharacterGrouping*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             WGCCharacterGrouping,
                             ABI::Windows::Globalization::Collation::ICharacterGrouping*,
                             ABI::Windows::Globalization::Collation::CharacterGrouping*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::Collation::ICharacterGroupings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Globalization.Collation.CharacterGroupings").Get(), &out));
    return [_createRtProxy<WGCCharacterGroupings>(out.Get()) retain];
}

- (NSString*)lookup:(NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Collation::ICharacterGroupings>(self);
    THROW_NS_IF_FAILED(_comInst->Lookup(nsStrToHstr(text).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end
