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

#import <CoreFoundation/CFAttributedString.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFString.h>
#import <algorithm>
#import <limits.h>
#import <map>
#import <set>

#import "CFAttributedStringInternal.h"

static IWLazyClassLookup _LazyNSMutableString("NSMutableString");

// Attribute functions

bool Attribute::isAfterRange(CFIndex rangeBegin, CFIndex rangeEnd) const {
    return begin > rangeEnd;
}

bool Attribute::isAfterOrAdjacentToRange(CFIndex rangeBegin, CFIndex rangeEnd) const {
    return begin >= rangeEnd;
}

bool Attribute::isBeforeRange(CFIndex rangeBegin, CFIndex rangeEnd) const {
    return end < rangeBegin;
}

bool Attribute::isBeforeOrAdjacentToRange(CFIndex rangeBegin, CFIndex rangeEnd) const {
    return end <= rangeBegin;
}

bool Attribute::containsIndex(CFIndex index) const {
    return (begin <= index) && (end > index);
}

CFRange Attribute::getCFRange() const {
    return CFRangeMake(begin, end - begin);
}

// cf_attrlist functions

cf_attrlist::const_iterator _CFAttrListReinsertWithRange(cf_attrlist& attrList,
                                                         cf_attrlist::const_iterator attribute,
                                                         CFIndex newBegin,
                                                         CFIndex newEnd) {
    Attribute replacement = Attribute((const idretain&)attribute->value, newBegin, newEnd);
    return attrList.insert(attrList.erase(attribute), replacement);
}

cf_attrlist::const_iterator _CFAttrListAddToAttribute(cf_attrlist& attrList,
                                                      cf_attrlist::const_iterator attribute,
                                                      CFIndex addBegin,
                                                      CFIndex addEnd) {
    return _CFAttrListReinsertWithRange(attrList, attribute, std::min(attribute->begin, addBegin), std::max(attribute->end, addEnd));
}

void _CFAttrListSubtractFromAttribute(cf_attrlist& attrList,
                                      cf_attrlist::const_iterator attribute,
                                      CFIndex subtractBegin,
                                      CFIndex subtractEnd) {
    if (attribute->end <= subtractEnd) {
        if (attribute->begin < subtractBegin) {
            // SUBTRACT:            |-------|
            // ATTRIBUTE:       |-------|
            //            or    |-----------|
            // RESULT:          |---|
            _CFAttrListReinsertWithRange(attrList, attribute, attribute->begin, subtractBegin);

        } else {
            // SUBTRACT:            |-------|
            // ATTRIBUTE:           |-----|
            //            or        |-------|
            //            or          |---|
            //            or          |-----|
            // RESULT:    none
            attrList.erase(attribute);
        }

    } else {
        if (attribute->begin < subtractBegin) {
            // SUBTRACT:            |-------|
            // ATTRIBUTE:        |-------------|
            // RESULT:           |--|       |--|

            // Need to split into two Attributes
            // attribute->begin to subtractBegin
            // subtractEnd to attribute->end

            Attribute secondAttribute = Attribute((const idretain&)attribute->value, subtractEnd, attribute->end);
            cf_attrlist::const_iterator firstAttributeIt =
                _CFAttrListReinsertWithRange(attrList, attribute, attribute->begin, subtractBegin);

            // Provide a hint - the second attribute should be inserted before the element that is currently after the first
            attrList.insert(++firstAttributeIt, secondAttribute);

        } else {
            // SUBTRACT:            |-------|
            // ATTRIBUTE:           |----------|
            //            or            |------|
            // RESULT:                      |--|
            _CFAttrListReinsertWithRange(attrList, attribute, subtractEnd, attribute->end);
        }
    }
}

cf_attrlist::const_iterator _CFAttrListResolveOverlap(cf_attrlist& attrList,
                                                      cf_attrlist::const_iterator newerAttribute,
                                                      cf_attrlist::const_iterator olderAttribute) {
    if ([newerAttribute->value isEqual:olderAttribute->value]) {
        // Combine the two if the values are the same
        auto ret = _CFAttrListAddToAttribute(attrList, newerAttribute, olderAttribute->begin, olderAttribute->end);
        attrList.erase(olderAttribute);
        return ret;

    } else {
        // Subtract if the values differ
        _CFAttrListSubtractFromAttribute(attrList, olderAttribute, newerAttribute->begin, newerAttribute->end);
        return newerAttribute;
    }
}

