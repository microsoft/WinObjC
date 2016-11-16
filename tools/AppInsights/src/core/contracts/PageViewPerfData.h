#ifndef PAGEVIEWPERFDATA_H
#define PAGEVIEWPERFDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "PageViewData.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API PageViewPerfData : public PageViewData
		{
		private:
			std::wstring m_perfTotal;
			std::wstring m_networkConnect;
			std::wstring m_sentRequest;
			std::wstring m_receivedResponse;
			std::wstring m_domProcessing;

		public:
			PageViewPerfData();
			PageViewPerfData(std::wstring envelopeName, std::wstring dataType);
			virtual ~PageViewPerfData();

			const std::wstring& GetPerfTotal() const { return m_perfTotal; }
			void SetPerfTotal(const std::wstring& value) { m_perfTotal = value; }

			const std::wstring& GetNetworkConnect() const { return m_networkConnect; }
			void SetNetworkConnect(const std::wstring& value) { m_networkConnect = value; }

			const std::wstring& GetSentRequest() const { return m_sentRequest; }
			void SetSentRequest(const std::wstring& value) { m_sentRequest = value; }

			const std::wstring& GetReceivedResponse() const { return m_receivedResponse; }
			void SetReceivedResponse(const std::wstring& value) { m_receivedResponse = value; }

			const std::wstring& GetDomProcessing() const { return m_domProcessing; }
			void SetDomProcessing(const std::wstring& value) { m_domProcessing = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
