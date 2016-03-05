#ifndef STREAMWRITER_H
#define STREAMWRITER_H

#include "Common.h"

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API StreamWriter
		{
		protected:
			/// <summary>
			/// Initializes a new instance of the <see cref="StreamWriter"/> class.
			/// </summary>
			StreamWriter();

		public:
			/// <summary>
			/// Finalizes an instance of the <see cref="StreamWriter"/> class.
			/// </summary>
			virtual ~StreamWriter();

			/// <summary>
			/// Writes the bool value.
			/// </summary>
			/// <param name="value">if set to <c>true</c> [value].</param>
			void Write(bool value);

			/// <summary>
			/// Writes the int value.
			/// </summary>
			/// <param name="value">The value.</param>
			void Write(int value);

			/// <summary>
			/// Writes the float value.
			/// </summary>
			/// <param name="value">The value.</param>
			void Write(float value);

			/// <summary>
			/// Writes the specified value.
			/// </summary>
			/// <param name="value">The value.</param>
			void Write(double value);

			virtual void Write(wchar_t value) = 0;
			virtual void Write(const wchar_t* value) = 0;
		};
	}
}
#endif
