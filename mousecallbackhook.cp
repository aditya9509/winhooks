#include <iostream>
#include <Windows.h>
#include "callbackhook.h"
#include "processinformation.h"

// Callback function for the mouse hook
LRESULT CALLBACK HookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        // Mouse event occurred
        MSLLHOOKSTRUCT* pMouseStruct = reinterpret_cast<MSLLHOOKSTRUCT*>(lParam);
        // Display information about the mouse event
        switch (wParam) {
            case WM_LBUTTONDOWN:
            case WM_RBUTTONDOWN:
			    ProcessInformation pinfo = getProcessInformation(pMouseStruct->pt);
                std::cout << pinfo.getPnme() <<" | Coordinates - X: " << pMouseStruct->pt.x << ", Y: " << pMouseStruct->pt.y << " | " << pinfo.getElementType() << std::endl;
                break;
       }

    }

    // Call the next hook in the chain
    return CallNextHookEx(hook, nCode, wParam, lParam);
}