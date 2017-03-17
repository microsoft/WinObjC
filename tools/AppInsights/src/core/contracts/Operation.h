#ifndef OPERATION_H
#define OPERATION_H

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
		class TELEMETRYCLIENT_API Operation : public ISerializable
		{
		private:
			Nullable<std::wstring> m_id;
			Nullable<std::wstring> m_name;
			Nullable<std::wstring> m_parentId;
			Nullable<std::wstring> m_rootId;
			Nullable<std::wstring> m_syntheticSource;
			Nullable<std::wstring> m_isSynthetic;

		public:
			Operation();
			virtual ~Operation();

			const Nullable<std::wstring>& GetId() const { return m_id; }
			void SetId(const Nullable<std::wstring>& value) { m_id = value; }

			const Nullable<std::wstring>& GetName() const { return m_name; }
			void SetName(const Nullable<std::wstring>& value) { m_name = value; }

			const Nullable<std::wstring>& GetParentId() const { return m_parentId; }
			void SetParentId(const Nullable<std::wstring>& value) { m_parentId = value; }

			const Nullable<std::wstring>& GetRootId() const { return m_rootId; }
			void SetRootId(const Nullable<std::wstring>& value) { m_rootId = value; }

			const Nullable<std::wstring>& GetSyntheticSource() const { return m_syntheticSource; }
			void SetSyntheticSource(const Nullable<std::wstring>& value) { m_syntheticSource = value; }

			const Nullable<std::wstring>& GetIsSynthetic() const { return m_isSynthetic; }
			void SetIsSynthetic(const Nullable<std::wstring>& value) { m_isSynthetic = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
