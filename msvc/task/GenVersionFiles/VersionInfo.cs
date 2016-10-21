using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
            string fileContent = System.IO.File.ReadAllText(filePath).Trim();
            if (fileContent == String.Empty || fileContent.IndexOf('\n') != -1)
            {
                throw new System.ArgumentException("Unexpected number of lines in version file.");
            }

            string[] components = fileContent.Split('.');
            if (components.Length != 4)
            {
                throw new System.ArgumentException("Incorrect number of version components.");
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
                    throw new System.ArgumentException("The " + component + " version is invalid");
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
            return String.Format("{0}.{1}.{2:D4}.{3:D2}", Major, Minor, Revision, Build);
        }

        private enum Component
        {
            Major = 0,
            Minor = 1,
            Revision = 2,
            Build = 3
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
