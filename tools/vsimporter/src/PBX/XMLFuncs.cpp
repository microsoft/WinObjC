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

#include <pugixml.hpp>

#include "XMLFuncs.h"
#include "ErrorReporter.h"

void getXMLProperty(const pugi::xml_node& node, const String& propName, String& ret, GetterBehavior opt, const ErrorReporter& reporter) {
    const pugi::xml_attribute attrib = node.attribute(propName.c_str());

    if (attrib)
        ret = attrib.value();
    else if (opt == VALUE_REQUIRED)
        reporter.reportError("Failed reading \"" + propName + "\" property.");
}
