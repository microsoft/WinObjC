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

#ifndef _PLISTFUNCS_H_
#define _PLISTFUNCS_H_

#include <string>

#include "types.h"
#include "sbassert.h"
#include "Plist.hpp"

class ErrorReporter;

enum GetterBehavior { VALUE_OPTIONAL = 0, VALUE_REQUIRED = 1 };

int getIntForKey(const Plist::dictionary_type& dict, const String& key, GetterBehavior opt, const ErrorReporter& reporter);
void getStringForKey(const Plist::dictionary_type& dict, const String& key, String& ret, GetterBehavior opt, const ErrorReporter& reporter);
void getStringVectorForKey(
    const Plist::dictionary_type& dict, const String& key, StringVec& ret, GetterBehavior opt, const ErrorReporter& reporter);

template <typename T>
void getStringMapForKey(const Plist::dictionary_type& dict, const String& key, T& ret, GetterBehavior opt, const ErrorReporter& reporter);

template <typename T>
const T& getContainerForKey(const Plist::dictionary_type& dict, const String& key, GetterBehavior opt, const ErrorReporter& reporter);

template <typename T>
const T& castContainer(const boost::any& val, GetterBehavior opt, const ErrorReporter& reporter);

#endif /* _PLISTFUNCS_H_ */
