#if _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include "Window.h"

#if _WIN32
// 0x00477280
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    return 0;
}
#endif
