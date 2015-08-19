#include "unistd.h"

#include <SDKDDKVer.h>
#include <Windows.h>

unsigned int sleep(unsigned int seconds)
{
	Sleep(seconds * 1000);
	return 0;
}
