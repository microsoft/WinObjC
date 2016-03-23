//******************************************************************************
//
// Copyright (c) 2016, Intel Corporation.
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


// Calling into C++/CX to determine if the default accelerometer device is available
// This step is necessary for now as this call using projections [WDSAccelerometer getDefault] does not return NULL
// as expected for the case where no accelerometer device is available.
bool checkDefaultAccelerometer() {
    auto accelerometer = Windows::Devices::Sensors::Accelerometer::GetDefault();

    if (accelerometer) {
        return true;
    } else {
        return false;
    }
}