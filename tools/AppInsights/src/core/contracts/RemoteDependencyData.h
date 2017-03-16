#ifndef REMOTEDEPENDENCYDATA_H
#define REMOTEDEPENDENCYDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "PageViewData.h"
#include "DependencySourceType.h"
#include "DependencyKind.h"
#include "DataPointType.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API RemoteDependencyData : public Domain
		{
		private:
			int m_ver;
			std::wstring m_name;
			DataPointType m_kind;
			double m_value;
			Nullable<int> m_count;
			Nullable<double> m_min;
			Nullable<double> m_max;
			Nullable<double> m_stdDev;
			DependencyKind m_dependencyKind;
			Nullable<bool> m_success;
			Nullable<bool> m_async;
			DependencySourceType m_dependencySource;
			std::wstring m_commandName;
			std::wstring m_dependencyTypeName;
			std::map<std::wstring, std::wstring> m_properties;

		public:
			RemoteDependencyData();
			RemoteDependencyData(std::wstring envelopeName, std::wstring dataType);
			virtual ~RemoteDependencyData();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

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

			const DependencyKind& GetDependencyKind() const { return m_dependencyKind; }
			void SetDependencyKind(const DependencyKind& value) { m_dependencyKind = value; }

			const Nullable<bool>& GetSuccess() const { return m_success; }
			void SetSuccess(const Nullable<bool>& value) { m_success = value; }

			const Nullable<bool>& GetAsync() const { return m_async; }
			void SetAsync(const Nullable<bool>& value) { m_async = value; }

			const DependencySourceType& GetDependencySource() const { return m_dependencySource; }
			void SetDependencySource(const DependencySourceType& value) { m_dependencySource = value; }

			const std::wstring& GetCommandName() const { return m_commandName; }
			void SetCommandName(const std::wstring& value) { m_commandName = value; }

			const std::wstring& GetDependencyTypeName() const { return m_dependencyTypeName; }
			void SetDependencyTypeName(const std::wstring& value) { m_dependencyTypeName = value; }

			const std::map<std::wstring, std::wstring>& GetProperties() const { return m_properties; }
			void SetProperties(const std::map<std::wstring, std::wstring>& value) { m_properties = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
