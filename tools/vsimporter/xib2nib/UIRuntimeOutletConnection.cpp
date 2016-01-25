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

#include "UIRuntimeOutletConnection.h"
#include <assert.h>

UIRuntimeOutletConnection::UIRuntimeOutletConnection() {
    _outputClassName = "UIRuntimeOutletConnection";
    _className = "UIRuntimeOutletConnection";
}

void UIRuntimeOutletConnection::InitFromXIB(XIBObject* obj) {
    ObjectConverter::InitFromXIB(obj);

    _outputClassName = "UIRuntimeOutletConnection";
    _label = obj->GetString("label", NULL);
    _source = obj->FindMember("source");
    _destination = obj->FindMember("destination");
}

void UIRuntimeOutletConnection::InitFromStory(XIBObject* obj) {
    ObjectConverter::InitFromStory(obj);

    _outputClassName = "UIRuntimeOutletConnection";

    //  Find the destination we're to plug into
    const char* destId = getAttrAndHandle("destination");
    _label = getAttrAndHandle("property");
    _source = _parent->_parent;

    ObjectConverter* destObj = (ObjectConverter*)findReference(destId);
    _destination = destObj;
    // TODO: destobj could be null and this crashes it
    //  Check if the destination property is part of our heirarchy
    XIBObject* curObj = this;
    while (curObj) {
        if (curObj == destObj) {
            destObj = (ObjectConverter*)_source;
            break;
        }
        curObj = curObj->_parent;
    }
    if (!destObj->_connectedObjects)
        destObj->_connectedObjects = new XIBArray();

    destObj->_connectedObjects->AddMember(NULL, this);
}

void UIRuntimeOutletConnection::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    ObjectConverter::ConvertStaticMappings(writer, obj);
    AddString(writer, "UILabel", _label);
    AddOutputMember(writer, "UISource", _source);
    AddOutputMember(writer, "UIDestination", _destination);
}
