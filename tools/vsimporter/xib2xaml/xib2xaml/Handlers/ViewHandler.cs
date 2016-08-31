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
using System.Windows.Controls;
using System.Windows.Media;
using System.Xaml;
using System.Xml.Linq;
using XamlTools.XamlDom;

namespace Xib2Xaml.Handlers
{
    internal class ViewHandler
    {
        // Full bound example: <Button Click="{x:Bind Model.EventHandlers['deepPathClicked:'].Handle}">Deep Path</Button>
        private const string XBindFormatString = "{{x:Bind Model.EventHandlers['{0}'].Handle}}";

        internal static List<XamlDomObject> CreateObject(XElement tag, XamlSchemaContext schema)
        {
            Debug.Assert(tag != null);

            var domObjects = new List<XamlDomObject>();

            // Create the view and canvas
            var canvas = new XamlDomObject(schema.GetXamlType(typeof(Canvas)));

            SetCommonProperties(tag, canvas);
            AddChildren(tag, schema.GetXamlType(typeof(Canvas)).ContentProperty, canvas);
            domObjects.Add(canvas);

            return domObjects;
        }

        protected static void AddChildren(XElement tag, XamlMember contentMember, XamlDomObject domObject)
        {
            var contentMemberNode = new XamlDomMember(contentMember);

            // Add children
            var subViews = tag.Element(XName.Get("subviews"));
            if (subViews != null)
            {
                foreach (var element in subViews.Elements(XName.Get("object")))
                {
                    AddControlToTree(contentMemberNode, element);
                }
            }

            domObject.MemberNodes.Add(contentMemberNode);
        }

        internal static void SetCommonProperties(XElement tag, XamlDomObject domObject)
        {
            Debug.Assert(tag != null && domObject != null);

            SetName(tag, domObject);

            SetFrameSize(tag, domObject);

            SetOpacity(tag, domObject);

            SetBackground(tag, domObject);

            GetDimensions(tag, domObject);

            // TODO: Re-enable once we figure out why the bindings do not permit single quotes in them
            //SetBindings(tag, domObject);
        }

        private static XamlDomObject CreateView(XElement viewTag, XamlSchemaContext schemaContext)
        {
            Debug.Assert(viewTag != null);

            // Create the view and canvas
            var canvas = new XamlDomObject(schemaContext.GetXamlType(typeof(Canvas)));
            var canvasChildrenMember = new XamlDomMember(schemaContext.GetXamlType(typeof(Canvas)).ContentProperty);

            SetFrameSize(viewTag, canvas);

            // Add children
            var subViews = viewTag.Element(XName.Get("subviews"));
            if (subViews != null)
            {
                foreach (var element in subViews.Elements(XName.Get("object")))
                {
                    AddControlToTree(canvasChildrenMember, element);
                }
            }

            if (canvasChildrenMember.Items != null && canvasChildrenMember.Items.Count > 0)
            {
                canvas.MemberNodes.Add(canvasChildrenMember);
            }

            return canvas;
        }

        protected static void SetName(XElement element, XamlDomObject domObject)
        {
            // Mark IDs so we can wire events and names properly. We need to strip them before sending to XXW though.
            var idAttr = element.Attribute(XName.Get("id"));
            if (idAttr != null)
            {
                XamlXibReader.IdToObjectMap.Add(idAttr.Value, domObject);

                // Modify the ID attrib so it doesn't contain dashes
                var name = idAttr.Value.Replace("-", "");
                domObject.MemberNodes.Insert(0, new XamlDomMember(XamlLanguage.Name, name));
            }
        }

        protected static void SetFrameSize(XElement windowTag, XamlDomObject rootWindowNode)
        {
            // Set the window's height and width
            var frameSizeElement = GetElementWithMatchingAttribute(windowTag, "key", "frame");
            if (frameSizeElement != null)
            {
                var widthAttr = frameSizeElement.Attribute(XName.Get("width"));
                if (widthAttr != null)
                {
                    rootWindowNode.SetMemberValue("Width", widthAttr.Value);
                }

                var heightAttr = frameSizeElement.Attribute(XName.Get("height"));
                if (heightAttr != null)
                {
                    rootWindowNode.SetMemberValue("Height", heightAttr.Value);
                }
            }
        }

