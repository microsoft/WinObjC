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

#ifndef ACCOUNTS_IMPEXP
#define ACCOUNTS_IMPEXP __declspec(dllimport)
#endif

#ifndef ACCOUNTS_EXPORT
#ifdef __cplusplus
#define ACCOUNTS_EXPORT ACCOUNTS_IMPEXP extern "C"
#define ACCOUNTS_EXPORT_CLASS ACCOUNTS_IMPEXP
#else
#define ACCOUNTS_EXPORT ACCOUNTS_IMPEXP extern
#define ACCOUNTS_EXPORT_CLASS ACCOUNTS_IMPEXP
#endif
#endif