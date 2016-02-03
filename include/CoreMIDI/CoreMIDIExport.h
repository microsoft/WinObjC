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

#ifndef COREMIDI_IMPEXP
#define COREMIDI_IMPEXP __declspec(dllimport)
#endif

#ifndef COREMIDI_EXPORT
#ifdef __cplusplus
#define COREMIDI_EXPORT COREMIDI_IMPEXP extern "C"
#define COREMIDI_EXPORT_CLASS COREMIDI_IMPEXP
#else
#define COREMIDI_EXPORT COREMIDI_IMPEXP extern
#define COREMIDI_EXPORT_CLASS COREMIDI_IMPEXP
#endif
#endif

#ifndef COREMIDI_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREMIDI_EXTERNC_BEGIN extern "C" {
#define COREMIDI_EXTERNC_END }
#else
#define COREMIDI_EXTERNC_BEGIN
#define COREMIDI_EXTERNC_END
#endif
#endif
