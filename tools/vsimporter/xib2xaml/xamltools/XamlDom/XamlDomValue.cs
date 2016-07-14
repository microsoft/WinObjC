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

using System.ComponentModel;
using System.Diagnostics;

namespace XamlTools.XamlDom
{
    [DebuggerDisplay("{Value}")]
    public class XamlDomValue : XamlDomItem
    {
        private object _value;

        public XamlDomValue()
        {
        }

        public XamlDomValue(object value)
        {
            _value = value;
        }

        [DefaultValue(null)]
        public virtual object Value
        {
            get { return _value; }
            set
            {
                CheckSealed();
                _value = value;
            }
        }
    }
}