void _CFAttrListReplaceRange(cf_attrlist& attrList, CFRange originalRange, CFIndex newRangeLength) {
    CFIndex originalRangeEnd = originalRange.location + originalRange.length;
    CFIndex newRangeEnd = originalRange.location + newRangeLength;

    CFIndex lengthDiff = newRangeLength - originalRange.length;

    // The first Attribute that overlaps with originalRange will be expanded/contracted to fill the new range
    auto originalAttribute = attrList.end();

    auto it = attrList.begin();
    while (it != attrList.end()) {
        if (it->isAfterOrAdjacentToRange(originalRange.location, originalRangeEnd)) {
            // End the first loop if it has progressed entirely beyond originalRange
            break;

        } else if (!it->isBeforeOrAdjacentToRange(originalRange.location, originalRangeEnd)) {
            // If current Attribute is neither before or after originalRange, then it must overlap with originalRange
            CFIndex itBegin = it->begin;
            CFIndex itEnd = it->end;
            originalAttribute = _CFAttrListReinsertWithRange(attrList,
                                                             it++,
                                                             std::min(itBegin, originalRange.location),
                                                             std::max(itEnd + lengthDiff, newRangeEnd));

            // Because a max of one Attribute can fill up the new range, break out of the first loop here
            break;

        } else {
            ++it;
        }
    }

    // At this point, iteration must either be
    // 1) attrList.end()
    // 2) after or adjacent to originalRange
    // 3) overlapping with originalRange
    while (it != attrList.end()) {
        CFIndex itBegin = it->begin;
        CFIndex itEnd = it->end;
        if (!it->isAfterOrAdjacentToRange(originalRange.location, originalRangeEnd)) {
            // Attribute must overlap with originalRange, as it is neither 1) nor 2)

            if (originalAttribute != attrList.end()) {
                // Shift the Attribute over, then resolve the overlap
                auto overlapAttribute = _CFAttrListReinsertWithRange(attrList, it++, itBegin + lengthDiff, itEnd + lengthDiff);
                _CFAttrListResolveOverlap(attrList, originalAttribute, overlapAttribute);
            } else {
                // Subtract everything before newRangeEnd from the attribute, and shift it over
                _CFAttrListReinsertWithRange(attrList, it++, newRangeEnd, itEnd + lengthDiff);
            }

        } else {
            // Attribute does not overlap with originalRange - shift it over
            _CFAttrListReinsertWithRange(attrList, it++, itBegin + lengthDiff, itEnd + lengthDiff);
        }
    }
}

__CFMutableAttributedString::__CFMutableAttributedString() : _stringData((__bridge CFMutableStringRef)[[_LazyNSMutableString alloc] init]) {
}

__CFMutableAttributedString::~__CFMutableAttributedString() {
    [(__bridge NSMutableString*)_stringData release];
}

void __CFMutableAttributedString::fixAttributesIfNotEditing() {
    if (!_editingMode) {
        _cleanEmptyLists();
        // TODO: 5244778, 5244811 - UI Kit extensions add extra operations that ought to be deferred here.
    }
}

void __CFMutableAttributedString::beginEditing() {
    _editingMode = true;
}

void __CFMutableAttributedString::endEditing() {
    _editingMode = false;
    fixAttributesIfNotEditing();
}

CFStringRef __CFMutableAttributedString::getString() {
    return _stringData;
}

CFIndex __CFMutableAttributedString::getLength() {
    return CFStringGetLength(_stringData);
}

CFTypeRef __CFMutableAttributedString::getAttribute(CFIndex loc, CFStringRef attrName, CFRange* outEffectiveRange) {
    _throwIfOutOfBounds(loc);

    const auto attrListEntry = _attributesMap.find(attrName);

    if (attrListEntry != _attributesMap.end()) {
        return getAttribute(loc, attrListEntry, outEffectiveRange);
    } else {
        // If the attrName is unknown, the Attribute is considered to be a 'nullptr' Attribute over the whole string.
        if (outEffectiveRange) {
            *outEffectiveRange = CFRangeMake(0, getLength());
        }
        return nullptr;
    }
}

