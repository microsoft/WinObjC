#ifndef JSONWRITER_H
#define JSONWRITER_H

#include "../Common/Common.h"
#include "../Common/Serializer.h"
#include <type_traits>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API JsonWriter : public Serializer
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="JsonWriter"/> class.
			/// </summary>
			/// <param name="writer">The writer.</param>
			JsonWriter(StreamWriter &writer);

			/// <summary>
			/// Finalizes an instance of the <see cref="JsonWriter"/> class.
			/// </summary>
			virtual ~JsonWriter();

			/// <summary>
			/// Begins the dictionary value.
			/// </summary>
			virtual void BeginDictionaryValue();

			/// <summary>
			/// Writes the name of the property.
			/// </summary>
			/// <param name="name">The name.</param>
			virtual void WritePropertyName(const std::wstring &name);

			/// <summary>
			/// Ends the dictionary value.
			/// </summary>
			virtual void EndDictionaryValue();

			/// <summary>
			/// Begins the array value.
			/// </summary>
			virtual void BeginArrayValue();

			/// <summary>
			/// Ends the array value.
			/// </summary>
			virtual void EndArrayValue();

			/// <summary>
			/// Writes the bool value.
			/// </summary>
			/// <param name="value">if set to <c>true</c> [value].</param>
			virtual void WriteBoolValue(bool value);

			/// <summary>
			/// Writes the integer value.
			/// </summary>
			/// <param name="value">The value.</param>
			virtual void WriteIntegerValue(int value);

			/// <summary>
			/// Writes the double value.
			/// </summary>
			/// <param name="value">The value.</param>
			virtual void WriteDoubleValue(double value);

			/// <summary>
			/// Writes the string value.
			/// </summary>
			/// <param name="value">The value.</param>
			virtual void WriteStringValue(const std::wstring &value);

		protected:
			/// <summary>
			/// Adds a comma if needed
			/// </summary>
			/// <param name="kind">The kind.</param>
			virtual void PrepareValue(StackEntry kind);
		};
	}
}
#endif
