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

namespace XamlTools.XamlDom
{
    public abstract class XamlDomNode
    {
        private int _endLineNumber;
        private int _endLinePosition;

        private bool _isSealed;
        private int _startLineNumber;
        private int _startLinePosition;

        public virtual int StartLineNumber
        {
            get { return _startLineNumber; }
            set
            {
                CheckSealed();
                _startLineNumber = value;
            }
        }

        public virtual int StartLinePosition
        {
            get { return _startLinePosition; }
            set
            {
                CheckSealed();
                _startLinePosition = value;
            }
        }

        public virtual int EndLineNumber
        {
            get { return _endLineNumber; }
            set
            {
                CheckSealed();
                _endLineNumber = value;
            }
        }

        public virtual int EndLinePosition
        {
            get { return _endLinePosition; }
            set
            {
                CheckSealed();
                _endLinePosition = value;
            }
        }

        public virtual bool IsSealed
        {
            get { return _isSealed; }
        }

        public virtual void Seal()
        {
            _isSealed = true;
        }

        protected void CheckSealed()
        {
            if (IsSealed)
            {
                throw new NotSupportedException(string.Format("The {0} is sealed.", GetType().Name));
            }
        }
    }
}