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
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Controls;
using System.Windows.Media;
using System.Xaml;
using System.Xml.Linq;
using XamlTools.XamlDom;

namespace Xib2Xaml.LegacyHandlers
{
    internal class ViewHandler
    {
        internal static List<XamlDomObject> CreateObject(XElement tag, XamlSchemaContext schema)
        {
            var domObjects = new List<XamlDomObject>();

            Debug.Assert(tag != null);

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
            var subViews = GetElementWithMatchingAttribute(tag, "key", "NSSubviews");
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

            // Mark ids so we can wire events and names properly.
            // We need to strip them before sending to XXW though.
            var idAttr = tag.Attribute(XName.Get("id"));
            if (idAttr != null)
            {
                XamlLegacyXibReader.IdToObjectMap.Add(idAttr.Value, domObject);
            }

            SetFrameSize(tag, domObject);

            SetOpacity(tag, domObject);

            var backgroundColor = GetElementWithMatchingAttribute(tag, "key", "IBUIBackgroundColor");
            if (backgroundColor != null)
            {
                SetColor(domObject, backgroundColor, domObject.Type.GetMember("Background"));
            }

            GetDimensions(tag, domObject);

            //var colors = from nsColor in element.Elements(XName.Get("object"))
            //             where nsColor.Attribute(XName.Get("class")).Value == "NSColor"
            //             select nsColor;

            //foreach (var color in colors)
            //{
            //    GetColor(controlType, domObject, color);
            //}

            //GetNormalTitle(element, domObject);

            //GetFont(element, controlType, domObject);

            //GetOpacity(element, controlType, domObject);

            //GetText(element, domObject);

            //GetImage(element, domObject);
        }

        private static XamlDomObject CreateView(XElement viewTag, XamlSchemaContext schemaContext)
        {
            Debug.Assert(viewTag != null);

            // Create the view and canvas
            var canvas = new XamlDomObject(schemaContext.GetXamlType(typeof(Canvas)));
            var canvasChildrenMember = new XamlDomMember(schemaContext.GetXamlType(typeof(Canvas)).ContentProperty);

            SetFrameSize(viewTag, canvas);

            var backgroundColor = GetElementWithMatchingAttribute(viewTag, "key", "IBUIBackgroundColor");
            //GetColor(canvas.Type, canvas, backgroundColor);

            // Add children
            var subViews = GetElementWithMatchingAttribute(viewTag, "key", "NSSubviews");
            if (subViews != null)
            {
                foreach (var element in subViews.Elements(XName.Get("object")))
                {
                    AddControlToTree(canvasChildrenMember, element);
                }
            }

            // TODO: Fix XamlToolkit to not choke on members with nothing inside of it
            if (canvasChildrenMember.Items != null && canvasChildrenMember.Items.Count > 0)
            {
                canvas.MemberNodes.Add(canvasChildrenMember);
            }

            return canvas;
        }

        protected static void SetOpacity(XElement element, XamlDomObject domObject)
        {
            var opacity = GetElementWithMatchingAttribute(element, "key", "IBUIOpaque");
            if (opacity != null)
            {
                var opacityValue = opacity.Value;
                Debug.Assert(opacityValue != null);
                if (opacityValue.Equals("yes", StringComparison.InvariantCultureIgnoreCase))
                {
                    domObject.SetMemberValue(domObject.Type.GetMember("Opacity"), "0.7");
                }
            }
        }

