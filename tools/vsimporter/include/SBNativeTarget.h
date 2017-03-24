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

#ifndef _SBNATIVETARGET_H_
#define _SBNATIVETARGET_H_

#include "SBTarget.h"

class PBXNativeTarget;

class SBNativeTarget : public SBTarget {
public:
    static SBNativeTarget* create(const PBXTarget* target, const StringSet& configNames, SBProject& parentProject);
    virtual ~SBNativeTarget();
    virtual TargetProductType getProductType() const {
        return m_type;
    }

private:
    SBNativeTarget(const PBXNativeTarget* target, const StringSet& configNames, SBProject& parentProject);
    SBNativeTarget();
    bool init();

    virtual VCProject* constructVCProject(VSTemplateProject* projTemplate);

    const PBXNativeTarget* m_target;
    TargetProductType m_type;
};

#endif /* _SBNATIVETARGET_H_ */
