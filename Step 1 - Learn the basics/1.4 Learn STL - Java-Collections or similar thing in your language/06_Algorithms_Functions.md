# C++ STL Algorithms — Complete Detailed Notes

> **Source:** Video transcript on C++ STL Algorithms
> **Topics Covered:** `sort()`, Custom Comparators, `__builtin_popcount`, `next_permutation`, `max_element` / `min_element`

---

## Table of Contents

1. [Sorting with `sort()`](#1-sorting-with-sort)
2. [Sorting a Sub-Array (Partial Sort)](#2-sorting-a-sub-array-partial-sort)
3. [Sorting in Descending Order](#3-sorting-in-descending-order)
4. [Custom Comparator — "My Way" Sorting](#4-custom-comparator--my-way-sorting)
5. [`__builtin_popcount` — Count Set Bits](#5-__builtin_popcount--count-set-bits)
6. [`next_permutation` — Generate All Permutations](#6-next_permutation--generate-all-permutations)
7. [`max_element` and `min_element`](#7-max_element-and-min_element)
8. [Quick Reference Cheat Sheet](#8-quick-reference-cheat-sheet)

---

## 1. Sorting with `sort()`

### Concept

Instead of manually implementing **Bubble Sort**, **Merge Sort**, or **Selection Sort**, C++ STL provides a built-in `sort()` function that handles everything in **a single line**.

### How Iterators Work

```
Array:   [ 1, 5, 3, 2 ]
Index:     a  a+1 a+2 a+3
Pointer:   ^               ^
           a             a+4
```

- `a` → points to the **first** element (starting iterator, **included**)
- `a + 4` → points **just past** the last element (ending iterator, **NOT included**)
- This is the classic **[start, end)** half-open interval used throughout STL

### Sorting a Raw Array

```cpp
#include <algorithm>  // Required header for sort()

int a[] = {1, 5, 3, 2};  // Array of size 4

// sort(starting_iterator, ending_iterator)
sort(a, a + 4);
// a + 4 means "one past the last element" — the ending boundary

// After sorting:
// a[] = {1, 2, 3, 5}
```

> **Key Rule:** `start` is **included**, `end` is **NOT included**.
> So `sort(a, a+4)` sorts indices 0, 1, 2, 3 — all four elements.

### Sorting a Vector

```cpp
#include <vector>
#include <algorithm>

vector<int> v = {1, 5, 3, 2};

// v.begin() → starting iterator (points to first element)
// v.end()   → ending iterator   (points one past last element)
sort(v.begin(), v.end());

// After sorting:
// v = {1, 2, 3, 5}
```

> **Note:** `sort()` works on **vectors** and **arrays**, but **NOT on maps** (maps maintain their own sorted order by key and cannot be re-sorted using `sort()`).

---

## 2. Sorting a Sub-Array (Partial Sort)

### Concept

You do NOT have to sort the entire array. You can sort **only a specific portion** by adjusting the iterator range.

### Example

```
Array:   [ 5, 2, 1, 3 ]
Index:     a  a+1 a+2 a+3
                  ^       ^
                a+2     a+4
```

We want to sort only the **last two elements** (indices 2 and 3):

```cpp
int a[] = {5, 2, 1, 3};

// Sort only from index 2 to index 3 (i.e., elements 1 and 3)
sort(a + 2, a + 4);
// a+2 is the start (included), a+4 is the end (not included)

// After partial sort:
// a[] = {5, 2, 1, 3}  → only last 2 sorted → {5, 2, 1, 3}
// Result: {5, 2, 1, 3}  (1 and 3 are already in order, so no visible change here)
```

Another clear example — sort only the middle:

```cpp
int a[] = {9, 4, 2, 7, 1};

sort(a + 1, a + 4);
// Sorts elements at index 1, 2, 3 → {4, 2, 7} → {2, 4, 7}

// Final array: {9, 2, 4, 7, 1}
// Index 0 and index 4 are untouched
```

> **Takeaway:** You have full control over which portion of the array/vector gets sorted by specifying the exact iterator range.

---

## 3. Sorting in Descending Order

### Concept

By default, `sort()` sorts in **ascending order**. To sort in **descending order**, pass a built-in **comparator** as the third argument.

### The Comparator: `greater<int>()`

```cpp
#include <algorithm>
#include <functional>  // For greater<>

int a[] = {1, 3, 5, 2};

// sort(start, end, comparator)
sort(a, a + 4, greater<int>());
// greater<int>() is an inbuilt comparator that reverses the order

// After sorting:
// a[] = {5, 3, 2, 1}
```

For a vector:

```cpp
vector<int> v = {1, 3, 5, 2};
sort(v.begin(), v.end(), greater<int>());
// v = {5, 3, 2, 1}
```

> **Summary of sort() modes:**
> | Mode | Code |
> |------|------|
> | Ascending (default) | `sort(a, a+n)` |
> | Descending | `sort(a, a+n, greater<int>())` |
> | Custom / "My Way" | `sort(a, a+n, comparatorFunction)` |

---

## 4. Custom Comparator — "My Way" Sorting

### Why Do We Need This?

Sometimes you want to sort by **multiple criteria** or in a **mixed order** (e.g., ascending by one field, descending by another). Built-in comparators can't handle this — you need to write your own.

### Problem Statement

Given a pair array:

```
Pairs: { (1,2), (2,1), (4,1) }
```

**Sorting Rules:**
1. **Primary:** Sort by **second element in ascending order**
2. **Tie-breaker:** If second elements are equal, sort by **first element in descending order**

**Expected Output:**

```
Step 1 — Sort by second element (ascending):
  Second elements: 2, 1, 1
  → (2,1) and (4,1) come first (second = 1), then (1,2) (second = 2)

Step 2 — Among (2,1) and (4,1) [same second = 1], sort by first descending:
  First elements: 2 and 4 → descending → 4 comes before 2

Final Order: (4,1), (2,1), (1,2)
```

### Syntax of Custom Sort

```cpp
sort(first_iterator, last_iterator, comp);
//                                  ^^^^
//                                  Your custom comparator function
```

### How to Write a Comparator

A comparator is a **boolean function** that takes **two elements** of the same type and answers:

> **"Is P1 correctly placed BEFORE P2?"**
> - Return `true`  → P1 should come before P2 (they are in correct order, don't swap)
> - Return `false` → P1 should come after P2 (they are in wrong order, swap them)

**Mental Model:**
- Imagine you have just **two elements**: P1 and P2
- Forget the entire array — just focus on these two
- Ask: "In my desired final order, should P1 appear before P2?"

### Full Code Example

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Comparator function
// Takes two pairs and returns true if p1 should come BEFORE p2
bool comparator(pair<int,int> p1, pair<int,int> p2) {

    // Rule 1: Sort by second element in ASCENDING order
    if (p1.second < p2.second) {
        // p1's second is smaller → p1 should come first → CORRECT ORDER
        return true;
    }

    // Rule 1 (opposite): p1's second is GREATER than p2's second
    if (p1.second > p2.second) {
        // p1's second is larger → p1 should come AFTER p2 → WRONG ORDER
        return false;
    }

    // Reaching here means: p1.second == p2.second (tie!)
    // Rule 2 (tie-breaker): Sort by first element in DESCENDING order
    // In descending, the LARGER first element should come first
    if (p1.first > p2.first) {
        // p1's first is greater → p1 should come first in descending → CORRECT ORDER
        return true;
    }

    // p1's first is NOT greater (either smaller or equal)
    // → p1 should come AFTER p2 → WRONG ORDER (or equal, either way return false is fine)
    return false;
}

int main() {
    pair<int,int> arr[] = {{1,2}, {2,1}, {4,1}};
    int n = 3;

    // Pass the comparator as third argument
    sort(arr, arr + n, comparator);

    // Output the sorted pairs
    for (int i = 0; i < n; i++) {
        cout << "(" << arr[i].first << "," << arr[i].second << ") ";
    }
    // Output: (4,1) (2,1) (1,2)

    return 0;
}
```

### The Comparator Logic — Step by Step Explanation

```
Comparing (2,1) and (4,1):
  p1 = (2,1), p2 = (4,1)
  p1.second (1) == p2.second (1) → go to tie-breaker
  p1.first (2) > p2.first (4)? → NO → return false
  → SWAP → (4,1) comes before (2,1) ✓

Comparing (4,1) and (1,2):
  p1 = (4,1), p2 = (1,2)
  p1.second (1) < p2.second (2)? → YES → return true
  → NO SWAP → (4,1) stays before (1,2) ✓

Final: (4,1), (2,1), (1,2) ✓
```

### General Template for Writing Any Comparator

```cpp
// Step 1: Identify your data type (here: pair<int,int>)
// Step 2: Write a bool function with two parameters of that type
// Step 3: For each sorting rule, check if p1 is in the correct position
//         Return true = correct order (keep), false = wrong order (swap)

bool myComparator(DataType p1, DataType p2) {

    // Primary condition
    if (p1.someField < p2.someField) return true;   // ascending
    if (p1.someField > p2.someField) return false;  // ascending (opposite)

    // Tie-breaker (when primary fields are equal)
    return (p1.otherField > p2.otherField);  // descending shorthand
}
```

> **Golden Rule for Comparators:**
> Always think in terms of **just two instances (P1 and P2)**. Never think about the whole array. Just ask: "Should P1 be before P2?"

---

## 5. `__builtin_popcount` — Count Set Bits

### Concept

In a computer, every integer is stored in **binary (32-bit representation)**. A **set bit** is a bit with value `1`. `__builtin_popcount` counts **how many bits are set to 1** in the binary representation of a number.

### Examples

```
Number 7  → Binary: 0000 0000 0000 0000 0000 0000 0000 0111
                                                          ^^^
                                                    Three 1-bits
→ __builtin_popcount(7) = 3
```

```
Number 6  → Binary: 0000 0000 0000 0000 0000 0000 0000 0110
                                                         ^^
                                                    Two 1-bits
→ __builtin_popcount(6) = 2
```

### Code

```cpp
#include <iostream>
using namespace std;

int main() {

    int num = 7;
    // 7 in binary = 111 → three 1-bits
    cout << __builtin_popcount(num);  // Output: 3

    int num2 = 6;
    // 6 in binary = 110 → two 1-bits
    cout << __builtin_popcount(num2); // Output: 2

    // For LONG LONG integers, use __builtin_popcountll
    long long bigNum = 1000000000LL;
    // __builtin_popcount will NOT work correctly for long long!
    cout << __builtin_popcountll(bigNum); // Use LL variant for long long

    return 0;
}
```

### `int` vs `long long`

| Data Type | Function to Use |
|-----------|-----------------|
| `int` (32-bit) | `__builtin_popcount(n)` |
| `long long` (64-bit) | `__builtin_popcountll(n)` |

> **Warning:** Never use `__builtin_popcount` on a `long long` variable — it will give wrong results. Always use `__builtin_popcountll` for 64-bit integers.

### Common Use Cases in DSA

- Checking how many bits are set in a number (bitmask problems)
- Counting the number of elements in a subset (bitmask DP)
- Comparing Hamming distances

---

## 6. `next_permutation` — Generate All Permutations

### Concept

`next_permutation()` transforms the current string/array into its **next lexicographically greater permutation**. It returns:
- `true` → successfully moved to the next permutation
- `false` → no more permutations (was at the last one), wraps around to first

### All Permutations of "123" in Dictionary Order

```
1st: 123
2nd: 132
3rd: 213
4th: 231
5th: 312
6th: 321  ← last permutation
        → next_permutation returns false here
```

Total permutations of 3 characters = 3! = **6**

### Code — Print All Permutations

```cpp
#include <iostream>
#include <algorithm>  // For next_permutation
#include <string>
using namespace std;

int main() {
    string s = "123";

    // CRITICAL: The string must be SORTED before starting
    // If not sorted, you will miss permutations that come before the starting string
    sort(s.begin(), s.end());  // Ensure we start from the lexicographically smallest

    // Print the first permutation (the sorted string itself)
    // Then keep generating next permutations until none are left

    do {
        cout << s << "\n";
        // next_permutation modifies s in-place to the next permutation
        // Returns true if next permutation exists
        // Returns false if s was the last (largest) permutation
    } while (next_permutation(s.begin(), s.end()));

    // Output:
    // 123
    // 132
    // 213
    // 231
    // 312
    // 321

    return 0;
}
```

> **Why `do-while` instead of `while`?**
> Because we want to **print the first permutation too** (the sorted string) before calling `next_permutation`.

### What Happens if You DON'T Start from Sorted?

```cpp
string s = "231";  // Not sorted!

do {
    cout << s << "\n";
} while (next_permutation(s.begin(), s.end()));

// Output (INCOMPLETE — misses 123, 132, 213):
// 231
// 312
// 321
// Only prints permutations AFTER "231" in dictionary order
```

> **Critical Rule:** To get **ALL** permutations, **always sort the string/array first** so you start from the lexicographically smallest arrangement.

### Works on Arrays Too

```cpp
int arr[] = {1, 2, 3};
int n = 3;

sort(arr, arr + n);  // Sort first

do {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
} while (next_permutation(arr, arr + n));
```

### Summary

| Scenario | Behavior |
|----------|----------|
| `next_permutation` on the last permutation (e.g., "321") | Returns `false`, string resets to first permutation ("123") |
| `next_permutation` on any other permutation | Returns `true`, string becomes the next one |
| Starting from an unsorted string | Only prints permutations from that point onward |
| Starting from sorted string | Prints ALL permutations |

---

## 7. `max_element` and `min_element`

### Concept

`max_element()` and `min_element()` return an **iterator (pointer/address)** pointing to the maximum or minimum element in a range. Use the **dereference operator `*`** to get the actual value.

### Code

```cpp
#include <iostream>
#include <algorithm>  // For max_element and min_element
using namespace std;

int main() {
    int a[] = {1, 10, 5, 6};
    int n = 4;

    // max_element returns an ITERATOR (pointer) to the max element
    auto maxIt = max_element(a, a + n);
    cout << *maxIt << "\n";  // Dereference to get the VALUE → Output: 10

    // min_element returns an ITERATOR (pointer) to the min element
    auto minIt = min_element(a, a + n);
    cout << *minIt << "\n";  // Dereference to get the VALUE → Output: 1

    // One-liner to get the value directly:
    cout << *max_element(a, a + n) << "\n";  // Output: 10
    cout << *min_element(a, a + n) << "\n";  // Output: 1

    return 0;
}
```

### With Vectors

```cpp
vector<int> v = {1, 10, 5, 6};

cout << *max_element(v.begin(), v.end()) << "\n";  // Output: 10
cout << *min_element(v.begin(), v.end()) << "\n";  // Output: 1
```

### Getting the Index of Max/Min Element

```cpp
int a[] = {1, 10, 5, 6};

// Subtract the starting pointer from the iterator to get the index
int maxIndex = max_element(a, a + 4) - a;
// max_element points to a[1] (value 10)
// a[1] - a = index 1
cout << maxIndex << "\n";  // Output: 1
```

> **Remember:** `max_element` / `min_element` return an **iterator (address)**, not the value directly. You **must dereference with `*`** to get the value.

---

## 8. Quick Reference Cheat Sheet

```cpp
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

// ──────────────────────────────────────────────
// SORT — Ascending (default)
sort(a, a + n);                      // Array
sort(v.begin(), v.end());            // Vector

// SORT — Descending
sort(a, a + n, greater<int>());
sort(v.begin(), v.end(), greater<int>());

// SORT — Partial (only a sub-range)
sort(a + i, a + j);                  // Sorts indices i to j-1

// SORT — Custom Comparator
bool myComp(DataType p1, DataType p2) {
    // return true  → p1 before p2 (correct, don't swap)
    // return false → p1 after p2  (wrong, do swap)
}
sort(a, a + n, myComp);

// ──────────────────────────────────────────────
// COUNT SET BITS (popcount)
__builtin_popcount(n);               // For int
__builtin_popcountll(n);             // For long long

// ──────────────────────────────────────────────
// NEXT PERMUTATION — All permutations
sort(s.begin(), s.end());            // MUST sort first!
do {
    // use s
} while (next_permutation(s.begin(), s.end()));

// ──────────────────────────────────────────────
// MAX / MIN ELEMENT
*max_element(a, a + n);              // Max value in array
*min_element(a, a + n);             // Min value in array
*max_element(v.begin(), v.end());   // Max value in vector
int idx = max_element(a, a+n) - a;  // Index of max element
```

---

## Key Takeaways

1. **`sort()` in one line** replaces manually coded sorting algorithms — always prefer it in competitive programming.

2. **Iterators follow `[start, end)`** — start is included, end is excluded. So `sort(a, a+n)` sorts `n` elements.

3. **`sort()` works on arrays and vectors, NOT maps.** Maps are inherently ordered.

4. **Partial sort** is possible by simply adjusting the iterator range.

5. **`greater<int>()`** gives descending order with no extra code.

6. **Comparators** are the most powerful tool — they let you define any arbitrary sort order. Always think in terms of **two elements (P1, P2)** and ask "is P1 correctly placed before P2?"

7. **`__builtin_popcount`** is O(1) and extremely fast for bit-counting. Use `popcountll` for `long long`.

8. **`next_permutation`** generates permutations in **lexicographic order**. Start from sorted input to get **all** permutations.

9. **`max_element` / `min_element`** return iterators — always **dereference with `*`** for the value.

---

*These STL tools are sufficient for the vast majority of competitive programming and DSA interview problems in C++.*