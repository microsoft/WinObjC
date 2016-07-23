//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <CoreData/CoreData.h>
#import <CoreFoundation/CFXMLParser.h>
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#import <ErrorHandling.h>
#import <LoggingNative.h>
#import <Starboard/SmartTypes.h>

#import <CoreData/NSManagedObjectModel-XMLParsing.h>

#include <list>
#include <stack>
#include <tuple>

static NSString* const _kNSManagedObjectModelTag = @"model";
static NSString* const _kNSManagedObjectModelEntityTag = @"entity";
static NSString* const _kNSManagedObjectModelEntityAttributeTag = @"attribute";
static NSString* const _kNSManagedObjectModelEntityRelationshipTag = @"relationship";
static NSString* const _kNSManagedObjectModelUserInfoTag = @"userInfo";
static NSString* const _kNSManagedObjectModelUserInfoEntryTag = @"entry";
static NSString* const _kNSManagedObjectModelEntityCompoundIndexTag = @"compoundIndex";
static NSString* const _kNSManagedObjectModelEntityCompoundIndexesTag = @"compoundIndexes";
static NSString* const _kNSManagedObjectModelEntityCompoundIndexIndexTag = @"index";
static NSString* const _kNSManagedObjectModelEntityUniquenessConstraintTag = @"uniquenessConstraint";
static NSString* const _kNSManagedObjectModelEntityUniquenessConstraintsTag = @"uniquenessConstraints";
static NSString* const _kNSManagedObjectModelEntityUniquenessConstraintConstraintTag = @"constraint";

// To save ourselves some string compares:
static NSString* _uniqueTag(NSString* tag) {
    static StrongId<NSSet<NSString*>> _tagSet = [NSSet setWithObjects:_kNSManagedObjectModelTag,
                                                                      _kNSManagedObjectModelEntityTag,
                                                                      _kNSManagedObjectModelEntityAttributeTag,
                                                                      _kNSManagedObjectModelEntityRelationshipTag,
                                                                      _kNSManagedObjectModelUserInfoTag,
                                                                      _kNSManagedObjectModelUserInfoEntryTag,
                                                                      _kNSManagedObjectModelEntityCompoundIndexTag,
                                                                      _kNSManagedObjectModelEntityCompoundIndexesTag,
                                                                      _kNSManagedObjectModelEntityUniquenessConstraintTag,
                                                                      _kNSManagedObjectModelEntityUniquenessConstraintsTag,
                                                                      nullptr];
    return [_tagSet member:tag];
}

static Class _classForElementName(NSString* elementName) {
    static StrongId<NSDictionary<NSString*, Class<_NSCDXMLCoding>>> _mappings = @{
        _kNSManagedObjectModelTag : [NSManagedObjectModel class],
        _kNSManagedObjectModelEntityTag : [NSEntityDescription class],
        _kNSManagedObjectModelEntityAttributeTag : [NSAttributeDescription class],
        _kNSManagedObjectModelEntityRelationshipTag : [NSRelationshipDescription class],
    };
    return [_mappings objectForKey:elementName];
}

// XML data model parsing is done via recursive descent and state management. Each element
// we encounter can push another state onto the stack. The state dictates what state transitions
// are available and what is to be done when the state is exited.
//
// Some of these states cascade, and their order should be retained.
enum _NSModelParsingState : unsigned int {
    _NSModelParsingStateNone = 0,
    _NSModelParsingStateGenericObject,
    _NSModelParsingStateModel,
    _NSModelParsingStateEntity,

    _NSModelParsingStateUserInfo,
    _NSModelParsingStateUserInfoEntry,

    _NSModelParsingStateCompoundIndices, // object is an array<array<string>>
    _NSModelParsingStateCompoundIndex, // object is an array<string>
    _NSModelParsingStateCompoundIndexEntry, // object is a string

    _NSModelParsingStateUniquenessConstraints, // object is an array<array<string>>
    _NSModelParsingStateUniquenessConstraint, // object is an array<string>
    _NSModelParsingStateUniquenessConstraintEntry, // object is a string
};

