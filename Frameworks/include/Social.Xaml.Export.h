//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#ifndef SOCIAL_XAML_IMPEXP
#define SOCIAL_XAML_IMPEXP __declspec(dllimport)
#endif

#ifndef SOCIAL_XAML_EXPORT
#ifdef __cplusplus
#define SOCIAL_XAML_EXPORT extern "C" SOCIAL_XAML_IMPEXP
#else
#define SOCIAL_XAML_EXPORT extern SOCIAL_XAML_IMPEXP
#endif
#endif