        protected static void SetOpacity(XElement element, XamlDomObject domObject)
        {
            var opacityAttr = element.Attribute(XName.Get("opaque"));
            if (opacityAttr != null && opacityAttr.Value.Equals("yes", StringComparison.InvariantCultureIgnoreCase))
            {
                // TODO: Investigate why the legacy handler set the opacity to 0.7 vs 1.0
                domObject.SetMemberValue(domObject.Type.GetMember("Opacity"), "0.7");
            }
        }

        protected static void SetBackground(XElement element, XamlDomObject domObject)
        {
            var backgroundColor = GetElementWithMatchingAttribute(element, "key", "backgroundColor");
            if (backgroundColor != null)
            {
                SetColor(domObject, backgroundColor, domObject.Type.GetMember("Background"));
            }
        }

        protected static string GetValueWithMatchingAttribute(XElement currentElement, string attribute,
            string className)
        {
            var element = GetElementWithMatchingAttribute(currentElement, attribute, className);
            if (element != null)
            {
                return element.Value;
            }

            return null;
        }

        protected static XElement GetElementWithMatchingAttribute(XElement currentElement, string attribute,
            string className)
        {
            var elements = from objectTag in currentElement.Elements()
                let attriNode = objectTag.Attribute(XName.Get(attribute))
                where attriNode != null && attriNode.Value == className
                select objectTag;

            Debug.Assert(elements.Count() == 1 || elements.Count() == 0);

            if (!elements.Any())
            {
                return null;
            }

            var element = elements.First();
            if (element.Name == XName.Get("reference"))
            {
                var refAttr = element.Attribute(XName.Get("ref"));
                if (refAttr == null)
                {
                    throw new NotImplementedException("Reference with no ref attribute");
                }

                element = XamlXibReader.GetReference(currentElement.Document, refAttr.Value);
            }

            return element;
        }

        protected static void GetAndSetValue(XElement element, XamlDomObject domObject, string key, XamlMember member)
        {
            var valueElement = element.Attribute(XName.Get(key));
            if (valueElement != null)
            {
                var textValue = valueElement.Value;
                domObject.SetMemberValue(member, textValue);
            }
        }

        private static XamlMember GetColorMember(XamlType xType, string colorType)
        {
            switch (colorType)
            {
                case "textColor":
                    return xType.GetMember("Foreground");
                case "normalTitleColor":
                    return xType.GetMember("Foreground");
                case "backgroundColor":
                    return xType.GetMember("Background");
                case "highlightedTitleColor":
                    return xType.GetMember("Background");
                case "highlightedColor":
                    return xType.GetMember("Background");
                case "shadowColor":
                    return xType.GetMember("Background");
                case "tintColor":
                    return xType.GetMember("Background");

                default:
                    throw new NotImplementedException("Doesn't support color type: " + colorType);
            }
        }

        protected static void SetColor(XamlDomObject domObject, XElement color, XamlMember colorMember)
        {
            string value = null;

            // Image doesn't have a background but the XIB file allows setting it
            if (colorMember == null && domObject.Type.UnderlyingType == typeof(Image))
            {
                return;
            }

            // ColorSpace could be set to custom, calibratedWhite, calibratedRGB
            var colorSpace = color.Attribute(XName.Get("colorSpace"));
            if (colorSpace != null)
            {
                var colorValue = colorSpace.Value;
                if (colorValue.Contains("RGB"))
                {
                    var redValue = color.Attribute(XName.Get("red")).Value;
                    var greenValue = color.Attribute(XName.Get("green")).Value;
                    var blueValue = color.Attribute(XName.Get("blue")).Value;
                    var alphaValue = color.Attribute(XName.Get("alpha")).Value;

                    var red = (byte) (double.Parse(redValue)*255);
                    var green = (byte) (double.Parse(greenValue)*255);
                    var blue = (byte) (double.Parse(blueValue)*255);
                    var alpha = (byte) (double.Parse(alphaValue)*255);

                    var colorARGB = Color.FromArgb(alpha, red, green, blue);
                    value = colorARGB.ToString();
                }
            }
            else
            {
                throw new NotImplementedException("Doesn't support colorspace");
            }

            Debug.Assert(value != null);
            domObject.SetMemberValue(colorMember, value);
        }