        protected static void SetFrameSize(XElement windowTag, XamlDomObject rootWindowNode)
        {
            // Set the window's height and width
            var frameSizeElement = GetElementWithMatchingAttribute(windowTag, "key", "NSFrameSize");
            if (frameSizeElement != null)
            {
                var frameSize = frameSizeElement.Value;
                var matches = Regex.Matches(frameSize, @"\d+");
                Debug.Assert(matches.Count == 2);
                rootWindowNode.SetMemberValue("Width", matches[0].Value);
                rootWindowNode.SetMemberValue("Height", matches[1].Value);
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
            if (elements.Count() == 0)
            {
                return null;
            }
            var element = elements.First();


            if (element.Name == XName.Get("reference"))
            {
                var refAttr = element.Attribute(XName.Get("ref"));
                if (refAttr == null)
                {
                    throw new NotImplementedException("Reference with no Ref attribute");
                }
                element = XamlLegacyXibReader.GetReference(currentElement.Document, refAttr.Value);
            }

            return element;
        }

        private static XamlMember GetColorMember(XamlType xType, string colorType)
        {
            switch (colorType)
            {
                case "IBUITextColor":
                    return xType.GetMember("Foreground");
                case "IBUINormalTitleColor":
                    return xType.GetMember("Foreground");
                case "IBUIBackgroundColor":
                    return xType.GetMember("Background");

                case "IBUIHighlightedTitleColor":
                    return xType.GetMember("Background");
                case "IBUIHighlightedColor":
                    return xType.GetMember("Background");
                case "IBUIShadowColor":
                    return xType.GetMember("Background");
                case "IBTintColor":
                    return xType.GetMember("Background");
                case "IBUITintColor":
                    return xType.GetMember("Background");

                default:
                    throw new NotImplementedException("Doesn't support color type: " + colorType);
            }
        }

        protected static void SetColor(XamlDomObject domObject, XElement color, XamlMember colorMember)
        {
            var colorType = color.Attribute(XName.Get("key")).Value;
            //XamlMember colorMember = GetColorMember(domObject.Type, colorType);

            //Image doesn't have a background but the XIB file allows setting it
            if (colorMember == null && domObject.Type.UnderlyingType == typeof(Image))
            {
                return;
            }

            var colorSpace = int.Parse(GetElementWithMatchingAttribute(color, "key", "NSColorSpace").Value);
            string value = null;
            switch (colorSpace)
            {
                case 1: //NSRGB
                {
                    var values =
                        XamlLegacyXibReader.DecodeFromBase64(GetElementWithMatchingAttribute(color, "key", "NSRGB").Value)
                            .Split(' ');

                    var color2 = Color.FromRgb((byte) (double.Parse(values[0])*255),
                        (byte) (double.Parse(values[1])*255),
                        (byte) (double.Parse(values[2])*255));
                    value = color2.ToString();
                }
                    break;
                case 2:
                case 3:
                {
                    var searchKey = colorSpace == 2 ? "NSRGB" : "NSWhite";
                    var asciiDecodedString =
                        XamlLegacyXibReader.DecodeFromBase64(GetElementWithMatchingAttribute(color, "key", searchKey).Value)
                            .Replace("\0", "");
                    var values = asciiDecodedString.Split(' ');

                    var doubleValues = colorSpace == 2 ? new double[4] : new double[3];
                    if (values.Length >= 1)
                    {
                        doubleValues[0] = double.Parse(values[0]);
                    }
                    if (values.Length >= 2)
                    {
                        doubleValues[1] = double.Parse(values[1]);
                    }
                    if (values.Length >= 3)
                    {
                        doubleValues[2] = double.Parse(values[2]);
                    }
                    if (colorSpace == 2)
                    {
                        if (values.Length == 4)
                        {
                            doubleValues[3] = double.Parse(values[3]);
                        }
                        Debug.Assert(values.Length <= 4);
                    }
                    else
                    {
                        Debug.Assert(values.Length <= 3);
                    }

                    byte[] rgbValues = null;
                    if (colorSpace == 2)
                    {
                        rgbValues = ColorConverters.CMYKtoRGB(doubleValues[0], doubleValues[1], doubleValues[2],
                            doubleValues[3]);
                    }
                    else if (colorSpace == 3)
                    {
                        rgbValues = ColorConverters.LabToRGB(doubleValues[0], doubleValues[1], doubleValues[2]);
                    }

                    var color2 = Color.FromRgb(rgbValues[0], rgbValues[1], rgbValues[2]);

                    value = color2.ToString();
                }
                    break;
                default:
                    throw new NotImplementedException("Doesn't suppor colorspace: " + colorSpace);
            }
            Debug.Assert(value != null);
            domObject.SetMemberValue(colorMember, value);
        }

        internal static void AddControlToTree(XamlDomMember member, XElement element)
        {
            var controlName = element.Attribute(XName.Get("class")).Value;

            List<XamlDomObject> objects;
            switch (controlName)
            {
                //TODO: Figure out if this is correct for SL Mobile.  Do they have the toolkit. Should we use label
                case "IBUILabel":
                    objects = LabelHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUIButton":
                    objects = ButtonHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUITextField":
                    objects = TextFieldHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUITextView":
                    objects = TextViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUIImageView":
                    objects = ImageViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUIWebView":
                    objects = WebViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUISegmentedControl":
                    objects = SegmentedControlHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUISlider":
                    objects = SliderHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUIScrollView":
                    objects = ScrollViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUIView":
                    objects = CreateObject(element, member.SchemaContext);
                    break;

                case "IBUITableView":
                    objects = TableViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUITableViewCell":
                    objects = TableViewCellHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUIActivityIndicatorView":
                    objects = ActivityIndicatorViewHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUIBarButtonItem":
                    objects = BarButtonHandler.CreateObject(element, member.SchemaContext);
                    break;
                case "IBUISwitch":
                    objects = SwitchHandler.CreateObject(element, member.SchemaContext);
                    break;

                //case "IBUINavigationBar": objects = LabelHandler.CreateObject(element, member.SchemaContext); break;
                //case "IBUINavigationBar": return typeof(UserControl);

                //case "IBUITableView": return typeof(UserControl);
                //case "IBUITableViewCell": return typeof(UserControl);

                //case "IBUITextField": return typeof(TextBox);
                //case "IBUIImageView": return typeof(Image);
                //case "IBUITextView": return typeof(TextBox);
                //case "IBUIProgressView": return typeof(ProgressBar);
                //case "IBUIWebView": return typeof(Microsoft.Phone.Controls.WebBrowser);

                ////TODO: FIgure out the correct thing for UIWebView.  Is there one in SL Mobile?
                //case "IBUISegmentedControl": return typeof(RadioButton);
                //case "IBUIView": return typeof(UserControl);
                //case "IBUIPageControl": return typeof(UserControl);
                //case "IBUITableView": return typeof(UserControl);
                //case "IBUITableViewCell": return typeof(UserControl);
                //case "IBUIScrollView": return typeof(ScrollViewer);
                //case "IBUIActivityIndicatorView": return typeof(UserControl);
                //case "IBUIPickerView": return typeof(UserControl);
                //case "IBUIDatePicker": return typeof(UserControl);
                //case "IBUINavigationBar": return typeof(UserControl);
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

            //// Find control type and create a node
            //XamlType controlType = member.SchemaContext.GetXamlType(XamlLegacyXibReader.GetControlType(controlName));
            //XamlDomObject domObject = new XamlDomObject(controlType);
            //member.Items.Add(domObject);

            //GetDimensions(element, domObject);

            //if (controlType.UnderlyingType == typeof(TextBox))
            //{
            //    domObject.SetMemberValue("TextWrapping", "Wrap");
            //}

            //var colors = from nsColor in element.Elements(XName.Get("object"))
            //             where nsColor.Attribute(XName.Get("class")).Value == "NSColor"
            //             select nsColor;

            //foreach (var color in colors)
            //{
            //    GetColor(controlType, domObject, color);
            //}

            //GetNormalTitle(element, domObject);

            //GetFont(element, controlType, domObject);

            //GetOpacity(element, controlType, domObject);

            //GetText(element, domObject);

            //GetImage(element, domObject);
        }

        protected static void GetDimensions(XElement element, XamlDomObject domObject)
        {
            var frame = GetElementWithMatchingAttribute(element, "key", "NSFrame");

            // Look for dimensions and location
            if (frame != null)
            {
                var dimensions = frame.Value;
                var matches = Regex.Matches(dimensions, @"\d+");
                // Certain controls have a 12 pixel border around them.  Make them look normal
                if (domObject.Type.CanAssignTo(domObject.SchemaContext.GetXamlType(typeof(TextBox))) ||
                    domObject.Type.CanAssignTo(domObject.SchemaContext.GetXamlType(typeof(Button)))
                    )
                {
                    var left = int.Parse(matches[0].Value) - 12; // XamlLegacyXibReader.WIDTHMULTIPLIER);
                    var top = int.Parse(matches[1].Value) - 12; // * XamlLegacyXibReader.HEIGHTMULTIPLIER);
                    var width = int.Parse(matches[2].Value) + 24; // * XamlLegacyXibReader.WIDTHMULTIPLIER);
                    var height = int.Parse(matches[3].Value) + 24; // * XamlLegacyXibReader.HEIGHTMULTIPLIER);

                    domObject.SetAttachableMemberValue(typeof(Canvas), "Left", left.ToString());
                    domObject.SetAttachableMemberValue(typeof(Canvas), "Top", top.ToString());
                    domObject.SetMemberValue("Width", width.ToString());
                    domObject.SetMemberValue("Height", height.ToString());

                    domObject.SetMemberValue("MinWidth", "0");
                    domObject.SetMemberValue("MinHeight", "0");
                }
                else
                {
                    domObject.SetAttachableMemberValue(typeof(Canvas), "Left", matches[0].Value);
                    domObject.SetAttachableMemberValue(typeof(Canvas), "Top", matches[1].Value);
                    domObject.SetMemberValue("Width", matches[2].Value);
                    domObject.SetMemberValue("Height", matches[3].Value);
                }
            }
            else
            {
                SetFrameSize(element, domObject);
            }
        }

        //static protected void GetNormalTitle(XElement element, XamlDomObject domObject)
        //{
        //    GetAndSetValue(element, domObject, "IBUINormalTitle", domObject.Type.ContentProperty);
        ////}

        //private void GetText(XElement element, XamlDomObject domObject)
        //{
        //    GetAndSetValue(element, domObject, "IBUIText", domObject.Type.ContentProperty);
        //}

        protected static void GetAndSetValue(XElement element, XamlDomObject domObject, string key, XamlMember member)
        {
            var valueElement = GetElementWithMatchingAttribute(element, "key", key);
            if (valueElement != null && !string.IsNullOrEmpty(valueElement.Value))
            {
                var attr = valueElement.Attribute(XName.Get("type"));
                var textValue = valueElement.Value;
                if (attr != null)
                {
                    if (attr.Value.Equals("base64-UTF8", StringComparison.InvariantCultureIgnoreCase))
                    {
                        var sb = new StringBuilder();
                        var newlines = textValue.Split('\n');
                        foreach (var line in newlines)
                        {
                            sb.Append(XamlLegacyXibReader.DecodeFromBase64(line));
                        }
                        textValue = sb.ToString();
                    }
                }
                domObject.SetMemberValue(member, textValue);
            }
        }
    }
}