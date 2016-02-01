#include "HttpRequest.h"
#include "../../common/Utils.h"
#include <algorithm>
#include <locale>
#include <codecvt>
#include <vector>

using namespace ApplicationInsights::core;

class HttpRequestImplBase { 
    public:
        HttpRequestImplBase() {}
        virtual void Init() = 0;
        virtual void Destroy() = 0;
        virtual int Send(const HttpRequest &req, const std::function<void(const HttpResponse &resp)> &completionCallback) = 0;
};

#ifdef WIN32
#include <windows.h>
#endif

#if defined(WINAPI_FAMILY_PARTITION) // it's SOME kind of Windows
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Win32, no store, no phone
#include <winhttp.h>
class HttpRequestImpl : public HttpRequestImplBase
{
    private:
        HINTERNET hSession;
    
    public:
		/// <summary>
		/// Initializes this instance.
		/// </summary>
		virtual void Init()
        {
            hSession = WinHttpOpen(L"Application Insights SDK/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                   WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
        }
    
		/// <summary>
		/// Destroys this instance.
		/// </summary>
		virtual void Destroy()
        {
            WinHttpCloseHandle(hSession);
        }
    
		/// <summary>
		/// Sends the specified req.
		/// </summary>
		/// <param name="req">The req.</param>
		/// <param name="completionCallback">The completion callback.</param>
		/// <returns>Error code</returns>
		virtual int Send(const HttpRequest &req, const std::function<void(const HttpResponse &resp)> &completionCallback)
        {
            HANDLE hConnect = nullptr;
            HANDLE hRequest = nullptr;
            BOOL result = false;
            
            try
			{
                if (!hSession) { throw static_cast<DWORD>(-1); }
            
                hConnect = WinHttpConnect(hSession, req.GetHostname().c_str(), INTERNET_DEFAULT_HTTPS_PORT, 0);
                if (!hConnect) { throw GetLastError(); }
                std::wstring method = (req.GetMethod() == HTTP_REQUEST_METHOD::POST ? L"POST" : (req.GetMethod() == HTTP_REQUEST_METHOD::GET ? L"GET" : L"PUT"));
                hRequest = WinHttpOpenRequest(hConnect, method.c_str(), req.GetRequestUri().c_str(), nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);
                if (!hRequest) { throw GetLastError(); }
            
                std::wstring all_headers;
                std::string payload = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(req.GetPayload());
                
                std::for_each(req.GetHeaderFields().GetFields().begin(), req.GetHeaderFields().GetFields().end(), [&all_headers] (const HttpHeaderField &field) {
                    all_headers += field.ToWString() + L"\r\n";
                });

				LPVOID payloadp = reinterpret_cast<LPVOID>(const_cast<char *>(payload.c_str()));
                result = WinHttpSendRequest(hRequest, reinterpret_cast<LPCWSTR>(all_headers.c_str()), (DWORD)-1, payloadp, payload.size(), payload.size(), 0);
                if (!result) { throw GetLastError(); }
                result = WinHttpReceiveResponse(hRequest, nullptr);
                if (!result) { throw GetLastError(); }
            
                DWORD http_code = 0, junk = sizeof(http_code);
            
                result = WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, nullptr, &http_code, &junk, WINHTTP_NO_HEADER_INDEX);
                if (!result) { throw GetLastError(); }
            
                std::vector<char> responseBuffer;
                DWORD availableData = 0, readData = 0, totalData = 0;
                
                while ((result = WinHttpQueryDataAvailable(hRequest, &availableData)) && availableData > 0) {
                    responseBuffer.resize(responseBuffer.size() + availableData);
                    result = WinHttpReadData(hRequest, &responseBuffer.data()[totalData], availableData, &readData);
                    if (!result) { throw GetLastError(); }
					totalData += readData;
                    responseBuffer.resize(totalData);
                }
                if (!result) { throw GetLastError(); }
                
                HttpResponse resp;
                
                resp.SetErrorCode(static_cast<int>(http_code));
                resp.SetPayload(std::string(&responseBuffer[0], responseBuffer.size()));
                
                WinHttpCloseHandle(hRequest);
                WinHttpCloseHandle(hConnect);
                completionCallback(resp);
                return 0;
            } catch (DWORD err) {
                if (hRequest) {
                    WinHttpCloseHandle(hRequest);
                }
                if (hConnect) {
                    WinHttpCloseHandle(hConnect);
                }

				Utils::WriteDebugLine(L"ERROR: Exception thrown while sending request");
                return err;
            }
        }
};
#else // Windows, but not desktop; Phone or App
#include <ppltasks.h>
using namespace concurrency;
using namespace Platform;
using namespace Windows::Storage::Streams;
using namespace Windows::Foundation;
using namespace Windows::Web::Http;

class HttpRequestImpl : public HttpRequestImplBase
{
    public:
        virtual void Init()
        {
        }
    
        virtual void Destroy()
        {
        }
    
