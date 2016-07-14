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
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Windows.Controls;
using System.Windows.Media;
using System.Xaml;
using System.Xml.Linq;
using XamlTools.XamlDom;
using Xib2Xaml.Handlers;

namespace Xib2Xaml
{
    public class XamlLegacyXibReader : XamlReader
    {
        internal const int IPHONE_WIDTH = 320;
        internal const int IPHONE_HEIGHT = 460;

        internal static int WIDTH = 480;
        internal static int HEIGHT = 800;

        private readonly XamlReader _underlyingReader;
        private XDocument _document;

        public XamlLegacyXibReader(string file)
        {
            IdToObjectMap = new Dictionary<string, XamlDomObject>();

            var objectNode = CreateXamlDom(XDocument.Load(file));
            var processor = new PostProcessor(objectNode);
            objectNode = processor.Process();

            _underlyingReader = new XamlDomReader(objectNode, objectNode.SchemaContext);
        }

        internal static double WIDTHMULTIPLIER
        {
            get { return (double) WIDTH/IPHONE_WIDTH; }
        }

        internal static double HEIGHTMULTIPLIER
        {
            get { return (double) HEIGHT/IPHONE_HEIGHT; }
        }

        internal static Dictionary<string, XamlDomObject> IdToObjectMap { get; set; }

        private XamlDomObject CreateXamlDom(XDocument xDocument)
        {
            _document = xDocument;
            var schemaContext = new XamlSchemaContext();

            var rootObjectsTag = GetElementWithMatchingAttribute(xDocument.Root.Element(XName.Get("data")), "key", "IBDocument.RootObjects");
            var windowTag = GetElementWithMatchingAttribute(rootObjectsTag, "class", "IBUIWindow");

            XamlDomObject rootDomObject;
            if (windowTag != null)
            {
                rootDomObject = ViewHandler.CreateObject(windowTag, schemaContext)[0];
            }
            else // No window so there's one or more views
            {
                rootDomObject = new XamlDomObject(schemaContext.GetXamlType(typeof(UserControl)));
                var canvas = new XamlDomObject(schemaContext.GetXamlType(typeof(Canvas)));

                // TODO: We should make the DOM handle string based lookup of content here correctly.  Null refs currently
                rootDomObject.MemberNodes.Add(
                    new XamlDomMember(schemaContext.GetXamlType(typeof(UserControl)).ContentProperty, canvas));
                var canvasChildrenMember = new XamlDomMember(schemaContext.GetXamlType(typeof(Canvas)).ContentProperty);
                canvas.MemberNodes.Add(canvasChildrenMember);

                foreach (var viewTag in from objectTag in rootObjectsTag.Elements()
                    let attriNode = objectTag.Attribute(XName.Get("class"))
                    where attriNode != null
                    select objectTag)
                {
                    if (viewTag.Attribute(XName.Get("class")).Value == "IBProxyObject" ||
                        viewTag.Attribute(XName.Get("class")).Value == "IBUICustomObject")
                    {
                        continue;
                    }
                    ViewHandler.AddControlToTree(canvasChildrenMember, viewTag);
                }
            }

            // Scale to make it the right dimensions
            rootDomObject.MemberNodes.Add(
                new XamlDomMember(rootDomObject.Type.GetMember("RenderTransform"),
                    new XamlDomObject(typeof(ScaleTransform),
                        new XamlDomMember("CenterX", (IPHONE_WIDTH/2).ToString()),
                        new XamlDomMember("CenterY", (IPHONE_HEIGHT/2).ToString()),
                        new XamlDomMember("ScaleX", WIDTHMULTIPLIER.ToString()),
                        new XamlDomMember("ScaleY", HEIGHTMULTIPLIER.ToString()))));

            WireNamesAndEvents(rootDomObject, xDocument);

            return rootDomObject;
        }

        private void WireNamesAndEvents(XamlDomObject rootDomObject, XDocument xDocument)
        {
            // Handle fields
            foreach (var outletElement in
                from objectNode in xDocument.Descendants(XName.Get("object"))
                let classMember = objectNode.Attribute(XName.Get("class"))
                where classMember != null && classMember.Value == "IBCocoaTouchOutletConnection"
                select objectNode)
            {
                var sourceId =
                    GetElementWithMatchingAttribute(outletElement, "key", "source", false)
                        .Attribute(XName.Get("ref"))
                        .Value;
                var destinationId =
                    GetElementWithMatchingAttribute(outletElement, "key", "destination", false)
                        .Attribute(XName.Get("ref"))
                        .Value;

                XamlDomObject targetObject;
                if (IdToObjectMap.TryGetValue(destinationId, out targetObject))
                {
                    var name = GetElementWithMatchingAttribute(outletElement, "key", "label").Value;
                    targetObject.MemberNodes.Insert(0, new XamlDomMember(XamlLanguage.Name, name));
                }
            }

            // Handle Events
            foreach (var eventElement in
                from objectNode in xDocument.Descendants(XName.Get("object"))
                let classMember = objectNode.Attribute(XName.Get("class"))
                where classMember != null && classMember.Value == "IBCocoaTouchEventConnection"
                select objectNode)
            {
                var sourceId =
                    GetElementWithMatchingAttribute(eventElement, "key", "source", false)
                        .Attribute(XName.Get("ref"))
                        .Value;
                var destinationId =
                    GetElementWithMatchingAttribute(eventElement, "key", "destination", false)
                        .Attribute(XName.Get("ref"))
                        .Value;

                XamlDomObject sourceObject;
                if (IdToObjectMap.TryGetValue(sourceId, out sourceObject))
                {
                    var name = GetElementWithMatchingAttribute(eventElement, "key", "label").Value;
                    if (name.Contains(":"))
                    {
                        name = name.Replace(":", "");
                    }
                    sourceObject.MemberNodes.Insert(0, new XamlDomMember(GetEvent(eventElement, sourceObject), name));
                }
            }
        }

