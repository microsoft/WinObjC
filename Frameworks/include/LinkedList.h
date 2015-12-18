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

#ifndef __UTILS_LINKEDLIST_H
#define __UTILS_LINKEDLIST_H

#include <malloc.h>
#ifdef EBRIUS
#include "Foundation/NSArray.h"
#endif

#define DECLTYPE decltype

#define LLTREE_FOREACH(var, objname)                                                                           \
    for (DECLTYPE(objname) var = objname->firstChild, __nextNode = var ? var->nextSibling : NULL; var != NULL; \
         var = __nextNode, __nextNode = var ? var->nextSibling : NULL)
#define LLTREE_FOREACH_REVERSE(var, objname)                                                                  \
    for (DECLTYPE(objname) var = objname->lastChild, __nextNode = var ? var->prevSibling : NULL; var != NULL; \
         var = __nextNode, __nextNode = var ? var->prevSibling : NULL)

template <class T, class objectOwnerType>
class LLTreeNode {
private:
    template <typename O>
    using _hasPrivateT = std::is_same<decltype(std::declval<O*>()->priv), T*>;
public:
    id self;
    T* parent;
    T* firstChild;
    T* lastChild;
    int childCount;

    T* prevSibling;
    T* nextSibling;

    id cachedSubnodesArray;

    LLTreeNode() {
        parent = NULL;
        firstChild = NULL;
        lastChild = NULL;

        prevSibling = NULL;
        nextSibling = NULL;
        childCount = 0;
        cachedSubnodesArray = nil;
    }

    ~LLTreeNode() {
        if (cachedSubnodesArray != nil) {
#ifndef __OBJC__
            _m(cachedSubnodesArray, "release");
#else
            [cachedSubnodesArray release];
#endif
        }
    }

    void setModified() {
        if (cachedSubnodesArray) {
#ifndef __OBJC__
            _m(cachedSubnodesArray, "autorelease");
#else
            [cachedSubnodesArray autorelease];
#endif
        }
        cachedSubnodesArray = nil;
    }

    id subnodesArray() {
        if (cachedSubnodesArray != nil)
            return cachedSubnodesArray;

        int subnodeCount = 0;
        id* subnodesCopy = (id*)alloca(sizeof(id) * childCount);
        for (T* curChild = firstChild; curChild != NULL; curChild = curChild->nextSibling) {
            subnodesCopy[subnodeCount++] = curChild->self;
        }

#ifndef __OBJC__
        cachedSubnodesArray = _m(_m(NSArray::_meta, "alloc"), "initWithObjects:count:", subnodesCopy, subnodeCount);
#else
        cachedSubnodesArray = [[NSArray alloc] initWithObjects:subnodesCopy count:subnodeCount];
#endif

        return cachedSubnodesArray;
    }

    void setSelf(id parentObj) {
        self = parentObj;
    }

    template <typename O, typename = typename std::enable_if<_hasPrivateT<O>::value>>
    void addChildBefore(O* child, objectOwnerType* before) {
        addChildBefore(child->priv, before != nil ? before->priv : NULL);
    }

    template <typename O, typename = typename std::enable_if<_hasPrivateT<O>::value>>
    void addChildAfter(O* child, objectOwnerType* after) {
        addChildAfter(child->priv, after != nil ? after->priv : NULL);
    }

    template <typename O, typename = typename std::enable_if<_hasPrivateT<O>::value>>
    int indexOfChild(O* child) {
        return indexOfChild(child->priv);
    }

    int indexOfChild(T* child) {
        int idx = 0;
        T* curNode = firstChild;

        while (curNode) {
            if (curNode == child)
                return idx;
            curNode = curNode->nextSibling;
            idx++;
        }

        return 0x7fffffff;
    }

    template <typename O, typename = typename std::enable_if<_hasPrivateT<O>::value>>
    bool containsChild(O* child) {
        if (child == nil)
            return false;

        return containsChild(child->priv);
    }

    bool containsChild(T* child) {
        if (child->parent == static_cast<T*>(this))
            return true;
        else
            return false;
    }

    T* childAtIndex(int idx) {
        T* cur = firstChild;
        while (idx--) {
            cur = cur->nextSibling;
        }

        return cur;
    }

    template <typename O, typename = typename std::enable_if<_hasPrivateT<O>::value>>
    void replaceChild(O* child, O* withChild) {
        replaceChild(child->priv, withChild->priv);
    }

    void replaceChild(T* child, T* withChild) {
        setModified();

        T* prev = child->prevSibling;
        T* next = child->nextSibling;

        child->prevSibling = NULL;
        child->nextSibling = NULL;
        child->parent = NULL;

        withChild->prevSibling = prev;
        withChild->nextSibling = next;

        if (prev)
            prev->nextSibling = withChild;
        if (next)
            next->prevSibling = withChild;

        if (firstChild == child)
            firstChild = withChild;
        if (lastChild == child)
            lastChild = withChild;
    }

