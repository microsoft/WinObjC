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
using System.Windows.Media;
using Microsoft.VisualStudio.Text.Classification;
using Microsoft.VisualStudio.Utilities;

namespace ObjectiveC
{
    #region Format definition

    //[Export(typeof(EditorFormatDefinition))]
    //[ClassificationType(ClassificationTypeNames = "ObjectiveCKeyword")]
    //[Name("ObjectiveCKeyword")]
    //[UserVisible(false)]
    //[Order(Before = Priority.Default)]
    //internal sealed class ObjectiveCKeyword : ClassificationFormatDefinition
    //{
    //    public ObjectiveCKeyword()
    //    {
    //        this.DisplayName = "ObjectiveCKeyword"; //human readable version of the name
    //        this.ForegroundColor = Colors.BlueViolet;
    //    }
    //}

    //[Export(typeof(EditorFormatDefinition))]
    //[ClassificationType(ClassificationTypeNames = "ObjectiveCCompilerDirective")]
    //[Name("ObjectiveCCompilerDirective")]
    //[UserVisible(true)]
    //[Order(Before = Priority.Default)]
    //internal sealed class ObjectiveCCompilerDirective : ClassificationFormatDefinition
    //{
    //    public ObjectiveCCompilerDirective()
    //    {
    //        this.DisplayName = "Objective-C Compiler Directive"; //human readable version of the name
    //        this.ForegroundColor = Colors.BlueViolet;
    //    }
    //}

    #endregion //Format definition
}
