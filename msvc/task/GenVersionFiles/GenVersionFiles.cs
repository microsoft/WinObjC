using System;
using System.IO;
using Microsoft.Build.Utilities;
using Microsoft.Build.Framework;

namespace GenVersionFiles
{
    public class GenVersionFiles : Task
    {
        [Required]
        public string VersionFile { get; set; }

        [Required]
        public string SharedHeaderFile { get; set; }

        void LogError(string message, params object[] list)
        {
            if (BuildEngine4 != null)
            {
                Log.LogError(message, list);
            }
        }

        public override bool Execute()
        {
            try
            {
                VersionInfo version = new VersionInfo();
                version.ReadFromFile(VersionFile);

                string fileExt = Path.GetExtension(SharedHeaderFile);
                if (fileExt == ".cs")
                {
                    CSHeaderFile csHeader = new CSHeaderFile(version);
                    csHeader.Write(SharedHeaderFile);
                }
                else if (fileExt == ".h")
                {
                    RCHeaderFile rcHeader = new RCHeaderFile(version);
                    rcHeader.Write(SharedHeaderFile);
                }
                else
                {
                    throw new ArgumentException("Unrecognized SharedHeaderFile type.");
                }

                return true;
            }
            catch (Exception e)
            {
                LogError(e.Message);
                return false;
            }
        }
    }
}
