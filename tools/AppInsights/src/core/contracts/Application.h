#ifndef APPLICATION_H
#define APPLICATION_H

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
		class TELEMETRYCLIENT_API Application : public ISerializable
		{
		private:
			Nullable<std::wstring> m_ver;
			Nullable<std::wstring> m_build;

		public:
			Application();
			virtual ~Application();

			const Nullable<std::wstring>& GetVer() const { return m_ver; }
			void SetVer(const Nullable<std::wstring>& value) { m_ver = value; }

			const Nullable<std::wstring>& GetBuild() const { return m_build; }
			void SetBuild(const Nullable<std::wstring>& value) { m_build = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
