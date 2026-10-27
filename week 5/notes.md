# Week 5: Data Structures

## Key Concepts Learned

*   **Resizing Arrays:** Using `realloc()` to dynamically resize contiguous blocks of memory when fixed-size arrays run out of space.
*   **Linked Lists:**
    *   Building dynamic collections of `node` structs where each node contains data and a pointer (`next`) to the following node.
    *   Trading higher memory usage and slower search (`O(n)`) for fast dynamic insertion (`O(1)` at the head).
*   **Trees and Binary Search Trees (BSTs):**
    *   Organizing nodes hierarchically where every left child is smaller than the parent and every right child is larger.
    *   Achieving `O(log n)` search times when the tree remains balanced.
*   **Hash Tables:**
    *   Combining the random-access speed of an array with the dynamic growth of linked lists.
    *   Writing a **hash function** to map inputs (like strings) to array indices, and resolving **collisions** using separate chaining.
*   **Tries (Retrieval Trees):** Multi-way tree structures where each node is an array of pointers representing characters, allowing constant-time (`O(1)`) lookups based on word length.
*   **Abstract Data Structures:**
    *   **Queues:** First-In, First-Out (FIFO) structures using `enqueue` and `dequeue`.
    *   **Stacks:** Last-In, First-Out (LIFO) structures using `push` and `pop`.

## Problem Sets Completed

*   **Inheritance:** Simulated the inheritance of blood types (`A`, `B`, `O` alleles) across multiple generations by recursively allocating and freeing a binary tree of family members.
*   **Speller:** Implemented a fast spell-checker in C by loading a large dictionary into a custom hash table, checking text files for misspelled words, and freeing all allocated memory without leaks.