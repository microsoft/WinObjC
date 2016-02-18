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

#pragma once

#ifndef COREDATA_IMPEXP
#define COREDATA_IMPEXP __declspec(dllimport)
#endif

#ifndef COREDATA_EXPORT
#ifdef __cplusplus
#define COREDATA_EXPORT COREDATA_IMPEXP extern "C"
#define COREDATA_EXPORT_CLASS COREDATA_IMPEXP
#else
#define COREDATA_EXPORT COREDATA_IMPEXP extern
#define COREDATA_EXPORT_CLASS COREDATA_IMPEXP
#endif
#endif

#ifndef COREDATA_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREDATA_EXTERNC_BEGIN extern "C" {
#define COREDATA_EXTERNC_END }
#else
#define COREDATA_EXTERNC_BEGIN
#define COREDATA_EXTERNC_END
#endif
#endif
