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

#ifndef _BUILDSETTINGSINFO_H_
#define _BUILDSETTINGSINFO_H_

#include "types.h"

class VariableCollection;
class VariableCollectionHierarchy;

enum ValueType { BoolValue, StringValue, StringListValue, PathValue, PathListValue };

enum ProductMask { AppSetting = 1, StaticLibSetting = 2, UniversalSetting = AppSetting | StaticLibSetting };

typedef String (*param_func)(const String&, const String&, const VariableCollectionHierarchy&);

struct ParamDesc {
    ParamDesc(const char* v1, const char* v2, param_func f = NULL) : val1(v1), val2(v2), func(f) {
    }

    const char* val1;
    const char* val2;
    param_func func;
};

struct SettingDesc {
    const char* name;
    const char* defaultValue;
    ValueType type;
    const ParamDesc* paramDesc;
    ProductMask mask;
};

void getDefaultSettingValues(VariableCollection& vc, ProductMask mask);
const SettingDesc& getSettingDescription(const String& name);

#endif /* _BUILDSETTINGSINFO_H_ */
