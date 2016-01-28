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

#ifndef HOMEKIT_IMPEXP
#define HOMEKIT_IMPEXP __declspec(dllimport)
#endif

#ifndef HOMEKIT_EXPORT
#ifdef __cplusplus
#define HOMEKIT_EXPORT HOMEKIT_IMPEXP extern "C"
#define HOMEKIT_EXPORT_CLASS HOMEKIT_IMPEXP
#else
#define HOMEKIT_EXPORT HOMEKIT_IMPEXP extern
#define HOMEKIT_EXPORT_CLASS HOMEKIT_IMPEXP
#endif
#endif

#ifndef HOMEKIT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define HOMEKIT_EXTERNC_BEGIN extern "C" {
#define HOMEKIT_EXTERNC_END }
#else
#define HOMEKIT_EXTERNC_BEGIN
#define HOMEKIT_EXTERNC_END
#endif
#endif
