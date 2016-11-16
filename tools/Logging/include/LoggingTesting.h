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
#pragma once

#include "LoggingNative.h"
#include <string>

// Test hooks used by unit tests to verify proper logging behavior.

// Enables writing data to these test hooks upon calling trace methods.
LOGGING_EXPORT bool g_isTestHookEnabled;

// Stores output of last debug printf call when test hook is enabled.
LOGGING_EXPORT std::wstring g_debugTestHook;

// Stores ETL log level of the last trace method call when test hook is enabled.
LOGGING_EXPORT int g_etlLevelTestHook;

// Stores ETL tag of the last trace method call when test hook is enabled.
LOGGING_EXPORT std::wstring g_etlTagTestHook;

// Stores ETL wide message buffer of the last trace method call when test hook is enabled.
LOGGING_EXPORT std::wstring g_etlBufferTestHook;

// Stores ETL narrow message buffer of the last trace method call when test hook is enabled.
LOGGING_EXPORT std::string g_etlBufferNarrowTestHook;