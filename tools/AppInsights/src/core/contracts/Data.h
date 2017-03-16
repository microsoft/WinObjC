#ifndef DATA_H
#define DATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "Base.h"
#include "Domain.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API Data : public Base
		{
		private:
			Domain* m_baseData;

		public:
			Data();
			virtual ~Data();

			Domain* GetBaseData() const { return m_baseData; }
			void SetBaseData(Domain& value) { m_baseData = &value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
