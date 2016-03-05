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

#ifndef METAL_IMPEXP
#define METAL_IMPEXP __declspec(dllimport)
#endif

#ifndef METAL_EXPORT
#ifdef __cplusplus
#define METAL_EXPORT METAL_IMPEXP extern "C"
#define METAL_EXPORT_CLASS METAL_IMPEXP
#else
#define METAL_EXPORT METAL_IMPEXP extern
#define METAL_EXPORT_CLASS METAL_IMPEXP
#endif
#endif

#ifndef METAL_EXTERNC_BEGIN
#if defined(__cplusplus)
#define METAL_EXTERNC_BEGIN extern "C" {
#define METAL_EXTERNC_END }
#else
#define METAL_EXTERNC_BEGIN
#define METAL_EXTERNC_END
#endif
#endif
