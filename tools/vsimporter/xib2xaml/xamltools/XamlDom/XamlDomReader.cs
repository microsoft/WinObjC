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
using System.Xaml;

namespace XamlTools.XamlDom
{
    public class XamlDomReader : XamlReader, IXamlLineInfo
    {
        private readonly bool _doNotReorder;
        private readonly IEnumerator<XamlNode> _nodes;

        public XamlDomReader(XamlDomNode domNode, XamlSchemaContext schemaContext)
            : this(domNode, schemaContext, null)
        {
        }

        public XamlDomReader(XamlDomNode domNode, XamlSchemaContext schemaContext, XamlDomReaderSettings settings)
        {
            if (schemaContext == null)
            {
                throw new ArgumentNullException("schemaContext");
            }
            if (domNode == null)
            {
                throw new ArgumentNullException("domNode");
            }

            SchemaContext = schemaContext;
            if (settings != null)
            {
                _doNotReorder = settings.DoNotReorderMembers;
            }
            _nodes = WalkDom(domNode).GetEnumerator();
        }

        public override bool IsEof
        {
            get { return NodeType != XamlNodeType.None; }
        }

        public override XamlMember Member
        {
            get
            {
                if (NodeType == XamlNodeType.StartMember)
                    return _nodes.Current.Member;
                return null;
            }
        }

        public override NamespaceDeclaration Namespace
        {
            get
            {
                var nsNode = _nodes.Current.Namespace;
                if (nsNode != null)
                    return nsNode;
                return null;
            }
        }

        public override XamlNodeType NodeType
        {
            get { return _nodes.Current.NodeType; }
        }

        public override XamlSchemaContext SchemaContext { get; }

        public override XamlType Type
        {
            get
            {
                if (NodeType == XamlNodeType.StartObject)
                    return _nodes.Current.Type;
                return null;
            }
        }

        public override object Value
        {
            get
            {
                if (NodeType == XamlNodeType.Value)
                {
                    return _nodes.Current.Value;
                }
                return null;
            }
        }

        public override bool Read()
        {
            return _nodes.MoveNext();
        }

        private IEnumerable<XamlNode> WalkDom(XamlDomNode domNode)
        {
            var objectNode = domNode as XamlDomObject;
            if (objectNode != null)
            {
                foreach (var node in ReadObjectNode(objectNode))
                {
                    yield return node;
                }
            }
            else
            {
                var memberNode = domNode as XamlDomMember;
                if (memberNode != null)
                {
                    foreach (var node in ReadMemberNode(memberNode))
                    {
                        yield return node;
                    }
                }
                else
                {
                    foreach (var node in ReadValueNode(domNode as XamlDomValue))
                    {
                        yield return node;
                    }
                }
            }
        }

        private IEnumerable<XamlNode> ReadValueNode(XamlDomValue XamlDomValue)
        {
            yield return XamlNode.GetValue(XamlDomValue);
        }

        private IEnumerable<XamlNode> ReadMemberNode(XamlDomMember memberNode)
        {
            if (memberNode.Items != null && memberNode.Items.Count > 0)
            {
                yield return XamlNode.GetStartMember(memberNode);
                foreach (var itemNode in memberNode.Items)
                {
                    var objectNode = itemNode as XamlDomObject;
                    IEnumerable<XamlNode> enumerable;
                    if (objectNode != null)
                    {
                        enumerable = ReadObjectNode(objectNode);
                    }
                    else
                    {
                        enumerable = ReadValueNode(itemNode as XamlDomValue);
                    }

                    foreach (var node in enumerable)
                    {
                        yield return node;
                    }
                }
                yield return XamlNode.GetEndMember(memberNode);
            }
        }

        private IEnumerable<XamlNode> ReadObjectNode(XamlDomObject objectNode)
        {
            foreach (var nsNode in objectNode.Namespaces)
            {
                yield return XamlNode.GetNamespaceDeclaration(nsNode);
            }

            yield return XamlNode.GetStartObject(objectNode);

            // We want to write out simple things that could be attributes out first if setting is set
            // We write out single values and things that are MEs
            if (!_doNotReorder)
            {
                foreach (var node in WritePossibleAttributes(objectNode))
                {
                    yield return node;
                }

                foreach (var node in WriteElementMembers(objectNode))
                {
                    yield return node;
                }
            }
            else
            {
                foreach (var memberNode in objectNode.MemberNodes)
                {
                    foreach (var node in ReadMemberNode(memberNode))
                    {
                        yield return node;
                    }
                }
            }

            yield return XamlNode.GetEndObject(objectNode);
        }

