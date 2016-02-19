//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#ifndef IAD_IMPEXP
#define IAD_IMPEXP __declspec(dllimport)
#endif

#ifndef IAD_EXPORT
#ifdef __cplusplus
#define IAD_EXPORT IAD_IMPEXP extern "C"
#define IAD_EXPORT_CLASS IAD_IMPEXP
#else
#define IAD_EXPORT IAD_IMPEXP extern
#define IAD_EXPORT_CLASS IAD_IMPEXP
#endif
#endif

#ifndef IAD_EXTERNC_BEGIN
#if defined(__cplusplus)
#define IAD_EXTERNC_BEGIN extern "C" {
#define IAD_EXTERNC_END }
#else
#define IAD_EXTERNC_BEGIN
#define IAD_EXTERNC_END
#endif
#endif
