# Project Name

## Overview

This project provides a mechanism to capture and display information about the Windows process associated with a mouse click event using hook procedures. It consists of several files that work together to achieve this functionality.

### Files Description

1. **processinformation.h**

   - Header file for the method signature used to retrieve Windows process information where the hook event occurred.

2. **processinformation.cpp**

   - Implementation of the `getProcessInformation` method, which takes a `Point` as an argument and returns information about the active window process at that point.

3. **callbackhook.h**

   - Header file for the method signature of the hook procedure.

4. **mousecallbackhook.cpp**

   - Implementation of one hook procedure for low-level mouse events. This hook procedure prints out process information whenever a mouse click event occurs anywhere on the system.

5. **hookEventListener.cpp**

   - The main event listener responsible for registering the hook and hook procedure, and listening to hook events.

### How to Compile & Run

To compile the `hookEventListener.cpp`, run the following `g++` command:

```bash
g++ hookEventListener.cpp mousecallbackhook.cpp processinformation.cpp -o hookEventListener -lPsapi
```

This command compiles the main event listener, hook procedure implementation, and process information retrieval implementation into an executable named hookEventListener. `The -lPsapi` flag links the Psapi library, which is required for process information retrieval.

To run the program, execute `hookEventListener.exe` executable.