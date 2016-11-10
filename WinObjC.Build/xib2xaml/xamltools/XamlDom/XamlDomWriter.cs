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

using System.Collections.Generic;
using System.Diagnostics;
using System.Xaml;

namespace XamlTools.XamlDom
{
    public class XamlDomWriter : XamlWriter, IXamlLineInfoConsumer
    {
        private int _lineNumber;
        private int _linePosition;
        private List<XamlDomNamespace> _namespaces;

        private readonly Stack<XamlDomNode> writerStack = new Stack<XamlDomNode>();

        public XamlDomWriter()
        {
            SchemaContext = new XamlSchemaContext();
        }

        public XamlDomWriter(XamlSchemaContext schemaContext)
        {
            SchemaContext = schemaContext;
        }

        private XamlDomNode CurrentStackNode
        {
            get
            {
                if (writerStack.Count > 0)
                {
                    return writerStack.Peek();
                }
                return null;
            }
        }

        #region XamlWriter Members

        public XamlDomNode RootNode { get; set; }

        public override void WriteGetObject()
        {
            WriteObject(null, true);
        }

        public override void WriteStartObject(XamlType xamlType)
        {
            WriteObject(xamlType, false);
        }

        private void WriteObject(XamlType xamlType, bool isGetObject)
        {
            var objectNode = isGetObject ? new XamlDomObject() : new XamlDomObject(xamlType);
            objectNode.IsGetObject = isGetObject;
            objectNode.StartLinePosition = _linePosition;
            objectNode.StartLineNumber = _lineNumber;

            // If it's a GetObject or a Directive, we need to store the actual XamlSchemaContext
            if (objectNode.IsGetObject || objectNode.Type.SchemaContext == XamlLanguage.Object.SchemaContext)
            {
                objectNode.SchemaContext = SchemaContext;
            }

            if (_namespaces != null)
            {
                foreach (var xdns in _namespaces)
                {
                    objectNode.Namespaces.Add(xdns);
                }

                _namespaces.Clear();
            }

            // If Root Node is null then this is the root node.
            // If Root Node is not null, then add this to the parent member.

            if (RootNode == null)
            {
                RootNode = objectNode;
            }
            else
            {
                var propertyNode = (XamlDomMember) writerStack.Peek();
                propertyNode.Items.Add(objectNode);
                objectNode.Parent = propertyNode;
                if (isGetObject)
                {
                    objectNode.Type = propertyNode.Member.Type;
                }
            }
            writerStack.Push(objectNode);
        }

        public override void WriteEndObject()
        {
            Debug.Assert(CurrentStackNode is XamlDomObject);
            CurrentStackNode.EndLineNumber = _lineNumber;
            CurrentStackNode.EndLinePosition = _linePosition;
            writerStack.Pop();
        }

        public override void WriteStartMember(XamlMember property)
        {
            var propertyNode = new XamlDomMember(property);

            // Only need to set the SchemaContext if it's a XamlDirective
            if (property.IsDirective)
            {
                propertyNode.SchemaContext = SchemaContext;
            }

            if (RootNode != null)
            {
                var objectNode = (XamlDomObject) writerStack.Peek();

                objectNode.MemberNodes.Add(propertyNode);
            }
            else
            {
                RootNode = propertyNode;
            }
            propertyNode.StartLineNumber = _lineNumber;
            propertyNode.StartLinePosition = _linePosition;

            writerStack.Push(propertyNode);
        }

        public override void WriteEndMember()
        {
            Debug.Assert(CurrentStackNode is XamlDomMember);
            CurrentStackNode.EndLineNumber = _lineNumber;
            CurrentStackNode.EndLinePosition = _linePosition;
            writerStack.Pop();
        }

        public override void WriteValue(object value)
        {
            var valueNode = new XamlDomValue();
            valueNode.Value = value;

            if (RootNode != null)
            {
                //text should always be inside of a property...
                var propertyNode = (XamlDomMember) writerStack.Peek();
                propertyNode.Items.Add(valueNode);
            }
            else
            {
                RootNode = valueNode;
            }

            valueNode.StartLineNumber = _lineNumber;
            valueNode.StartLinePosition = _linePosition;
            valueNode.EndLineNumber = _lineNumber;
            valueNode.EndLinePosition = _linePosition;
        }

        public override void WriteNamespace(NamespaceDeclaration namespaceDeclaration)
        {
            if (_namespaces == null)
            {
                _namespaces = new List<XamlDomNamespace>();
            }

            var nsNode = new XamlDomNamespace(namespaceDeclaration);
            nsNode.StartLineNumber = _lineNumber;
            nsNode.StartLinePosition = _linePosition;
            nsNode.EndLineNumber = _lineNumber;
            nsNode.EndLinePosition = _linePosition;

            _namespaces.Add(nsNode);
        }

        public override XamlSchemaContext SchemaContext { get; }

        #endregion

        #region IXamlLineInfoConsumer Members

        void IXamlLineInfoConsumer.SetLineInfo(int lineNumber, int linePosition)
        {
            _lineNumber = lineNumber;
            _linePosition = linePosition;
        }

        bool IXamlLineInfoConsumer.ShouldProvideLineInfo
        {
            get { return true; }
        }

        #endregion
    }
}