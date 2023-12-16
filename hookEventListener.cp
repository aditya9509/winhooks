#include <iostream>
#include <Windows.h>

// Global variable to store the handle to the hook
HHOOK hook;

#include "callbackhook.h"

int main() {
    // Set up the mouse hook
    hook = SetWindowsHookEx(WH_MOUSE_LL, HookCallback, GetModuleHandle(NULL), 0);

    if (hook == NULL) {
        std::cerr << "Failed to set up hook." << std::endl;
        return 1;
    }

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) != 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unhook the mouse hook before exiting
    UnhookWindowsHookEx(hook);

    return 0;
}

// g++ hookEventListener.cc mousecallbackhook.cc processinformation.cc -o hook  -lPsapi