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

#ifndef _SBAGGREGATETARGET_H_
#define _SBAGGREGATETARGET_H_

#include "SBTarget.h"

class PBXAggregateTarget;

class SBAggregateTarget : public SBTarget {
public:
    static SBAggregateTarget* create(const PBXTarget* target, const StringSet& configNames, SBProject& parentProject);
    virtual ~SBAggregateTarget();

private:
    SBAggregateTarget(const PBXAggregateTarget* target, const StringSet& configNames, SBProject& parentProject);
    SBAggregateTarget();

    virtual VCProject* constructVCProject(VSTemplateProject* projTemplate);

    const PBXAggregateTarget* m_target;
};

#endif /* _SBAGGREGATETARGET_H_ */