    template <typename O, typename = typename std::enable_if<_hasPrivateT<O>::value>>
    void exchangeChild(O* child1, O* child2) {
        exchangeChild(child1->priv, child2->priv);
    }

    void exchangeChild(T* child1, T* child2) {
        setModified();

        T* prev1 = child1->prevSibling;
        if (prev1 == child2)
            prev1 = child1;
        T* next1 = child1->nextSibling;
        if (next1 == child2)
            next1 = child1;

        T* prev2 = child2->prevSibling;
        if (prev2 == child1)
            prev2 = child2;
        T* next2 = child2->nextSibling;
        if (next2 == child1)
            next2 = child2;

        child1->prevSibling = prev2;
        child1->nextSibling = next2;
        child2->prevSibling = prev1;
        child2->nextSibling = next1;

        if (child1->prevSibling)
            child1->prevSibling->nextSibling = child1;
        if (child1->nextSibling)
            child1->nextSibling->prevSibling = child1;

        if (child2->prevSibling)
            child2->prevSibling->nextSibling = child2;
        if (child2->nextSibling)
            child2->nextSibling->prevSibling = child2;

        if (firstChild == child1) {
            firstChild = child2;
        } else if (firstChild == child2) {
            firstChild = child1;
        }

        if (lastChild == child1) {
            lastChild = child2;
        } else if (lastChild == child2) {
            lastChild = child1;
        }
    }

    void addChildBefore(T* child, T* before) {
        assert(child->parent == NULL);

        setModified();

        if (before == NULL)
            before = firstChild;

        T* prev = NULL;
        if (before)
            prev = before->prevSibling;
        T* next = before;

        child->parent = static_cast<T*>(this);
        child->prevSibling = prev;
        child->nextSibling = next;

        if (prev)
            prev->nextSibling = child;
        if (next)
            next->prevSibling = child;

        if (firstChild == NULL || firstChild == before)
            firstChild = child;
        if (lastChild == NULL)
            lastChild = child;

        childCount++;
    }

    void addChildAfter(T* child, T* after) {
        assert(child->parent == NULL);

        setModified();

        if (after == NULL)
            after = lastChild;

        T* next = NULL;
        if (after)
            next = after->nextSibling;
        T* prev = after;

        child->parent = static_cast<T*>(this);
        child->prevSibling = prev;
        child->nextSibling = next;

        if (prev)
            prev->nextSibling = child;
        if (next)
            next->prevSibling = child;

        if (firstChild == NULL)
            firstChild = child;
        if (lastChild == NULL || lastChild == after)
            lastChild = child;

        childCount++;
    }

    template <typename O, typename = typename std::enable_if<_hasPrivateT<O>::value>>
    void removeChild(O* child) {
        removeChild(child->priv);
    }

    void removeChild(T* child) {
        assert(child->parent == static_cast<T*>(this));

        setModified();

        T* prev = child->prevSibling;
        T* next = child->nextSibling;

        child->prevSibling = NULL;
        child->nextSibling = NULL;
        child->parent = NULL;

        if (prev)
            prev->nextSibling = next;
        if (next)
            next->prevSibling = prev;

        if (firstChild == child)
            firstChild = next;
        if (lastChild == child)
            lastChild = prev;

        childCount--;
    }

    template <typename O, typename = typename std::enable_if<_hasPrivateT<O>::value>>
    void insertChildAtIndex(O* child, int idx) {
        insertChildAtIndex(child->priv, idx);
    }

    void insertChildAtIndex(T* child, int idx) {
        T* cur = firstChild;
        while (idx--) {
            cur = cur->nextSibling;
        }

        if (cur) {
            addChildBefore(child, cur);
        } else {
            //  End of the list
            addChildAfter(child, NULL);
        }
    }
};

template <class T>
class LLTreeNodeNoObj {
public:
    id self;
    T* parent;
    T* firstChild;
    T* lastChild;
    int childCount;

    T* prevSibling;
    T* nextSibling;

    id cachedSubnodesArray;

    LLTreeNodeNoObj() {
        parent = NULL;
        firstChild = NULL;
        lastChild = NULL;

        prevSibling = NULL;
        nextSibling = NULL;
        childCount = 0;
        cachedSubnodesArray = nil;
    }

    ~LLTreeNodeNoObj() {
        if (cachedSubnodesArray != nil) {
#ifndef __OBJC__
            _m(cachedSubnodesArray, "release");
#else
            [cachedSubnodesArray release];
#endif
        }
    }

    void setModified() {
        if (cachedSubnodesArray) {
#ifndef __OBJC__
            _m(cachedSubnodesArray, "autorelease");
#else
            [cachedSubnodesArray autorelease];
#endif
        }
        cachedSubnodesArray = nil;
    }

