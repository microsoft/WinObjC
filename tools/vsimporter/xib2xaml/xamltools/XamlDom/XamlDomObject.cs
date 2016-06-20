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
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Windows.Markup;
using System.Xaml;
using System.Xaml.Schema;

namespace XamlTools.XamlDom
{
    [DebuggerDisplay("<{Type.Name}>")]
    [ContentProperty("MemberNodes")]
    public class XamlDomObject : XamlDomItem, IXamlTypeResolver, IXamlNamespaceResolver
    {
        #region Public Constructors
        public XamlDomObject()
        {
        }

        public XamlDomObject(XamlType xamlType)
        {
            _type = xamlType;
            if (xamlType != null)
            {
                _schemaContext = xamlType.SchemaContext;
            }
        }

        public XamlDomObject(XamlType xamlType, params XamlDomMember[] members)
            : this(xamlType)
        {
            foreach (var memberNode in members)
            {
                MemberNodes.Add(memberNode);
            }

            // We can't rely on setting the SchemaContext to force a resolve since we haven't assigned
            // the members yet.  Therefore, we need to resolve here.
            Resolve();
        }

        public XamlDomObject(Type type, XamlSchemaContext schemaContext)
        {
            if (type == null)
            {
                throw new ArgumentNullException("type");
            }
            if (schemaContext == null)
            {
                throw new ArgumentNullException("schemaContext");
            }

            _type = schemaContext.GetXamlType(type);
        }

        public XamlDomObject(Type type, XamlSchemaContext schemaContext, params XamlDomMember[] members)
            : this(type, schemaContext)
        {
            foreach (var memberNode in members)
            {
                MemberNodes.Add(memberNode);
            }

            Resolve();
        }

        public XamlDomObject(Type type, params XamlDomMember[] members)
        {
            foreach (var memberNode in members)
            {
                MemberNodes.Add(memberNode);
            }

            _unresolvedType = type;
        }

        public XamlDomObject(bool isGetObject, params XamlDomMember[] members)
        {
            foreach (var memberNode in members)
            {
                MemberNodes.Add(memberNode);
            }
            _isGetObject = isGetObject;
        }
        #endregion

        #region Public Properties
        [DefaultValue(null)]
        public virtual XamlType Type
        {
            get { return _type; }
            set
            {
                CheckSealed();
                _type = value;
                SchemaContext = _type.SchemaContext;
            }
        }

        [DefaultValue(false)]
        public virtual bool IsGetObject
        {
            get { return _isGetObject; }
            set
            {
                CheckSealed();
                _isGetObject = value;
            }
        }

