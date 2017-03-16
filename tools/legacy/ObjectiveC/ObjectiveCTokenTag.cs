//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using Microsoft.VisualStudio.Text;
using Microsoft.VisualStudio.Text.Classification;
using Microsoft.VisualStudio.Text.Editor;
using Microsoft.VisualStudio.Text.Tagging;
using Microsoft.VisualStudio.Utilities;

namespace ObjectiveC
{
    [Export(typeof(ITaggerProvider))]
    [ContentType("ObjectiveC")]
    [TagType(typeof(ObjectiveCTokenTag))]

    internal sealed class ObjectiveCTokenTagProvider : ITaggerProvider
    {
        public ITagger<T> CreateTagger<T>(ITextBuffer buffer) where T : ITag
        {
            return new ObjectiveCTokenTagger(buffer) as ITagger<T>;
        }
    }

    public class ObjectiveCTokenTag : ITag
    {
        public ObjectiveCTokenTypes type { get; private set; }

        public ObjectiveCTokenTag(ObjectiveCTokenTypes type)
        {
            this.type = type;
        }
    }

    internal sealed class ObjectiveCTokenTagger : ITagger<ObjectiveCTokenTag>
    {
        ITextBuffer mBuffer;
        IDictionary<string, ObjectiveCTokenTypes> mDict;

        internal ObjectiveCTokenTagger(ITextBuffer buffer)
        {
            mBuffer = buffer;
            mDict = new Dictionary<string, ObjectiveCTokenTypes>();

            // Keyword
            mDict["BOOL"] = ObjectiveCTokenTypes.Keyword;
            mDict["Class"] = ObjectiveCTokenTypes.Keyword;
            mDict["bycopy"] = ObjectiveCTokenTypes.Keyword;
            mDict["byref"] = ObjectiveCTokenTypes.Keyword;
            mDict["id"] = ObjectiveCTokenTypes.Keyword;
            mDict["IMP"] = ObjectiveCTokenTypes.Keyword;
            mDict["in"] = ObjectiveCTokenTypes.Keyword;
            mDict["inout"] = ObjectiveCTokenTypes.Keyword;
            mDict["nil"] = ObjectiveCTokenTypes.Keyword;
            mDict["NO"] = ObjectiveCTokenTypes.Keyword;
            mDict["Nil"] = ObjectiveCTokenTypes.Keyword;
            mDict["NULL"] = ObjectiveCTokenTypes.Keyword;
            mDict["oneway"] = ObjectiveCTokenTypes.Keyword;
            mDict["out"] = ObjectiveCTokenTypes.Keyword;
            mDict["Protocol"] = ObjectiveCTokenTypes.Keyword;
            mDict["SEL"] = ObjectiveCTokenTypes.Keyword;
            mDict["self"] = ObjectiveCTokenTypes.Keyword;
            mDict["super"] = ObjectiveCTokenTypes.Keyword;
            mDict["YES"] = ObjectiveCTokenTypes.Keyword;
            mDict["atomic"] = ObjectiveCTokenTypes.Keyword;
            mDict["nonatomic"] = ObjectiveCTokenTypes.Keyword;
            mDict["retain"] = ObjectiveCTokenTypes.Keyword;
            mDict["readonly"] = ObjectiveCTokenTypes.Keyword;
            mDict["readwrite"] = ObjectiveCTokenTypes.Keyword;
            mDict["strong"] = ObjectiveCTokenTypes.Keyword;
            mDict["weak"] = ObjectiveCTokenTypes.Keyword;
            mDict["unsafe_unretained"] = ObjectiveCTokenTypes.Keyword;
            mDict["_Complex"] = ObjectiveCTokenTypes.Keyword;
            mDict["_Imaginery"] = ObjectiveCTokenTypes.Keyword;

            // Compiler Directives
            mDict["@interface"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@end"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@implementation"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@protocol"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@class"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@public"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@protected"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@private"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@property"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@try"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@throw"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@catch"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@finally"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@synthesize"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@dynamic"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@selector"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@autoreleasepool"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@compatibility_alias"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@defs"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@encode"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@import"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@optional"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@package"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@required"] = ObjectiveCTokenTypes.CompilerDirective;
            mDict["@synchronized"] = ObjectiveCTokenTypes.CompilerDirective;
        }

        public event EventHandler<SnapshotSpanEventArgs> TagsChanged
        {
            add { }
            remove { }
        }

        public IEnumerable<ITagSpan<ObjectiveCTokenTag>> GetTags(NormalizedSnapshotSpanCollection spans)
        {
            foreach (SnapshotSpan curSpan in spans)
            {
                ITextSnapshotLine containingLine = curSpan.Start.GetContainingLine();
                int curLoc = containingLine.Start.Position;
                string[] delimiters = new string[10] { " ", "\t", ";", ":", ".", ",", "(", ")", "[", "]" };
                string[] tokens = containingLine.GetText().Split(delimiters, StringSplitOptions.None);

                foreach (string ObjectiveCToken in tokens)
                {
                    if (mDict.ContainsKey(ObjectiveCToken))
                    {
                        var tokenSpan = new SnapshotSpan(curSpan.Snapshot, new Span(curLoc, ObjectiveCToken.Length));
                        if( tokenSpan.IntersectsWith(curSpan) )
                        {
                            yield return new TagSpan<ObjectiveCTokenTag>(tokenSpan, new ObjectiveCTokenTag(mDict[ObjectiveCToken]));
                        }
                    }
                    else if (ObjectiveCToken.StartsWith("@\""))
                    {
                        var tokenSpan = new SnapshotSpan(curSpan.Snapshot, new Span(curLoc, 1));
                        if (tokenSpan.IntersectsWith(curSpan))
                        {
                            yield return new TagSpan<ObjectiveCTokenTag>(tokenSpan, new ObjectiveCTokenTag(ObjectiveCTokenTypes.AtString));
                        }
                    }

                    //add an extra char location because of the space
                    curLoc += ObjectiveCToken.Length + 1;
                }
            }
        }
    }
}
