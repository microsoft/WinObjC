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

#ifndef COREFOUNDATION_EXPORT
#define COREFOUNDATION_EXPORT __declspec(dllimport) extern
#endif

#define COREFOUNDATION_EXPORT_DLL __declspec(dllexport) extern

#ifndef COREFOUNDATION_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREFOUNDATION_EXTERNC_BEGIN extern "C" {
#define COREFOUNDATION_EXTERNC_END }
#else
#define COREFOUNDATION_EXTERNC_BEGIN
#define COREFOUNDATION_EXTERNC_END
#endif
#endif