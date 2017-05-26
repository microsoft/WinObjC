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

// WindowsPhoneApplicationModel.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.ApplicationModel.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneApplicationModel.h"
#include "WindowsPhoneApplicationModel_priv.h"

@implementation WPAApplicationProfile

ComPtr<ABI::Windows::Phone::ApplicationModel::IApplicationProfileStatics> WPAIApplicationProfileStatics_inst() {
    ComPtr<ABI::Windows::Phone::ApplicationModel::IApplicationProfileStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.ApplicationModel.ApplicationProfile").Get(),
                                                       &inst));
    return inst;
}

+ (WPAApplicationProfileModes)modes {
    ABI::Windows::Phone::ApplicationModel::ApplicationProfileModes unmarshalledReturn;
    auto _comInst = WPAIApplicationProfileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Modes(&unmarshalledReturn));
    return (WPAApplicationProfileModes)unmarshalledReturn;
}

@end
