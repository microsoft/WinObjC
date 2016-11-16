#ifndef PAGEVIEWDATA_H
#define PAGEVIEWDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "EventData.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API PageViewData : public EventData
		{
		private:
			std::wstring m_url;
			std::wstring m_duration;

		public:
			PageViewData();
			PageViewData(std::wstring envelopeName, std::wstring dataType);
			virtual ~PageViewData();

			const std::wstring& GetUrl() const { return m_url; }
			void SetUrl(const std::wstring& value) { m_url = value; }

			const std::wstring& GetDuration() const { return m_duration; }
			void SetDuration(const std::wstring& value) { m_duration = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
