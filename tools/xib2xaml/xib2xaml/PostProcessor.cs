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

using System.Linq;
using System.Xaml;
using XamlTools.XamlDom;

namespace Xib2Xaml
{
    internal class PostProcessor
    {
        private readonly XamlDomObject _rootNode;

        public PostProcessor(XamlDomObject objectNode)
        {
            _rootNode = objectNode;
        }

        internal XamlDomObject Process()
        {
            _rootNode.Namespaces.Add(new XamlDomNamespace(new NamespaceDeclaration(XamlLanguage.Xaml2006Namespace, "x")));

            //TODO: We need to create "unknown" nodes for Content properties since Silverlight 3 doesn't support
            //      direct content.  I think that if we spew out unknown members with the right values, it'll right
            //      things as attributes instead of content.
            foreach (var contentMember in
                from objectNode in _rootNode.DescendantsAndSelf()
                where objectNode.Type.ContentProperty != null
                where objectNode.HasMember(objectNode.Type.ContentProperty)
                select objectNode.GetMemberNode(objectNode.Type.ContentProperty))
            {
                // Only special case things that have one child that is a value node
                if (contentMember.Items.Count == 1)
                {
                    var valueNode = contentMember.Item as XamlDomValue;
                    if (valueNode != null)
                    {
                        var fakeMember = new NonContentPropertyXamlMember(contentMember.Member);

                        var newMemberNode = new XamlDomMember(fakeMember, valueNode);
                        var parentObject = contentMember.Parent;
                        parentObject.RemoveMemberNode(contentMember);
                        parentObject.MemberNodes.Add(newMemberNode);
                    }
                }
            }

            return _rootNode;
        }
    }
}