CFTypeRef __CFMutableAttributedString::getAttribute(CFIndex loc, cf_attrmap::iterator attrMapEntry, CFRange* outEffectiveRange) {
    _throwIfOutOfBounds(loc);

    const auto& attrList = attrMapEntry->second;
    auto attributeIter = attrList.begin();

    // Iterate through the Attribute ranges until either
    while (attributeIter != attrList.end()) {
        int begin = attributeIter->begin;
        int end = attributeIter->end;
        if (attributeIter->containsIndex(loc)) {
            // find an Attribute that contains loc
            if (outEffectiveRange) {
                *outEffectiveRange = attributeIter->getCFRange();
            }
            return attributeIter->value;

        } else if (attributeIter->begin > loc) {
            // iterate entirely past loc
            break;
        }

        attributeIter++;
    }

    if (outEffectiveRange) {
        // Unable to find a matching Attribute at loc, but must still provide a range
        // This may or may not be bounded by Attributes on either side.
        CFIndex end = (attributeIter == attrList.end()) ? CFAttributedStringGetLength(this) : attributeIter->begin;
        CFIndex begin = (attributeIter == attrList.begin()) ? 0 : (--attributeIter)->end;

        *outEffectiveRange = CFRangeMake(begin, end - begin);
    }

    return nullptr;
}

CFDictionaryRef __CFMutableAttributedString::getAttributes(CFIndex loc, CFRange* outEffectiveRange) {
    _throwIfOutOfBounds(loc);

    CFMutableDictionaryRef returnValue = CFDictionaryCreateMutable(nullptr, 0, nullptr, nullptr);
    CFRange effectiveRangeForAttribute;

    // Because the contract for the API stipulates that it returns a range where the attributes are exactly the same,
    // this function must keep track of an aggregate (intersection of all) range as it iterates
    CFIndex effectiveRangeAggMin = INT_MIN;
    CFIndex effectiveRangeAggMax = INT_MAX;

    for (cf_attrmap::iterator attrMapEntry = _attributesMap.begin(); attrMapEntry != _attributesMap.end(); attrMapEntry++) {
        CFTypeRef attribute = getAttribute(loc, attrMapEntry, (outEffectiveRange) ? &effectiveRangeForAttribute : nullptr);

        // Don't need to add nullptr to the dictionary
        if (attribute) {
            CFDictionarySetValue(returnValue, attrMapEntry->first, attribute);
        }

        // Re-evaluate the aggregate range if needed
        if (outEffectiveRange) {
            effectiveRangeAggMin = std::max(effectiveRangeAggMin, effectiveRangeForAttribute.location);
            effectiveRangeAggMax = std::min(effectiveRangeAggMax, effectiveRangeForAttribute.location + effectiveRangeForAttribute.length);
        }
    }

    if (outEffectiveRange) {
        *outEffectiveRange = CFRangeMake(effectiveRangeAggMin, effectiveRangeAggMax - effectiveRangeAggMin);
    }

    return returnValue;
}

void __CFMutableAttributedString::removeAttribute(CFRange deleteRange, CFStringRef attrName) {
    _throwIfOutOfBounds(deleteRange.location + deleteRange.length);

    const auto attrListEntry = _attributesMap.find(attrName);

    if (attrListEntry != _attributesMap.end()) {
        removeAttribute(deleteRange, attrListEntry);
    }
}

void __CFMutableAttributedString::removeAttribute(CFRange deleteRange, cf_attrmap::iterator attrMapEntry) {
    _throwIfOutOfBounds(deleteRange.location + deleteRange.length);

    cf_attrlist& attrList = attrMapEntry->second;

    // Compute the end of the range to be deleted
    CFIndex deleteRangeEnd = deleteRange.location + deleteRange.length;

    auto it = attrList.begin();
    while (it != attrList.end()) {
        if (it->isAfterOrAdjacentToRange(deleteRange.location, deleteRangeEnd)) {
            // End the loop as it has progressed beyond the delete range
            break;

        } else if (!it->isBeforeOrAdjacentToRange(deleteRange.location, deleteRangeEnd)) {
            // If current Attribute is neither before or after deleteRange, then it must overlap with deleteRange
            // Subtract deleteRange from it
            _CFAttrListSubtractFromAttribute(attrList, it++, deleteRange.location, deleteRangeEnd);

        } else {
            ++it;
        }
    }
}

