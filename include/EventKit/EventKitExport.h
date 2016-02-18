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

#ifndef EVENTKIT_IMPEXP
#define EVENTKIT_IMPEXP __declspec(dllimport)
#endif

#ifndef EVENTKIT_EXPORT
#ifdef __cplusplus
#define EVENTKIT_EXPORT EVENTKIT_IMPEXP extern "C"
#define EVENTKIT_EXPORT_CLASS EVENTKIT_IMPEXP
#else
#define EVENTKIT_EXPORT EVENTKIT_IMPEXP extern
#define EVENTKIT_EXPORT_CLASS EVENTKIT_IMPEXP
#endif
#endif

#ifndef EVENTKIT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define EVENTKIT_EXTERNC_BEGIN extern "C" {
#define EVENTKIT_EXTERNC_END }
#else
#define EVENTKIT_EXTERNC_BEGIN
#define EVENTKIT_EXTERNC_END
#endif
#endif
