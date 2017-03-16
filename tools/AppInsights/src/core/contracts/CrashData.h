#ifndef CRASHDATA_H
#define CRASHDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "CrashDataBinary.h"
#include "CrashDataHeaders.h"
#include "CrashDataThread.h"
#include "Domain.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API CrashData : public Domain
		{
		private:
			int m_ver;
			CrashDataHeaders* m_headers;
			std::vector<CrashDataThread*> m_threads;
			std::vector<CrashDataBinary*> m_binaries;

		public:
			CrashData();
			CrashData(std::wstring envelopeName, std::wstring dataType);
			virtual ~CrashData();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

			CrashDataHeaders* GetHeaders() const { return m_headers; }
			void SetHeaders(CrashDataHeaders* value) { m_headers = value; }

			const std::vector<CrashDataThread*>& GetThreads() const { return m_threads; }
			void SetThreads(const std::vector<CrashDataThread*>& value) { m_threads = value; }

			const std::vector<CrashDataBinary*>& GetBinaries() const { return m_binaries; }
			void SetBinaries(const std::vector<CrashDataBinary*>& value) { m_binaries = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}

#endif