void __CFMutableAttributedString::replaceString(CFRange range, CFStringRef replacement) {
    _throwIfOutOfBounds(range.location + range.length);

    // Replace the string data
    CFStringReplace(_stringData, range, replacement);

    // Remove/shift Attributes accordingly
    for (auto& attrListEntry : _attributesMap) {
        _CFAttrListReplaceRange(attrListEntry.second, range, CFStringGetLength(replacement));
    }
}

void __CFMutableAttributedString::replaceAttributedString(CFRange range, CFAttributedStringRef replacement) {
    _throwIfOutOfBounds(range.location + range.length);

    // Do a normal replace string to get attributes shifted and _stringData in the right state
    replaceString(range, replacement->getString());

    // Remove any attributes from the range of replacement
    for (auto it = _attributesMap.begin(); it != _attributesMap.end(); it++) {
        removeAttribute(CFRangeMake(range.location, replacement->getLength()), it);
    }

    // Set new attributes from the replacement string, making sure to shift the ranges appropriately
    for (auto it = replacement->_attributesMap.begin(); it != replacement->_attributesMap.end(); it++) {
        for (auto attribute = it->second.begin(); attribute != it->second.end(); attribute++) {
            CFRange attributeCFRange = attribute->getCFRange();
            setAttribute(CFRangeMake(attributeCFRange.location + range.location, attributeCFRange.length), it->first, attribute->value);
        }
    }
}

void __CFMutableAttributedString::setAttribute(CFRange range, CFStringRef attrName, CFTypeRef value) {
    _throwIfOutOfBounds(range.location + range.length);

    auto attrListEntry = _attributesMap.find(attrName);

    if (attrListEntry == _attributesMap.end()) {
        attrListEntry = _attributesMap.emplace(attrName, cf_attrlist()).first;
    }

    cf_attrlist& attrList = attrListEntry->second;
    auto insertedAttribute = attrList.insert(Attribute((id)value, range));

    // Iterate forwards, combining or erasing where necessary
    auto forwardIt = insertedAttribute;
    forwardIt++;
    while (forwardIt != attrList.end()) {
        if (forwardIt->isAfterRange(insertedAttribute->begin, insertedAttribute->end)) {
            // End the first loop if it has progressed entirely beyond inserted attribute's range
            break;
        } else {
            insertedAttribute = _CFAttrListResolveOverlap(attrList, insertedAttribute, forwardIt++);
        }
    }

    // Iterate backwards, combining or erasing where necessary
    if (insertedAttribute != attrList.begin()) {
        auto reverseIt = insertedAttribute;
        --reverseIt;

        while (true) {
            if (reverseIt->isBeforeRange(insertedAttribute->begin, insertedAttribute->end)) {
                // End the second loop if it has progressed entirely before inserted attribute's range
                break;
            } else if (reverseIt == attrList.begin()) {
                // End the second loop if it has reached the first element in the list
                _CFAttrListResolveOverlap(attrList, insertedAttribute, reverseIt);
                break;
            } else {
                insertedAttribute = _CFAttrListResolveOverlap(attrList, insertedAttribute, reverseIt--);
            }
        }
    }
}

// Helper struct for saving context for calling CFDictionaryApplyFunction
struct SetAttributeContext {
    CFRange range;
    CFMutableAttributedStringRef self;
};

// Private helper for calling setAttribute() in CFDictionaryApplyFunction
static void _callSetAttributeWith(const void* key, const void* value, void* context) {
    SetAttributeContext* callingContext = (SetAttributeContext*)context;
    callingContext->self->setAttribute(callingContext->range, (CFStringRef)key, value);
}

void __CFMutableAttributedString::setAttributes(CFRange range, CFDictionaryRef replacement, Boolean clearOtherAttributes) {
    _throwIfOutOfBounds(range.location + range.length);

    if (clearOtherAttributes) {
        for (auto it = _attributesMap.begin(); it != _attributesMap.end(); it++) {
            removeAttribute(range, it);
        }
    }

    SetAttributeContext callingContext = { range, this };
    CFDictionaryApplyFunction(replacement, _callSetAttributeWith, &callingContext);
}

void __CFMutableAttributedString::_cleanEmptyLists() {
    auto it = _attributesMap.begin();

    while (it != _attributesMap.end()) {
        if (it->second.empty()) {
            it = _attributesMap.erase(it);
        } else {
            it++;
        }
    }
}

void __CFMutableAttributedString::_throwIfOutOfBounds(CFIndex index) {
    if (index > getLength()) {
        THROW_NS_HR(E_BOUNDS);
    }
}