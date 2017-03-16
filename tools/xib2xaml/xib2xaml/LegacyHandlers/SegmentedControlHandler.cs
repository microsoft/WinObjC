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
using System.Windows.Controls;
using System.Xaml;
using System.Xml.Linq;
using XamlTools.XamlDom;

namespace Xib2Xaml.LegacyHandlers
{
    internal class SegmentedControlHandler : ViewHandler
    {
        internal new static List<XamlDomObject> CreateObject(XElement tag, XamlSchemaContext schema)
        {
            var domObjects = new List<XamlDomObject>();

            var listBox = new XamlDomObject(schema.GetXamlType(typeof(ListBox)));
            var childrenMember = new XamlDomMember(listBox.Type.ContentProperty);
            listBox.MemberNodes.Add(childrenMember);

            var titles = GetElementWithMatchingAttribute(tag, "key", "IBSegmentTitles");
            Debug.Assert(titles != null);

            foreach (var title in titles.Elements(XName.Get("string")))
            {
                childrenMember.Items.Add(new XamlDomObject(schema.GetXamlType(typeof(ListBoxItem)),
                    new XamlDomMember(XamlLanguage.Initialization, title.Value)));
            }


            SetCommonProperties(tag, listBox);
            domObjects.Add(listBox);
            return domObjects;
        }

        internal new static void SetCommonProperties(XElement tag, XamlDomObject domObject)
        {
            ViewHandler.SetCommonProperties(tag, domObject);
        }
    }
}