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
using System.Collections;
using System.Collections.Generic;

namespace XamlTools.XamlDom
{
    internal class XamlNodeCollection<T> : IList<T> where T : XamlDomNode
    {
        private List<T> _nodes;
        private readonly XamlDomNode _parentNode;

        public XamlNodeCollection(XamlDomNode parent)
        {
            _parentNode = parent;
        }

        public bool IsSealed { get; private set; }

        private List<T> Nodes
        {
            get
            {
                if (_nodes == null)
                {
                    _nodes = new List<T>();
                }

                return _nodes;
            }
        }

        public int Count
        {
            get { return Nodes.Count; }
        }

        #region IEnumerable<T> Members

        public IEnumerator<T> GetEnumerator()
        {
            return Nodes.GetEnumerator();
        }

        #endregion

        #region IEnumerable Members

        IEnumerator IEnumerable.GetEnumerator()
        {
            return Nodes.GetEnumerator();
        }

        #endregion

        public void Seal()
        {
            IsSealed = true;
            foreach (XamlDomNode node in _nodes)
            {
                node.Seal();
            }
        }

        private void SetParent(T node)
        {
            var itemNode = node as XamlDomItem;
            var propNode = node as XamlDomMember;

            if (itemNode != null)
            {
                itemNode.Parent = (XamlDomMember) _parentNode;
            }
            if (propNode != null)
            {
                propNode.Parent = (XamlDomObject) _parentNode;
            }
        }

        private void SetParentToNull(T node)
        {
            var objNode = node as XamlDomObject;
            var propNode = node as XamlDomMember;

            if (objNode != null)
            {
                objNode.Parent = null;
            }
            if (propNode != null)
            {
                propNode.Parent = null;
            }
        }

        private void CheckSealed()
        {
            if (IsSealed)
            {
                throw new NotSupportedException("The MemberNode is read-only");
            }
        }

        #region IList<T> Members

        public void Add(T node)
        {
            CheckSealed();
            Nodes.Add(node);
            SetParent(node);
        }

        public int IndexOf(T item)
        {
            return Nodes.IndexOf(item);
        }

        public void Insert(int index, T item)
        {
            CheckSealed();
            Nodes.Insert(index, item);
            SetParent(item);
        }

        public void RemoveAt(int index)
        {
            CheckSealed();
            SetParentToNull(Nodes[index]);
            Nodes.RemoveAt(index);
        }

        public T this[int index]
        {
            get { return Nodes[index]; }
            set
            {
                CheckSealed();
                Nodes[index] = value;
                SetParent(value);
            }
        }

        #endregion

        #region ICollection<T> Members

        public bool IsReadOnly
        {
            get { return IsSealed; }
        }

        public void Clear()
        {
            CheckSealed();
            foreach (var node in Nodes)
            {
                SetParentToNull(node);
            }
            Nodes.Clear();
        }

        public bool Contains(T item)
        {
            return Nodes.Contains(item);
        }

        public void CopyTo(T[] array, int arrayIndex)
        {
            CheckSealed();
            Nodes.CopyTo(array, arrayIndex);
            //TODO: should .Parent property be cleared on the copies?
        }

        public bool Remove(T item)
        {
            CheckSealed();
            SetParentToNull(item);
            return Nodes.Remove(item);
        }

        #endregion
    }
}