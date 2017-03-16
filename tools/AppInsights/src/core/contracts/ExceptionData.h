#ifndef EXCEPTIONDATA_H
#define EXCEPTIONDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "Domain.h"
#include "ExceptionDetails.h"
#include "SeverityLevel.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API ExceptionData : public Domain
		{
		private:
			int m_ver;
			std::wstring m_handledAt;
			std::vector<ExceptionDetails*> m_exceptions;
			Nullable<SeverityLevel> m_severityLevel;
			std::wstring m_problemId;
			int m_crashThreadId;
			std::map<std::wstring, std::wstring> m_properties;
			std::map<std::wstring, double> m_measurements;

		public:
			ExceptionData();
			ExceptionData(std::wstring envelopeName, std::wstring dataType);
			virtual ~ExceptionData();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

			const std::wstring& GetHandledAt() const { return m_handledAt; }
			void SetHandledAt(const std::wstring& value) { m_handledAt = value; }

			const std::vector<ExceptionDetails*>& GetExceptions() const { return m_exceptions; }
			void SetExceptions(const std::vector<ExceptionDetails*>& value) { m_exceptions = value; }

			const Nullable<SeverityLevel>& GetSeverityLevel() const { return m_severityLevel; }
			void SetSeverityLevel(const Nullable<SeverityLevel>& value) { m_severityLevel = value; }

			const std::wstring& GetProblemId() const { return m_problemId; }
			void SetProblemId(const std::wstring& value) { m_problemId = value; }

			const int& GetCrashThreadId() const { return m_crashThreadId; }
			void SetCrashThreadId(const int& value) { m_crashThreadId = value; }

			const std::map<std::wstring, std::wstring>& GetProperties() const { return m_properties; }
			void SetProperties(const std::map<std::wstring, std::wstring>& value) { m_properties = value; }

			const std::map<std::wstring, double>& GetMeasurements() const { return m_measurements; }
			void SetMeasurements(const std::map<std::wstring, double>& value) { m_measurements = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
