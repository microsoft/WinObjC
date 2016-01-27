#ifndef DATAPOINT_H
#define DATAPOINT_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "DataPointType.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API DataPoint : public ISerializable
		{
		private:
			std::wstring m_name;
			DataPointType m_kind;
			double m_value;
			Nullable<int> m_count;
			Nullable<double> m_min;
			Nullable<double> m_max;
			Nullable<double> m_stdDev;

		public:
			DataPoint();
			virtual ~DataPoint();

			const std::wstring& GetName() const { return m_name; }
			void SetName(const std::wstring& value) { m_name = value; }

			const DataPointType& GetKind() const { return m_kind; }
			void SetKind(const DataPointType& value) { m_kind = value; }

			const double& GetValue() const { return m_value; }
			void SetValue(const double& value) { m_value = value; }

			const Nullable<int>& GetCount() const { return m_count; }
			void SetCount(const Nullable<int>& value) { m_count = value; }

			const Nullable<double>& GetMin() const { return m_min; }
			void SetMin(const Nullable<double>& value) { m_min = value; }

			const Nullable<double>& GetMax() const { return m_max; }
			void SetMax(const Nullable<double>& value) { m_max = value; }

			const Nullable<double>& GetStdDev() const { return m_stdDev; }
			void SetStdDev(const Nullable<double>& value) { m_stdDev = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
