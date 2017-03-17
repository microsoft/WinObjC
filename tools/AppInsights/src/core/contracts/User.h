#ifndef USER_H
#define USER_H

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
		class TELEMETRYCLIENT_API User : public ISerializable
		{
		private:
			Nullable<std::wstring> m_accountAcquisitionDate;
			Nullable<std::wstring> m_accountId;
			Nullable<std::wstring> m_userAgent;
			Nullable<std::wstring> m_id;
			Nullable<std::wstring> m_storeRegion;

		public:
			User();
			virtual ~User();

			const Nullable<std::wstring>& GetAccountAcquisitionDate();
			void SetAccountAcquisitionDate(const Nullable<std::wstring>& value);

			const Nullable<std::wstring>& GetAccountId();
			void SetAccountId(const Nullable<std::wstring>& value);

			const Nullable<std::wstring>& GetUserAgent();
			void SetUserAgent(const Nullable<std::wstring>& value);

			const Nullable<std::wstring>& GetId();
			void SetId(const Nullable<std::wstring>& value);

			const Nullable<std::wstring>& GetStoreRegion();
			void SetStoreRegion(const Nullable<std::wstring>& value);

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
