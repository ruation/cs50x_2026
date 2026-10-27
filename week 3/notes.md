# Week 3: Algorithms

## Key Concepts Learned

*   **Searching Algorithms:**
    *   **Linear Search:** Checking elements one by one from start to finish.
    *   **Binary Search:** Dividing a sorted array in half repeatedly to find a target efficiently.
*   **Asymptotic Notation:** Measuring algorithm efficiency as input size (`n`) grows:
    *   **Big O:** Upper bound (worst-case running time, such as `O(n^2)`, `O(n log n)`, `O(n)`, `O(log n)`, `O(1)`).
    *   **Big Omega:** Lower bound (best-case running time).
    *   **Big Theta:** When the best-case and worst-case running times are the same.
*   **Sorting Algorithms:**
    *   **Selection Sort:** Repeatedly finding the smallest element and swapping it into place (`O(n^2)`).
    *   **Bubble Sort:** Repeatedly swapping adjacent elements if they are in the wrong order (`O(n^2)`).
    *   **Merge Sort:** Recursively dividing the array in half, sorting the halves, and merging them back together (`O(n log n)`).
*   **Structs:** Creating custom data types using `typedef struct` to group related variables (like a candidate's name and vote count) under a single object.
*   **Recursion:** Writing functions that call themselves to solve smaller instances of the same problem, built around a **base case** (to stop the recursion) and a **recursive case**.

## Problem Sets Completed

*   **Sort:** Analyzed compiled binary programs by timing their execution on sorted, reversed, and random text files to identify which used Bubble Sort, Selection Sort, and Merge Sort.
*   **Plurality:** Simulated a simple plurality election where every voter gets one vote and the candidate with the most votes wins.
*   **Tideman:** Implemented a ranked-choice election system using the Tideman (ranked pairs) method, utilizing 2D arrays, sorting, and recursion (Depth-First Search) to detect and prevent cycles in a directed graph.