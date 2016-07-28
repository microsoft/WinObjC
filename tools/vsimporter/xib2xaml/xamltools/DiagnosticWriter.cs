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
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Xaml;

namespace XamlTools
{
    public class DiagnosticWriter : XamlWriter, IXamlLineInfoConsumer
    {
        private const string _nullString = "*null*";
        private const string _nullObjectFromMember = "*objectFromMember*";
        private int _depth;

        private bool _lineInfoIsNew;
        private int _lineNumber;
        private int _linePosition;

        private readonly TextWriter _out;
        private SimpleWriterStack _stack;
        private readonly XamlWriter _wrappedWriter;
        private IXamlLineInfoConsumer _wrappedWriterLineInfoConsumer;

        public DiagnosticWriter(XamlSchemaContext xamlSchemaContext)
        {
            Initialize();
            _out = Console.Out;
            SchemaContext = xamlSchemaContext;
        }

        public DiagnosticWriter(XamlWriter wrappedWriter, XamlSchemaContext xamlSchemaContext)
            : this(xamlSchemaContext)
        {
            _wrappedWriter = wrappedWriter;
            Initialize();
        }

        public DiagnosticWriter(TextWriter outputStream, XamlWriter wrappedWriter, XamlSchemaContext xamlSchemaContext)
            : this(outputStream, xamlSchemaContext)
        {
            _wrappedWriter = wrappedWriter;
            Initialize();
        }

        public DiagnosticWriter(TextWriter outputStream, XamlSchemaContext xamlSchemaContext)
        {
            Initialize();
            _out = outputStream;
            SchemaContext = xamlSchemaContext;
        }

        public bool ShowCloseComments { get; set; }

        public string IndentUnit { get; set; }

        public string FromMemberText { get; set; }

        public bool ShowLinebreaks { get; set; }

        public string UnknownText { get; set; }

        public string ImplicitText { get; set; }

        private string LineInfoString
        {
            get
            {
                if (_lineInfoIsNew)
                {
                    _lineInfoIsNew = false;
                    return string.Format("({0},{1})", _lineNumber, _linePosition);
                }
                return string.Empty;
            }
        }

        private void Initialize()
        {
            IndentUnit = " ";
            FromMemberText = "Retrieved";
            UnknownText = "Unknown";
            ImplicitText = "Implicit";
            _stack = new SimpleWriterStack();
            _wrappedWriterLineInfoConsumer = _wrappedWriter as IXamlLineInfoConsumer;
        }

        private static Type FindType(string name)
        {
            foreach (var asm in AppDomain.CurrentDomain.GetAssemblies())
            {
                foreach (var t in asm.GetTypes())
                {
                    if (t.Name == name)
                        return t;
                }
            }
            return null;
        }

        // =========== private ===============
        private void Indent()
        {
            for (var i = 0; i < _depth; i++)
            {
                _out.Write(IndentUnit);
            }
        }

        #region XamlWriter
        public override void WriteGetObject()
        {
            WriteObject(null, true);
        }

        public override void WriteStartObject(XamlType xamlType)
        {
            WriteObject(xamlType, false);
        }

        private void WriteObject(XamlType xamlType, bool isFromMember)

        {
            Indent();

            if (isFromMember)
            {
                _out.Write("GO");
            }
            else
            {
                _out.Write("SO ");
            }

            SimpleWriterFrame frame;
            if (_stack.CurrentIndex == 0 ||
                _stack.Peek().NodeType == XamlNodeType.StartObject ||
                _stack.Peek().NodeType == XamlNodeType.GetObject)
            {
                frame = new SimpleWriterFrame();
                _stack.Push(frame);
            }
            else
            {
                frame = _stack.Peek();
            }

            frame.Type = xamlType;

            if (xamlType == null)
            {
                if (isFromMember)
                {
                    frame.NodeType = XamlNodeType.GetObject;
                }
                else
                {
                    _out.Write(_nullString);
                }
            }
            else
            {
                // Figure out prefix
                frame.NodeType = XamlNodeType.StartObject;
                var xmlNamespaces = xamlType.GetXamlNamespaces();
                var prefix = _stack.FindPrefixFromXmlnsList(xmlNamespaces);
                _stack.Peek().TypePrefix = prefix;

                switch (prefix)
                {
                    case null:
                        var nullStr = isFromMember ? _nullObjectFromMember : _nullString;
                        _out.Write(nullStr + ":");
                        break;
                    case "":
                        break;
                    default:
                        _out.Write("{0}:", prefix);
                        break;
                }

                if (xamlType.TypeArguments != null)
                {
                    _out.Write("{0}({1})", xamlType.Name, Join(xamlType.TypeArguments, PrintType, ", "));
                }
                else
                {
                    _out.Write("{0}", xamlType.Name);
                }
            }

            if (!isFromMember && xamlType.IsUnknown)
            {
                _out.Write("     [{0}]", UnknownText);
            }

            _out.WriteLine("     {0}", LineInfoString);
            ++_depth;

            if (_wrappedWriter != null)
            {
                if (isFromMember)
                {
                    _wrappedWriter.WriteGetObject();
                }
                else
                {
                    _wrappedWriter.WriteStartObject(xamlType);
                }
            }
        }

