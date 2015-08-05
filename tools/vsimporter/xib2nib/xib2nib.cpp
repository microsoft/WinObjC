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

// Xib2Nib.cpp.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
#include <vector>
#include <assert.h>

#include "XIBObject.h"
#include "XIBObjectTypes.h"
#include "NIBWriter.h"

void ConvertStoryboard(pugi::xml_document& doc)
{
    pugi::xml_node curNode = doc.first_child();

    //  Get topmost
    const char *initialController = curNode.attribute("initialViewController").value();

    for (; curNode; curNode = curNode.next_sibling()) {
        if (curNode.type() == pugi::xml_node_type::node_element) {
            XIBArray *root = new XIBArray();
            root->ScanStoryObjects(curNode);
        }
    }

    XIBObject::ParseAllStoryMembers();

    NIBWriter::ExportController(initialController);

    return;
}

void ConvertXIBToNib(FILE *fpOut, pugi::xml_document& doc)
{
    pugi::xml_node dataNode = doc.first_element_by_path("/archive/data");

    XIBObject *root = new XIBObject();
    root->ScanXIBNode(dataNode);
    XIBObject::ParseAllXIBMembers();

    XIBObject *Objects = root->FindMember("IBDocument.Objects");
    XIBObject *objectRecords = Objects->FindMember("objectRecords");
    XIBDictionary *properties = (XIBDictionary *) Objects->FindMember("flattenedProperties");

    XIBObject *orderedObjects = objectRecords->FindMember("orderedObjects");

    //  Go through each ordered object to find replacements
    for ( memberList::iterator cur = orderedObjects->_members.begin(); cur != orderedObjects->_members.end(); cur ++ ) {
        XIBMember *curMember = *cur;
        XIBObject *curObject = curMember->_obj;

        if ( strcmp(curObject->ClassName(), "IBObjectRecord") == 0 ) {
            XIBObject *obj = curObject->FindMember("object");

            if ( obj ) {
                XIBObject *objectId = curObject->FindMember("objectID");
                int objId = objectId->intValue();

                //  Attempt to find any associated custom class name
                char szPropName[255];
                sprintf(szPropName, "%d.CustomClassName", objId);
                const char *pClassName = obj->ClassName();

                XIBObject *customName = properties->ObjectForKey(szPropName);
                if ( customName ) {
                    const char *pCustomName = customName->stringValue();
                    obj->SetSwappedClassName(pCustomName);
                }
            }
        }
    }

    //  Create connections list
    XIBArray *connections = new XIBArray();
    XIBObject *connectionrecords = Objects->FindMember("connectionRecords");

    for ( memberList::iterator cur = connectionrecords->_members.begin(); cur != connectionrecords->_members.end(); cur ++ ) {
        XIBMember *curMember = *cur;
        XIBObject *curObject = curMember->_obj;

        if ( strcmp(curObject->ClassName(), "IBConnectionRecord") == 0 ) {
            XIBObject *obj = curObject->FindMember("connection");

            if ( obj ) {
                connections->AddMember(NULL, obj);
            }
        }
    }

    //  Sort connection records alphabetically using stable, uh, bubble sort
    for ( ;; ) {
        bool didSwap = false;

        for ( memberList::iterator cur = connections->_members.begin(); cur != connections->_members.end(); cur ++ ) {
            if ( (cur + 1) == connections->_members.end() ) break;
            XIBMember *curMember = (*cur);
            XIBMember *nextMember = (*(cur + 1));

            if ( curMember->_name != NULL ) continue;

            //  Event connections first
            if ( strcmp(curMember->_obj->_className, "IBCocoaTouchOutletConnection") == 0 &&
                 strcmp(nextMember->_obj->_className, "IBCocoaTouchEventConnection") == 0 ) {
                *cur = nextMember;
                *(cur + 1) = curMember;
                didSwap = true;
                continue;
            }

            if ( strcmp(curMember->_obj->_className, nextMember->_obj->_className) == 0 ) {
                const char *label1 = curMember->_obj->FindMember("label")->stringValue();
                const char *label2 = nextMember->_obj->FindMember("label")->stringValue();

                if ( strcmp(label1, label2) > 0 ) {
                    *cur = nextMember;
                    *(cur + 1) = curMember;
                    didSwap = true;
                }
            }
        }

        if ( !didSwap ) break;
    }

    //  Construct root object
    XIBObject *rootObjects = root->FindMember("IBDocument.RootObjects");
    rootObjects->_className = "NSArray";
    connections->_className = "NSArray";

    XIBArray *allObjects = new XIBArray();
    XIBArray *accessibilityObjects = new XIBAccessibilityArray();
    XIBArray *visibleWindows = new XIBArray();

    XIBObject *nibRoot = new XIBArray();
    nibRoot->_className = "NSObject";
    nibRoot->_members.clear();
    nibRoot->AddMember("UINibTopLevelObjectsKey", rootObjects);
    nibRoot->AddMember("UINibObjectsKey", allObjects);
    nibRoot->AddMember("UINibConnectionsKey", connections);
    nibRoot->AddMember("UINibVisibleWindowsKey", visibleWindows);
    nibRoot->AddMember("UINibAccessibilityConfigurationsKey", accessibilityObjects);
    nibRoot->AddMember("UINibKeyValuePairsKey", new XIBArray());

    NIBWriter *writer = new NIBWriter(fpOut);
    writer->_allUIObjects = allObjects;
    writer->_visibleWindows = visibleWindows;
    writer->AddOutputObject(nibRoot);
    writer->WriteData();
}

int main(int argc, char* argv[])
{
#if 0
    argv[1] = "input.xib";
    argv[2] = "output.nib";
    argc = 3;
#endif

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(argv[1]);
    if ( !result ) {
        printf("Error opening %s\n", argv[1]);
        exit(2);
        return -1;
    }

    pugi::xml_node rootNode = doc.first_child();
    const char *type = getNodeAttrib(rootNode, "type");
    if ( !type ) {
        printf("Unable to find input type\n");
        exit(3);
        return -1;
    }
    if ( strstr(type, "Storyboard.XIB") != NULL ) {
        ConvertStoryboard(doc);
    } else if ( strstr(type, ".XIB") != NULL) {
        if ( argc < 3 ) {
            printf("Usage: xib2nib input.xib output.nib\n");
            exit(1);
            return -1;
        }

        FILE *fpOut = fopen(argv[2], "wb");
        if ( !fpOut ) {
            printf("Error opening %s\n", argv[2]);
            exit(3);
            return -1;
        }

        ConvertXIBToNib(fpOut, doc);
        fclose(fpOut);
    } else {
        printf("Unable to determine input type type=\"%s\"\n", type);
        exit(4);
        return -1;
    }

    exit(0);
}
