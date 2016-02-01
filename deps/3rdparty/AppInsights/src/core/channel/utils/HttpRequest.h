#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <map>
#include <string>
#include <memory>
#include <functional>

#include "HttpResponse.h"
#include "HttpHeaderFields.h"

namespace ApplicationInsights
{
	namespace core
	{
		enum class HTTP_REQUEST_METHOD
		{
			GET,
			POST,
			PUT
		};

		class TELEMETRYCLIENT_API HttpRequest
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="HttpRequest"/> class.
			/// </summary>
			/// <param name="method">The method.</param>
			/// <param name="hostname">The hostname.</param>
			/// <param name="requestUri">The request URI.</param>
			/// <param name="jsonPayload">The json payload.</param>
			HttpRequest(HTTP_REQUEST_METHOD method, const std::wstring& hostname = L"", const std::wstring& requestUri = L"*", const std::wstring& jsonPayload = L"");

			/// <summary>
			/// Finalizes an instance of the <see cref="HttpRequest"/> class.
			/// </summary>
			virtual ~HttpRequest();

			/// <summary>
			/// Gets the request method.
			/// </summary>
			/// <returns>the method</returns>
			HTTP_REQUEST_METHOD GetMethod() const {
				return m_Method;
			}

			/// <summary>
			/// Gets the request URI.
			/// </summary>
			/// <returns>the request uri</returns>
			std::wstring GetRequestUri() const {
				return m_RequestUri;
			}

			/// <summary>
			/// Gets the hostname.
			/// </summary>
			/// <returns>the hostname</returns>
			std::wstring GetHostname() const {
				return m_Hostname;
			}

			/// <summary>
			/// Gets the header fields.
			/// </summary>
			/// <returns>constant header fields</returns>
			const HttpHeaderFields& GetHeaderFields() const {
				return m_HeaderFields;
			}

			/// <summary>
			/// Gets the header fields.
			/// </summary>
			/// <returns>the header fields</returns>
			HttpHeaderFields& GetHeaderFields() {
				return m_HeaderFields;
			}

			/// <summary>
			/// Gets the payload.
			/// </summary>
			/// <returns>the payload</returns>
			const std::wstring GetPayload() const { return m_JsonPayload; }

			/// <summary>
			/// Sends the request and then calls the completion callback.
			/// </summary>
			/// <param name="completionCallback">The completion callback.</param>
			/// <returns>error code</returns>
			int Send(const std::function<void(const HttpResponse &resp)> &completionCallback) const;

		private:
			void *m_impl;
			HTTP_REQUEST_METHOD m_Method;
			std::wstring m_RequestUri;
			HttpHeaderFields m_HeaderFields;
			std::wstring m_JsonPayload;
			std::wstring m_Hostname;
		};
	}
}
#endif