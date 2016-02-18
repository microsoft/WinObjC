#ifndef STRINGWRITER_H
#define STRINGWRITER_H

#include "StreamWriter.h"
#include <string>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API StringWriter :
			public StreamWriter
		{
			std::wstring *builder;

		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="StringWriter"/> class.
			/// </summary>
			/// <param name="builder">The builder.</param>
			StringWriter(std::wstring* builder);

			/// <summary>
			/// Finalizes an instance of the <see cref="StringWriter"/> class.
			/// </summary>
			virtual ~StringWriter();


			/// <summary>
			/// Gets the wstring represenation of the contents of the class
			/// </summary>
			/// <returns>The wstring represenation of the contents</returns>
			std::wstring ToString() const {
				return *builder;
			}

			/// <summary>
			/// Writes the specified value.
			/// </summary>
			/// <param name="value">The value.</param>
			virtual void Write(wchar_t value);

			/// <summary>
			/// Writes the specified value.
			/// </summary>
			/// <param name="value">The value.</param>
			virtual void Write(const wchar_t* value);
		};
	}
}
#endif
