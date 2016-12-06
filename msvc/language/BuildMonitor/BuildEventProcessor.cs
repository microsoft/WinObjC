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
using System.Globalization;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using Threading = System.Threading.Tasks;
using EnvDTE;
using Microsoft.VisualStudio.Shell;
using Microsoft.VisualStudio.Shell.Interop;

namespace BuildMonitor
{
    internal class BuildEventProcessor
    {
        #region Private Constants

        private const string WinObjCProjectType = "{66a26720-8fb5-11d2-aa7e-00c04f688dde}";

        #region Regular Expressions Patterns

        /// <summary>
        /// Match for local paths and files.
        /// </summary>
        /// <example>
        /// matches:  "C:\Path", "D:\Path\To\File3.txt", "Z:\Path\With Embedded Spaces\And In the File.name", 
        /// "c:/root/path/to/file.txt", "c:/root/path with spaces/to file/file with spaces.txt"
        /// </example>
        private const string LocalPathsPattern = @"((([a-zA-Z]:)?(/[\sa-zA-Z0-9._\-]+)+/?)|(([a-zA-Z]:)?(\{path separator}[\sa-zA-Z0-9._\-]+)+\{path separator}?))";

        /// <summary>
        /// Match for network share paths and files.
        /// </summary>
        /// <example>
        /// matches:  "\\share\path", "\\share\path wi7h embedded spaces\And In the File2.name",
        /// "//root/path/to/file", "//~", "//root/pa7h with spaces/to f1le/file with sp4ces.txt"
        /// </example>
        private const string NetworkPathsPattern = @"(/(/([\sa-zA-Z0-9_.\-~])*)+)|((\{path separator})(\{path separator}[\sa-zA-Z0-9_.\-]+)+)";

        /// <summary>
        /// Match for potocol handlers with path and file text.
        /// </summary>
        /// <example>
        /// matches:  "file://Path/To/File.name", "https://some/public/web/api23.htm"
        /// </example>
        private const string ProtocolsPattern = @"(([a-zA-Z])+://(([a-zA-Z0-9_.\-/])+)+)";

        /// <summary>
        /// Match for user ID patterns, e.g. domain and username, UNC, et alia.
        /// </summary>
        /// <example>
        /// matches:  "{user}", "domain\user", "user23@domain.tld", "userid:some-long-guid-like-string-of-text"
        /// </example>
        private const string IdentifierPattern = @"({([a-zA-Z0-9@.\-_])+})|(([a-zA-Z0-9.\-_])+\\([a-zA-Z0-9.\-_])+)|(([a-zA-Z0-9.\-_])+@([a-zA-Z0-9.\-_])+)|(user(\w){0,2}(\W){0,1}([a-zA-Z0-9.\-_])+)";

        #endregion

        #endregion Private Constants

        #region Private Members

        private DTE _dte;
        private IVsSolution _solution;
        private bool _microsoftInternalUser = false;

        // build and project members
        private Guid _currentBuildGuid;
        private Guid _firstIslandwoodProjectGuid;
        private string _solutionConfigRaw;
        private string _solutionPlatform;
        private string _solutionConfig;

        // compiled regexes
        private Regex _localPathsMatcher;
        private Regex _networkPathsMatcher;
        private Regex _protocolsMatcher;
        private Regex _identifierMatcher;

        private Stopwatch _processorStopwatch;

        #endregion Private Members
        
        /// <summary>
        /// Initializes a new instance of the <see cref="BuildMonitor"/> class.
        /// </summary>
        public BuildEventProcessor(DTE dte, IVsSolution solution, bool microsoftInternalUser)
        {
            if (dte == null)
            {
                throw new ArgumentNullException("dte");
            }

            if (solution == null)
            {
                throw new ArgumentNullException("solution");
            }

            _dte = dte;
            _solution = solution;
            _microsoftInternalUser = microsoftInternalUser;

            string pathSeparator = Path.DirectorySeparatorChar.ToString();
            _localPathsMatcher = new Regex(BuildEventProcessor.LocalPathsPattern.Replace("{path separator}", pathSeparator), RegexOptions.Compiled);
            _networkPathsMatcher = new Regex(BuildEventProcessor.NetworkPathsPattern.Replace("{path separator}", pathSeparator), RegexOptions.Compiled);
            _protocolsMatcher = new Regex(BuildEventProcessor.ProtocolsPattern, RegexOptions.Compiled);
            _identifierMatcher = new Regex(BuildEventProcessor.IdentifierPattern, RegexOptions.Compiled);

            _processorStopwatch = new Stopwatch();
        }

