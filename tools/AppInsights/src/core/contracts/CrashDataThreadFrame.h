#ifndef CRASHDATATHREADFRAME_H
#define CRASHDATATHREADFRAME_H

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
		class TELEMETRYCLIENT_API CrashDataThreadFrame : public ISerializable
		{
		private:
			std::wstring m_address;
			std::wstring m_symbol;
			std::map<std::wstring, std::wstring> m_registers;

		public:
			CrashDataThreadFrame();
			virtual ~CrashDataThreadFrame();

			const std::wstring& GetAddress() const { return m_address; }
			void SetAddress(const std::wstring& value) { m_address = value; }

			const std::wstring& GetSymbol() const { return m_symbol; }
			void SetSymbol(const std::wstring& value) { m_symbol = value; }

			const std::map<std::wstring, std::wstring>& GetRegisters() const { return m_registers; }
			void SetRegisters(const std::map<std::wstring, std::wstring>& value) { m_registers = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
