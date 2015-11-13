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

#ifdef __cplusplus

#if defined(__WIN32__)
#if defined(COREDATA_INSIDE_BUILD)
#define COREDATA_EXPORT extern "C" __declspec(dllexport)
#else
#define COREDATA_EXPORT extern "C" __declspec(dllimport)
#endif
#else
#define COREDATA_EXPORT extern "C"
#endif

#else

#if defined(__WIN32__)
#if defined(COREDATA_INSIDE_BUILD)
#define COREDATA_EXPORT __declspec(dllexport) extern
#else
#define COREDATA_EXPORT __declspec(dllimport) extern
#endif
#else
#define COREDATA_EXPORT extern
#endif

#endif
