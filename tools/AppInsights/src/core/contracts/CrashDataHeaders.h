#ifndef CRASHDATAHEADERS_H
#define CRASHDATAHEADERS_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API CrashDataHeaders : public ISerializable
		{
		private:
			std::wstring m_id;
			std::wstring m_process;
			int m_processId;
			std::wstring m_parentProcess;
			int m_parentProcessId;
			int m_crashThread;
			std::wstring m_applicationPath;
			std::wstring m_applicationIdentifier;
			std::wstring m_applicationBuild;
			std::wstring m_exceptionType;
			std::wstring m_exceptionCode;
			std::wstring m_exceptionAddress;
			std::wstring m_exceptionReason;

		public:
			CrashDataHeaders();
			virtual ~CrashDataHeaders();

			const std::wstring& GetId() const { return m_id; }
			void SetId(const std::wstring& value) { m_id = value; }

			const std::wstring& GetProcess() const { return m_process; }
			void SetProcess(const std::wstring& value) { m_process = value; }

			const int& GetProcessId() const { return m_processId; }
			void SetProcessId(const int& value) { m_processId = value; }

			const std::wstring& GetParentProcess() const { return m_parentProcess; }
			void SetParentProcess(const std::wstring& value) { m_parentProcess = value; }

			const int& GetParentProcessId() const { return m_parentProcessId; }
			void SetParentProcessId(const int& value) { m_parentProcessId = value; }

			const int& GetCrashThread() const { return m_crashThread; }
			void SetCrashThread(const int& value) { m_crashThread = value; }

			const std::wstring& GetApplicationPath() const { return m_applicationPath; }
			void SetApplicationPath(const std::wstring& value) { m_applicationPath = value; }

			const std::wstring& GetApplicationIdentifier() const { return m_applicationIdentifier; }
			void SetApplicationIdentifier(const std::wstring& value) { m_applicationIdentifier = value; }

			const std::wstring& GetApplicationBuild() const { return m_applicationBuild; }
			void SetApplicationBuild(const std::wstring& value) { m_applicationBuild = value; }

			const std::wstring& GetExceptionType() const { return m_exceptionType; }
			void SetExceptionType(const std::wstring& value) { m_exceptionType = value; }

			const std::wstring& GetCrashExceptionCode() const { return m_exceptionCode; }
			void SetCrashExceptionCode(const std::wstring& value) { m_exceptionCode = value; }

			const std::wstring& GetExceptionAddress() const { return m_exceptionAddress; }
			void SetExceptionAddress(const std::wstring& value) { m_exceptionAddress = value; }

			const std::wstring& GetExceptionReason() const { return m_exceptionReason; }
			void SetExceptionReason(const std::wstring& value) { m_exceptionReason = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
