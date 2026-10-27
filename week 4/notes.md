# Week 4: Memory

## Key Concepts Learned

*   **Hexadecimal:** Using base-16 (`0-9` and `A-F`, prefixed with `0x`) to represent memory addresses and RGB color values compactly.
*   **Pointers and Addresses:**
    *   Using the address-of operator (`&`) to find where a variable is stored in memory.
    *   Using the dereference operator (`*`) to declare pointers and access the value at a specific memory address.
*   **Strings as Pointers:** Understanding that `string` in CS50 is simply an alias (`typedef char *string`) for a pointer to the first character of a character array.
*   **Pointer Arithmetic:** Performing mathematical operations on pointers to navigate contiguous blocks of memory.
*   **Dynamic Memory Allocation:**
    *   Requesting memory from the heap at runtime using `malloc()`.
    *   Releasing allocated memory back to the operating system using `free()`.
    *   Using `valgrind` to detect memory leaks and invalid memory access (segmentation faults).
*   **Memory Layout:** Understanding how the **Machine Code**, **Globals**, **Heap** (grows downward), and **Stack** (grows upward for function calls) are organized in RAM.
*   **File I/O:** Opening, reading, writing, and closing files in C using `FILE *`, `fopen()`, `fclose()`, `fread()`, and `fwrite()`.

## Problem Sets Completed

*   **Volume:** Modified the volume of a `.wav` audio file by reading its 44-byte header and multiplying each 16-bit audio sample by a scaling factor.
*   **Filter (More):** Manipulated 24-bit BMP images at the pixel level to apply grayscale, reflection, box blur, and Sobel edge detection filters.
*   **Recover:** Scanned a raw memory card image in 512-byte blocks to locate JPEG headers (magic numbers) and recover deleted photos into separate image files.