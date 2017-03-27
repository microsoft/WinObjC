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

#ifndef _ERRORREPORTER_H_
#define _ERRORREPORTER_H_

#include "types.h"
#include "SBLog.h"

class ErrorReporter {
public:
    ErrorReporter(SBLogLevel defaultSeverity);
    ErrorReporter(SBLogLevel defaultSeverity, const String& errContext);
    virtual ~ErrorReporter();
    virtual void reportError(const String& errorMessage) const;
    virtual void reportError(const String& errorMessage, SBLogLevel severity) const;
    void setContext(const String& errContext) {
        m_errorContext = errContext;
    }

protected:
    SBLogLevel m_severity;
    String m_errorContext;

private:
    ErrorReporter();
};

#endif /* _ERRORREPORTER_H_ */