        #region Public Methods
        public bool HasIslandwoodProjects()
        {
            foreach (Project project in _dte.Solution.Projects)
            {
                if (project.Kind.ToString().ToLowerInvariant().Equals(BuildEventProcessor.WinObjCProjectType))
                {
                    SetBuildConfig();
                    _firstIslandwoodProjectGuid = ParseProjectGuid(project);
                    return true;
                }
            }

            return false;
        }

        public void BeginIslandWoodBuild()
        {
            Dictionary<string, string> beginBuildProperties = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            _currentBuildGuid = Guid.NewGuid();
            beginBuildProperties.Add("BuildId", _currentBuildGuid.ToString());
            beginBuildProperties.Add("ProjectId", _firstIslandwoodProjectGuid.ToString());
            beginBuildProperties.Add("IsMsftInternal", _microsoftInternalUser.ToString());
            beginBuildProperties.Add("UICulture", CultureInfo.CurrentUICulture.Name);
            beginBuildProperties.Add("WindowsLanguage", CultureInfo.CurrentUICulture.ThreeLetterWindowsLanguageName);
            beginBuildProperties.Add("IsoLanguage", CultureInfo.CurrentUICulture.ThreeLetterISOLanguageName);
            beginBuildProperties.Add("SolutionConfigRaw", _solutionConfigRaw);
            beginBuildProperties.Add("SolutionConfig", _solutionConfig);
            beginBuildProperties.Add("SolutionPlatform", _solutionPlatform);

            BuildTelemetryClient.TrackEvent("BeginIslandwoodBuild", beginBuildProperties, null);
        }

        public Threading.Task SendErrorDetails(IVsTaskList errorList)
        {
            Threading.Task processTaskListTask = new System.Threading.Tasks.Task(() =>
            {
                _processorStopwatch.Start();

                IVsEnumTaskItems taskEnum = null;
                IVsTaskItem[] oneItem = new IVsTaskItem[1];
                
                if (errorList != null)
                {
                    try { 
                        errorList.EnumTaskItems(out taskEnum);

                        if (taskEnum != null)
                        {
                            int maxItems = 10000;
                            Int32.TryParse(Properties.Resources.MaxErrorsToProcess, out maxItems);

                            taskEnum.Next(1, oneItem, null);
                            for (int i = 0; (i < maxItems) && (oneItem[0] != null); ++i)
                            {
                                ProcessTaskListItem(oneItem[0]);
                                taskEnum.Next(1, oneItem, null);
                            }
                        }
                    }
                    catch (Exception e)
                    {
                        Dictionary<string, string> exceptionDetails = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
                        exceptionDetails.Add("BuildId", _currentBuildGuid.ToString());
                        exceptionDetails.Add("ProjectId", _firstIslandwoodProjectGuid.ToString());
                        exceptionDetails.Add("Exception", e.GetType().ToString());
                        exceptionDetails.Add("Message", e.Message);
                        exceptionDetails.Add("InnerException", (e.InnerException == null ? "null" : e.InnerException.GetType().ToString()));
                        exceptionDetails.Add("InnerMessage", (e.InnerException == null ? "null" : e.InnerException.Message));
                        BuildTelemetryClient.TrackEvent("IslandwoodBuildMonitorException", exceptionDetails, null);
                    }
                    finally
                    {
                        // send all events in case the Visual Studio instance is closed or solution unloaded
                        BuildTelemetryClient.FlushEvents();
                    }
                }

                _processorStopwatch.Stop();

                Dictionary<string, string> perfProperties = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
                perfProperties.Add("BuildId", _currentBuildGuid.ToString());
                perfProperties.Add("ProjectId", _firstIslandwoodProjectGuid.ToString());

                Dictionary<string, double> perfMetrics = new Dictionary<string, double>(StringComparer.OrdinalIgnoreCase);
                perfMetrics.Add("ProcessTasks", _processorStopwatch.ElapsedMilliseconds);

                BuildTelemetryClient.TrackEvent("IslandwoodBuildMonitorPerformance", perfProperties, perfMetrics);

                // reset state in case projects/solutions are unloaded before next build
                _firstIslandwoodProjectGuid = Guid.Empty;
            });

            processTaskListTask.Start();

            return processTaskListTask;
        }

        #endregion Public Methods