    id subnodesArray() {
        if (cachedSubnodesArray != nil)
            return cachedSubnodesArray;

        int subnodeCount = 0;
        id* subnodesCopy = (id*)alloca(sizeof(id) * childCount);
        for (T* curChild = firstChild; curChild != NULL; curChild = curChild->nextSibling) {
            subnodesCopy[subnodeCount++] = curChild->self;
        }

#ifndef __OBJC__
        cachedSubnodesArray = _m(_m(NSArray::_meta, "alloc"), "initWithObjects:count:", subnodesCopy, subnodeCount);
#else
        cachedSubnodesArray = _m(_m(NSArray::_meta, "alloc"), "initWithObjects:count:", subnodesCopy, subnodeCount);
#endif

        return cachedSubnodesArray;
    }

    void setSelf(id parentObj) {
        self = parentObj;
    }

    int indexOfChild(T* child) {
        int idx = 0;
        T* curNode = firstChild;

        while (curNode) {
            if (curNode == child)
                return idx;
            curNode = curNode->nextSibling;
            idx++;
        }

        return 0x7fffffff;
    }

    bool containsChild(T* child) {
        if (child->parent == static_cast<T*>(this))
            return true;
        else
            return false;
    }

    T* childAtIndex(int idx) {
        T* cur = firstChild;
        while (idx--) {
            cur = cur->nextSibling;
        }

        return cur;
    }

    void replaceChild(T* child, T* withChild) {
        setModified();

        T* prev = child->prevSibling;
        T* next = child->nextSibling;

        child->prevSibling = NULL;
        child->nextSibling = NULL;
        child->parent = NULL;

        withChild->prevSibling = prev;
        withChild->nextSibling = next;

        if (prev)
            prev->nextSibling = withChild;
        if (next)
            next->prevSibling = withChild;

        if (firstChild == child)
            firstChild = withChild;
        if (lastChild == child)
            lastChild = withChild;
    }

    void exchangeChild(T* child1, T* child2) {
        setModified();

        T* prev1 = child1->prevSibling;
        if (prev1 == child2)
            prev1 = child1;
        T* next1 = child1->nextSibling;
        if (next1 == child2)
            next1 = child1;

        T* prev2 = child2->prevSibling;
        if (prev2 == child1)
            prev2 = child2;
        T* next2 = child2->nextSibling;
        if (next2 == child1)
            next2 = child2;

        child1->prevSibling = prev2;
        child1->nextSibling = next2;
        child2->prevSibling = prev1;
        child2->nextSibling = next1;

        if (child1->prevSibling)
            child1->prevSibling->nextSibling = child1;
        if (child1->nextSibling)
            child1->nextSibling->prevSibling = child1;

        if (child2->prevSibling)
            child2->prevSibling->nextSibling = child2;
        if (child2->nextSibling)
            child2->nextSibling->prevSibling = child2;

        if (firstChild == child1) {
            firstChild = child2;
        } else if (firstChild == child2) {
            firstChild = child1;
        }

        if (lastChild == child1) {
            lastChild = child2;
        } else if (lastChild == child2) {
            lastChild = child1;
        }
    }

    void addChildBefore(T* child, T* before) {
        assert(child->parent == NULL);

        setModified();

        if (before == NULL)
            before = firstChild;

        T* prev = NULL;
        if (before)
            prev = before->prevSibling;
        T* next = before;

        child->parent = static_cast<T*>(this);
        child->prevSibling = prev;
        child->nextSibling = next;

        if (prev)
            prev->nextSibling = child;
        if (next)
            next->prevSibling = child;

        if (firstChild == NULL || firstChild == before)
            firstChild = child;
        if (lastChild == NULL)
            lastChild = child;

        childCount++;
    }

    void addChildAfter(T* child, T* after) {
        assert(child->parent == NULL);

        setModified();

        if (after == NULL)
            after = lastChild;

        T* next = NULL;
        if (after)
            next = after->nextSibling;
        T* prev = after;

        child->parent = static_cast<T*>(this);
        child->prevSibling = prev;
        child->nextSibling = next;

        if (prev)
            prev->nextSibling = child;
        if (next)
            next->prevSibling = child;

        if (firstChild == NULL)
            firstChild = child;
        if (lastChild == NULL || lastChild == after)
            lastChild = child;

        childCount++;
    }

    void removeChild(T* child) {
        assert(child->parent == static_cast<T*>(this));

        setModified();

        T* prev = child->prevSibling;
        T* next = child->nextSibling;

        child->prevSibling = NULL;
        child->nextSibling = NULL;
        child->parent = NULL;

        if (prev)
            prev->nextSibling = next;
        if (next)
            next->prevSibling = prev;

        if (firstChild == child)
            firstChild = next;
        if (lastChild == child)
            lastChild = prev;

        childCount--;
    }

    void insertChildAtIndex(T* child, int idx) {
        T* cur = firstChild;
        while (idx--) {
            cur = cur->nextSibling;
        }

        if (cur) {
            addChildBefore(child, cur);
        } else {
            //  End of the list
            addChildAfter(child, NULL);
        }
    }
};

#endif
