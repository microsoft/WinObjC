#ifndef METRICDATA_H
#define METRICDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "DataPoint.h"
#include "Domain.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API MetricData : public Domain
		{
		private:
			int m_ver;
			std::vector<DataPoint*> m_metrics;
			std::map<std::wstring, std::wstring> m_properties;

		public:
			MetricData();
			MetricData(std::wstring envelopeName, std::wstring dataType);
			virtual ~MetricData();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

			const std::vector<DataPoint*>& GetMetrics() const { return m_metrics; }
			void SetMetrics(const std::vector<DataPoint*>& value) { m_metrics = value; }

			const std::map<std::wstring, std::wstring>& GetProperties() const { return m_properties; }
			void SetProperties(const std::map<std::wstring, std::wstring>& value) { m_properties = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
