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
using System.IO;
using System.Linq;
using System.Windows.Controls;
using System.Xaml;
using System.Xml.Linq;
using XamlTools.XamlDom;
using Xib2Xaml.Handlers;

namespace Xib2Xaml
{
    public class XamlXibReader : XamlReader
    {
        internal const int IPHONE_WIDTH = 320;
        internal const int IPHONE_HEIGHT = 460;

        internal static int WIDTH = 480;
        internal static int HEIGHT = 800;

        private readonly XamlReader _underlyingReader;

        private XDocument _document;

        public XamlXibReader(string file)
        {
            IdToObjectMap = new Dictionary<string, XamlDomObject>();

            var objectNode = CreateXamlDom(file);
            var processor = new PostProcessor(objectNode);
            objectNode = processor.Process();

            _underlyingReader = new XamlDomReader(objectNode, objectNode.SchemaContext);
        }

        internal static double WidthMultiplier
        {
            get { return (double) WIDTH/IPHONE_WIDTH; }
        }

        internal static double HeightMultiplier
        {
            get { return (double) HEIGHT/IPHONE_HEIGHT; }
        }

        internal static Dictionary<string, XamlDomObject> IdToObjectMap { get; set; }

        private XamlDomObject CreateXamlDom(string file)
        {
            var schemaContext = new XamlSchemaContext();

            _document = XDocument.Load(file);
            if (_document?.Root == null)
            {
                throw new NotSupportedException("Failed to find valid XAML document: file");
            }

            var rootDomObject = new XamlDomObject(schemaContext.GetXamlType(typeof(Page)));
            rootDomObject.MemberNodes.Insert(0, new XamlDomMember(XamlLanguage.Class, $"IslandwoodAutoGenNamespace.{Path.GetFileNameWithoutExtension(file)}"));

            var canvas = new XamlDomObject(schemaContext.GetXamlType(typeof(Canvas)));
            rootDomObject.MemberNodes.Add(new XamlDomMember(schemaContext.GetXamlType(typeof(Page)).ContentProperty, canvas));

            var canvasChildrenMember = new XamlDomMember(schemaContext.GetXamlType(typeof(Canvas)).ContentProperty);
            canvas.MemberNodes.Add(canvasChildrenMember);

            // TODO: This may no longer be needed but it's referenced in certain control handlers so more investigation required
            /*
            rootDomObject.MemberNodes.Add(
                new XamlDomMember(rootDomObject.Type.GetMember("RenderTransform"),
                    new XamlDomObject(typeof(ScaleTransform),
                        new XamlDomMember("CenterX", (IPHONE_WIDTH/2).ToString()),
                        new XamlDomMember("CenterY", (IPHONE_HEIGHT/2).ToString()),
                        new XamlDomMember("ScaleX", WidthMultiplier.ToString(CultureInfo.InvariantCulture)),
                        new XamlDomMember("ScaleY", HeightMultiplier.ToString(CultureInfo.InvariantCulture)))));
            */

            var rootObjectsTag = _document.Root.Element(XName.Get("objects"));
            if (rootObjectsTag == null)
            {
                throw new NotSupportedException("Failed to find XML node: objects");
            }

            var placeholderTag = GetElementWithMatchingAttribute(rootObjectsTag, "placeholderIdentifier", "IBFilesOwner");
            if (placeholderTag == null)
            {
                throw new NotSupportedException("Failed to find XML node with required attribute: placeholderIdentifier");
            }

            // Loop over outlets vwhere property attribute is a view
            foreach (var outletElement in
                from outletNode in placeholderTag.Descendants(XName.Get("outlet"))
                let propertyAttr = outletNode.Attribute(XName.Get("property"))
                where propertyAttr != null && propertyAttr.Value == "view"
                select outletNode)
            {
                // Find the node with the matching ID
                var destinationAttr = outletElement.Attribute(XName.Get("destination"));
                if (destinationAttr == null)
                {
                    throw new NotSupportedException("Failed to find XML outlet node with required attribute: destination");
                }

                // TODO: Handle the possibility that subviews don't exist
                var viewTag = GetElementWithMatchingAttribute(rootObjectsTag, "id", destinationAttr.Value);
                var subviewsTag = viewTag.Element(XName.Get("subviews"));
                if (subviewsTag != null)
                {
                    foreach (var subviewTag in from objectTag in subviewsTag.Elements()
                        let attriNode = objectTag.Attribute(XName.Get("id"))
                        where attriNode != null
                        select objectTag)
                    {
                        // Build the tree
                        ViewHandler.AddControlToTree(canvasChildrenMember, subviewTag);
                    }
                }
            }

            // Second pass over the outlets to insert x:Name and x:Bind against added controls
            WireNamesAndEvents(placeholderTag);

            return rootDomObject;
        }

        private void WireNamesAndEvents(XElement placeholderTag)
        {
            // Handle names
            foreach (var outletElement in placeholderTag.Descendants(XName.Get("outlet")))
            {
                XamlDomObject targetObject;
                var destinationId = outletElement.Attribute(XName.Get("destination")).Value;
                if (IdToObjectMap.TryGetValue(destinationId, out targetObject))
                {
                    var name = outletElement.Attribute(XName.Get("property")).Value;
                    if (!string.IsNullOrWhiteSpace(name))
                    {
                        // x:Name is always the first element so replace it with the outlet property
                        targetObject.MemberNodes[0] = new XamlDomMember(XamlLanguage.Name, name);
                    }
                }
            }

            // TODO: Handle events
        }

        internal static XElement GetReference(XDocument document, string reference)
        {
            var elements = from objectTag in document.Descendants()
                let idAttr = objectTag.Attribute(XName.Get("id"))
                where idAttr != null && idAttr.Value == reference
                select objectTag;

            Debug.Assert(elements.Count() == 1);

            return elements.First();
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

            Debug.Assert(elements.Count() == 0 || elements.Count() == 1 );

            if (!elements.Any())
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