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

using System.ComponentModel.Composition;
using Microsoft.VisualStudio.Text.Classification;
using Microsoft.VisualStudio.Utilities;

namespace ObjectiveC
{
    internal static class ObjectiveCClassificationDefinition
    {
        [Export(typeof(ClassificationTypeDefinition))]
        [Name("ObjectiveCKeyword")]
        [BaseDefinition("Keyword")]
        internal static ClassificationTypeDefinition ObjCKeyword = null;

        [Export(typeof(ClassificationTypeDefinition))]
        [Name("ObjectiveCCompilerDirective")]
        [BaseDefinition("Keyword")]
        internal static ClassificationTypeDefinition ObjCCompilerDirective = null;

        [Export(typeof(ClassificationTypeDefinition))]
        [Name("ObjectiveCAtString")]
        [BaseDefinition("String")]
        internal static ClassificationTypeDefinition ObjCAtString = null;
    }
}
