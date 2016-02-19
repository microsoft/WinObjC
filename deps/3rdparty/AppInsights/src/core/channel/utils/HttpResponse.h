#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>
#include "../../Common/Common.h"

namespace ApplicationInsights
{
	namespace core
	{
		enum class HTTP_RESPONSE_CODE
		{
			HTTP_OK = 200,
			HTTP_SVR_ERROR = 500
		};

		class TELEMETRYCLIENT_API HttpResponse
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="HttpResponse"/> class.
			/// </summary>
			HttpResponse();

			/// <summary>
			/// Finalizes an instance of the <see cref="HttpResponse"/> class.
			/// </summary>
			virtual ~HttpResponse();

			/// <summary>
			/// Sets the error code.
			/// </summary>
			/// <param name="error">The error.</param>
			void SetErrorCode(int error);

			/// <summary>
			/// Gets the error code.
			/// </summary>
			/// <returns>the error code</returns>
			int GetErrorCode() const;

			/// <summary>
			/// Sets the payload.
			/// </summary>
			/// <param name="payload">The payload.</param>
			void SetPayload(std::string payload);

			/// <summary>
			/// Gets the payload.
			/// </summary>
			/// <returns>sthe payload</returns>
			const char *GetPayload() const;

		private:
			int m_errorCode;
			std::string m_payload;
		};
	}
}
#endif
