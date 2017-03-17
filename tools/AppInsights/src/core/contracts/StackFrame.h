#ifndef STACKFRAME_H
#define STACKFRAME_H

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
		class TELEMETRYCLIENT_API StackFrame : public ISerializable
		{
		private:
			int m_level;
			std::wstring m_method;
			std::wstring m_assembly;
			std::wstring m_fileName;
			int m_line;

		public:
			StackFrame();
			virtual ~StackFrame();

			const int& GetLevel() const { return m_level; }
			void SetLevel(const int& value) { m_level = value; }

			const std::wstring& GetMethod() const { return m_method; }
			void SetMethod(const std::wstring& value) { m_method = value; }

			const std::wstring& GetAssembly() const { return m_assembly; }
			void SetAssembly(const std::wstring& value) { m_assembly = value; }

			const std::wstring& GetFileName() const { return m_fileName; }
			void SetFileName(const std::wstring& value) { m_fileName = value; }

			const int& GetLine() const { return m_line; }
			void SetLine(const int& value) { m_line = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
