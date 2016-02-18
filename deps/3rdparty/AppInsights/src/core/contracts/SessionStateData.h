#ifndef SESSIONSTATEDATA_H
#define SESSIONSTATEDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "Domain.h"
#include "SessionState.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API SessionStateData : public Domain
		{
		private:
			int m_ver;
			SessionState m_state;

		public:
			SessionStateData();
			SessionStateData(std::wstring envelopeName, std::wstring dataType);
			virtual ~SessionStateData();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

			const SessionState& GetState() const { return m_state; }
			void SetState(const SessionState& value) { m_state = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