struct _NSModelParsingContext {
    StrongId<NSManagedObjectModel> model;

    using StateType = std::tuple<_NSModelParsingState, StrongId<NSObject>>;
    std::stack<StateType, std::list<StateType>> states;

    void push_state(_NSModelParsingState st, id object) {
        states.emplace(st, object);
    }
    std::tuple<_NSModelParsingState, id> pop() {
        auto state = states.top();
        states.pop();
        return state;
    }
    std::tuple<_NSModelParsingState, id> peek() {
        return states.top();
    }
    _NSModelParsingState state() {
        return states.empty() ? _NSModelParsingStateNone : std::get<_NSModelParsingState>(peek());
    }
    size_t count() const {
        return states.size();
    }
};

static void* SKIP = nullptr;
static void* CONTINUE = (void*)0x01;

#define EMIT_STATE(st, ...)                   \
    do {                                      \
        context->push_state(st, __VA_ARGS__); \
        return CONTINUE;                      \
    } while (0);

static void* xmlCreateStructure(CFXMLParserRef parser, CFXMLNodeRef node, void* info) {
    _NSModelParsingContext* context = (_NSModelParsingContext*)info;
    switch (CFXMLNodeGetTypeCode(node)) {
        case kCFXMLNodeTypeElement: {
            NSString* tag = (NSString*)CFXMLNodeGetString(node);
            NSString* elementName = _uniqueTag(tag);

            CFXMLElementInfo* elementInfo = (CFXMLElementInfo*)CFXMLNodeGetInfoPtr(node);
            NSDictionary* attributes = (NSDictionary*)elementInfo->attributes;

            switch (context->state()) {
                case _NSModelParsingStateEntity:
                    // Only entities may contain indices or constraints.
                    if ([elementName isEqualToString:_kNSManagedObjectModelEntityCompoundIndexesTag]) {
                        EMIT_STATE(_NSModelParsingStateCompoundIndices, [NSMutableArray array]);
                    } else if ([elementName isEqualToString:_kNSManagedObjectModelEntityUniquenessConstraintsTag]) {
                        EMIT_STATE(_NSModelParsingStateUniquenessConstraints, [NSMutableArray array]);
                    }
                // Entities fall through to base.
                case _NSModelParsingStateModel:
                case _NSModelParsingStateNone:
                case _NSModelParsingStateGenericObject: {
                    // Anything may contain userInfo.
                    if ([elementName isEqualToString:_kNSManagedObjectModelUserInfoTag]) {
                        EMIT_STATE(_NSModelParsingStateUserInfo, [NSMutableDictionary dictionary]);
                    }

                    Class cls = _classForElementName(elementName);
                    if (!cls) {
                        return SKIP;
                    }

                    auto newState = _NSModelParsingStateGenericObject;
                    if ([elementName isEqualToString:_kNSManagedObjectModelEntityTag]) {
                        newState = _NSModelParsingStateEntity;
                    } else if ([elementName isEqualToString:_kNSManagedObjectModelTag]) {
                        newState = _NSModelParsingStateModel;
                    }

                    EMIT_STATE(newState, [[[cls alloc] _initWithXMLElementName:elementName attributes:attributes] autorelease]);
                    break;
                }
                case _NSModelParsingStateCompoundIndices:
                case _NSModelParsingStateUniquenessConstraints:
                    // Both of these contain arrays of strings.
                    // Since their states are stacked in order, we can advance to the next higher state to populate the array.
                    EMIT_STATE((_NSModelParsingState)(context->state() + 1), [NSMutableArray array]);
                    break;
                case _NSModelParsingStateCompoundIndex:
                case _NSModelParsingStateUniquenessConstraint:
                    EMIT_STATE((_NSModelParsingState)(context->state() + 1), attributes[@"value"]);
                    break;
                case _NSModelParsingStateUserInfo:
                    if ([elementName isEqualToString:_kNSManagedObjectModelUserInfoEntryTag]) {
                        // return attributes directly: endStructure will consume it.
                        EMIT_STATE(_NSModelParsingStateUserInfoEntry, attributes);
                    }
                    break;
                default:
                    return SKIP;
            }
            return SKIP;
        }
        default:
            return SKIP;
    }
}