        private string UnknownLabel(XamlType type)
        {
            return type.IsUnknown
                ? string.Format("   [{0}]", UnknownText)
                : string.Empty;
        }

        private string PrintType(XamlType type)
        {
            return type.Name +
                   (type.TypeArguments == null
                       ? string.Empty
                       : "(" + Join(type.TypeArguments, PrintType, ", ") + ")")
                   + UnknownLabel(type);
        }

        private delegate S Func<R, S>(R src);

        private static string Join<R>(IList<R> src, Func<R, string> ToString, string delim)
        {
            var sb = new StringBuilder();
            var remaining = src.Count;
            foreach (var r in src)
            {
                sb.Append(ToString(r));
                if (--remaining > 0)
                    sb.Append(delim);
            }

            return sb.ToString();
        }

        public override void WriteEndObject()
        {
            --_depth;
            Indent();

            _out.Write("EO");

            var xamlType = _stack.Peek().Type;

            if (ShowCloseComments)
            {
                _out.Write("        // ");

                if (xamlType == null)
                {
                    _out.Write(_nullString);
                }
                else
                {
                    var xmlNamespaces = xamlType.GetXamlNamespaces();
                    var prefix = _stack.FindPrefixFromXmlnsList(xmlNamespaces);

                    if (!string.IsNullOrEmpty(prefix))
                    {
                        _out.Write("{0}:", prefix);
                    }
                    _out.Write("{0}", xamlType.Name);
                }
            }
            _out.WriteLine("     {0}", LineInfoString);

            _stack.Pop();

            if (_wrappedWriter != null)
            {
                _wrappedWriter.WriteEndObject();
            }
        }

        public override void WriteStartMember(XamlMember property)
        {
            Indent();

            _out.Write("SM ");

            _stack.Peek().Member = property;

            if (property == null)
            {
                _out.Write(_nullString);
            }
            else
            {
                var xmlns = property.GetXamlNamespaces();
                var prefix = _stack.FindPrefixFromXmlnsList(xmlns);
                if (prefix != string.Empty && prefix != _stack.Peek().TypePrefix)
                {
                    _out.Write("{0}:", prefix);
                }

                if (property.IsAttachable)
                {
                    _out.Write("{0}.", property.DeclaringType.Name);
                }
                _out.Write("{0}", property.Name);

                if (property.IsUnknown)
                {
                    _out.Write("     [{0}]", UnknownText);
                }
            }

            _out.WriteLine("     {0}", LineInfoString);
            ++_depth;

            if (_wrappedWriter != null)
            {
                _wrappedWriter.WriteStartMember(property);
            }
        }

        public override void WriteEndMember()
        {
            --_depth;
            Indent();

            _out.Write("EM");

            var property = _stack.Peek().Member;

            if (ShowCloseComments)
            {
                _out.Write("        // ");
                if (property == null)
                {
                    _out.Write(_nullString);
                }
                else
                {
                    var xmlNamespaces = _stack.Peek().Type.GetXamlNamespaces();
                    var prefix = _stack.FindPrefixFromXmlnsList(xmlNamespaces);

                    if (prefix != string.Empty && prefix != _stack.Peek().TypePrefix)
                    {
                        _out.Write("{0}:", prefix);
                    }
                    if (property.IsAttachable)
                    {
                        _out.Write("{0}.", property.DeclaringType.Name);
                    }
                    _out.Write("{0}", property.Name);
                }
            }

            _stack.Peek().Member = null;

            _out.WriteLine("     {0}", LineInfoString);

            if (_wrappedWriter != null)
            {
                _wrappedWriter.WriteEndMember();
            }
        }

        public override void WriteValue(object value)
        {
            Indent();

            var valueString = value as string;
            if (value == null)
            {
                _out.Write("V ", _nullString);
            }
            else if (valueString != null)
            {
                if (ShowLinebreaks)
                {
                    valueString = valueString.Replace("\n", "\\n");
                }
                _out.Write("V \"{0}\"", valueString);
            }
            else
            {
                _out.Write("V ({0})  [{1}]", value, value.GetType().Name);
            }
            _out.WriteLine("     {0}", LineInfoString);

            if (_wrappedWriter != null)
            {
                _wrappedWriter.WriteValue(value);
            }
        }

