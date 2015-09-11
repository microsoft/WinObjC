#include <Windows.h>
#include <stdio.h>

__attribute((constructor)) void InitCOM()
{
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}