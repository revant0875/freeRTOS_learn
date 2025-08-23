# FreeRTOS Project Structure (POSIX Demo)

This project runs a FreeRTOS demo application on a POSIX/Linux system.  
Since FreeRTOS is modular, not all source files are required for every project.  
This README explains what each file does and when you need it.  

---

## Core Kernel Files

- **`tasks.c`**  
  Implements task creation, scheduling, suspension, and deletion.  
  Always required.  

- **`list.c`**  
  Provides linked list utilities used internally by tasks, queues, and timers.  
  Always required.  

- **`queue.c`**  
  Implements queues, semaphores, and mutexes.  
  Always required.  

---

## Optional Modules

- **`timers.c`**  
  Implements software timers (`xTimerCreate`, `xTimerStart`, etc.).  
  Only include if your project uses software timers.  

- **`event_groups.c`**  
  Implements event groups (`xEventGroupCreate`, `xEventGroupSetBits`, etc.).  
  Only include if your project uses event groups.  

---

## Portable Layer (for POSIX/Linux)

- **`portable/ThirdParty/GCC/Posix/port.c`**  
  The FreeRTOS porting layer for POSIX/Linux.  
  Handles task switching using pthreads and signals.  
  Required for POSIX builds.  

- **`portable/ThirdParty/GCC/Posix/utils/wait_for_event.c`**  
  Support utilities for the POSIX port (used for task blocking and waking).  
  Required for POSIX builds.  

---

## Memory Management

FreeRTOS requires exactly one memory management scheme:  

- **`heap_1.c`** → Very simple, no `free()`.  
- **`heap_2.c`** → Supports free, but fragments easily.  
- **`heap_3.c`** → Wraps the standard `malloc/free`.  
- **`heap_4.c`** → General-purpose allocator with coalescing.  
- **`heap_5.c`** → Like `heap_4`, but supports multiple memory regions.  

In this project, we use **`heap_4.c`**, which is the most flexible for learning.  

---

## Application

- **`main.c`**  
  Your application code.  
  Creates tasks and runs the FreeRTOS scheduler.  

---

## Minimum Files Needed for This Demo

For a basic task scheduling demo (no timers or event groups):  