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

#include <sstream>

#include "PlistFuncs.h"
#include "SimpleVariableCollection.h"
#include "SBLog.h"
#include "utils.h"

#include "PBXObject.h"
#include "PBXDocument.h"
#include "ErrorReporter.h"

typedef enum { ValueGood = 0, ValueMissing = 1, ValueBadType = 2 } ValueStatus;

struct ValueError {
    ValueError(ValueStatus s, const String& m) : status(s), msg(m) {
    }

    String msg;
    ValueStatus status;
};

typedef std::vector<ValueError> ValueErrorVec;

static const Plist::string_type* string_cast(const boost::any& val) {
    return boost::any_cast<Plist::string_type>(&val);
}

static const Plist::integer_type* integer_cast(const boost::any& val) {
    return boost::any_cast<Plist::integer_type>(&val);
}

static const Plist::array_type* array_cast(const boost::any& val) {
    return boost::any_cast<Plist::array_type>(&val);
}

static const Plist::dictionary_type* dictionary_cast(const boost::any& val) {
    return boost::any_cast<Plist::dictionary_type>(&val);
}

static String getValueType(const boost::any& val) {
    return val.type().name();
}

static ValueStatus getStringVector(const boost::any& val, StringVec& ret, ValueErrorVec& errMsgs);

static ValueStatus getString(const boost::any& val, String& ret, ValueErrorVec& errMsgs) {
    ValueStatus status = ValueGood;

    const Plist::string_type* textVal;
    const Plist::array_type* arrayVal;

    if ((textVal = string_cast(val))) {
        ret = *textVal;
    } else if ((arrayVal = array_cast(val))) {
        StringVec vals;
        status = getStringVector(val, vals, errMsgs);
        if (status == ValueGood)
            ret = joinStrings(vals, " ");
    } else {
        status = ValueBadType;
        errMsgs.push_back(ValueError(status, "Unexpected type " + getValueType(val) + "."));
    }

    return status;
}

static ValueStatus getStringVector(const boost::any& val, StringVec& ret, ValueErrorVec& errMsgs) {
    ValueStatus status = ValueGood;

    const Plist::array_type* arrayVal;

    if ((arrayVal = array_cast(val))) {
        Plist::array_type::const_iterator arrIt = arrayVal->begin();
        Plist::array_type::const_iterator arrEnd = arrayVal->end();
        for (; arrIt != arrEnd; arrIt++) {
            String str;
            if (getString(*arrIt, str, errMsgs) == ValueGood)
                ret.push_back(str);
        }
    } else {
        status = ValueBadType;
        errMsgs.push_back(ValueError(status, "Unexpected type " + getValueType(val) + "."));
    }

    return status;
}

template <typename T>
static ValueStatus getStringMap(const boost::any& val, T& ret, ValueErrorVec& errMsgs) {
    ValueStatus status = ValueGood;

    const Plist::dictionary_type* dictVal;

    if ((dictVal = dictionary_cast(val))) {
        Plist::dictionary_type::const_iterator dictIt = dictVal->begin();
        Plist::dictionary_type::const_iterator dictEnd = dictVal->end();
        for (; dictIt != dictEnd; dictIt++) {
            StringPair kvPair(dictIt->first, "");
            if (getString(dictIt->second, kvPair.second, errMsgs) == ValueGood)
                ret.insert(kvPair);
        }
    } else {
        status = ValueBadType;
        errMsgs.push_back(ValueError(status, "Unexpected type " + getValueType(val) + "."));
    }

    return status;
}

static void reportErrorsForKey(const ValueErrorVec& errMsgs, GetterBehavior opt, const String& key, const ErrorReporter& reporter) {
    ValueErrorVec::const_iterator mIt = errMsgs.begin();
    ValueErrorVec::const_iterator mEnd = errMsgs.end();
    for (; mIt != mEnd; mIt++) {
        String errMsg;
        if (!key.empty())
            errMsg = "Problem reading \"" + key + "\" key. " + mIt->msg;
        else
            errMsg = mIt->msg;

        if (opt != VALUE_OPTIONAL && mIt->status == ValueMissing)
            reporter.reportError(errMsg);
        else if (mIt->status == ValueBadType)
            reporter.reportError(errMsg, SB_WARN);
    }
}

static const boost::any& getValueForKey(const Plist::dictionary_type& dict, const String& key, ValueErrorVec& errMsgs) {
    static const boost::any emptyVal;

    Plist::dictionary_type::const_iterator foundIt = dict.find(key);
    if (foundIt != dict.end()) {
        return foundIt->second;
    } else {
        errMsgs.push_back(ValueError(ValueMissing, "Missing value."));
        return emptyVal;
    }
}