static void addChild(CFXMLParserRef parser, void* parent, void* child, void* info) {
    // addChild is called immediately after a child is created, but before any of its sub-elements are parsed.
    // We defer tree construction to endStructure to make sure we're adding things inside-out.
    // Without an addChild callback, endStructure never gets called.
    return;
}

static void endStructure(CFXMLParserRef parser, void* xmlType, void* info) {
    _NSModelParsingContext* context = (_NSModelParsingContext*)info;
    if (context->count() == 0) {
        return;
    }
    auto tpl(context->pop());
    id object(std::get<id>(tpl));

    id parent = nil;
    if (context->count() > 0) {
        parent = std::get<id>(context->peek());
    }

    switch (std::get<_NSModelParsingState>(tpl)) {
        case _NSModelParsingStateModel:
            [object _awakeFromXML];
            context->model = object;
            break;
        case _NSModelParsingStateGenericObject:
        case _NSModelParsingStateEntity:
            [parent _insertChildElement:object];
            break;
        case _NSModelParsingStateUserInfo:
            [parent setUserInfo:object];
            break;
        case _NSModelParsingStateUserInfoEntry: { // in this state, parent is a userInfo node represented by a dictionary
            NSMutableDictionary* userInfo = (NSMutableDictionary*)parent;
            NSDictionary* entry = (NSDictionary*)object;
            [parent setObject:[[entry[@"value"] copy] autorelease] forKey:entry[@"key"]];
            break;
        }
        case _NSModelParsingStateCompoundIndices:
            [(NSEntityDescription*)parent setCompoundIndexes:object];
            break;
        case _NSModelParsingStateUniquenessConstraints:
            [(NSEntityDescription*)parent setUniquenessConstraints:object];
            break;
        case _NSModelParsingStateCompoundIndex:
        case _NSModelParsingStateCompoundIndexEntry:
        case _NSModelParsingStateUniquenessConstraint:
        case _NSModelParsingStateUniquenessConstraintEntry: {
            // Each of these is an array of things. Since each of these states adds an object to an array,
            // we can get by by simply flattening them into a single case.
            NSMutableArray* entries = (NSMutableArray*)parent;
            NSObject<NSCopying>* entry = (NSObject<NSCopying>*)object;
            [entries addObject:[entry copy]];
            break;
        }
        case _NSModelParsingStateNone:
        default:
            TraceError(L"NSManagedObjectModel-XMLParsing", L"Invalid state?");
            break;
    }
}

static CFXMLParserCallBacks xmlParserCallbacks{
    0, xmlCreateStructure, addChild, endStructure, nullptr, nullptr,
};

NSManagedObjectModel* _NSManagedObjectModelFromXMLData(NSData* data, NSURL* sourceURL) {
    if (!data) {
        return nil;
    }

    _NSModelParsingContext ctx{};
    CFXMLParserContext cfXmlContext{
        0, &ctx, nullptr, nullptr, nullptr,
    };
    CFXMLParserRef parser = CFXMLParserCreate(kCFAllocatorDefault,
                                              (CFDataRef)data,
                                              (CFURLRef)[sourceURL absoluteURL],
                                              kCFXMLParserSkipMetaData | kCFXMLParserReplacePhysicalEntities | kCFXMLParserSkipWhitespace,
                                              kCFXMLNodeCurrentVersion,
                                              &xmlParserCallbacks,
                                              &cfXmlContext);
    if (!CFXMLParserParse(parser)) {
        return nil;
    }
    return [ctx.model.detach() autorelease];
}

NSManagedObjectModel* _NSManagedObjectModelFromXMLDataAtURL(NSURL* url) {
    if (!url) {
        return nil;
    }

    NSData* data = [NSData dataWithContentsOfURL:url];
    return _NSManagedObjectModelFromXMLData(data, url);
}
