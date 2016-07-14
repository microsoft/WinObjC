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

using System.Xaml;
using System.Xml;

namespace XamlTools.XamlDom
{
    public static class XamlDomServices
    {
        public static XamlDomObject Load(string fileName)
        {
            return Load(fileName, new XamlSchemaContext());
        }


        public static XamlDomObject Load(string fileName, XamlSchemaContext schemaContext)
        {
            XamlDomObject rootObject = null;
            using (var xr = XmlReader.Create(fileName))
            {
                var xxrs = new XamlXmlReaderSettings();
                xxrs.ProvideLineInfo = true;
                var xxr = new XamlXmlReader(xr, schemaContext, xxrs);

                rootObject = (XamlDomObject) Load(xxr);
            }
            return rootObject;
        }

        public static XamlDomNode Load(XamlReader xxr)
        {
            var ixli = xxr as IXamlLineInfo;

            var dw = new XamlDomWriter(xxr.SchemaContext);
            XamlServices.Transform(xxr, dw);
            return dw.RootNode;
        }

        public static void Save(XamlDomObject rootObjectNode, string fileName)
        {
            var schemaContext = rootObjectNode.Type.SchemaContext;
            var dr = new XamlDomReader(rootObjectNode, schemaContext);
            var xws = new XmlWriterSettings();
            xws.Indent = true;
            using (var xw = XmlWriter.Create(fileName, xws))
            {
                var xxw = new XamlXmlWriter(xw, schemaContext);
                XamlServices.Transform(dr, xxw);
            }
        }
    }
}