        internal static void AddControlToTree(XamlDomMember member, XElement element)
        {
            List<XamlDomObject> objects;

            var controlName = element.Name.LocalName;
            switch (controlName)
            {
                case "label":
                    objects = LabelHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "button":
                    objects = ButtonHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "textField":
                    objects = TextFieldHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "textView":
                    objects = TextViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "imageView":
                    objects = ImageViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "webView":
                    objects = WebViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "segmentedControl":
                    objects = SegmentedControlHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "slider":
                    objects = SliderHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "scrollView":
                    objects = ScrollViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "view":
                    objects = CreateObject(element, member.SchemaContext);
                    break;
                case "tableView":
                    objects = TableViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "tableViewCell":
                    objects = TableViewCellHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "activityIndicatorView":
                    objects = ActivityIndicatorViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "barButtonItem":
                    objects = BarButtonHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "switch":
                    objects = SwitchHandler.CreateObject(element, member.SchemaContext);
                    break;

                //case "IBUINavigationBar": return typeof(UserControl);
                //case "IBUIProgressView": return typeof(ProgressBar);
                //case "IBUIPageControl": return typeof(UserControl);
                //case "IBUIPickerView": return typeof(UserControl);
                //case "IBUIDatePicker": return typeof(UserControl);
                //case "IBUISearchBar": return typeof(UserControl);
                //case "IBUITabBar": return typeof(UserControl);
                //case "IBUIToolbar": return typeof(ToolBar);

                default:
                    throw new NotImplementedException("Unknown control type: " + controlName);
            }

            Debug.Assert(objects != null);

            foreach (var domObject in objects)
            {
                member.Items.Add(domObject);
            }
        }

        protected static void GetDimensions(XElement element, XamlDomObject domObject)
        {
            // Look for dimensions and location
            var frame = GetElementWithMatchingAttribute(element, "key", "frame");
            if (frame != null)
            {
                var xAttr = frame.Attribute(XName.Get("x"));
                var yAttr = frame.Attribute(XName.Get("y"));
                var widthAttr = frame.Attribute(XName.Get("width"));
                var heightAttr = frame.Attribute(XName.Get("height"));

                domObject.SetAttachableMemberValue(typeof(Canvas), "Left", xAttr.Value);
                domObject.SetAttachableMemberValue(typeof(Canvas), "Top", yAttr.Value);
                domObject.SetMemberValue("Width", widthAttr.Value);
                domObject.SetMemberValue("Height", heightAttr.Value);
            }
            else
            {
                SetFrameSize(element, domObject);
            }
        }

        #region XAML Binding
        internal static XamlMember GetEvent(XamlDomObject domObject)
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

        protected static void SetBindings(XElement element, XamlDomObject domObject)
        {
            var connections = element.Element(XName.Get("connections"));
            if (connections != null)
            {
                foreach (var action in connections.Elements(XName.Get("action")))
                {
                    var selector = action.Attribute(XName.Get("selector"));
                    if (selector!= null)
                    {
                        var selectorValue = selector.Value;
                        if (selectorValue.Contains(":"))
                        {
                            var bindingDelegate = string.Format(XBindFormatString, selectorValue);
                            domObject.MemberNodes.Insert(0, new XamlDomMember(GetEvent(domObject), bindingDelegate));
                        }
                    }
                }
            }
        }
        #endregion
    }
}