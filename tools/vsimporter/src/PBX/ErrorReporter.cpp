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

#include "sbassert.h"
#include "telemetryutils.h"
#include "ErrorReporter.h"

ErrorReporter::~ErrorReporter() {}

ErrorReporter::ErrorReporter(SBLogLevel defaultSeverity)
  : m_severity(defaultSeverity)
{}

ErrorReporter::ErrorReporter(SBLogLevel defaultSeverity, const String& errContext)
  : m_severity(defaultSeverity),
    m_errorContext(errContext)
{}

void ErrorReporter::reportError(const String& errorMessage) const
{
  reportError(errorMessage, m_severity);
}

void ErrorReporter::reportError(const String& errorMessage, SBLogLevel severity) const
{
  String fullError = m_errorContext + errorMessage;
  if (severity != SB_ERROR)
    SBLog::log(severity) << fullError << std::endl;
  else
    sbValidateWithTelemetry(0, fullError);
}