template <typename T>
static const T& castContainer(const boost::any& val, ValueErrorVec& errMsgs) {
    static const T emptyContainer;

    const T* containerPtr = boost::any_cast<T>(&val);
    if (containerPtr) {
        return *containerPtr;
    } else {
        if (!val.empty())
            errMsgs.push_back(ValueError(ValueBadType, "Unexpected type " + getValueType(val) + "."));
        return emptyContainer;
    }
}

void getStringForKey(
    const Plist::dictionary_type& dict, const String& key, String& ret, GetterBehavior opt, const ErrorReporter& reporter) {
    ValueErrorVec errMsgs;
    const boost::any& val = getValueForKey(dict, key, errMsgs);
    if (!val.empty())
        getString(val, ret, errMsgs);
    reportErrorsForKey(errMsgs, opt, key, reporter);
}

int getIntForKey(const Plist::dictionary_type& dict, const String& key, GetterBehavior opt, const ErrorReporter& reporter) {
    String val;
    getStringForKey(dict, key, val, opt, reporter);

    int ret = 0;
    String::size_type sz = String::npos;
    try {
        ret = std::stoi(val, &sz);
    } catch (std::exception& e) {
    }

    if (sz != val.length())
        reporter.reportError("Failed to convert value of \"" + key + "\" to an integer.");

    return ret;
}

void getStringVectorForKey(
    const Plist::dictionary_type& dict, const String& key, StringVec& ret, GetterBehavior opt, const ErrorReporter& reporter) {
    ValueErrorVec errMsgs;
    const boost::any& val = getValueForKey(dict, key, errMsgs);
    if (!val.empty())
        getStringVector(val, ret, errMsgs);
    reportErrorsForKey(errMsgs, opt, key, reporter);
}

template <typename T>
void getStringMapForKey(const Plist::dictionary_type& dict, const String& key, T& ret, GetterBehavior opt, const ErrorReporter& reporter) {
    ValueErrorVec errMsgs;
    const boost::any& val = getValueForKey(dict, key, errMsgs);
    if (!val.empty())
        getStringMap(val, ret, errMsgs);
    reportErrorsForKey(errMsgs, opt, key, reporter);
}

template void getStringMapForKey<StringMap>(const Plist::dictionary_type&, const String&, StringMap&, GetterBehavior, const ErrorReporter&);
template void getStringMapForKey<SimpleVariableCollection>(
    const Plist::dictionary_type&, const String&, SimpleVariableCollection&, GetterBehavior, const ErrorReporter&);

template <typename T>
const T& castContainer(const boost::any& val, GetterBehavior opt, const ErrorReporter& reporter) {
    ValueErrorVec errMsgs;
    const T& ret = castContainer<T>(val, errMsgs);
    reportErrorsForKey(errMsgs, opt, "", reporter);
    return ret;
}

template const Plist::dictionary_type& castContainer<Plist::dictionary_type>(const boost::any&, GetterBehavior, const ErrorReporter&);
template const Plist::array_type& castContainer<Plist::array_type>(const boost::any&, GetterBehavior, const ErrorReporter&);

template <typename T>
const T& getContainerForKey(const Plist::dictionary_type& dict, const String& key, GetterBehavior opt, const ErrorReporter& reporter) {
    ValueErrorVec errMsgs;
    const boost::any& val = getValueForKey(dict, key, errMsgs);
    const T& ret = castContainer<T>(val, errMsgs);
    reportErrorsForKey(errMsgs, opt, key, reporter);
    return ret;
}

template const Plist::dictionary_type& getContainerForKey<Plist::dictionary_type>(const Plist::dictionary_type&,
                                                                                  const String&,
                                                                                  GetterBehavior,
                                                                                  const ErrorReporter&);
template const Plist::array_type& getContainerForKey<Plist::array_type>(const Plist::dictionary_type&,
                                                                        const String&,
                                                                        GetterBehavior,
                                                                        const ErrorReporter&);

PBXDocument* PBXDocument::createFromFile(const String& projPath) {
    String projFilePath = joinPaths(projPath, "project.pbxproj");
    const Plist::dictionary_type* pDict = NULL;
    boost::any pDoc;

    try {
        Plist::readPlist(projFilePath.c_str(), pDoc);
        pDict = dictionary_cast(pDoc);
    } catch (const std::exception& e) {
        SBLog::error() << e.what() << std::endl;
        pDict = NULL;
    }

    if (pDict) {
        return PBXDocument::createFromPlist(*pDict, projPath);
    } else {
        SBLog::error() << "Failed to read \"" << projFilePath << "\" project file." << std::endl;
        return NULL;
    }
}
