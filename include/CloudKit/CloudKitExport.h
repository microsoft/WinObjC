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

#ifndef CLOUDKIT_IMPEXP
#define CLOUDKIT_IMPEXP __declspec(dllimport)
#endif

#ifndef CLOUDKIT_EXPORT
#ifdef __cplusplus
#define CLOUDKIT_EXPORT CLOUDKIT_IMPEXP extern "C"
#define CLOUDKIT_EXPORT_CLASS CLOUDKIT_IMPEXP
#else
#define CLOUDKIT_EXPORT CLOUDKIT_IMPEXP extern
#define CLOUDKIT_EXPORT_CLASS CLOUDKIT_IMPEXP
#endif
#endif

#ifndef CLOUDKIT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define CLOUDKIT_EXTERNC_BEGIN extern "C" {
#define CLOUDKIT_EXTERNC_END }
#else
#define CLOUDKIT_EXTERNC_BEGIN
#define CLOUDKIT_EXTERNC_END
#endif
#endif
