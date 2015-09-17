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

#include "UIRuntimeEventConnection.h"
#include "UIControl.h"
#include <assert.h>

UIRuntimeEventConnection::UIRuntimeEventConnection()
{
    _outputClassName = "UIRuntimeEventConnection";
    _className = "UIRuntimeEventConnection";
    _eventMask = -1;
    _label = NULL;
}

void UIRuntimeEventConnection::InitFromXIB(XIBObject *obj)
{
    ObjectConverter::InitFromXIB(obj);

    _label = obj->GetString("label", NULL);
    _source = obj->FindMember("source");
    _destination = obj->FindMember("destination");

    _eventMask = -1;
    int type = obj->GetInt("IBEventType", -1);

    if ( type != -1 ) {
        _eventMask = (1 << (type - 1));
    }

    obj->_outputClassName = "UIRuntimeEventConnection";
}

void UIRuntimeEventConnection::InitFromStory(XIBObject *obj)
{
    ObjectConverter::InitFromStory(obj);

    obj->_outputClassName = "UIRuntimeEventConnection";

    //  Find the destination we're to plug into
    const char *destId = getAttrib("destination");
    if ( strcmp(obj->_className, "action") == 0 ) {
        _label = getAttrib("selector");
        const char *type = getAttrib("eventType");

        if ( type ) {
            if (strcmp(type, "touchUpInside") == 0) {
                _eventMask = UIControlEventTouchUpInside;
            } else if (strcmp(type, "touchDown") == 0) {
                _eventMask = UIControlEventTouchDown;
            } else if (strcmp(type, "valueChanged") == 0) {
                _eventMask = UIControlEventValueChanged;
            } else {
                printf("Unknown UIRuntimeEventConnection event type %s\n", type);
            }
        }
    } else {
        assert(0);
    }
    _source = _parent->_parent;

    ObjectConverter *destObj = (ObjectConverter *) findReference(destId);
    _destination = destObj;

    //  Check if the destination property is part of our heirarchy
    XIBObject *curObj = this;
    while ( curObj ) {
        if ( curObj == destObj ) {
            destObj = (ObjectConverter *) _source;
            break;
        }
        curObj = curObj->_parent;
    }
    if ( !destObj->_connectedObjects ) destObj->_connectedObjects = new XIBArray();

    destObj->_connectedObjects->AddMember(NULL, this);
}

void UIRuntimeEventConnection::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    ObjectConverter::ConvertStaticMappings(writer, obj);
    if ( _label ) AddString(writer, "UILabel", _label);
    AddOutputMember(writer, "UISource", _source);
    AddOutputMember(writer, "UIDestination", _destination);
    if ( _eventMask != -1 ) AddInt(writer, "UIEventMask", _eventMask);
}
