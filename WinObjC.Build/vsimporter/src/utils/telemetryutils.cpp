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


#include "sbassert.h"
#include "telemetryutils.h"
#include <string>
#include "..\WBITelemetry\WBITelemetry.h"


// Wrap sbassert with a telemetry call.
void sbAssertWithTelemetry(bool condition, const std::string& cause) {
	// If we don't meet the condition, send a VSImporterIncomplete telemetry event
	if (!condition) {
		if (!cause.empty()) {
			std::string strippedCause = stripTrailingData(cause);
			TELEMETRY_EVENT_DATA(L"VSImporterIncomplete", strippedCause.c_str());
		}
		else {
			TELEMETRY_EVENT_DATA(L"VSImporterIncomplete", "No cause given");
		}
	}
	sbAssert(condition, cause);
}

// Wrap sbvalidate with a telemetry call.
void sbValidateWithTelemetry(bool condition, const std::string& cause) {
	// If we don't meet the condition, send a VSImporterIncomplete telemetry event
	if (!condition) {
		if (!cause.empty()) {
			std::string strippedCause = stripTrailingData(cause);
			TELEMETRY_EVENT_DATA(L"VSImporterIncomplete", strippedCause.c_str());
		}
		else {
			TELEMETRY_EVENT_DATA(L"VSImporterIncomplete", "No cause given");
		}
	}
	sbValidate(condition, cause);
}

// remove potentially personal data from telemetry calls
std::string stripTrailingData(const std::string& cause) {
	// Output follows the form of "Invalid message: contextual information"
	// We need to remove the contextual information if any exists.
	size_t index = cause.find(":");
	if (index != -1) {
		// Substring represents start of string to just before the colon
		std::string output = cause.substr(0, index);
		return output;
	}
	else {
		return cause;
	}
}