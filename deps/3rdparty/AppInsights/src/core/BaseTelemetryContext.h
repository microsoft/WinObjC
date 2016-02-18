#ifndef BASETELEMETRYCONTEXT_H
#define BASETELEMETRYCONTEXT_H

#include <string>
#include "TelemetryClientConfig.h"
#include "Contracts/Contracts.h"
#include "Common/Common.h"

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API BaseTelemetryContext
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="BaseTelemetryContext"/> class.
			/// </summary>
			/// <param name="iKey">The i key.</param>
			BaseTelemetryContext(const std::wstring& iKey);

			/// <summary>
			/// Finalizes an instance of the <see cref="BaseTelemetryContext"/> class.
			/// </summary>
			virtual ~BaseTelemetryContext();

			/// <summary>
			/// Initializes the context.
			/// </summary>
			virtual void InitContext();

			/// <summary>
			/// Gets the user.
			/// </summary>
			/// <returns>the user context</returns>
			User& GetUser() { return user; }
			const User& GetUser() const { return user; }

			/// <summary>
			/// Gets the device.
			/// </summary>
			/// <returns>tne device context</returns>
			Device& GetDevice() { return device; }
			const Device& GetDevice() const { return device; }

			/// <summary>
			/// Gets the application.
			/// </summary>
			/// <returns>the application context</returns>
			Application& GetApplication() { return app; }
			const Application& GetApplication() const { return app; }

			/// <summary>
			/// Gets the session.
			/// </summary>
			/// <returns>the session context</returns>
			Session& GetSession() { return session; }
			const Session& GetSession() const { return session; }

			/// <summary>
			/// Renews the session.
			/// </summary>
			void RenewSession();

			/// <summary>
			/// Gets the context tags.
			/// </summary>
			/// <param name="tags">The tags.</param>
			/// <returns>RESULT_OK if succedded</returns>
			RESULT GetContextTags(wstring_wstring_map& buffer);

		protected:
			/// <summary>
			/// Initializes the user context.
			/// </summary>
			virtual void InitUser();

			/// <summary>
			/// Initializes the device context.
			/// </summary>
			virtual void InitDevice();

			/// <summary>
			/// Initializes the application.
			/// </summary>
			virtual void InitApplication();

			/// <summary>
			/// Initializes the session.
			/// </summary>
			virtual void InitSession();
				
			User user;
			Device device;
			Application app;
			Session session;
			std::wstring m_iKey;
		};
	}
}
#endif
