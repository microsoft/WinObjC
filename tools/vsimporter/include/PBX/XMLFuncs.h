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

#ifndef _XMLFUNCS_H_
#define _XMLFUNCS_H_

#include "types.h"

namespace pugi {
class xml_document;
class xml_node;
};

class ErrorReporter;

enum GetterBehavior { VALUE_OPTIONAL = 0, VALUE_REQUIRED = 1 };

void getXMLProperty(const pugi::xml_node& node, const String& propName, String& ret, GetterBehavior opt, const ErrorReporter& reporter);

#endif /* _XMLFUNCS_H_ */