        [DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
        public virtual KeyedCollection<string, XamlDomNamespace> Namespaces
        {
            get
            {
                if (_namespaces == null)
                {
                    _namespaces = new SealableNamespaceCollection();
                    if (IsSealed)
                    {
                        _namespaces.Seal();
                    }
                }
                return _namespaces;
            }
        }

        [DesignerSerializationVisibility(DesignerSerializationVisibility.Content)]
        public virtual IList<XamlDomMember> MemberNodes
        {
            get
            {
                if (_memberNodes == null)
                {
                    _memberNodes = new XamlNodeCollection<XamlDomMember>(this);
                    if (IsSealed)
                    {
                        _memberNodes.Seal();
                    }
                }
                return _memberNodes;
            }
        }

        public virtual XamlSchemaContext SchemaContext
        {
            get { return _schemaContext; }
            set
            {
                CheckSealed();
                if (Type != null && Type.SchemaContext != XamlLanguage.Array.SchemaContext &&
                    Type.SchemaContext != value)
                {
                    throw new InvalidOperationException("SchemaContext must match the XamlType's SchemaContext");
                }
                _schemaContext = value;
                Resolve();
            }
        }
        #endregion

        #region Public Methods
        public override void Seal()
        {
            base.Seal();

            if (_memberNodes != null)
            {
                _memberNodes.Seal();
            }

            if (_namespaces != null)
            {
                _namespaces.Seal();
            }
        }

        public bool HasMember(string instanceMember)
        {
            if (instanceMember == null)
            {
                throw new ArgumentNullException("instanceMember");
            }
            if (instanceMember.Contains("."))
            {
                throw new NotSupportedException(
                    "Attachable members are not supported in HasMember.  Please call HasAttachableMember");
            }

            return Logic_HasMember((XamlType) null, instanceMember);
        }

        public bool HasAttachableMember(XamlType declaringType, string attachableMember)
        {
            if (attachableMember == null)
            {
                throw new ArgumentNullException("attachableMember");
            }

            // TODO: Handle unknowns
            return HasMember(declaringType.GetAttachableMember(attachableMember));
        }

        public bool HasAttachableMember(Type declaringType, string attachableMember)
        {
            if (attachableMember == null)
            {
                throw new ArgumentNullException("attachableMember");
            }

            return Logic_HasMember(declaringType, attachableMember);
        }

        public virtual bool HasMember(XamlMember xamlMember)
        {
            if (xamlMember == null)
            {
                throw new ArgumentNullException("xamlMember");
            }

            return GetMemberNode(xamlMember) != null;
        }

        public XamlDomMember GetMemberNode(string instanceMember)
        {
            if (instanceMember == null)
            {
                throw new ArgumentNullException("instanceMember");
            }

            if (instanceMember.Contains("."))
            {
                throw new NotSupportedException(
                    "Attachable members are not supported in GetMemberNode.  Please call GetAttachableMemberNode");
            }

            return Logic_GetMemberNode((XamlType) null, instanceMember);
        }

        public XamlDomMember GetAttachableMemberNode(XamlType declaringType, string attachableMember)
        {
            if (attachableMember == null)
            {
                throw new ArgumentNullException("attachableMember");
            }

            if (declaringType == null)
            {
                throw new ArgumentNullException("declaringType");
            }

            return Logic_GetMemberNode(declaringType, attachableMember);
        }

        public XamlDomMember GetAttachableMemberNode(Type declaringType, string attachableMember)
        {
            if (attachableMember == null)
            {
                throw new ArgumentNullException("attachableMember");
            }

            if (declaringType == null)
            {
                throw new ArgumentNullException("declaringType");
            }

            return Logic_GetMemberNode(declaringType, attachableMember);
        }

        public virtual XamlDomMember GetMemberNode(XamlMember xamlMember)
        {
            if (xamlMember == null)
            {
                throw new ArgumentNullException("xamlMember");
            }

            var directive = xamlMember as XamlDirective;
            XamlMember aliasedMember = null;
            if (directive != null && Type != null)
            {
                aliasedMember = Type.GetAliasedProperty(directive);
            }
            if (_memberNodes != null)
            {
                foreach (var memberNode in _memberNodes)
                {
                    if (memberNode.Member == xamlMember || (aliasedMember != null && memberNode.Member == aliasedMember))
                    {
                        return memberNode;
                    }
                }
            }

            return null;
        }

        public void SetAttachableMemberValue(Type declaringType, string attachableMember, object value)
        {
            if (declaringType == null)
            {
                throw new ArgumentNullException("declaringType");
            }

            if (attachableMember == null)
            {
                throw new ArgumentNullException("attachableMember");
            }

            var xamlType = SchemaContext.GetXamlType(declaringType);
            Logic_SetMember(xamlType, attachableMember, value);
        }

        public void SetAttachableMemberValue(XamlType declaringType, string attachableMember, object value)
        {
            if (declaringType == null)
            {
                throw new ArgumentNullException("declaringType");
            }

            if (attachableMember == null)
            {
                throw new ArgumentNullException("attachableMember");
            }

            Logic_SetMember(declaringType, attachableMember, value);
        }

        public void SetMemberValue(string instanceMember, object value)
        {
            if (instanceMember == null)
            {
                throw new ArgumentNullException("instanceMember");
            }

            Logic_SetMember(null, instanceMember, value);
        }

        public virtual void SetMemberValue(XamlMember xamlMember, object value)
        {
            if (xamlMember == null)
            {
                throw new ArgumentNullException("xamlMember");
            }

            var node = GetMemberNode(xamlMember);
            if (node == null)
            {
                node = new XamlDomMember(xamlMember);
                MemberNodes.Add(node);
            }

            node.Item = new XamlDomValue(value);
        }

        public virtual XamlDomMember RemoveMember(XamlMember xamlMember)
        {
            if (xamlMember == null)
            {
                throw new ArgumentNullException("xamlMember");
            }

            return RemoveMemberNode(GetMemberNode(xamlMember));
        }

        public virtual XamlDomMember RemoveMemberNode(XamlDomMember node)
        {
            if (node == null)
            {
                throw new ArgumentNullException("node");
            }

            if (_memberNodes != null)
            {
                if (_memberNodes.Remove(node))
                {
                    return node;
                }
            }

            return null;
        }

        public virtual IEnumerable<XamlDomObject> DescendantsAndSelf()
        {
            return DescendantsAndSelf((XamlType) null);
        }

        public virtual IEnumerable<XamlDomObject> DescendantsAndSelf(Type type)
        {
            return DescendantsAndSelf(SchemaContext.GetXamlType(type));
        }

        public virtual IEnumerable<XamlDomObject> DescendantsAndSelf(XamlType type)
        {
            var members = new Stack<XamlDomMember>();

            for (var i = MemberNodes.Count - 1; i >= 0; i--)
            {
                members.Push(MemberNodes[i]);
            }

            if (IsObjectNodeAssignable(type, this))
            {
                yield return this;
            }

            while (members.Count > 0)
            {
                var member = members.Pop();
                foreach (var itemNode in member.Items)
                {
                    var objectNode = itemNode as XamlDomObject;
                    if (objectNode != null)
                    {
                        for (var i = objectNode.MemberNodes.Count - 1; i >= 0; i--)
                        {
                            members.Push(objectNode.MemberNodes[i]);
                        }

                        if (IsObjectNodeAssignable(type, objectNode))
                        {
                            yield return objectNode;
                        }
                    }
                }
            }
        }
        #endregion

        #region IXamlTypeResolver Members
        public virtual Type Resolve(string qualifiedTypeName)
        {
            string xmlNs;
            string typeName;
            SplitQualifiedName(qualifiedTypeName, out xmlNs, out typeName);

            var referencedXamlType = SchemaContext.GetXamlType(new XamlTypeName(xmlNs, typeName));

            return referencedXamlType != null
                ? referencedXamlType.UnderlyingType
                : null;
        }

        private void SplitQualifiedName(string qualifiedName, out string prefix, out string name)
        {
            prefix = string.Empty;
            name = qualifiedName;

            var colonIdx = qualifiedName.IndexOf(':');
            if (colonIdx != -1)
            {
                prefix = qualifiedName.Substring(0, colonIdx);
                name = qualifiedName.Substring(colonIdx + 1);
            }
        }
        #endregion

        #region IXamlNamespaceResolver Members
        public virtual string GetNamespace(string prefix)
        {
            if (_namespaces != null && _namespaces.Contains(prefix))
            {
                return _namespaces[prefix].NamespaceDeclaration.Namespace;
            }
            if (Parent != null)
            {
                return Parent.LookupNamespaceByPrefix(prefix);
            }
            return null;
        }

        public IEnumerable<NamespaceDeclaration> GetNamespacePrefixes()
        {
            var objectNode = this;
            var prefixes = new List<string>();
            while (objectNode != null)
            {
                if (objectNode._namespaces != null)
                {
                    foreach (var nsNode in objectNode.Namespaces)
                    {
                        if (!prefixes.Contains(nsNode.NamespaceDeclaration.Prefix))
                        {
                            prefixes.Add(nsNode.NamespaceDeclaration.Prefix);
                            yield return nsNode.NamespaceDeclaration;
                        }
                    }
                }

                if (objectNode.Parent != null)
                {
                    objectNode = objectNode.Parent.Parent;
                }
                else
                {
                    // If we don't have a parent member, then set objectNode to null
                    objectNode = null;
                }
            }
        }
        #endregion

        #region Internal and private methods
        internal void Resolve()
        {
            if (SchemaContext == null && Parent != null && Parent.SchemaContext != null)
            {
                _schemaContext = Parent.SchemaContext;
            }

            Debug.Assert(SchemaContext != null);
            if (Type == null && _unresolvedType != null)
            {
                _type = SchemaContext.GetXamlType(_unresolvedType);
                _unresolvedType = null;
            }

            foreach (var memberNode in MemberNodes)
            {
                memberNode.Resolve();
            }
        }

        private XamlMember ResolveXamlMember(XamlType declaringType, string member)
        {
            if (declaringType != null)
            {
                return declaringType.GetAttachableMember(member);
            }

            if (!IsGetObject)
            {
                return Type.GetMember(member);
            }

            if (Parent != null)
            {
                Parent.Member.Type.GetMember(member);
            }

            return null;
        }

        private bool IsObjectNodeAssignable(XamlType type, XamlDomObject objectNode)
        {
            if (type == null || (!objectNode.IsGetObject && objectNode.Type.CanAssignTo(type)) ||
                (objectNode.IsGetObject && objectNode.Parent != null && objectNode.Parent.Member.Type.CanAssignTo(type)))
            {
                return true;
            }

            return false;
        }

        private XamlDomMember Logic_GetMemberNode(Type declaringType, string member)
        {
            return Logic_GetMemberNode(declaringType != null ? SchemaContext.GetXamlType(declaringType) : null, member);
        }

        private XamlDomMember Logic_GetMemberNode(XamlType declaringXamlType, string member)
        {
            var xamlMember = ResolveXamlMember(declaringXamlType, member);
            if (xamlMember == null)
            {
                // TODO: Search for unknowns
                return null;
            }

            return GetMemberNode(xamlMember);
        }

        private bool Logic_HasMember(Type declaringType, string member)
        {
            return Logic_HasMember(declaringType != null ? SchemaContext.GetXamlType(declaringType) : null, member);
        }

        private bool Logic_HasMember(XamlType declaringXamlType, string member)
        {
            var xamlMember = ResolveXamlMember(declaringXamlType, member);
            if (xamlMember == null)
            {
                // TODO: Search for unknowns
                return false;
            }

            return HasMember(xamlMember);
        }

        private void Logic_SetMember(XamlType declaringXamlType, string member, object value)
        {
            var xamlMember = ResolveXamlMember(declaringXamlType, member);
            if (xamlMember == null)
            {
                // TODO: Support unknowns
                return;
            }
            SetMemberValue(xamlMember, value);
        }
        #endregion

        #region Private data
        private SealableNamespaceCollection _namespaces;
        private XamlSchemaContext _schemaContext;
        private XamlType _type;
        private bool _isGetObject;
        private Type _unresolvedType;
        private XamlNodeCollection<XamlDomMember> _memberNodes;
        #endregion
    }
}