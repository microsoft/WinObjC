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

namespace Xib2Xaml.LegacyHandlers
{
    internal class ButtonHandler : ViewHandler
    {
        internal new static List<XamlDomObject> CreateObject(XElement tag, XamlSchemaContext schema)
        {
            var domObjects = new List<XamlDomObject>();

            Debug.Assert(tag != null);

            // Create the view and canvas
            var textBlock = new XamlDomObject(schema.GetXamlType(typeof(Button)));

            SetCommonProperties(tag, textBlock);
            domObjects.Add(textBlock);

            return domObjects;
        }

        internal new static void SetCommonProperties(XElement tag, XamlDomObject domObject)
        {
            ViewHandler.SetCommonProperties(tag, domObject);

            var normalColor = GetElementWithMatchingAttribute(tag, "key", "IBUINormalTitleColor");
            if (normalColor != null)
            {
                SetColor(domObject, normalColor, domObject.Type.GetMember("Foreground"));
            }

            //TODO Highlighed colors and others
            GetAndSetValue(tag, domObject, "IBUINormalTitle", domObject.Type.ContentProperty);

            var normalTitle = GetValueWithMatchingAttribute(tag, "key", "IBUINormalTitle");
            var highlightedTitle = GetValueWithMatchingAttribute(tag, "key", "IBUIHighlightedTitle");
            var disabledTitle = GetValueWithMatchingAttribute(tag, "key", "IBUIDisabledTitle");
            var selectedTitle = GetValueWithMatchingAttribute(tag, "key", "IBUISelectedTitle");

            if (highlightedTitle != normalTitle && !string.IsNullOrEmpty(highlightedTitle))
            {
                throw new NotImplementedException();
            }
            if (disabledTitle != normalTitle && !string.IsNullOrEmpty(disabledTitle))
            {
                throw new NotImplementedException();
            }
            if (selectedTitle != normalTitle && !string.IsNullOrEmpty(selectedTitle))
            {
                throw new NotImplementedException();
            }

            string normalImagePath = null;
            string selectedImagePath = null;
            string disabledImagePath = null;
            string highlightedImagePath = null;

            // Check for images
            var normalImage = GetElementWithMatchingAttribute(tag, "key", "IBUINormalImage");
            if (normalImage != null)
            {
                Debug.Assert("NSImage" == GetElementWithMatchingAttribute(normalImage, "key", "NSClassName").Value);

                normalImagePath = GetElementWithMatchingAttribute(normalImage, "key", "NSResourceName").Value;
            }

            var selectedImage = GetElementWithMatchingAttribute(tag, "key", "IBUISelectedImage");
            if (selectedImage != null)
            {
                Debug.Assert("NSImage" == GetElementWithMatchingAttribute(normalImage, "key", "NSClassName").Value);

                selectedImagePath = GetElementWithMatchingAttribute(normalImage, "key", "NSResourceName").Value;
            }

            var disabledImage = GetElementWithMatchingAttribute(tag, "key", "IBUISelectedImage");
            if (disabledImage != null)
            {
                Debug.Assert("NSImage" == GetElementWithMatchingAttribute(normalImage, "key", "NSClassName").Value);

                disabledImagePath = GetElementWithMatchingAttribute(normalImage, "key", "NSResourceName").Value;
            }

            var highlightedImage = GetElementWithMatchingAttribute(tag, "key", "IBUISelectedImage");
            if (highlightedImage != null)
            {
                Debug.Assert("NSImage" == GetElementWithMatchingAttribute(normalImage, "key", "NSClassName").Value);

                highlightedImagePath = GetElementWithMatchingAttribute(normalImage, "key", "NSResourceName").Value;
            }

            if (highlightedImagePath != normalImagePath)
            {
                throw new NotImplementedException();
            }
            if (disabledImagePath != normalImagePath)
            {
                throw new NotImplementedException();
            }
            if (selectedImagePath != normalImagePath)
            {
                throw new NotImplementedException();
            }

            //I dont know what to do if we have both...
            Debug.Assert(string.IsNullOrEmpty(normalImagePath) || string.IsNullOrEmpty(normalTitle));

            if (normalImagePath != null)
            {
                var controlTemplateObject =
                    new XamlDomObject(domObject.SchemaContext.GetXamlType(typeof(ControlTemplate)),
                        new XamlDomMember("TargetType", "Button"),
                        new XamlDomMember(domObject.SchemaContext.GetXamlType(typeof(ControlTemplate)).ContentProperty,
                            new XamlDomObject(typeof(Image),
                                new XamlDomMember("Source", normalImagePath)
                                )
                            )
                        );

                var sourceMember = new XamlDomMember(domObject.Type.GetMember("Template"));
                sourceMember.Items.Add(controlTemplateObject);

                domObject.MemberNodes.Add(sourceMember);
            }
        }
    }
}