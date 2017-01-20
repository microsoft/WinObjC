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
using Microsoft.Win32;
using System;

namespace BuildMonitor
{
    internal static class BuildTelemetryClient
    {
        private const string SqmClientRegKey = @"SOFTWARE\Microsoft\SQMClient";
        private const string SqmMachineIdRegValue = "MachineId";

        private static TelemetryClient _telemetryClient;
        private static string _machineId;

        static BuildTelemetryClient()
        {
            TelemetryConfiguration.Active.TelemetryChannel.EndpointAddress = Properties.Resources.TelemetryEndpoint;
            TelemetryConfiguration.Active.InstrumentationKey = Properties.Resources.AppInsightsInstrumentationKey;
            _telemetryClient = new TelemetryClient();

            try
            {
                /* 
                 * Explicitly open the registry as 64-bit so the values under SQMClient show up on 64-bit OS.
                 * On 32-bit OS this will not have any effect and the values under SQMClient will show up.
                 */
                RegistryKey sqmClientKey = RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64);
                sqmClientKey = sqmClientKey.OpenSubKey(SqmClientRegKey, false);
                if (sqmClientKey != null)
                {
                    string machineId = (string)sqmClientKey.GetValue(SqmMachineIdRegValue, string.Empty);
                    if (!string.IsNullOrEmpty(machineId))
                    {
                        Guid parsedMachineId = Guid.Empty;
                        Guid.TryParse(machineId, out parsedMachineId);
                        _machineId = parsedMachineId.ToString();
                    }
                }
                else
                {
                    _machineId = Guid.Empty.ToString();
                }
            }
            catch (Exception)
            {
                _machineId = Guid.Empty.ToString();
            }
        }

        public static void TrackEvent(string eventName)
        {
            _telemetryClient.TrackEvent(eventName);
        }

        public static void TrackEvent(string eventName, Dictionary<string, string> properties, Dictionary<string, double> metrics)
        {
            if(properties == null)
            {
                properties = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
                properties.Add("MachineId", _machineId);
            }
            else if (!properties.ContainsKey("machineid"))
            {
                properties.Add("MachineId", _machineId);
            }

            _telemetryClient.TrackEvent(eventName, properties, metrics);
        }

        public static void FlushEvents()
        {
            _telemetryClient.Flush();
        }
    }
}
