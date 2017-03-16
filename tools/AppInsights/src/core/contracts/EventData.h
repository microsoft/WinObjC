#ifndef EVENTDATA_H
#define EVENTDATA_H

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
		class TELEMETRYCLIENT_API EventData : public Domain
		{
		private:
			int m_ver;
			std::wstring m_name;
			std::map<std::wstring, std::wstring> m_properties;
			std::map<std::wstring, double> m_measurements;

		public:
			EventData();
			EventData(std::wstring envelopeName, std::wstring dataType);
			virtual ~EventData();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

			const std::wstring& GetName() const { return m_name; }
			void SetName(const std::wstring& value) { m_name = value; }

			const std::map<std::wstring, std::wstring>& GetProperties() const { return m_properties; }
			void SetProperties(const std::map<std::wstring, std::wstring>& value) { m_properties = value; }

			const std::map<std::wstring, double>& GetMeasurements() const { return m_measurements; }
			void SetMeasurements(const std::map<std::wstring, double>& value) { m_measurements = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
