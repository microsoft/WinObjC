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

#ifndef _PBXOBJECTIDCONVERT_H_
#define _PBXOBJECTIDCONVERT_H_

#include "types.h"
#include "PBXDocument.h"

/*
 * Converts a list of string ids corresponding to objects in the PBXDocument to a vector of
 * pointers of type T.
 */
template <class T>
void convertObjectIdList(const PBXDocument* pbxDoc, const StringVec& ids, std::vector<T*>& ret) {
    StringVec::const_iterator it = ids.begin();
    StringVec::const_iterator itEnd = ids.end();
    for (; it != itEnd; it++) {
        PBXObject* foundObject = pbxDoc->findObjectWithId(*it);
        T* obj = dynamic_cast<T*>(foundObject);
        if (obj)
            ret.push_back(obj);
    }
}

/*
 * Converts a string id corresponding to an object in the PBXDocument to a pointer of type T.
 */
template <class T>
void convertObjectId(const PBXDocument* pbxDoc, const String& id, T*& ret) {
    PBXObject* foundObject = pbxDoc->findObjectWithId(id);
    T* obj = dynamic_cast<T*>(foundObject);
    ret = obj;
}

#endif /* _PBXOBJECTIDCONVERT_H_ */
