# FreeRTOS Heap Memory Allocation Schemes

FreeRTOS provides multiple memory allocation strategies (implemented as `heap_x.c` files).  
You can choose one depending on the application requirements.  
Only **one** heap_x.c should be included in your build.

---

## 1. `heap_1.c` – Simplest, No Free
- **How it works**:  
  - Very basic allocator.  
  - Memory is only **allocated** (using `pvPortMalloc`).  
  - Memory is **never freed** (no `vPortFree`).  

- **Pros**:  
  - Extremely small and deterministic.  
  - No fragmentation (since free is not supported).  

- **Cons**:  
  - If you run out of heap, you must reset the system.  
  - Cannot be used for tasks/objects that are created and deleted dynamically.  

- **Use case**:  
  - Small systems with **static or fixed allocation** (tasks created once and never deleted).  

---

## 2. `heap_2.c` – Alloc + Free (Simple, Fragmentation Possible)
- **How it works**:  
  - Supports both `malloc` and `free`.  
  - Uses a simple algorithm to manage free blocks.  

- **Pros**:  
  - Allows memory to be freed.  
  - Simple to use.  

- **Cons**:  
  - Can **fragment over time**, especially if allocation/free patterns are irregular.  

- **Use case**:  
  - Small embedded systems where fragmentation is not a big concern.  

---

## 3. `heap_3.c` – Wraps Standard `malloc`/`free`
- **How it works**:  
  - Directly maps `pvPortMalloc` → `malloc` and `vPortFree` → `free`.  
  - Relies on the **compiler’s C library heap implementation**.  

- **Pros**:  
  - No additional FreeRTOS memory manager required.  
  - Simple if the C library heap is reliable.  

- **Cons**:  
  - Not deterministic (malloc/free may be slow or unpredictable).  
  - Debugging fragmentation is harder.  
  - No control over heap size inside FreeRTOS (`configTOTAL_HEAP_SIZE` is ignored).  

- **Use case**:  
  - Prototyping or desktop/Posix simulation where standard malloc/free are fine.  

---

## 4. `heap_4.c` – Best General Purpose
- **How it works**:  
  - Similar to `heap_2.c` but adds **coalescing** of adjacent free blocks.  
  - Reduces fragmentation.  

- **Pros**:  
  - Supports both alloc and free.  
  - Much better fragmentation handling.  
  - Widely recommended for production use.  

- **Cons**:  
  - Slightly larger code size than heap_1/2.  

- **Use case**:  
  - Most **real-world embedded projects**.  
  - Safe balance between flexibility and determinism.  

---

## 5. `heap_5.c` – Multiple Heap Regions
- **How it works**:  
  - Extends `heap_4.c` by supporting **multiple non-contiguous memory regions**.  
  - Useful when RAM is scattered (e.g., internal SRAM + external SDRAM).  

- **Pros**:  
  - Same benefits as `heap_4.c`.  
  - Can use all available RAM regions.  

- **Cons**:  
  - More complex configuration (requires defining memory regions in code).  

- **Use case**:  
  - Advanced MCUs/SoCs with multiple RAM banks or special-purpose memory.  

---

## Summary Table

| Heap Type  | Free Supported? | Fragmentation Handling | Complexity | Typical Use Case |
|------------|-----------------|------------------------|------------|------------------|
| **heap_1** | ❌ No           | None (safe)           | Very Low   | Fixed allocations only |
| **heap_2** | ✅ Yes          | Possible              | Low        | Small apps, simple free |
| **heap_3** | ✅ Yes (stdlib) | Depends on libc        | Very Low   | PC/Posix ports, prototyping |
| **heap_4** | ✅ Yes          | Coalesces free blocks | Medium     | Recommended default |
| **heap_5** | ✅ Yes          | Coalesces, multi-heap | Higher     | Multi-region memory systems |

---

**Recommendation**:  
- For **learning and most projects**, start with `heap_4.c`.  
- Use `heap_5.c` only if your MCU has multiple separate RAM regions.  
- Avoid `heap_3.c` in embedded unless you know your C library allocator is reliable.  
- Use `heap_1.c` only for very simple, static systems.