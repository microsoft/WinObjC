using System;
using System.Collections.Generic;
using System.IO;

namespace GenVersionFiles
{
    class VersionInfo
    {
        public VersionInfo()
        {
            numericVersion = new uint[4];
        }

        public void ReadFromFile(string filePath)
        {
            List<string> fileContents = new List<string>();
            foreach (string line in File.ReadLines(filePath))
            {
                int commentStart = line.IndexOf('#');
                string strippedLine = line.Substring(0, commentStart >= 0 ? commentStart : line.Length).Trim();
                if (strippedLine != String.Empty)
                {
                    fileContents.Add(strippedLine);
                }
            }

            if (fileContents.Count != 1)
            {
                throw new System.ArgumentException(String.Format("Unexpected number of lines in {0} file.", Path.GetFileName(filePath)));
            }

            string[] components = fileContents[0].Split('.');
            if (components.Length != 4)
            {
                throw new System.ArgumentException(String.Format("Incorrect number of version components in {0} file.", Path.GetFileName(filePath)));
            }

            for (int i = 0; i < 4; ++i)
            {
                Component component = (Component)i;
                try
                {
                    uint componentValue = UInt32.Parse(components[i]);
                    SetNumericComponent(component, componentValue);
                }
                catch (Exception)
                {
                    throw new System.ArgumentException(String.Format("Invalid " + component + " version component in {0} file.", Path.GetFileName(filePath)));
                }
            }
        }

        public uint Major
        {
            get { return GetNumericComponent(Component.Major); }
            set { SetNumericComponent(Component.Major, value); }
        }

        public uint Minor
        {
            get { return GetNumericComponent(Component.Minor); }
            set { SetNumericComponent(Component.Minor, value); }
        }

        public uint Revision
        {
            get { return GetNumericComponent(Component.Revision); }
            set { SetNumericComponent(Component.Revision, value); }
        }

        public uint Build
        {
            get { return GetNumericComponent(Component.Build); }
            set { SetNumericComponent(Component.Build, value); }
        }

        public override string ToString()
        {
            return String.Format("{0}.{1}.{2:D4}.{3:D2}", Major, Minor, Build, Revision);
        }

        private enum Component
        {
            Major = 0,
            Minor = 1,
            Build = 2,
            Revision = 3
        }

        private uint[] numericVersion;

        private uint GetNumericComponent(Component component)
        {
            return numericVersion[(int)component];
        }

        private void SetNumericComponent(Component component, uint value)
        {
            if (value < 0 || value > 65535)
            {
                throw new System.ArgumentException();
            }
            numericVersion[(int)component] = value;
        }
    }
}
