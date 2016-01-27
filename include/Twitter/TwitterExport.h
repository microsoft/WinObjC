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

#ifndef TWITTER_IMPEXP
#define TWITTER_IMPEXP __declspec(dllimport)
#endif

#ifndef TWITTER_EXPORT
#ifdef __cplusplus
#define TWITTER_EXPORT TWITTER_IMPEXP extern "C"
#define TWITTER_EXPORT_CLASS TWITTER_IMPEXP
#else
#define TWITTER_EXPORT TWITTER_IMPEXP extern
#define TWITTER_EXPORT_CLASS TWITTER_IMPEXP
#endif
#endif

#ifndef TWITTER_EXTERNC_BEGIN
#if defined(__cplusplus)
#define TWITTER_EXTERNC_BEGIN extern "C" {
#define TWITTER_EXTERNC_END }
#else
#define TWITTER_EXTERNC_BEGIN
#define TWITTER_EXTERNC_END
#endif
#endif