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

using System.Collections.Generic;
using Microsoft.ApplicationInsights;
using Microsoft.ApplicationInsights.Extensibility;

namespace BuildMonitor
{
    internal static class BuildTelemetryClient
    {
        private static TelemetryClient _telemetryClient;

        static BuildTelemetryClient()
        {
            TelemetryConfiguration.Active.TelemetryChannel.EndpointAddress = Properties.Resources.TelemetryEndpoint;
            TelemetryConfiguration.Active.InstrumentationKey = Properties.Resources.AppInsightsInstrumentationKey;
            _telemetryClient = new TelemetryClient();
        }

        public static void TrackEvent(string eventName)
        {
            _telemetryClient.TrackEvent(eventName);
        }

        public static void TrackEvent(string eventName, Dictionary<string, string> properties, Dictionary<string, double> metrics)
        {
            _telemetryClient.TrackEvent(eventName, properties, metrics);
        }

        public static void FlushEvents()
        {
            _telemetryClient.Flush();
        }
    }
}
