using System.IO;

namespace GenVersionFiles
{
    class CSHeaderFile
    {
        public CSHeaderFile(VersionInfo version)
        {
            this.version = version;
        }

        private VersionInfo version;

        public void Write(string filePath)
        {
            using (StreamWriter file = new System.IO.StreamWriter(filePath))
            {
                file.WriteLine("using System.Reflection;");
                file.WriteLine("using System.Runtime.CompilerServices;");
                file.WriteLine("using System.Runtime.InteropServices;");
                file.WriteLine();
                file.WriteLine("[assembly: AssemblyFileVersion(\"{0}.{1}.{2}.{3}\")]", version.Major, version.Minor, version.Build, version.Revision);
                file.WriteLine("[assembly: AssemblyInformationalVersion(\"{0}\")]", version.ToString());
            }
        }
    }
}
