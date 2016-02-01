#ifndef REQUESTDATA_H
#define REQUESTDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "Domain.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API RequestData : public Domain
		{
		private:
			int m_ver;
			std::wstring m_id;
			std::wstring m_name;
			std::wstring m_startTime;
			std::wstring m_duration;
			std::wstring m_responseCode;
			bool m_success;
			std::wstring m_httpMethod;
			std::wstring m_url;
			std::map<std::wstring, std::wstring> m_properties;
			std::map<std::wstring, double> m_measurements;

		public:
			RequestData();
			RequestData(std::wstring envelopeName, std::wstring dataType);
			virtual ~RequestData();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

			const std::wstring& GetId() const { return m_id; }
			void SetId(const std::wstring& value) { m_id = value; }

			const std::wstring& GetName() const { return m_name; }
			void SetName(const std::wstring& value) { m_name = value; }

			const std::wstring& GetStartTime() const { return m_startTime; }
			void SetStartTime(const std::wstring& value) { m_startTime = value; }

			const std::wstring& GetDuration() const { return m_duration; }
			void SetDuration(const std::wstring& value) { m_duration = value; }

			const std::wstring& GetResponseCode() const { return m_responseCode; }
			void SetResponseCode(const std::wstring& value) { m_responseCode = value; }

			const bool& GetSuccess() const { return m_success; }
			void SetSuccess(const bool& value) { m_success = value; }

			const std::wstring& GetHttpMethod() const { return m_httpMethod; }
			void SetHttpMethod(const std::wstring& value) { m_httpMethod = value; }

			const std::wstring& GetUrl() const { return m_url; }
			void SetUrl(const std::wstring& value) { m_url = value; }

			const std::map<std::wstring, std::wstring>& GetProperties() const { return m_properties; }
			void SetProperties(const std::map<std::wstring, std::wstring>& value) { m_properties = value; }

			const std::map<std::wstring, double>& GetMeasurements() const { return m_measurements; }
			void SetMeasurements(const std::map<std::wstring, double>& value) { m_measurements = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
