//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

using namespace Windows::Phone::Devices::Notification;
using namespace Windows::Foundation;

void vibrate() {

    // This check is needed as an exception is thrown by the GetDefault() method  
    // on devices without vibration hardware.
    if (Metadata::ApiInformation::IsTypePresent("Windows.Phone.Devices.Notification.VibrationDevice")) {
        auto vibrationDevice = VibrationDevice::GetDefault();

        if (vibrationDevice) {

            // Vibration duration set as 0.5 second. The unit is 100-nanoseconds. 
            TimeSpan vibrationDuration = { 5000000 };

            vibrationDevice->Vibrate(vibrationDuration);
        }
    }
}
