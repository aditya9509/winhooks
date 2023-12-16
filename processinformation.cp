#include <Windows.h>
#include <iostream>
#include <Psapi.h>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include "processinformation.h"

ProcessInformation getProcessInformation( POINT p) {  // Method/function defined inside the class
    HWND hWnd = WindowFromPoint(p);
	ProcessInformation pinfo;
    if (hWnd != NULL) {
        DWORD processId;
        GetWindowThreadProcessId(hWnd, &processId);
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);

            if (hProcess != NULL) {
                char filename[MAX_PATH];
                DWORD result = GetModuleFileNameExA(hProcess, NULL, filename, MAX_PATH);

                if (result > 0) {
					 std::string myString(filename);					 
					 
					 char className[256];
                     GetClassNameA(hWnd, className, sizeof(className));

					 std::string classString(className);
  					 pinfo.setPnme(myString.substr(myString.find_last_of("/\\")+1));
					 pinfo.setElementType(classString);
                } else {
                     pinfo.setPnme("NA");
					 pinfo.setElementType("NA");
 
                }

                CloseHandle(hProcess);
            } else {
                     pinfo.setPnme("NA");
					 pinfo.setElementType("NA");
            }
        
    } else {
                     pinfo.setPnme("NA");
					 pinfo.setElementType("NA");
    }
	
	return pinfo;

}
