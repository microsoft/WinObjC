#include "config.h"

#include <AL/alc.h>

#include "alMain.h"

#ifdef __ALC_HAS_CPP11__
#include <string>

typedef std::function<void(ALCdevice * resultDevice)> __callback_t;

static void alcOpenDeviceAsyncfuncCpp11(ALCdevice * resultDevice, ALCvoid* user_arg)
{
	__callback_t* nested_callback_function = (__callback_t*)user_arg;

	//invoke callback
	(*nested_callback_function)(resultDevice);

	//cleanup
	delete nested_callback_function;
}

ALC_API ALCboolean ALC_APIENTRY alcOpenDeviceAsync(const ALCchar *devicename, const __callback_t &callback)
{
	auto nested_callback_function = new (std::nothrow) __callback_t(callback);
	if (nested_callback_function == NULL)
	{
		alcSetError(NULL, ALC_OUT_OF_MEMORY);
		return ALC_FALSE;
	}

	ALCboolean re = alcOpenDeviceAsync(devicename, alcOpenDeviceAsyncfuncCpp11, nested_callback_function);

	if (re != ALC_TRUE)
		delete nested_callback_function;

	return re;
}
#endif//ifdef __ALC_HAS_CPP11__