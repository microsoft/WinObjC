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

#ifndef AUDIOUNIT_IMPEXP
#define AUDIOUNIT_IMPEXP __declspec(dllimport)
#endif

#ifndef AUDIOUNIT_EXPORT
#ifdef __cplusplus
#define AUDIOUNIT_EXPORT AUDIOUNIT_IMPEXP extern "C"
#define AUDIOUNIT_EXPORT_CLASS AUDIOUNIT_IMPEXP
#else
#define AUDIOUNIT_EXPORT AUDIOUNIT_IMPEXP extern
#define AUDIOUNIT_EXPORT_CLASS AUDIOUNIT_IMPEXP
#endif
#endif

#ifndef AUDIOUNIT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define AUDIOUNIT_EXTERNC_BEGIN extern "C" {
#define AUDIOUNIT_EXTERNC_END }
#else
#define AUDIOUNIT_EXTERNC_BEGIN
#define AUDIOUNIT_EXTERNC_END
#endif
#endif