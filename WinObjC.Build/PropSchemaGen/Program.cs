using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using System.Xml.Serialization;

using ClangCompile;
using System.Xml;
using System.IO;
using Microsoft.Build.Framework;

namespace PropSchemaGen
{
    /// <summary>
    /// Serves as main entry and Attribute parser for ClangCompile
    /// </summary>
    class Program
    {
        // Formality is a B.
        static string xmlns = "clr-namespace:Microsoft.Build.Framework.XamlTypes;assembly=Microsoft.Build.Framework";

        /// <summary>
        /// Assigns each property of a class to an XML attribute for a given Element
        /// </summary>
        /// <param name="doc">XmlDocument used to create elements</param>
        /// <param name="obj">Class whose properties are to be serialized</param>
        /// <param name="elem">Element to add attributes to</param>
        /// <returns>The same XmlElement, for brevity of code</returns>
        static XmlElement PropsToXmlAttr(XmlDocument doc, object obj, XmlElement elem)
        {
            foreach (PropertyInfo pi in obj.GetType().GetProperties(BindingFlags.Public | BindingFlags.DeclaredOnly | BindingFlags.Instance))
            {
                if (pi.GetValue(obj) != null && pi.GetValue(obj).ToString() != "")
                {
                    DefaultValueAttribute dvAttr = (DefaultValueAttribute)Attribute.GetCustomAttribute(pi, typeof(DefaultValueAttribute));

                    if (dvAttr == null)
                    {
                        elem.SetAttribute(pi.Name, pi.GetValue(obj).ToString());
                    }
                    else
                    {
                        if(dvAttr.Value.ToLower() == pi.GetValue(obj).ToString().ToLower()) {
                            Console.WriteLine("Default value of {0} skipped for {1}", dvAttr.Value, pi.Name);
                        }
                        else 
                        {
                            Console.WriteLine("Default value of {0} overwritten by {1} for {2}", dvAttr.Value, pi.GetValue(obj).ToString(), pi.Name);
                            elem.SetAttribute(pi.Name, pi.GetValue(obj).ToString());
                        }
                    }
                }
            }
            return elem;
        }

        /// <summary>
        /// Helper that creates an element "name" under "parentName.name" and populates the attributes with obj's properties.
        /// </summary>
        /// <param name="doc">XmlDocument used to create elements</param>
        /// <param name="obj">Class whose properties are to be serialized</param>
        /// <param name="elem">Element to which a subelement will be added</param>
        /// <param name="name">Name of the subelement</param>
        /// <returns>The same XmlElement, for brevity of code</returns>
        static XmlElement AttrToSubElem(XmlDocument doc, object obj, XmlElement elem, string name)
        {
            XmlElement subElem = (XmlElement)elem.AppendChild(doc.CreateElement(elem.Name + "." + name, xmlns)).AppendChild(doc.CreateElement(name, xmlns));
            PropsToXmlAttr(doc, obj, subElem);            
            return elem;
        }

