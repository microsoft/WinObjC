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

#ifndef _SBLOG_H_
#define _SBLOG_H_

#include <iostream>
#include <fstream>

#include "types.h"
#include "SplitStream.h"

enum SBLogLevel { SB_DEBUG = 0, SB_INFO = 1, SB_WARN = 2, SB_ERROR = 3 };

class SBLog {
public:
    ~SBLog();

    static void setVerbosity(SBLogLevel level);
    static void initWithLogDir(const String& logDir);
    static void printLocation();
    static SplitStream& log(SBLogLevel level);
    static SplitStream& error() {
        return log(SB_ERROR);
    }
    static SplitStream& warning() {
        return log(SB_WARN);
    }
    static SplitStream& info() {
        return log(SB_INFO);
    }
    static SplitStream& debug() {
        return log(SB_DEBUG);
    }
    static const String& getLogPath() {
        return s_logger.m_logPath;
    }

    // Functions for file tracking
    static void registerWorkspace(const String& absPath);
    static void registerProject(const String& absPath);
    static void registerTargetDir(const String& absPath);
    static void registerFile(const String& absPath);
    static void writeTrackedFiles();

private:
    SBLog();
    SplitStream& getStreamForSeverity(SBLogLevel severity);

    SBLogLevel m_verbosity;
    SplitStream m_errStream;
    SplitStream m_logStream;
    std::ofstream* m_logFile;
    String m_logPath;

    // Contrainers for file tracking
    StringSet m_workspacePaths;
    StringSet m_projectPaths;
    StringSet m_targetDirs;
    StringSet m_miscFiles;

    static SplitStream s_nullStream;
    static SBLog s_logger;
};

#endif /* _SBLOG_H_ */
