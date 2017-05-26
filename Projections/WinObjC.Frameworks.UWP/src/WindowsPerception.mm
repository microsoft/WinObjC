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

// WindowsPerception.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Perception.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPerception.h"
#include "WindowsPerception_priv.h"

@implementation WPPerceptionTimestamp

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::IPerceptionTimestamp> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)targetTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::IPerceptionTimestamp>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)predictionAmount {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::IPerceptionTimestamp>(self);
    THROW_NS_IF_FAILED(_comInst->get_PredictionAmount(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WPPerceptionTimestampHelper

ComPtr<ABI::Windows::Perception::IPerceptionTimestampHelperStatics> WPIPerceptionTimestampHelperStatics_inst() {
    ComPtr<ABI::Windows::Perception::IPerceptionTimestampHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Perception.PerceptionTimestampHelper").Get(),
                                                       &inst));
    return inst;
}

+ (WPPerceptionTimestamp*)fromHistoricalTargetTime:(WFDateTime*)targetTime {
    ComPtr<ABI::Windows::Perception::IPerceptionTimestamp> unmarshalledReturn;
    auto _comInst = WPIPerceptionTimestampHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromHistoricalTargetTime(*[targetTime internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPerceptionTimestamp>(unmarshalledReturn.Get());
}

@end
