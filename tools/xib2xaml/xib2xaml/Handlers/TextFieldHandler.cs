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
using System.Windows.Controls;
using System.Xaml;
using System.Xml.Linq;
using XamlTools.XamlDom;

namespace Xib2Xaml.Handlers
{
    internal class TextFieldHandler : ViewHandler
    {
        internal new static List<XamlDomObject> CreateObject(XElement tag, XamlSchemaContext schema)
        {
            var domObjects = new List<XamlDomObject>();

            Debug.Assert(tag != null);

            // Create the view and canvas
            var textBox = new XamlDomObject(schema.GetXamlType(typeof(TextBox)));

            SetCommonProperties(tag, textBox);
            domObjects.Add(textBox);

            return domObjects;
        }

        internal new static void SetCommonProperties(XElement tag, XamlDomObject domObject)
        {
            ViewHandler.SetCommonProperties(tag, domObject);

            // TODO: Hardcoded to wrap - should align with lineBreakMode
            domObject.SetMemberValue("TextWrapping", "Wrap");

            var textColor = GetElementWithMatchingAttribute(tag, "key", "textColor");
            if (textColor != null)
            {
                SetColor(domObject, textColor, domObject.Type.GetMember("Foreground"));
            }

            var isEnabled = GetElementWithMatchingAttribute(tag, "key", "enabled");
            if (isEnabled != null)
            {
                if (isEnabled.Value.Equals("no", StringComparison.InvariantCultureIgnoreCase))
                {
                    domObject.SetMemberValue(domObject.Type.GetMember("IsEnabled"), "false");
                }
            }

            GetAndSetValue(tag, domObject, "text", domObject.Type.ContentProperty);
        }
    }
}