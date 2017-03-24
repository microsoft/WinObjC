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

#include "PBXAggregateTarget.h"
#include "SBAggregateTarget.h"

SBAggregateTarget::~SBAggregateTarget() {
}

SBAggregateTarget::SBAggregateTarget(const PBXAggregateTarget* target, const StringSet& configNames, SBProject& parentProject)
    : SBTarget(target, configNames, parentProject), m_target(target) {
}

SBAggregateTarget* SBAggregateTarget::create(const PBXTarget* target, const StringSet& configNames, SBProject& parentProject) {
    SBAggregateTarget* ret = new SBAggregateTarget(dynamic_cast<const PBXAggregateTarget*>(target), configNames, parentProject);
    if (!ret->init()) {
        delete ret;
        ret = NULL;
    }

    return ret;
}

VCProject* SBAggregateTarget::constructVCProject(VSTemplateProject* projTemplate) {
    return SBTarget::constructVCProject(projTemplate);
}