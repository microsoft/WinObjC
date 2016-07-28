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
// 
using System;
using System.Collections.ObjectModel;

namespace XamlTools.XamlDom
{
    internal class SealableNamespaceCollection : KeyedCollection<string, XamlDomNamespace>
    {
        public bool IsSealed { get; private set; }

        public void Seal()
        {
            IsSealed = true;

            foreach (var xdns in this)
            {
                xdns.Seal();
            }
        }

        private void CheckSealed()
        {
            if (IsSealed)
            {
                throw new NotSupportedException("The Dictionary has been sealed.");
            }
        }

        #region KeyedCollection Members

        protected override string GetKeyForItem(XamlDomNamespace item)
        {
            return item.NamespaceDeclaration.Prefix;
        }

        protected override void InsertItem(int index, XamlDomNamespace item)
        {
            CheckSealed();
            base.InsertItem(index, item);
        }

        protected override void RemoveItem(int index)
        {
            CheckSealed();
            base.RemoveItem(index);
        }

        protected override void SetItem(int index, XamlDomNamespace item)
        {
            CheckSealed();
            base.SetItem(index, item);
        }

        protected override void ClearItems()
        {
            CheckSealed();
            base.ClearItems();
        }

        #endregion
    }
}