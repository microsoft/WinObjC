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

#ifndef QUICKLOOK_IMPEXP
#define QUICKLOOK_IMPEXP __declspec(dllimport)
#endif

#ifndef QUICKLOOK_EXPORT
#ifdef __cplusplus
#define QUICKLOOK_EXPORT QUICKLOOK_IMPEXP extern "C"
#define QUICKLOOK_EXPORT_CLASS QUICKLOOK_IMPEXP
#else
#define QUICKLOOK_EXPORT QUICKLOOK_IMPEXP extern
#define QUICKLOOK_EXPORT_CLASS QUICKLOOK_IMPEXP
#endif
#endif

#ifndef QUICKLOOK_EXTERNC_BEGIN
#if defined(__cplusplus)
#define QUICKLOOK_EXTERNC_BEGIN extern "C" {
#define QUICKLOOK_EXTERNC_END }
#else
#define QUICKLOOK_EXTERNC_BEGIN
#define QUICKLOOK_EXTERNC_END
#endif
#endif