        internal static XamlMember GetEvent(XElement eventElement, XamlDomObject domObject)
        {
            if (domObject.Type.CanAssignTo(domObject.SchemaContext.GetXamlType(typeof(Slider))))
            {
                return domObject.Type.GetMember("ValueChanged");
            }
            if (domObject.Type.CanAssignTo(domObject.SchemaContext.GetXamlType(typeof(TextBox))))
            {
                return domObject.Type.GetMember("TextChanged");
            }
            if (domObject.Type.CanAssignTo(domObject.SchemaContext.GetXamlType(typeof(Button))))
            {
                return domObject.Type.GetMember("Click");
            }
            throw new NotImplementedException();
        }

        //private void GetFont(XElement element, XamlType controlType, XamlDomObject domObject)
        //{
        //    XElement fontElement = GetElementWithMatchingAttribute(element, "key", "IBUIFont");
        //    if (fontElement != null)
        //    {
        //        var fontName = GetElementWithMatchingAttribute(fontElement, "key", "NSName");
        //        if (fontName != null)
        //        {
        //            domObject.SetMemberValue(controlType.GetMember("FontFamily"), fontName.Value);
        //        }

        //        var fontSize = GetElementWithMatchingAttribute(fontElement, "key", "NSSize");
        //        if (fontSize != null)
        //        {
        //            domObject.SetMemberValue(controlType.GetMember("FontSize"), Double.Parse(fontSize.Value).ToString());
        //        }
        //    }
        //}

        internal static XElement GetReference(XDocument document, string reference)
        {
            var elements = from objectTag in document.Descendants()
                let idAttr = objectTag.Attribute(XName.Get("id"))
                where idAttr != null && idAttr.Value == reference
                select objectTag;
            Debug.Assert(elements.Count() == 1);
            return elements.First();
        }

        internal static string DecodeFromBase64(string originalString)
        {
            var paddingLength = originalString.Length%4;
            var paddedString = originalString;
            switch (paddingLength)
            {
                case 0:
                    paddedString = originalString;
                    break;
                case 1:
                    paddedString = originalString.Remove(originalString.Length - 2) + "=";
                    break;
                case 2:
                    paddedString = originalString + "==";
                    break;
                case 3:
                    paddedString = originalString + "=";
                    break;
            }

            var bytes = Convert.FromBase64String(paddedString);
            var value = Encoding.ASCII.GetString(bytes);

            return value.Replace("\0", "");
        }

        private XElement GetElementWithMatchingAttribute(XElement currentElement, string attribute, string className)
        {
            return GetElementWithMatchingAttribute(currentElement, attribute, className, true);
        }

        private XElement GetElementWithMatchingAttribute(XElement currentElement, string attribute, string className,
            bool resolveReferences)
        {
            var elements = from objectTag in currentElement.Elements()
                let attriNode = objectTag.Attribute(XName.Get(attribute))
                where attriNode != null && attriNode.Value == className
                select objectTag;

            Debug.Assert(elements.Count() == 1 || elements.Count() == 0);
            if (elements.Count() == 0)
            {
                return null;
            }
            var element = elements.First();

            if (resolveReferences)
            {
                if (element.Name == XName.Get("reference"))
                {
                    var refAttr = element.Attribute(XName.Get("ref"));
                    if (refAttr == null)
                    {
                        throw new NotImplementedException("Reference with no Ref attribute");
                    }
                    element = GetReference(_document, refAttr.Value);
                }
            }

            return element;
        }

        #region XamlReader methods

        public override bool IsEof
        {
            get { return _underlyingReader.IsEof; }
        }

        public override XamlMember Member
        {
            get { return _underlyingReader.Member; }
        }

        public override NamespaceDeclaration Namespace
        {
            get { return _underlyingReader.Namespace; }
        }

        public override XamlNodeType NodeType
        {
            get { return _underlyingReader.NodeType; }
        }

        public override bool Read()
        {
            return _underlyingReader.Read();
        }

        public override XamlSchemaContext SchemaContext
        {
            get { return _underlyingReader.SchemaContext; }
        }

        public override XamlType Type
        {
            get { return _underlyingReader.Type; }
        }

        public override object Value
        {
            get { return _underlyingReader.Value; }
        }

        #endregion
    }
}