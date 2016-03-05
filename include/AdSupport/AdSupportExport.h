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

#ifndef ADSUPPORT_IMPEXP
#define ADSUPPORT_IMPEXP __declspec(dllimport)
#endif

#ifndef ADSUPPORT_EXPORT
#ifdef __cplusplus
#define ADSUPPORT_EXPORT ADSUPPORT_IMPEXP extern "C"
#define ADSUPPORT_EXPORT_CLASS ADSUPPORT_IMPEXP
#else
#define ADSUPPORT_EXPORT ADSUPPORT_IMPEXP extern
#define ADSUPPORT_EXPORT_CLASS ADSUPPORT_IMPEXP
#endif
#endif

#ifndef ADSUPPORT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define ADSUPPORT_EXTERNC_BEGIN extern "C" {
#define ADSUPPORT_EXTERNC_END }
#else
#define ADSUPPORT_EXTERNC_BEGIN
#define ADSUPPORT_EXTERNC_END
#endif
#endif
