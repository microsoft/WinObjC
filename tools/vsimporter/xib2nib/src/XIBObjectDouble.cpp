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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "XIBObjectDouble.h"

XIBObjectDouble::XIBObjectDouble(pugi::xml_node node) {
    _val = strtod(node.child_value(), NULL);
    _node = node;
}

XIBObjectDouble::XIBObjectDouble(double val) {
    _val = val;
}

bool XIBObjectDouble::NeedsSerialization() {
    return false;
}

void XIBObjectDouble::WriteData(NIBWriter* writer) {
    writer->WriteByte(NIBOBJ_DOUBLE);
    writer->WriteBytes(&_val, 8);
}

float XIBObjectDouble::floatValue() {
    return (float)_val;
}