        #region Private Methods
        private void ProcessTaskListItem(IVsTaskItem taskListItem)
        {
            IVsErrorItem errorTaskItem = taskListItem as IVsErrorItem;

            if (errorTaskItem != null)
            {
                uint errorCategory = 255;
                errorTaskItem.GetCategory(out errorCategory);

                // is this task an error from an Islandwood project
                if (errorCategory == (uint)TaskErrorCategory.Error ||
                    errorCategory == (uint)TaskErrorCategory.Warning)
                {
                    string sourceFile = string.Empty;
                    taskListItem.Document(out sourceFile);

                    if (string.IsNullOrEmpty(sourceFile) == false &&
                        (sourceFile.EndsWith(".m") || sourceFile.EndsWith(".mm") || sourceFile.EndsWith(".h")))
                    {

                        Dictionary<string, string> errorDetails = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
                        errorDetails.Add("BuildId", _currentBuildGuid.ToString());

                        Guid errorProjectGuid = _firstIslandwoodProjectGuid;

                        IVsHierarchy errorTaskItemHierarchy = null;
                        if (errorTaskItem.GetHierarchy(out errorTaskItemHierarchy) == 0 &&
                            errorTaskItemHierarchy != null)
                        {
                            _solution.GetGuidOfProject(errorTaskItemHierarchy, out errorProjectGuid);
                        }

                        errorDetails.Add("ProjectId", errorProjectGuid.ToString());

                        string errorCategoryText = errorCategory == 0 ? TaskErrorCategory.Error.ToString() : TaskErrorCategory.Warning.ToString();
                        errorDetails.Add("Category", errorCategoryText);

                        string rawErrorText = string.Empty;
                        taskListItem.get_Text(out rawErrorText);
                        errorDetails.Add("Description", ParseAndScrubErrorMessage(rawErrorText));

                        BuildTelemetryClient.TrackEvent("IslandwoodBuildError", errorDetails, null);
                    }
                }
            }
        }

        private Guid ParseProjectGuid(Project project)
        {
            string uniqueName = project.UniqueName;
            if (!string.IsNullOrEmpty(uniqueName))
            {
                int startProjectGuidText = uniqueName.IndexOf("{");
                if (startProjectGuidText > -1)
                {
                    int endProjectGuidText = uniqueName.IndexOf("}");
                    if (endProjectGuidText > -1)
                    {
                        Guid projectGuid = Guid.Empty;
                        Guid.TryParse(uniqueName.Substring(startProjectGuidText, (endProjectGuidText - startProjectGuidText) + 1), out projectGuid);

                        if (!projectGuid.ToString().Equals(Guid.Empty.ToString()))
                            return projectGuid;
                    }
                }

            }

            return Guid.Empty;
        }

        private string ParseAndScrubErrorMessage(string message)
        {
            if (string.IsNullOrEmpty(message) == false)
            { 
                StringBuilder scrubbedMessage = new StringBuilder(message);
                ScrubMessagePrivateInfo(scrubbedMessage, _localPathsMatcher);
                ScrubMessagePrivateInfo(scrubbedMessage, _networkPathsMatcher);
                ScrubMessagePrivateInfo(scrubbedMessage, _protocolsMatcher);
                ScrubMessagePrivateInfo(scrubbedMessage, _identifierMatcher);

                // return scrubbed message with all other information intact
                return scrubbedMessage.ToString();
            }

            // return generic error message
            return "Error message was empty or null.";
        }

        private StringBuilder ScrubMessagePrivateInfo(StringBuilder message, Regex matcher)
        {
            MatchCollection privateInfoMatches = matcher.Matches(message.ToString());
            if (privateInfoMatches.Count > 0)
            {
                foreach (Match privateInfo in privateInfoMatches)
                {
                    message.Replace(privateInfo.ToString(), "** information redacted **");
                }
            }

            return message;
        }

        private void SetBuildConfig()
        {
            for(int item = 1; item <= _dte.Solution.Properties.Count; item++)
            {
                if (_dte.Solution.Properties.Item(item).Name.Equals("ActiveConfig"))
                {
                    _solutionConfigRaw = _dte.Solution.Properties.Item(item).Value.ToString();
                    break;
                }
            }

            // split the raw configuration as it is in the format:  "Config|Platform", e.g. "Debug|Win32"
            string[] buildProps = _solutionConfigRaw.Split(new char[] { '|' }, StringSplitOptions.RemoveEmptyEntries);
            if (buildProps.Length > 0)
            {
                _solutionConfig = buildProps[0];
                if (buildProps.Length == 2)
                    _solutionPlatform = buildProps[1];
                else
                    _solutionPlatform = "No solution platform set.";
            }
            else
            {
                _solutionConfig = "No solution configuration set.";
                _solutionPlatform = "No solution platform set.";
            }
        }

        #endregion Private Methods
    }
}
