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

#ifndef MAPKIT_IMPEXP
#define MAPKIT_IMPEXP __declspec(dllimport)
#endif

#ifndef MAPKIT_EXPORT
#ifdef __cplusplus
#define MAPKIT_EXPORT MAPKIT_IMPEXP extern "C"
#define MAPKIT_EXPORT_CLASS MAPKIT_IMPEXP
#else
#define MAPKIT_EXPORT MAPKIT_IMPEXP extern
#define MAPKIT_EXPORT_CLASS MAPKIT_IMPEXP
#endif
#endif

#ifndef MAPKIT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define MAPKIT_EXTERNC_BEGIN extern "C" {
#define MAPKIT_EXTERNC_END }
#else
#define MAPKIT_EXTERNC_BEGIN
#define MAPKIT_EXTERNC_END
#endif
#endif
