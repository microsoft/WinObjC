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

#ifndef EAGL_IMPEXP
 #define EAGL_IMPEXP __declspec(dllimport)
#endif

#ifndef EAGL_EXPORT
 #ifdef __cplusplus
  #define EAGL_EXPORT EAGL_IMPEXP extern "C"
  #define EAGL_EXPORT_CLASS EAGL_IMPEXP 
 #else
  #define EAGL_EXPORT EAGL_IMPEXP extern  
  #define EAGL_EXPORT_CLASS EAGL_IMPEXP
 #endif
#endif
