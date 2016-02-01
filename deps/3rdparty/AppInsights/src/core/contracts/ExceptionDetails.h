#ifndef EXCEPTIONDETAILS_H
#define EXCEPTIONDETAILS_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "StackFrame.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API ExceptionDetails : public ISerializable
		{
		private:
			int m_id;
			int m_outerId;
			std::wstring m_typeName;
			std::wstring m_message;
			bool m_hasFullStack;
			std::wstring m_stack;
			std::vector<StackFrame*> m_parsedStack;

		public:
			ExceptionDetails();
			virtual ~ExceptionDetails();

			const int& GetId() const { return m_id; }
			void SetId(const int& value) { m_id = value; }

			const int& GetOuterId() const { return m_outerId; }
			void SetOuterId(const int& value) { m_outerId = value; }

			const std::wstring& GetTypeName() const { return m_typeName; }
			void SetTypeName(const std::wstring& value) { m_typeName = value; }

			const std::wstring& GetMessage() const { return m_message; }
			void SetMessage(const std::wstring& value) { m_message = value; }

			const bool& GetHasFullStack() const { return m_hasFullStack; }
			void SetHasFullStack(const bool& value) { m_hasFullStack = value; }

			const std::wstring& GetStack() const { return m_stack; }
			void SetStack(const std::wstring& value) { m_stack = value; }

			const std::vector<StackFrame*>& GetParsedStack() const { return m_parsedStack; }
			void SetParsedStack(const std::vector<StackFrame*>& value) { m_parsedStack = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}

#endif
