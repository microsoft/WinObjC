#ifndef HTTPHEADERFIELD_H
#define HTTPHEADERFIELD_H

#include "../../Common/Common.h"
#include <string>
namespace ApplicationInsights
{
	namespace core
	{
		/// <summary>
		/// 
		/// </summary>
		class TELEMETRYCLIENT_API HttpHeaderField
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="HttpHeaderField" /> class.
			/// </summary>
			/// <param name="name">The name.</param>
			/// <param name="value">The value.</param>
			HttpHeaderField(const std::wstring& name = L"", const std::wstring& value = L"");

			/// <summary>
			/// Gets the field name.
			/// </summary>
			/// <returns>the field name</returns>
			const std::wstring& GetName() const {
				return m_strName;
			}

			/// <summary>
			/// Gets the field value.
			/// </summary>
			/// <returns>the value of the field</returns>
			const std::wstring& GetValue() const {
				return m_strValue;
			}

			/// <summary>
			/// Determine if two header fields have the same name (value may differ)
			/// </summary>
			/// <param name="field">The field.</param>
			/// <returns>true if the fields match, otherwise false</returns>
			bool operator ==(const HttpHeaderField& field) const {
#if WINAPI_FAMILY || _WIN32
				return _wcsicmp(m_strName.c_str(), field.m_strName.c_str()) == 0;
#else
				return wcscasecmp(m_strName.c_str(), field.m_strName.c_str()) == 0;
#endif
			}

			/// <summary>
			/// Determine if two header fields different names (value might be the same)
			/// </summary>
			/// <param name="field">The field.</param>
			/// <returns>true if the fields DO NOT match, otherwise false</returns>
			bool operator !=(const HttpHeaderField& field) const {
#if WINAPI_FAMILY || _WIN32
				return _wcsicmp(m_strName.c_str(), field.m_strName.c_str()) != 0;
#else
				return wcscasecmp(m_strName.c_str(), field.m_strName.c_str()) != 0;
#endif
			}

			/// <summary>
			/// Convert header fields to the string.
			/// </summary>
			/// <returns>string representation of the fields</returns>
			std::string ToString() const;

			/// <summary>
			/// Convert header fields to the string.
			/// </summary>
			/// <returns>wstring representation of the fields</returns>
			std::wstring ToWString() const;

		private:
			std::wstring m_strName;
			std::wstring m_strValue;
		};
	}
}
#endif