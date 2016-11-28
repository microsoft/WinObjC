// ******************************************************************************
// 
//  Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// 
//  This code is licensed under the MIT License (MIT).
// 
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
// 
// ******************************************************************************

using System;
using System.IO;
using System.Reflection;
using System.Text;
using System.Xaml;
using System.Xml;

namespace Xib2Xaml
{
    internal class Program
    {
        private const string PlaceHolderClassNameToken = "<PlaceHolderClassName>";
        private const string PlaceHolderCPPFile = "xib2xaml.Resources.placeholder.xaml.cpp";
        private const string PlaceHolderHeaderFile = "xib2xaml.Resources.placeholder.xaml.h";

        private static void GenerateXAMLCodeBehindFromResource(string className, string resourceName, string destinationFileName)
        {
            if (string.IsNullOrWhiteSpace(className))
            {
                throw new ArgumentNullException(nameof(className));
            }

            using (var resource = Assembly.GetExecutingAssembly().GetManifestResourceStream(resourceName))
            {
                if (resource == null)
                {
                    throw new ArgumentException("Failed to find resource", nameof(resourceName));
                }

                // Modify the contents of the embedded resource replacing the <PlaceHolderClassNameToken> with the supplied className
                var sb = new StringBuilder();
                using (var bs = new BufferedStream(resource))
                using (var sr = new StreamReader(bs))
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        var replacedText = line.Replace(PlaceHolderClassNameToken, className);
                        sb.Append(replacedText).AppendLine();
                    }
                }

                // Create the new file with the modified contents of the embedded resource
                using (Stream outputStream = File.Create(destinationFileName))
                {
                    using (var streamWriter = new StreamWriter(outputStream))
                    {
                        streamWriter.Write(sb.ToString());
                        streamWriter.Close();
                    }
                }
            }
        }

        private static void Main(string[] args)
        {
            if (args.Length < 1)
            {
                Console.WriteLine("Usage: Xib2Xaml XibFile");
                return;
            }

            if (args.Length == 3)
            {
                XamlXibReader.WIDTH = int.Parse(args[1]);
                XamlXibReader.HEIGHT = int.Parse(args[2]);
            }

            using (var xamlReader = new XamlXibReader(args[0]))
            using (var xmlWriter = XmlWriter.Create(args[0].Replace(".xib", ".xaml"), new XmlWriterSettings {Indent = true}))
            using (var xamlWriter = new XamlXmlWriter(xmlWriter, xamlReader.SchemaContext))
            {
                XamlServices.Transform(xamlReader, xamlWriter);
            }

            // Create boilerplate code-behind files (.cpp, .h) to accompany the newly created XAML file
            var className = Path.GetFileNameWithoutExtension(args[0]);
            GenerateXAMLCodeBehindFromResource(className, PlaceHolderCPPFile, args[0].Replace(".xib", ".xaml.cpp"));
            GenerateXAMLCodeBehindFromResource(className, PlaceHolderHeaderFile, args[0].Replace(".xib", ".xaml.h"));
        }
    }
}