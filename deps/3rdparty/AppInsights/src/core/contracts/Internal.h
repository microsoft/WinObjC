#ifndef INTERNAL_H
#define INTERNAL_H

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
		class TELEMETRYCLIENT_API Internal : public ISerializable
		{
		private:
			Nullable<std::wstring> m_sdkVersion;
			Nullable<std::wstring> m_agentVersion;

		public:
			Internal();
			virtual ~Internal();

			const Nullable<std::wstring>& GetSdkVersion() const { return m_sdkVersion; }
			void SetSdkVersion(const Nullable<std::wstring>& value) { m_sdkVersion = value; }

			const Nullable<std::wstring>& GetAgentVersion() const { return m_agentVersion; }
			void SetAgentVersion(const Nullable<std::wstring>& value) { m_agentVersion = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}

#endif
