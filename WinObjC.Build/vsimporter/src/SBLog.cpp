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
#include "utils.h"

#include "SBLog.h"

SBLog SBLog::s_logger;
SplitStream SBLog::s_nullStream;

SBLog::SBLog()
  : m_verbosity(SB_DEBUG),
    m_errStream(std::cerr),
    m_logStream(std::cout),
    m_logFile(NULL)
{}

SBLog::~SBLog()
{
  delete m_logFile;
}

void SBLog::setVerbosity(SBLogLevel level)
{
  s_logger.m_verbosity = level;
}

void SBLog::initWithLogDir(const String& logDir)
{
  // Nothing to do if log directory is empty
  if (logDir.empty())
    return;

  // Create the log directory
  if (mkpath(logDir)) {
    SBLog::error() << "Failed to create \"" << logDir << "\" log directory. All log output will go to stderr." << std::endl;
    return;
  }

  // Create a unique filename
  std::stringstream ss;
  ss.precision(0);
  ss << std::fixed << logDir << "/ParseLog-" << getEpochTime() << ".log";
  std::string logPath = ss.str();

  // Try opening the log file
  std::ofstream* newFile = new std::ofstream(logPath.c_str());
  if (!newFile->good()) {
    delete newFile;
    SBLog::error() << "Failed to open \"" << logPath << "\" log file for writing. All log output will go to stderr." << std::endl;
    return;
  }

  // Update the logger
  delete s_logger.m_logFile;
  s_logger.m_logFile = newFile;
  s_logger.m_logPath = logPath;
  s_logger.m_logStream.clear();
  s_logger.m_logStream.addStream(*newFile);
  s_logger.m_errStream.addStream(*newFile);
}

void SBLog::printLocation()
{
  if (!s_logger.m_logPath.empty())
    std::cerr << "See " << s_logger.m_logPath << " for error details." << std::endl;
}

SplitStream& SBLog::getStreamForSeverity(SBLogLevel severity)
{
  if (severity < s_logger.m_verbosity)
    return s_nullStream;
  else if (severity == SB_ERROR)
    return m_errStream;
  else
    return m_logStream;
}

SplitStream& SBLog::log(SBLogLevel severity)
{
  // Figure out which output stream to return
  SplitStream& out = s_logger.getStreamForSeverity(severity);

  // Write the severity prefix before returning
  static const char* const levelLabels[] = {"[D] ", "[I] ", "[W] ", "[E] "};
  assert(severity < sizeof(levelLabels) / sizeof(char*));

  out << levelLabels[severity];
  return out;
}
