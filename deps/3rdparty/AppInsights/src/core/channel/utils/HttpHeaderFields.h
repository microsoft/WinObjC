#ifndef HTTPHEADERFIELDS_H
#define HTTPHEADERFIELDS_H

#include <list>
#include <string>
#include "HttpHeaderField.h"

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API HttpHeaderFields
		{
		public:
			/// <summary>
			/// Gets all the fields.
			/// </summary>
			/// <returns>the constant list of field</returns>
			const std::list<HttpHeaderField>& GetFields() const {
				return m_Fields;
			}

			/// <summary>
			/// Determine if a field with the specified name exists.
			/// </summary>
			/// <param name="fieldName">Name of the field.</param>
			/// <returns>true if it contains a field with fieldName, otherwise false</returns>
			bool HasField(const std::wstring& fieldName) const {
				return std::find(m_Fields.cbegin(), m_Fields.cend(), HttpHeaderField(fieldName)) != m_Fields.end();
			}

			/// <summary>
			/// Gets the operator with the specified name.
			/// </summary>
			/// <param name="fieldName">Name of the field.</param>
			/// <returns>constant field for fieldName</returns>
			const HttpHeaderField& operator [](const std::wstring& fieldName) const {
				return *std::find(m_Fields.cbegin(), m_Fields.cend(), HttpHeaderField(fieldName));
			}

			/// <summary>
			/// Gets the field.
			/// </summary>
			/// <param name="fieldName">Name of the field.</param>
			/// <returns>constant Fields</returns>
			const HttpHeaderField& GetField(const std::wstring& fieldName) const {
				return *std::find(m_Fields.cbegin(), m_Fields.cend(), HttpHeaderField(fieldName));
			}

			/// <summary>
			/// Sets the field.
			/// </summary>
			/// <param name="fieldName">Name of the field.</param>
			/// <param name="fieldValue">The field value.</param>
			void SetField(const std::wstring& fieldName, const std::wstring& fieldValue) {
				auto iter = std::find(m_Fields.cbegin(), m_Fields.cend(), HttpHeaderField(fieldName));
				if (iter != m_Fields.end())
				{
					m_Fields.remove(*iter);
				}

				m_Fields.push_back(HttpHeaderField(fieldName, fieldValue));
			}

		private:
			std::list<HttpHeaderField> m_Fields;
		};
	}
}
#endif