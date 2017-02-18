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

#if defined(NO_STUBS) // stubs = errors
#ifndef NO_STUB_METHODS
#define NO_STUB_METHODS
#endif
#ifndef NO_STUB_PROPERTIES
#define NO_STUB_PROPERTIES
#endif
#elif !defined(NO_WARN_STUBS) // stubs = warnings [default]
#ifndef WARN_STUB_METHODS
#define WARN_STUB_METHODS
#endif
#ifndef WARN_STUB_PROPERTIES
#define WARN_STUB_PROPERTIES
#endif
#endif

// There are two ways to emit availability warnings: availability(platform, introduced, message) and deprecated().
// Unfortunately for us, we are not a Clang-recognized platform, and none of the existing platform values work for us. Ideally,
// we could set winobjc '1.0' as the target, and the availability attribute would take care of warning for us since we're below 1.0.
// We can't. deprecated() makes for a deprecation warning, but it does actually generate a warning. It is for this reason
// that we choose to use it.

#if defined(NO_STUB_METHODS)
#define STUB_METHOD __attribute__((unavailable("method not yet implemented")))
#define NOTINPLAN_METHOD __attribute__((unavailable("method not in current implementation roadmap")))
#elif defined(WARN_STUB_METHODS)
#define STUB_METHOD __attribute__((deprecated("method not yet implemented")))
#define NOTINPLAN_METHOD __attribute__((deprecated("method not in current implementation roadmap")))
#else
#define STUB_METHOD
#define NOTINPLAN_METHOD
#endif

#if defined(NO_STUB_PROPERTIES)
#define STUB_PROPERTY __attribute__((unavailable("property not yet implemented")))
#define NOTINPLAN_PROPERTY __attribute__((unavailable("property not in current implementation roadmap")))
#elif defined(WARN_STUB_PROPERTIES)
#define STUB_PROPERTY __attribute__((deprecated("property not yet implemented")))
#define NOTINPLAN_PROPERTY __attribute__((deprecated("property not in current implementation roadmap")))
#else
#define STUB_PROPERTY
#define NOTINPLAN_PROPERTY
#endif
