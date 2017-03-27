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

#ifndef _PBXOBJECT_H_
#define _PBXOBJECT_H_

#include <stdlib.h> /* NULL */

#include "Plist.hpp"
#include "types.h"
#include "ErrorReporter.h"

class PBXDocument;

class PBXObject {
public:
    virtual ~PBXObject() = 0;
    virtual void resolvePointers() = 0;

    const PBXDocument& getOwner() const {
        return *m_pbxDoc;
    }
    const String& getId() const {
        return m_id;
    }
    const String& getType() const {
        return m_isa;
    }

protected:
    PBXObject();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) = 0;

    void checkFieldPtr(bool ptrCond, const String& fieldName) const {
        if (!ptrCond)
            m_accessER.reportError(fieldName + " is null.");
    }

    template <class T>
    void checkFieldVal(bool cond, const T& fieldVal, const String& fieldName) const {
        if (!cond)
            m_accessER.reportError(fieldName + " has unexpected value: \"" + fieldVal + "\".");
    }

    template <class T>
    void checkFieldNonEmpty(const T& fieldVal, const String& fieldName) const {
        if (fieldVal.empty())
            m_accessER.reportError(fieldName + " is empty.");
    }

    String m_id;
    const PBXDocument* m_pbxDoc;
    String m_isa;

    // Error reporter for initialization stage
    ErrorReporter m_parseER;
    // Error reporter for runtime access
    ErrorReporter m_accessER;
};

#endif /* _PBXOBJECT_H_ */
