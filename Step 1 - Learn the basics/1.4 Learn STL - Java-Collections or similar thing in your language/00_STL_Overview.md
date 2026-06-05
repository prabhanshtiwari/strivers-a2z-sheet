# C++ Standard Template Library (STL) — Complete Notes

> Notes derived from the *Take It Forward* STL lecture. Every concept, function, and code snippet from the video is captured here.

---

## What is STL?

STL stands for **Standard Template Library**. It is a compilation of:

- **Algorithms** — sorting, searching, permutations, etc.
- **Containers** — data structures like vector, stack, map, set, etc.
- **Iterators** — objects that point to memory locations inside containers.
- **Functions** — utility helpers like `__builtin_popcount`, `next_permutation`, etc.

The purpose of STL is to let you use powerful data structures and algorithms **without writing them from scratch**, keeping your code short and efficient.

---

## C++ Code Skeleton

```cpp
#include <bits/stdc++.h>   // Includes ALL standard libraries at once — no need to include math.h, string.h etc. individually
using namespace std;        // Allows you to write cin/cout instead of std::cin / std::cout

int main() {
    // Your code goes here
    return 0;
}
```

### Why `#include <bits/stdc++.h>`?
Instead of writing multiple includes like:
```cpp
#include <math.h>
#include <string.h>
#include <algorithm>
```
…you write just **one line** and all libraries are automatically included.

### Why `using namespace std`?
Without it, you must prefix everything with `std::`:
```cpp
std::cin >> a;   // takes input
std::cout << a;  // prints output
```
With `using namespace std`, you can simply write:
```cpp
cin >> a;
cout << a;
```

---

## Functions in C++

### Void Function (returns nothing)
```cpp
void print() {
    cout << "Raj";   // prints "Raj" to screen; returns nothing
}

int main() {
    print();         // calling the void function
}
```

### Return-Type Function
```cpp
int sum(int a, int b) {
    return a + b;    // returns the sum of a and b
}

int main() {
    int s = sum(1, 5);   // passes 1 → a, 5 → b; s gets value 6
    cout << s;            // prints 6
}
```
The return type can be `int`, `double`, `string`, or any data type.

---

## STL Structure — What We Will Learn

| Part | Topics Covered |
|------|---------------|
| **Containers** | pair, vector, list, deque, stack, queue, priority\_queue, set, multiset, unordered\_set, map, multimap, unordered\_map |
| **Iterators** | begin, end, rbegin, rend, auto, range-based for |
| **Algorithms** | sort, custom comparator |
| **Functions** | `__builtin_popcount`, `next_permutation`, `max_element`, `min_element` |

---

## File Index

| File | Contents |
|------|----------|
| `01_Pairs.md` | Pair, nested pairs, pair arrays |
| `02_Vectors.md` | Vector declaration, iterators, insert, erase, all functions |
| `03_List_Deque.md` | List and Deque containers |
| `04_Stack_Queue.md` | Stack (LIFO), Queue (FIFO), Priority Queue |
| `05_Set_Map.md` | Set, Multiset, Unordered Set, Map, Multimap, Unordered Map |
| `06_Algorithms_Functions.md` | Sort, Comparators, popcount, next\_permutation, max/min element |
