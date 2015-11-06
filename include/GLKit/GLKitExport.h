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
#ifndef GLKIT_IMPEXP
#ifdef __GLKIT_INSIDE_BUILD
#define GLKIT_IMPEXP __declspec(dllexport)
#else
#define GLKIT_IMPEXP __declspec(dllimport)
#endif
#endif

#ifndef GLKIT_EXPORT
#ifdef __cplusplus
#define GLKIT_EXPORT GLKIT_IMPEXP extern "C"
#define GLKIT_EXPORT_CLASS GLKIT_IMPEXP
#else
#define GLKIT_EXPORT GLKIT_IMPEXP extern
#define GLKIT_EXPORT_CLASS GLKIT_IMPEXP
#endif
#endif
