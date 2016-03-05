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

#ifndef IMAGEIO_IMPEXP
#define IMAGEIO_IMPEXP __declspec(dllimport)
#endif

#ifndef IMAGEIO_EXPORT
#ifdef __cplusplus
#define IMAGEIO_EXPORT IMAGEIO_IMPEXP extern "C"
#define IMAGEIO_EXPORT_CLASS IMAGEIO_IMPEXP
#else
#define IMAGEIO_EXPORT IMAGEIO_IMPEXP extern
#define IMAGEIO_EXPORT_CLASS IMAGEIO_IMPEXP
#endif
#endif

#ifndef IMAGEIO_EXTERNC_BEGIN
#if defined(__cplusplus)
#define IMAGEIO_EXTERNC_BEGIN extern "C" {
#define IMAGEIO_EXTERNC_END }
#else
#define IMAGEIO_EXTERNC_BEGIN
#define IMAGEIO_EXTERNC_END
#endif
#endif
