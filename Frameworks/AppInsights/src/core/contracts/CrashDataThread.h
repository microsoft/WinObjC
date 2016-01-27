#ifndef CRASHDATATHREAD_H
#define CRASHDATATHREAD_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "CrashDataThreadFrame.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API CrashDataThread : public ISerializable
		{
		private:
			int m_id;
			std::vector<CrashDataThreadFrame*> m_frames;

		public:
			CrashDataThread();
			virtual ~CrashDataThread();

			const int& GetId() const { return m_id; }
			void SetId(const int& value) { m_id = value; }

			const std::vector<CrashDataThreadFrame*>& GetFrames() const { return m_frames; }
			void SetFrames(const std::vector<CrashDataThreadFrame*>& value) { m_frames = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
