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

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Runtime.InteropServices;
using Threading = System.Threading.Tasks;
using EnvDTE;
using Microsoft.VisualStudio.Shell;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.Win32;

namespace BuildMonitor
{
    /// <summary>
    /// This is the class that implements the package exposed by this assembly.
    /// </summary>
    /// <remarks>
    /// <para>
    /// The minimum requirement for a class to be considered a valid package for Visual Studio
    /// is to implement the IVsPackage interface and register itself with the shell.
    /// This package uses the helper classes defined inside the Managed Package Framework (MPF)
    /// to do it: it derives from the Package class that provides the implementation of the
    /// IVsPackage interface and uses the registration attributes defined in the framework to
    /// register itself and its components with the shell. These attributes tell the pkgdef creation
    /// utility what data to put into .pkgdef file.
    /// </para>
    /// <para>
    /// To get loaded into VS, the package must be referred by &lt;Asset Type="Microsoft.VisualStudio.VsPackage" ...&gt; in .vsixmanifest file.
    /// </para>
    /// </remarks>
    [PackageRegistration(UseManagedResourcesOnly = true)]
    [Guid(BuildMonitor.PackageGuidString)]
    [SuppressMessage("StyleCop.CSharp.DocumentationRules", "SA1650:ElementDocumentationMustBeSpelledCorrectly", Justification = "pkgdef, VS and vsixmanifest are valid VS terms")]
    [ProvideAutoLoad(UIContextGuids80.SolutionExists)]
    public sealed class BuildMonitor : Package
    {
        #region Constants

        /// <summary>
        /// BuildMonitor GUID string.
        /// </summary>
        public const string PackageGuidString = "fad1be88-3546-4da2-aa6c-fb694819a313";

        private const string VS14OptInRegKey = @"HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\VSCommon\14.0\SQM";
        private const string VS15OptInRegKey = @"HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\VSCommon\15.0\SQM";
        private const string OptInRegValue = "OptIn";
        private const string MsftInternalRegKey = @"HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\SQMClient";
        private const string MsftInternalRegValue = "MSFTInternal";

        #endregion Constants

        #region Private Members
        
        private BuildEvents _buildEvents;

        private BuildEventProcessor _eventProcessor;

        #endregion Private Members

        /// <summary>
        /// Initializes a new instance of the <see cref="BuildMonitor"/> class.
        /// </summary>
        public BuildMonitor()
        { }

        #region VSPackage Members

        /// <summary>
        /// Initialization of the package; this method is called right after the package is sited, so this is the place
        /// where you can put all the initialization code that rely on services provided by VisualStudio.
        /// </summary>
        protected override void Initialize()
        {
            base.Initialize();

            try
            {
                string localOptInRegKeyVsCurrent = VS14OptInRegKey;
                string localOptInRegKeyVsNext = VS15OptInRegKey;

                // modify the registry key path to account for OS architecture
                if (Environment.Is64BitOperatingSystem == false)
                {
                    localOptInRegKeyVsCurrent = localOptInRegKeyVsCurrent.Replace(@"\WOW6432Node", string.Empty);
                    localOptInRegKeyVsNext = localOptInRegKeyVsNext.Replace(@"\WOW6432Node", string.Empty);
                }

                // check registry for opt in accounting for null values if key doesn't exist
                int? vsCurrentOptIn = (int?)Registry.GetValue(localOptInRegKeyVsCurrent, OptInRegValue, 0);
                int? vsNextOptIn = (int?)Registry.GetValue(localOptInRegKeyVsNext, OptInRegValue, 0);
                int? userOptedIn = vsCurrentOptIn.GetValueOrDefault() + vsNextOptIn.GetValueOrDefault();

                int? microsoftInternalUser = (int?)Registry.GetValue(BuildMonitor.MsftInternalRegKey, BuildMonitor.MsftInternalRegValue, 0);
                microsoftInternalUser = microsoftInternalUser.GetValueOrDefault();

                if (!(userOptedIn == 0 && microsoftInternalUser == 0))
                {
                    DTE dte = GetService(typeof(SDTE)) as DTE;
                    if (dte == null)
                    {
                        throw new InvalidOperationException("No Visual Studio Desktop Environment service (SDTE) available!");
                    }

                    _buildEvents = dte.Events.BuildEvents;
                    _buildEvents.OnBuildBegin += ProcessBuildBeginEvents;
                    _buildEvents.OnBuildDone += ProcessBuildDoneEvents;

                    IVsSolution solution = (IVsSolution)GetService(typeof(SVsSolution));
                    if (solution == null)
                    {
                        throw new InvalidOperationException("No Visual Studio Solution service (SVsSolution) available!");
                    }

                    _eventProcessor = new BuildEventProcessor(dte, solution, (microsoftInternalUser != 0));
                }
            }
            catch { }
        }

        protected override int QueryClose(out bool canClose)
        {
            return base.QueryClose(out canClose);
        }

        #endregion

        #region Build Event Handlers

        private void ProcessBuildBeginEvents(vsBuildScope scope, vsBuildAction action)
        {
            if (_eventProcessor.HasIslandwoodProjects())
            {
                _eventProcessor.BeginIslandWoodBuild();
            }
        }

        private void ProcessBuildDoneEvents(vsBuildScope scope, vsBuildAction action)
        {
            if (_eventProcessor.HasIslandwoodProjects())
            {
                IVsTaskList errorList = GetService(typeof(SVsErrorList)) as IVsTaskList;

                _eventProcessor.SendErrorDetails(errorList);
            }
        }

        #endregion
    }
}
