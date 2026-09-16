# Week 2: Arrays

## Key Concepts Learned

*   **Compilation Steps:**
    *   **Preprocessing:** Handling `#include` directives by copying header files.
    *   **Compiling:** Converting C code into assembly code.
    *   **Assembling:** Converting assembly code into binary machine code.
    *   **Linking:** Combining compiled code with external libraries (like `cs50.h` or `stdio.h`).
*   **Debugging:** Using tools like `debug50` to step through code, set breakpoints, and monitor variable values during execution.
*   **Arrays:**
    *   Storing multiple elements of the same data type in contiguous memory locations.
    *   Zero-indexed access (`array[0]`, `array[1]`, etc.).
*   **Strings as Character Arrays:**
    *   Strings are sequences of `char` ending with a special sentinel value: the null terminator (`\0`, ASCII 0).
    *   Using the `<string.h>` library for functions like `strlen()`.
    *   Using the `<ctype.h>` library for character checks and conversions (`isupper()`, `tolower()`).
*   **Command-Line Arguments:**
    *   Passing parameters into `main()` via `int argc` (argument count) and `string argv[]` (argument vector).
    *   Validating input quantity and format before program execution.
*   **Cryptography Basics:**
    *   Converting plaintext into ciphertext using a key and an encryption algorithm.

## Problem Sets Completed

*   **Scrabble:** Calculated the score of two user-provided words using an array of letter point values to decide the winner.
*   **Readability:** Calculated text grade levels using the Coleman-Liau formula ($index = 0.0588 \times L - 0.296 \times S - 15.8$) by counting letters, words, and sentences in a string.
*   **Substitution:** Implemented a substitution cipher using a 26-character command-line key to validate and map plaintext characters to ciphertext.