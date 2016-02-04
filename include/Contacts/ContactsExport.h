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

#ifndef CONTACTS_IMPEXP
#define CONTACTS_IMPEXP __declspec(dllimport)
#endif

#ifndef CONTACTS_EXPORT
#ifdef __cplusplus
#define CONTACTS_EXPORT CONTACTS_IMPEXP extern "C"
#define CONTACTS_EXPORT_CLASS CONTACTS_IMPEXP
#else
#define CONTACTS_EXPORT CONTACTS_IMPEXP extern
#define CONTACTS_EXPORT_CLASS CONTACTS_IMPEXP
#endif
#endif

#ifndef CONTACTS_EXTERNC_BEGIN
#if defined(__cplusplus)
#define CONTACTS_EXTERNC_BEGIN extern "C" {
#define CONTACTS_EXTERNC_END }
#else
#define CONTACTS_EXTERNC_BEGIN
#define CONTACTS_EXTERNC_END
#endif
#endif
