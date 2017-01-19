using System.IO;

namespace GenVersionFiles
{
    class RCHeaderFile
    {
        public RCHeaderFile(VersionInfo version)
        {
            this.version = version;
        }

        private VersionInfo version;

        public void Write(string filePath)
        {
            using (StreamWriter file = new System.IO.StreamWriter(filePath))
            {
                file.WriteLine("#define FILE_VERSION {0}, {1}, {2}, {3}", version.Major, version.Minor, version.Build, version.Revision);
                file.WriteLine("#define FILE_VERSION_STR \"{0}\"", version.ToString());
            }
        }
    }
}