        private IEnumerable<XamlNode> WriteElementMembers(XamlDomObject objectNode)
        {
            foreach (var memberNode in objectNode.MemberNodes)
            {
                if (IsAttribute(memberNode))
                {
                    continue;
                }

                foreach (var node in ReadMemberNode(memberNode))
                {
                    yield return node;
                }
            }
        }

        private IEnumerable<XamlNode> WritePossibleAttributes(XamlDomObject objectNode)
        {
            foreach (var memberNode in objectNode.MemberNodes)
            {
                if (IsAttribute(memberNode))
                {
                    foreach (var node in ReadMemberNode(memberNode))
                    {
                        yield return node;
                    }
                }
            }
        }

        private bool IsAttribute(XamlDomMember memberNode)
        {
            if (memberNode.Items.Count == 1)
            {
                if (memberNode.Item is XamlDomValue)
                {
                    return true;
                }
                var objectType = (memberNode.Item as XamlDomObject).Type;
                if (objectType != null && objectType.IsMarkupExtension)
                {
                    return true;
                }
            }
            return false;
        }

        private class XamlNode
        {
            private static readonly XamlNode _xamlNode = new XamlNode();
            public int LineNumber;
            public int LinePosition;
            public XamlMember Member;
            public NamespaceDeclaration Namespace;
            public XamlNodeType NodeType = XamlNodeType.None;

            public XamlType Type;
            public object Value;

            public void Clear()
            {
                Type = null;
                Member = null;
                Namespace = null;
                NodeType = XamlNodeType.None;
                Value = null;
                LineNumber = 0;
                LinePosition = 0;
            }

            public static XamlNode GetNamespaceDeclaration(XamlDomNamespace nsNode)
            {
                _xamlNode.Clear();
                _xamlNode.Namespace = nsNode.NamespaceDeclaration;
                _xamlNode.NodeType = XamlNodeType.NamespaceDeclaration;
                _xamlNode.LineNumber = nsNode.StartLineNumber;
                _xamlNode.LinePosition = nsNode.StartLinePosition;
                return _xamlNode;
            }

            public static XamlNode GetStartObject(XamlDomObject objectNode)
            {
                _xamlNode.Clear();
                if (objectNode.IsGetObject)
                {
                    _xamlNode.NodeType = XamlNodeType.GetObject;
                }
                else
                {
                    _xamlNode.NodeType = XamlNodeType.StartObject;
                    _xamlNode.Type = objectNode.Type;
                }
                _xamlNode.LineNumber = objectNode.StartLineNumber;
                _xamlNode.LinePosition = objectNode.StartLinePosition;
                return _xamlNode;
            }

            internal static XamlNode GetEndObject(XamlDomObject objectNode)
            {
                _xamlNode.Clear();
                _xamlNode.NodeType = XamlNodeType.EndObject;
                _xamlNode.LineNumber = objectNode.EndLineNumber;
                _xamlNode.LinePosition = objectNode.EndLinePosition;
                return _xamlNode;
            }

            internal static XamlNode GetStartMember(XamlDomMember memberNode)
            {
                _xamlNode.Clear();
                _xamlNode.NodeType = XamlNodeType.StartMember;
                _xamlNode.Member = memberNode.Member;
                _xamlNode.LineNumber = memberNode.StartLineNumber;
                _xamlNode.LinePosition = memberNode.StartLinePosition;
                return _xamlNode;
            }


            internal static XamlNode GetEndMember(XamlDomMember memberNode)
            {
                _xamlNode.Clear();
                _xamlNode.NodeType = XamlNodeType.EndMember;
                _xamlNode.LineNumber = memberNode.EndLineNumber;
                _xamlNode.LinePosition = memberNode.EndLinePosition;
                return _xamlNode;
            }

            internal static XamlNode GetValue(XamlDomValue XamlDomValue)
            {
                _xamlNode.Clear();
                _xamlNode.NodeType = XamlNodeType.Value;
                _xamlNode.Value = XamlDomValue.Value;
                _xamlNode.LineNumber = XamlDomValue.StartLineNumber;
                _xamlNode.LinePosition = XamlDomValue.StartLinePosition;
                return _xamlNode;
            }
        }

        #region IXamlLineInfo Members

        bool IXamlLineInfo.HasLineInfo
        {
            get { return true; }
        }

        int IXamlLineInfo.LineNumber
        {
            get { return _nodes.Current.LineNumber; }
        }

        int IXamlLineInfo.LinePosition
        {
            get { return _nodes.Current.LinePosition; }
        }

        #endregion
    }
}