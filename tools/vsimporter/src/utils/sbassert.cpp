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

#include <stdlib.h>

#include "SBLog.h"
#include "sbassert.h"
#include "..\WBITelemetry\WBITelemetry.h"

void sbAssert(bool condition, const std::string& cause) {
    if (!condition) {
        if (!cause.empty())
            SBLog::error() << cause << std::endl;
        SBLog::printLocation();
#ifdef _DEBUG
        abort();
#else
        // Due to issue 6715724, flush before exiting
        TELEMETRY_FLUSH();
        exit(EXIT_FAILURE);
#endif
    }
}

void sbValidate(bool condition, const std::string& cause) {
    if (!condition) {
        if (!cause.empty())
            SBLog::error() << cause << std::endl;
        SBLog::printLocation();
        // Due to issue 6715724, flush before exiting
        TELEMETRY_FLUSH();
        exit(EXIT_FAILURE);
    }
}