        static void Main(string[] args)
        {
            XmlDocument doc = new XmlDocument();
            XmlElement projectElement = doc.CreateElement("ProjectSchemaDefinitions", xmlns);
            List<string> categories = new List<string>();

            doc.AppendChild(projectElement);

            // These attributes are probably common to all property schemas in Visual Studio.
            projectElement.SetAttribute("xmlns", "clr-namespace:Microsoft.Build.Framework.XamlTypes;assembly=Microsoft.Build.Framework");
            projectElement.SetAttribute("xmlns:x", "http://schemas.microsoft.com/winfx/2006/xaml");
            projectElement.SetAttribute("xmlns:sys", "clr-namespace:System;assembly=mscorlib");
            projectElement.SetAttribute("xmlns:transformCallback", "Microsoft.Cpp.Dev10.ConvertPropertyCallback");

            XmlElement ruleElement = (XmlElement)projectElement.AppendChild(doc.CreateElement("Rule", xmlns));

            ruleElement.AppendChild(doc.CreateComment("This file is generated! Modify with caution!"));

            RuleAttribute ruleAttr = (RuleAttribute)Attribute.GetCustomAttribute(typeof(Clang), typeof(RuleAttribute));

            if (ruleAttr == null)
            {
                throw new InvalidOperationException("Class requires Rule attribute!");
            }

            PropsToXmlAttr(doc, ruleAttr, ruleElement);

            DataSourceAttribute dataAttr = (DataSourceAttribute)Attribute.GetCustomAttribute(typeof(Clang), typeof(DataSourceAttribute));

            if (dataAttr == null)
            {
                throw new InvalidOperationException("Class requires DataSource attribute!");
            }

            AttrToSubElem(doc, dataAttr, ruleElement, "DataSource");

            XmlElement catsElement = (XmlElement)ruleElement.AppendChild(doc.CreateElement("Rule.Categories", xmlns));

            PropertyCategoryAttribute[] allAttributes = (PropertyCategoryAttribute[])Attribute.GetCustomAttributes(typeof(Clang), typeof(PropertyCategoryAttribute));
            allAttributes = allAttributes.OrderBy(x => x.Order).ToArray();
            Dictionary<string, PropertyCategoryAttribute> categoryMap = allAttributes.ToDictionary(x => x.Name);
            MemberInfo[] members = typeof(Clang).GetMembers(BindingFlags.Public | BindingFlags.DeclaredOnly | BindingFlags.Instance);

            foreach (PropertyCategoryAttribute catAttr in allAttributes)
            {
                XmlElement catElement = (XmlElement)catsElement.AppendChild(doc.CreateElement("Category", xmlns));

                PropsToXmlAttr(doc, catAttr, catElement);
            }

            foreach(MemberInfo member in members) {
                PropertyPageAttribute[] attrs = (PropertyPageAttribute[])Attribute.GetCustomAttributes(member, typeof(PropertyPageAttribute));

                foreach (PropertyPageAttribute attr in attrs)
                {
                    Console.WriteLine("Member name: {0}", member.Name);

                    if (attr.Category != null && attr.Category != "")
                    {
                        PropertyCategoryAttribute req;
                        if (!categoryMap.TryGetValue(attr.Category, out req))
                        {
                            Console.WriteLine("Category not found: {0}", attr.Category);
                        }
                    }
                }

                XmlElement curElement = null;

                switch (member.MemberType)
                {
                    case MemberTypes.Property:
                        PropertyInfo pInfo = (PropertyInfo)member;
                        PropertyPageAttribute propAttr = (PropertyPageAttribute)Attribute.GetCustomAttribute(member, typeof(PropertyPageAttribute));
                        
                        // Untracked parameter.
                        if (propAttr == null)
                        {
                            continue;
                        }

                        if (pInfo.PropertyType.IsSubclassOf(typeof(Enum)))
                        {
                            Console.WriteLine("Warning: Enumerations are invalid types because VisualStudio isn't that smart. You'll have to make it a string and back it with an enum.");
                            continue;
                        }
                        else if (pInfo.PropertyType.IsAssignableFrom(typeof(ITaskItem[])))
                        {
                            curElement = (XmlElement)ruleElement.AppendChild(doc.CreateElement("StringListProperty", xmlns));
                            PropsToXmlAttr(doc, propAttr, curElement).SetAttribute("Name", member.Name);
                        }
                        else if (pInfo.PropertyType.IsAssignableFrom(typeof(String)))
                        {
                            EnumeratedValueAttribute enumAttr = (EnumeratedValueAttribute)Attribute.GetCustomAttribute(member, typeof(EnumeratedValueAttribute));

                            if (enumAttr != null)
                            {
                                curElement = (XmlElement)ruleElement.AppendChild(doc.CreateElement("EnumProperty", xmlns));
                                PropsToXmlAttr(doc, propAttr, curElement).SetAttribute("Name", member.Name);

                                int foundAttr = 0;

                                FieldInfo[] fields = enumAttr.Enumeration.GetFields(BindingFlags.Public | BindingFlags.Static);
                                foreach (FieldInfo field in fields)
                                {
                                    FieldAttribute attr = (FieldAttribute)field.GetCustomAttribute(typeof(FieldAttribute));
                                    if (attr != null)
                                    {
                                        foundAttr++;
                                        PropsToXmlAttr(doc, attr, (XmlElement)curElement.AppendChild(doc.CreateElement("EnumValue", xmlns))).SetAttribute("Name", field.Name);
                                    }
                                }

                                if (foundAttr > 0 && foundAttr != fields.Length)
                                {
                                    Console.WriteLine("Not all fields in {0} have attributes", pInfo.Name);
                                }
                            }
                            else
                            {
                                curElement = (XmlElement)ruleElement.AppendChild(doc.CreateElement("StringProperty", xmlns));
                                PropsToXmlAttr(doc, propAttr, curElement).SetAttribute("Name", member.Name);
                            }
                        }
                        else if (pInfo.PropertyType.IsAssignableFrom(typeof(String[])))
                        {
                            curElement = (XmlElement)ruleElement.AppendChild(doc.CreateElement("StringListProperty", xmlns));
                            PropsToXmlAttr(doc, propAttr, curElement).SetAttribute("Name", member.Name);
                        }
                        else if (pInfo.PropertyType.IsAssignableFrom(typeof(Boolean)))
                        {
                            curElement = (XmlElement)ruleElement.AppendChild(doc.CreateElement("BoolProperty", xmlns));
                            PropsToXmlAttr(doc, propAttr, curElement).SetAttribute("Name", member.Name);
                        }
                        else if (pInfo.PropertyType.IsAssignableFrom(typeof(int)))
                        {
                            curElement = (XmlElement)ruleElement.AppendChild(doc.CreateElement("IntProperty", xmlns));
                            PropsToXmlAttr(doc, propAttr, curElement).SetAttribute("Name", member.Name);
                        }
                        break;
                    
                    // Fields are not exposed, only property accessors. 
                    case MemberTypes.Field:
                        break;

                    default:
                        break;

                }

                if (curElement != null)
                {
                    DataSourceAttribute dataSrcAttr = (DataSourceAttribute)Attribute.GetCustomAttribute(member, typeof(DataSourceAttribute));
                    if (dataSrcAttr != null)
                    {
                        AttrToSubElem(doc, dataSrcAttr, curElement, "DataSource");
                    }
                }
            }

            IEnumerable<Attribute> additionalAttrs = Attribute.GetCustomAttributes(typeof(Clang), typeof(ItemTypeAttribute));
            additionalAttrs = additionalAttrs.Concat(Attribute.GetCustomAttributes(typeof(Clang), typeof(FileExtensionAttribute)));
            additionalAttrs = additionalAttrs.Concat(Attribute.GetCustomAttributes(typeof(Clang), typeof(ContentTypeAttribute)));

            foreach (Attribute additionalAttr in additionalAttrs)
            {
                string attrName = additionalAttr.GetType().Name;
                attrName = attrName.Substring(0, attrName.Length - "Attribute".Length);
                // So lollers. C# is great. 
                PropsToXmlAttr(doc, additionalAttr, (XmlElement)projectElement.AppendChild(doc.CreateElement(attrName, xmlns)));
            }

            FileStream fs = new FileStream(@"..\..\sbclang.xml", FileMode.Create);
            XmlWriterSettings xmlSettings = new XmlWriterSettings();
            xmlSettings.NewLineOnAttributes = true;
            xmlSettings.Indent = true;
            xmlSettings.NamespaceHandling = NamespaceHandling.OmitDuplicates;
            XmlWriter writer = XmlWriter.Create(fs, xmlSettings);

            doc.Save(writer);

            Console.WriteLine("All done! Press any key to exit.");
            Console.ReadKey();
        }
    }
}