        public override void WriteNamespace(NamespaceDeclaration namespaceDeclaration)
        {
            var xamlNs = namespaceDeclaration.Namespace;
            var prefix = namespaceDeclaration.Prefix;
            Indent();
            var prefixString = string.IsNullOrEmpty(prefix) ? string.Empty : ":" + prefix;
            if (xamlNs == null)
            {
                _out.Write("NS  xmlns{0}={1}", prefixString, _nullString);
            }
            else
            {
                _out.Write("NS  xmlns{0}=\"{1}\"", prefixString, xamlNs);
            }
            _out.WriteLine("     {0}", LineInfoString);

            SimpleWriterFrame frame;
            if (_stack.CurrentIndex == 0)
            {
                frame = new SimpleWriterFrame();
                _stack.Push(frame);
            }
            else
            {
                frame = _stack.Peek();
                if (frame.NodeType == XamlNodeType.GetObject ||
                    frame.NodeType == XamlNodeType.StartObject)
                {
                    frame = new SimpleWriterFrame();
                    _stack.Push(frame);
                }
            }

            frame.NodeType = XamlNodeType.StartMember;
            frame.AddNamespaceTableEntry(xamlNs, prefix);

            if (_wrappedWriter != null)
            {
                _wrappedWriter.WriteNamespace(new NamespaceDeclaration(xamlNs, prefix));
            }
        }

        protected override void Dispose(bool disposing)
        {
            try
            {
                if (disposing && !IsDisposed)
                {
                    Indent();
                    _out.WriteLine("Closed.");

                    if (_wrappedWriter != null)
                    {
                        _wrappedWriter.Close();
                    }
                }
            }
            finally
            {
                base.Dispose(disposing);
            }
        }

        public override XamlSchemaContext SchemaContext { get; }

        public object Result
        {
            get
            {
                var objectWriter = _wrappedWriter as XamlObjectWriter;
                if (objectWriter != null)
                {
                    return objectWriter.Result;
                }
                return null;
            }
        }
        #endregion

        #region IXamlLineInfoConsumer Members
        public void SetLineInfo(int lineNumber, int linePosition)
        {
            {
                _lineNumber = lineNumber;
                _linePosition = linePosition;
                _lineInfoIsNew = true;

                if (_wrappedWriterLineInfoConsumer != null && _wrappedWriterLineInfoConsumer.ShouldProvideLineInfo)
                {
                    _wrappedWriterLineInfoConsumer.SetLineInfo(lineNumber, linePosition);
                }
            }
        }

        public bool ShouldProvideLineInfo
        {
            get { return true; }
        }

        #endregion
    }

    public class SimpleWriterFrame
    {
        public Dictionary<string, string> NamespaceTable;

        public SimpleWriterFrame(XamlType type)
        {
            Type = type;
        }

        public SimpleWriterFrame()
        {
        }

        public XamlNodeType NodeType { get; set; }
        public XamlType Type { get; set; }
        public string TypePrefix { get; set; }
        public XamlMember Member { get; set; }

        public void AddNamespaceTableEntry(string namespaceUri, string prefix)
        {
            if (NamespaceTable == null)
            {
                NamespaceTable = new Dictionary<string, string>();
            }
            // right now, we only store the first prefix in the NamespaceTable.  Ideally, we'd store them all and give back the best one (shortest?).
            if (!NamespaceTable.ContainsKey(namespaceUri))
            {
                NamespaceTable.Add(namespaceUri, prefix);
            }
        }
    }

    public class SimpleWriterStack
    {
        private const int InitialStackSize = 100;

        private SimpleWriterFrame[] _stackData = new SimpleWriterFrame[InitialStackSize];

        public int CurrentIndex { get; set; }

        public void Push(SimpleWriterFrame frame)
        {
            _stackData[CurrentIndex++] = frame;
            if (CurrentIndex == _stackData.Length)
            {
                //double the size of the stack
                var newStackData = new SimpleWriterFrame[_stackData.Length*2];
                _stackData.CopyTo(newStackData, 0);
                _stackData = newStackData;
            }
        }

        public SimpleWriterFrame Peek()
        {
            return _stackData[CurrentIndex - 1];
        }

        public SimpleWriterFrame Pop()
        {
            return _stackData[--CurrentIndex];
        }

        public string FindPrefixFromXmlnsList(IList<string> xmlnsList)
        {
            // this case should only have one uri in the list.
            if (xmlnsList[0] == "http://www.w3.org/XML/1998/namespace")
            {
                return "xml";
            }

            var searchIndex = CurrentIndex;
            for (var i = CurrentIndex - 1; i >= 0; i--)
            {
                var searchFrame = _stackData[i];
                if (searchFrame.NamespaceTable != null)
                {
                    foreach (var xmlns in xmlnsList)
                    {
                        string prefix;
                        if (searchFrame.NamespaceTable.TryGetValue(xmlns, out prefix))
                        {
                            return prefix;
                        }
                    }
                }
            }

            // This case should only have one uri in the list.
            foreach (var xmlns in xmlnsList)
            {
                if (xmlns == "http://schemas.microsoft.com/winfx/2006/xaml"
                     || xmlns == "http://schemas.microsoft.com/winfx/2009/xaml"
                    )
                {
                    return "xamlNamespace"; // in case nobody used the xamlnamespace
                }
            }
            return null;
        }
    }
}