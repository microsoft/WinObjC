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

using Microsoft.VisualStudio.Language.StandardClassification;

namespace ObjectiveC
{
    [Export(typeof(ITaggerProvider))]
    [ContentType("ObjectiveC")]
    [TagType(typeof(ClassificationTag))]

    internal sealed class ObjectiveCProvider : ITaggerProvider
    {
        [Export]
        [Name("ObjectiveC")]
        [BaseDefinition("C/C++")]
        internal static ContentTypeDefinition ObjectiveCContentType = null;

        [Export]
        [FileExtension(".m")]
        [ContentType("ObjectiveC")]
        internal static FileExtensionToContentTypeDefinition ObjectiveCFileExt = null;

        [Export]
        [FileExtension(".mm")]
        [ContentType("ObjectiveC")]
        internal static FileExtensionToContentTypeDefinition ObjectiveCPPFileExt = null;

        [Export]
        [FileExtension(".h")]
        [ContentType("ObjectiveC")]
        internal static FileExtensionToContentTypeDefinition ObjectiveCHeaderExt = null;

        [Import]
        internal IClassificationTypeRegistryService ClassificationTypeRegistry = null;

        [Import]
        internal IBufferTagAggregatorFactoryService aggregatorFactory = null;

        [Import]
        internal IStandardClassificationService standardClassificationService = null;

        public ITagger<T> CreateTagger<T>(ITextBuffer buffer) where T : ITag
        {
            ITagAggregator<ObjectiveCTokenTag> objcTagAggregator = aggregatorFactory.CreateTagAggregator<ObjectiveCTokenTag>(buffer);
            return new ObjectiveCClassifier(buffer, objcTagAggregator, ClassificationTypeRegistry) as ITagger<T>;
        }
    }

    internal sealed class ObjectiveCClassifier : ITagger<ClassificationTag>
    {
        ITextBuffer mBuffer;
        ITagAggregator<ObjectiveCTokenTag> mAggregator;
        IDictionary<ObjectiveCTokenTypes, IClassificationType> mTypeDictionary;

        internal ObjectiveCClassifier(ITextBuffer buffer,
                               ITagAggregator<ObjectiveCTokenTag> tagAggregator,
                               IClassificationTypeRegistryService typeService)
        {
            mBuffer = buffer;
            mAggregator = tagAggregator;
            mTypeDictionary = new Dictionary<ObjectiveCTokenTypes, IClassificationType>();
            mTypeDictionary[ObjectiveCTokenTypes.Keyword] = typeService.GetClassificationType("ObjectiveCKeyword");
            mTypeDictionary[ObjectiveCTokenTypes.CompilerDirective] = typeService.GetClassificationType("ObjectiveCCompilerDirective");
            mTypeDictionary[ObjectiveCTokenTypes.AtString] = typeService.GetClassificationType("ObjectiveCAtString");
        }

        public event EventHandler<SnapshotSpanEventArgs> TagsChanged
        {
            add { }
            remove { }
        }

        public IEnumerable<ITagSpan<ClassificationTag>> GetTags(NormalizedSnapshotSpanCollection spans)
        {
            foreach (var tagSpan in this.mAggregator.GetTags(spans))
            {
                var tagSpans = tagSpan.Span.GetSpans(spans[0].Snapshot);
                yield return new TagSpan<ClassificationTag>(tagSpans[0], new ClassificationTag(mTypeDictionary[tagSpan.Tag.type]));
            }
        }
    }
}
