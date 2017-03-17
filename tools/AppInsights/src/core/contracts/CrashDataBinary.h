#ifndef CRASHDATABINARY_H
#define CRASHDATABINARY_H

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
		class TELEMETRYCLIENT_API CrashDataBinary : public ISerializable
		{
		private:
			std::wstring m_startAddress;
			std::wstring m_endAddress;
			std::wstring m_name;
			long m_cpuType;
			long m_cpuSubType;
			std::wstring m_uuid;
			std::wstring m_path;

		public:
			CrashDataBinary();
			virtual ~CrashDataBinary();

			const std::wstring& GetStartAddress() const { return m_startAddress; }
			void SetStartAddress(const std::wstring& value) { m_startAddress = value; }

			const std::wstring& GetEndAddress() const { return m_endAddress; }
			void SetEndAddress(const std::wstring& value) { m_endAddress = value; }

			const std::wstring& GetName() const { return m_name; }
			void SetName(const std::wstring& value) { m_name = value; }

			const long& GetCpuType() const { return m_cpuType; }
			void SetCpuType(const long& value) { m_cpuType = value; }

			const long& GetCpuSubType() const { return m_cpuSubType; }
			void SetCpuSubType(const long& value) { m_cpuSubType = value; }

			const std::wstring& GetUuid() const { return m_uuid; }
			void SetUuid(const std::wstring& value) { m_uuid = value; }

			const std::wstring& GetPath() const { return m_path; }
			void SetPath(const std::wstring& value) { m_path = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