		/// <summary>
		/// Sends the specified request.
		/// </summary>
		/// <param name="req">The req.</param>
		/// <param name="completionCallback">The completion callback.</param>
		/// <returns>0 always</returns>
		virtual int Send(const HttpRequest &req, const std::function<void(const HttpResponse &resp)> &completionCallback)
		{
			String^ suri = ref new String((L"https://" + req.GetHostname() + req.GetRequestUri()).c_str());
			Uri^ uri = ref new Uri(suri);
			HttpClient^ httpClient = ref new HttpClient();
			String^ payload = ref new String(std::wstring(req.GetPayload()).c_str());
			String^ contentType = ref new String(L"application/json");
			HttpStringContent^ httpContent = ref new HttpStringContent(payload, UnicodeEncoding::Utf8, contentType);

			auto result = create_task(httpClient->PostAsync(uri, httpContent)
				).then([this, completionCallback](HttpResponseMessage^ response) {
				int code = static_cast<int>(response->StatusCode);

				create_task(response->Content->ReadAsStringAsync()).then([this, code, completionCallback](String ^content) {
					std::wstring rpayload(content->Data(), content->Length());
					std::string srpayload(std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(rpayload));
					HttpResponse resp;

					resp.SetErrorCode(code);
					resp.SetPayload(srpayload);
					completionCallback(resp);
				}).then([completionCallback](concurrency::task<void> t) {
					try {
						t.get();
					}
					catch (Exception^) {
						Utils::WriteDebugLine(L"ERROR: Exception thrown while receiving");
						completionCallback(HttpResponse());
					}
					catch (std::exception &) {
						Utils::WriteDebugLine(L"ERROR: Exception thrown while receiving");
						completionCallback(HttpResponse());
					}
					catch (...) {
						Utils::WriteDebugLine(L"ERROR: Exception thrown while receiving");
						completionCallback(HttpResponse());
					}
				});
			}).then([completionCallback](concurrency::task<void> t) {
				try {
					t.get();
				}
				catch (Exception^) {
					Utils::WriteDebugLine(L"ERROR: Exception thrown while sending");
					completionCallback(HttpResponse());
				}
				catch (std::exception &) {
					Utils::WriteDebugLine(L"ERROR: Exception thrown while sending");
					completionCallback(HttpResponse());
				}
				catch (...) {
					Utils::WriteDebugLine(L"ERROR: Exception thrown while sending");
					completionCallback(HttpResponse());
				}
			});
			return 0;
		}
};
#endif
#else // Everything else - OS X, Linux, Droid; use Curl
#include <curl/curl.h>

static size_t curl_write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    reinterpret_cast<std::string *>(stream)->append(reinterpret_cast<char *>(ptr), size * nmemb);
    return size * nmemb;
}

class HttpRequestImpl : public HttpRequestImplBase
{
    private:
        CURL *curl;
        static bool didGlobalInit;
    public:
        static void GlobalDestroy() { curl_global_cleanup(); }
    
        virtual void Init()
        {
            if (!HttpRequestImpl::didGlobalInit) {
                curl_global_init(CURL_GLOBAL_DEFAULT);
                HttpRequestImpl::didGlobalInit = true;
            }
            curl = curl_easy_init();

            // Enable "does the SSL cert have a valid root?" check.
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1);
            // Enable "does the SSL cert's CN match the hostname?" check.
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2);

#ifdef CPP_LIB_DEBUG
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
#else
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
#endif
        }
        virtual void Destroy()
        {
            curl_easy_cleanup(curl);
        }
        virtual int Send(const HttpRequest &req, const std::function<void(const HttpResponse &resp)> &completionCallback)
        {
            CURLcode res = CURLE_FAILED_INIT;
            
			if (curl == nullptr) {
                return res;
            }
            
            std::string url = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(L"https://" + req.GetHostname() + req.GetRequestUri());
            
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            if (req.GetMethod() == HTTP_REQUEST_METHOD::POST || req.GetMethod() == HTTP_REQUEST_METHOD::PUT) {
                curl_easy_setopt(curl, CURLOPT_POST, 1L);
                if (req.GetMethod() == HTTP_REQUEST_METHOD::PUT) {
                    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
                }
            }
            
            struct curl_slist *headerlist = nullptr;
            
            std::for_each(req.GetHeaderFields().GetFields().begin(), req.GetHeaderFields().GetFields().end(), [&headerlist] (const HttpHeaderField &field) {
                headerlist = curl_slist_append(headerlist, field.ToString().c_str());
            });
            
            std::string payload = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(req.GetPayload());
            std::string responseBuffer;
            
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
            
            if ((res = curl_easy_perform(curl)) != CURLE_OK) {
                return res;
            }
            
            int http_code = 0;
            HttpResponse resp;
            
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            resp.SetErrorCode(http_code);
            resp.SetPayload(responseBuffer);
            
            completionCallback(resp);
            return CURLE_OK;
        }
};
bool HttpRequestImpl::didGlobalInit = false;
#endif

/// <summary>
/// Initializes a new instance of the <see cref="HttpRequest"/> class.
/// </summary>
/// <param name="method">The method.</param>
/// <param name="hostname">The hostname.</param>
/// <param name="requestUri">The request URI.</param>
/// <param name="jsonPayload">The json payload.</param>
HttpRequest::HttpRequest(HTTP_REQUEST_METHOD method, const std::wstring& hostname, const std::wstring& requestUri, const std::wstring& jsonPayload)
	: m_impl(nullptr),
    m_Method(method),
	m_RequestUri(requestUri),
	m_JsonPayload(jsonPayload),
	m_Hostname(hostname)
{
    m_impl = new HttpRequestImpl;
    reinterpret_cast<HttpRequestImpl *>(m_impl)->Init();
}

/// <summary>
/// Finalizes an instance of the <see cref="HttpRequest"/> class.
/// </summary>
HttpRequest::~HttpRequest()
{
    reinterpret_cast<HttpRequestImpl *>(m_impl)->Destroy();
    delete reinterpret_cast<HttpRequestImpl *>(m_impl);
}

/// <summary>
/// Sends the request and then calls the completion callback.
/// </summary>
/// <param name="completionCallback">The completion callback.</param>
/// <returns></returns>
int HttpRequest::Send(const std::function<void(const HttpResponse &resp)> &completionCallback) const
{
    return reinterpret_cast<HttpRequestImpl *>(m_impl)->Send(*this, completionCallback);
}
