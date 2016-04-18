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
#pragma once

#ifndef CFNETWORK_IMPEXP
#define CFNETWORK_IMPEXP __declspec(dllimport)
#endif

#ifndef CFNETWORK_EXPORT
#ifdef __cplusplus
#define CFNETWORK_EXPORT CFNETWORK_IMPEXP extern "C"
#define CFNETWORK_EXPORT_CLASS CFNETWORK_IMPEXP
#else
#define CFNETWORK_EXPORT CFNETWORK_IMPEXP extern
#define CFNETWORK_EXPORT_CLASS CFNETWORK_IMPEXP
#endif
#endif

#ifndef CFNETWORK_EXTERNC_BEGIN
#if defined(__cplusplus)
#define CFNETWORK_EXTERNC_BEGIN extern "C" {
#define CFNETWORK_EXTERNC_END }
#else
#define CFNETWORK_EXTERNC_BEGIN
#define CFNETWORK_EXTERNC_END
#endif
#endif
