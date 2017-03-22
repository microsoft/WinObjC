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

#ifndef __XIBOBJECT_H
#define __XIBOBJECT_H

#include <vector>
#include <pugixml.hpp>
#include <string.h>
#include <unordered_set>

class XIBObject;

extern float screenWidth, screenHeight;

class XIBMember {
public:
    const char *_name, *_refId;
    XIBObject* _obj;
    int _outputNameIdx;

    XIBMember();
};

typedef std::vector<XIBObject*> xibList;
typedef std::vector<XIBMember*> memberList;

class XIBObjectInt;
class XIBObjectString;
class NIBWriter;
class ObjectConverter;
class XIBArray;

#include "NIBWriter.h"

typedef struct { float width, height; } CGSize;

typedef struct {
    float x, y;
    float width, height;
} UIRect;

typedef struct { float x, y; } UIPoint;

const char* getNodeAttrib(pugi::xml_node node, const char* name);

class XIBObject {
public:
    pugi::xml_node _node;
    const char *_className, *_swappedClassName;
    const char* _id;
    const char* _outputClassName;
    int _outputClassNameIdx;
    int _outputObjectIdx;
    bool _needsConversion;
    ObjectConverter* _converter;
    bool _isStory;

    XIBArray* _connectedObjects;
    XIBObject* _parent;
    xibList _variations;

    static xibList _allObjs;
    bool _ignoreUIObject;

public:
    memberList _members;
    memberList _outputMembers;
    int _outputMembersIdx;

    const char* _getAttrib(const char* name, bool isHandled);
    const char* getAttrib(const char* name);
    XIBObject();
    void ScanXIBNode(pugi::xml_node node);
    void ScanStoryObjects(pugi::xml_node node);
    void AddMember(const char* keyName, XIBObject* member);
    void AddOutputMember(NIBWriter* writer, const char* keyName, XIBObject* obj);

    virtual void InitFromXIB(XIBObject* obj);
    virtual void InitFromStory(XIBObject* obj);
    virtual void Awaken();
    virtual void ConvertStaticMappings(NIBWriter* writer, XIBObject* obj);

    virtual XIBObject* ApplyVariation(XIBObject* variation);

    XIBObject* FindMember(char* keyName);
    XIBObject* _FindMember(char* keyName, bool isHandled);
    XIBObject* FindMemberClass(char* className);
    virtual bool NeedsSerialization();

    virtual float floatValue();
    virtual int intValue();
    virtual const char* stringValue();
    virtual bool isNil();

    virtual bool EqualToString(const char* str);
    const char* ClassName();
    void SetSwappedClassName(const char* pName);
    const char* SwappedClassName();
    void ResolveReferences();

    static XIBObject* findReference(const char* id);
    static void ParseAllXIBMembers();
    static void ParseAllStoryMembers();

    virtual void EmitObject(NIBWriter* writer);
    virtual void WriteData(NIBWriter* writer);

    CGSize GetSize(char* pPropName, float defaultWidth, float defaultHeight);
    const char* GetString(char* pPropName, char* defaultValue);
    int GetInt(char* pPropName, int defaultValue);
    bool GetBool(char* pPropName, bool defaultValue);

    template <typename TData>
    void AddData(NIBWriter* writer, char* pPropName, const TData& data) {
        char* dataOut = (char*)malloc(sizeof(TData) + 1);
        dataOut[0] = 6;
        memcpy(&dataOut[1], &data, sizeof(TData));
        AddOutputMember(writer, strdup(pPropName), new XIBObjectDataWriter(dataOut, sizeof(TData) + 1));
    }

    void AddSize(NIBWriter* writer, char* pPropName, CGSize size);
    void AddPoint(NIBWriter* writer, char* pPropName, UIPoint point);
    void AddRect(NIBWriter* writer, char* pPropName, UIRect rect);

    void AddString(NIBWriter* writer, char* pPropNamme, const char* str);
    void AddMutableString(NIBWriter* writer, char* pPropNamme, char* str);
    void AddInt(NIBWriter* writer, char* pPropName, int val);
    void AddBool(NIBWriter* writer, char* pPropName, bool val);

    static std::unordered_set<size_t> _handledNodes;
    static void setNodeHandled(pugi::xml_node node);
    static void setAttrHandled(pugi::xml_attribute attr);
    static void setMemberHandled(XIBObject* member);
    void setMemberHandledByName(char* name);
    void setSelfHandled();
    static void getDocumentCoverage(pugi::xml_document& doc);

    const char* getAttrAndHandle(const char* name);
    XIBObject* FindMemberAndHandle(char* keyName);
};
#endif
