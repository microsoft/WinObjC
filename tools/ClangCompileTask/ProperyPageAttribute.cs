using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace ClangCompile
{
    // Default in terms of Visual Studio. IE, if nothing is set, it will be this.
    public class DefaultValueAttribute : System.Attribute
    {
        public string Value { get; set; }
    }

    public class OrderedAttribute : System.Attribute
    {
        public int Order { get; set; }
    }

    [AttributeUsage(AttributeTargets.Class, AllowMultiple=true)]
    public class PropertyCategoryAttribute : OrderedAttribute
    {
        public string Name { get; set; }
        public string DisplayName { get; set; }
        public string Subtype { get; set; }
    }

    public class EnumeratedValueAttribute : System.Attribute
    {
        public Type Enumeration { get; set; }
    }

    public class DataSourceAttribute : System.Attribute
    {
        public string Persistence { get; set; }
        public string ItemType { get; set; }
        public string SourceType { get; set; }
    }

    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
    public class FileExtensionAttribute : System.Attribute
    {
        public string Name { get; set; }
        public string ContentType { get; set; }
    }

    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
    public class ItemTypeAttribute : System.Attribute
    {
        public string Name { get; set; }
        public string DisplayName { get; set; }
    }

    [AttributeUsage(AttributeTargets.Class, AllowMultiple=true)]
    public class ContentTypeAttribute : System.Attribute
    {
        public string Name { get; set; }
        public string DisplayName { get; set; }
        public string ItemType { get; set; }
    }

    public class RuleAttribute : System.Attribute
    {
        public string Name { get; set; }
        public string PageTemplate { get; set; }
        public string SwitchPrefix { get; set; }
        public string DisplayName { get; set; }
        public string Order { get; set; }
    }

    public class PropertyPageAttribute : System.Attribute
    {
        public PropertyPageAttribute() : base()
        {
            IncludeInCommandLine = true;
            Visible = true;
        }
        public string Category { get; set; }
        public string Subtype { get; set; }
        public string DisplayName { get; set; }
        public string Description { get; set; }
        public string Switch { get; set; }
        public string ReverseSwitch { get; set; }
        [DefaultValue(Value = "true")]
        public Boolean IncludeInCommandLine { get; set; }
        [DefaultValue(Value = "true")]
        public Boolean Visible { get; set; }
    }

    [AttributeUsage(AttributeTargets.Field, AllowMultiple = false)]
    public class FieldAttribute : System.Attribute
    {
        public string Switch { get; set; }
        public string DisplayName { get; set; }
        public string Description { get; set; }
    }

    [AttributeUsage(AttributeTargets.Property, AllowMultiple = false)]
    public class ResolvePathAttribute : System.Attribute
    {

    }
}
