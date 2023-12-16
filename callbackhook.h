#ifndef CALLBACKHOOK_H  // Include guard to prevent multiple inclusion
#define CALLBACKHOOK_H

#include <Windows.h>

extern HHOOK hook;
LRESULT CALLBACK HookCallback(int nCode, WPARAM wParam, LPARAM lParam);


#endif