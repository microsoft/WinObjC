#ifndef DOMAIN_H
#define DOMAIN_H

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
		class TELEMETRYCLIENT_API Domain : public ISerializable
		{
		private:
			std::wstring m_envelopeName;
			std::wstring m_baseType;

		public:
			Domain(std::wstring envelopeName, std::wstring dataType);
			virtual ~Domain();

			const std::wstring& GetEnvelopeName() const { return m_envelopeName; }
			const std::wstring& GetBaseType() const { return m_baseType; }
			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
