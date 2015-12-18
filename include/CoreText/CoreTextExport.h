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

#ifndef CORETEXT_IMPEXP
#define CORETEXT_IMPEXP __declspec(dllimport)
#endif

#ifndef CORETEXT_EXPORT
#ifdef __cplusplus
#define CORETEXT_EXPORT CORETEXT_IMPEXP extern "C"
#define CORETEXT_EXPORT_CLASS CORETEXT_IMPEXP
#else
#define CORETEXT_EXPORT CORETEXT_IMPEXP extern
#define CORETEXT_EXPORT_CLASS CORETEXT_IMPEXP
#endif
#endif
