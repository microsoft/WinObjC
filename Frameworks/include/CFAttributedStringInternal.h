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

#pragma once

#import <CoreFoundation/CFAttributedString.h>
#import <map>
#import <set>

#import "CFBridgeBase.h"
#import "Starboard.h"

/**
 * Struct for representing an Attribute over a range of a string.
 */
struct Attribute {
    idretain value;

    // Note: begin/end here saves a few operations over using CFRange, and is easier to read in a number of places
    CFIndex begin;
    CFIndex end;

    Attribute(id initValue, CFIndex initBegin, CFIndex initEnd) : value(idretain(initValue)), begin(initBegin), end(initEnd) {
    }

    Attribute(id initValue, CFRange initRange) : Attribute(initValue, initRange.location, initRange.location + initRange.length) {
    }

    Attribute(const Attribute& other) : Attribute(other.value._val, other.begin, other.end) {
    }

    /**
     * Evaluates the Attribute's relative position to a range.
     */
    bool isAfterRange(CFIndex rangeBegin, CFIndex rangeEnd) const;
    bool isAfterOrAdjacentToRange(CFIndex rangeBegin, CFIndex rangeEnd) const;
    bool isBeforeRange(CFIndex rangeBegin, CFIndex rangeEnd) const;
    bool isBeforeOrAdjacentToRange(CFIndex rangeBegin, CFIndex rangeEnd) const;

    /**
     * Evaluates whether the Attribute contains a location in the string.
     */
    bool containsIndex(CFIndex index) const;

    /**
     * Returns the range of the Attribute as a CFRange.
     */
    CFRange getCFRange() const;

    // Comparison operator for Attribute - sort by the beginning of the range
    bool operator<(const Attribute& other) const {
        return begin < other.begin;
    }
};

// Using std::multiset as a sorted list of Attributes that can handle temporary collisions
using cf_attrlist = std::multiset<Attribute>;

// Internal data structure for sorting Attributes by range - a map of attribute names -> sorted lists
using cf_attrmap = std::map<CFStringRef, cf_attrlist>;

// Internal helpers for working with cf_attrlist

/**
 * Helper function to re-insert an Attribute into attrList with a new range
 * Sorted collections such as std::multi/set don't allow elements to be edited while iterating, as doing so may disrupt the sort
 * Instead, erase and re-insert the same element, but edited
 * Returns: An iterator to the re-inserted Attribute.
 */
cf_attrlist::const_iterator _CFAttrListReinsertWithRange(cf_attrlist& attrList,
                                                         cf_attrlist::const_iterator attribute,
                                                         CFIndex newBegin,
                                                         CFIndex newEnd);

/**
 * Updates attrList to add a range from addBegin to addEnd from the range of attribute
 * Precondition:    Assumed that the add range overlaps with the attribute range
 * Returns: An iterator to the expanded Attribute.
 */
cf_attrlist::const_iterator _CFAttrListAddToAttribute(cf_attrlist& attrList,
                                                      cf_attrlist::const_iterator attribute,
                                                      CFIndex addBegin,
                                                      CFIndex addEnd);

/**
 * Updates attrList to subtract a range from subtractBegin to subtractEnd from the range of attribute
 * This may leave the original single attribute as two attributes
 * Precondition:    Assumed that the subtraction range overlaps with the attribute range
 */
void _CFAttrListSubtractFromAttribute(cf_attrlist& attrList,
                                      cf_attrlist::const_iterator attribute,
                                      CFIndex subtractBegin,
                                      CFIndex subtractEnd);

/**
 * Resolves a conflict between two overlapping attributes.
 * The older attribute is coalesced, subtracted, or removed accordingly.
 * Returns: A (possibly new) iterator to the newer attribute.
 */
cf_attrlist::const_iterator _CFAttrListResolveOverlap(cf_attrlist& attrList,
                                                      cf_attrlist::const_iterator newerAttribute,
                                                      cf_attrlist::const_iterator olderAttribute);

/**
 * Updates the Attribute ranges in attrList to match a replacement of originalRange to one of newLength
 */
void _CFAttrListReplaceRange(cf_attrlist& attrList, CFRange originalRange, CFIndex newRangeLength);

/**
 * Internal struct that actually backs and implements [NS|CF][Mutable]AttributedString
 */
struct __CFMutableAttributedString : CFBridgeBase<__CFMutableAttributedString> {
public:
    /**
     * Creates the object with an empty backing string and no attributes
     */
    __CFMutableAttributedString();
    ~__CFMutableAttributedString();

    /**
     * Calls a set of cleanup/consistency functions, if the string is not currently in editing mode.
     */
    void fixAttributesIfNotEditing();

    void beginEditing();
    void endEditing();

    CFStringRef getString();
    CFIndex getLength();
    CFTypeRef getAttribute(CFIndex loc, CFStringRef attrName, CFRange* outEffectiveRange);
    CFDictionaryRef getAttributes(CFIndex loc, CFRange* outEffectiveRange);
    void removeAttribute(CFRange deleteRange, CFStringRef attrName);
    void replaceString(CFRange range, CFStringRef replacement);
    void replaceAttributedString(CFRange range, CFAttributedStringRef replacement);
    void setAttribute(CFRange range, CFStringRef attrName, CFTypeRef value);
    void setAttributes(CFRange range, CFDictionaryRef replacement, Boolean clearOtherAttributes);

private:
    cf_attrmap _attributesMap;

    // Internal string data storage
    CFMutableStringRef _stringData;

    // When true, will defer certain operations until endEditing() is called.
    // Set true by beginEditing
    bool _editingMode = false;

    /**
     * Removes empty lists from _attributesMap
     */
    void _cleanEmptyLists();

    /**
     * Overloads for member functions, that take an cf_attrmap::iterator rather than an attribute name,
     * for calling from contexts that already iterate through _attributesMap
     */
    CFTypeRef getAttribute(CFIndex loc, cf_attrmap::iterator attrMapEntry, CFRange* outEffectiveRange);
    void removeAttribute(CFRange deleteRange, cf_attrmap::iterator attrMapEntry);

    /**
     * Helper for throwing out-of-bounds exceptions
     */
    void _throwIfOutOfBounds(CFIndex index);
};