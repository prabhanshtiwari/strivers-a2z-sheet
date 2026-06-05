# C++ STL — Vectors

> The most important and widely used container in C++ STL. Master this — the functions here apply to almost every other container.

---

## What is a Vector?

A **vector** is a **dynamic array**. Unlike a regular array whose size is fixed at declaration, a vector can **grow and shrink at runtime**.

| Feature | Regular Array | Vector |
|---------|--------------|--------|
| Size | Fixed — cannot change | Dynamic — can grow/shrink |
| Use when | You know the exact size | You don't know the size ahead of time |

---

## Declaring a Vector

```cpp
vector<int> v;          // declares an empty vector of integers
vector<double> v;       // vector of doubles
vector<string> v;       // vector of strings
vector<pair<int,int>> v;// vector of pairs
```

---

## Inserting Elements

### `push_back(value)` — add to the end
```cpp
vector<int> v;
v.push_back(1);   // v = {1}         — inserts 1 at the back
v.push_back(2);   // v = {1, 2}      — inserts 2 at the back
```

### `emplace_back(value)` — add to the end (faster than push_back)
```cpp
v.emplace_back(4);   // v = {1, 2, 4}  — faster alternative to push_back
```

> **`emplace_back` vs `push_back`:** Both do the same job, but `emplace_back` is **faster** internally (constructs in-place). Prefer `emplace_back` when performance matters.

### Inserting into a vector of pairs
```cpp
vector<pair<int,int>> v;

// Using push_back — must use curly braces
v.push_back({1, 2});      // inserts pair (1,2) — curly braces required

// Using emplace_back — no curly braces needed
v.emplace_back(1, 2);     // automatically creates pair (1,2)
```

---

## Declaring with Pre-filled Values

```cpp
vector<int> v(5, 100);
// Creates a vector of size 5, all elements = 100
// v = {100, 100, 100, 100, 100}
//      idx0  idx1  idx2  idx3  idx4
```

```cpp
vector<int> v(5);
// Creates a vector of size 5
// Elements = 0 or garbage value (compiler-dependent)
```

```cpp
vector<int> v1(5, 20);    // v1 = {20, 20, 20, 20, 20}
vector<int> v2(v1);       // v2 is a COPY of v1 = {20, 20, 20, 20, 20}
// v1 and v2 are independent — changing one does not affect the other
```

> **Important:** Even if you declare a vector with size 5, you can still `push_back` more elements — it will **automatically expand** to size 6, 7, etc.

---

## Accessing Elements

Given: `v = {20, 10, 15, 5, 7}`

```cpp
cout << v[0];     // Output: 20  — access by index (like an array)
cout << v[1];     // Output: 10
cout << v[3];     // Output: 5

cout << v.at(0);  // Output: 20  — alternate syntax (rarely used)
```

### `v.front()` — first element
```cpp
cout << v.front();   // Output: 20  — returns the first element
```

### `v.back()` — last element
```cpp
cout << v.back();    // Output: 7   — returns the last element
```

---

## Iterators

An **iterator** is a pointer to a memory address inside the container. It does **not** hold the value directly — it holds the **address** where the value lives.

### `v.begin()` — iterator to the first element
```cpp
vector<int>::iterator it = v.begin();
// 'it' now points to the memory address of the first element (20)
// it does NOT store 20 — it stores the address of 20

cout << *it;   // Output: 20  — '*' dereferences: gets the VALUE at that address
```

### Moving an iterator
```cpp
it++;          // moves iterator to next memory address (now points to 10)
cout << *it;   // Output: 10

it += 2;       // jumps forward by 2 positions (now points to 5)
cout << *it;   // Output: 5
```

### `v.end()` — iterator to ONE PAST the last element
```cpp
// IMPORTANT: end() does NOT point to the last element
// It points to the memory AFTER the last element

auto it = v.end();
it--;          // move back one position — now points to last element (7)
cout << *it;   // Output: 7
```

### `v.rbegin()` and `v.rend()` — reverse iterators
```cpp
// Reverse iterators treat the container as reversed
// rbegin() → points to last element
// rend()   → points to one before the first element
// Incrementing (it++) moves BACKWARDS

// Almost never used in practice — just know they exist
```

---

## Printing a Vector — 3 Ways

Given: `v = {10, 20, 30}`

### Way 1: Index-based loop
```cpp
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";   // prints each element by index
}
// Output: 10 20 30
```

### Way 2: Iterator loop
```cpp
for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";    // dereference iterator to get value
}
// Output: 10 20 30
```

### Way 3: Auto iterator (shorthand)
```cpp
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";    // 'auto' automatically figures out the iterator type
}
// Output: 10 20 30
```

### Way 4: Range-based for loop (most commonly used)
```cpp
for (auto it : v) {
    cout << it << " ";     // 'it' takes each value directly (not an iterator/address)
}
// Output: 10 20 30
```

> **`auto` keyword:** Automatically assigns the correct data type. `auto x = 5` → x is `int`. `auto x = "hello"` → x is `string`.

---

## Erasing Elements

### Erase a single element (by iterator/address)
```cpp
vector<int> v = {10, 20, 12, 23};

v.erase(v.begin() + 1);
// begin() + 1 points to index 1 which is 20
// 20 gets deleted, vector reshuffles
// v = {10, 12, 23}
```

### Erase a range of elements
```cpp
vector<int> v = {10, 20, 30, 40, 50};

v.erase(v.begin() + 1, v.begin() + 3);
// Deletes from index 1 (inclusive) to index 3 (EXCLUSIVE)
// Deletes: 20 (index 1) and 30 (index 2)
// 40 (index 3) is NOT deleted — end is exclusive
// v = {10, 40, 50}
```

> **Rule:** In erase(start, end) — start is **included**, end is **NOT included**.

### Erase example from the lecture
```cpp
vector<int> v = {10, 20, 12, 23, 35};

v.erase(v.begin() + 2, v.begin() + 4);
// begin()+2 = 12 (included), begin()+4 = 35 (excluded)
// Deletes 12 (index 2) and 23 (index 3)
// v = {10, 20, 35}
```

---

## Inserting Elements

### Insert a single element at a position
```cpp
vector<int> v = {10, 20, 30, 40};

v.insert(v.begin(), 300);
// Inserts 300 at the very beginning
// v = {300, 10, 20, 30, 40}

v.insert(v.begin() + 1, 5);
// Inserts 5 at index 1 (second position)
// v = {300, 5, 10, 20, 30, 40}
```

### Insert multiple copies of an element
```cpp
vector<int> v = {10, 20, 30, 40};

v.insert(v.begin() + 1, 2, 5);
// At position index 1, insert the number 5, two times
// v = {10, 5, 5, 20, 30, 40}
```

Syntax: `v.insert(position, count, value)`

### Insert another vector into a vector
```cpp
vector<int> copy = {50, 50};
vector<int> v = {10, 20, 30};

v.insert(v.begin(), copy.begin(), copy.end());
// Inserts entire 'copy' vector at the beginning of v
// v = {50, 50, 10, 20, 30}
```

---

## Other Important Vector Functions

### `v.size()` — number of elements
```cpp
vector<int> v = {10, 20, 30};
cout << v.size();   // Output: 3
```

### `v.pop_back()` — remove last element
```cpp
vector<int> v = {10, 20, 30};
v.pop_back();       // removes 30 (last element)
// v = {10, 20}
```

### `v.swap(v2)` — swap two vectors
```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6};
v1.swap(v2);
// v1 = {4, 5, 6}
// v2 = {1, 2, 3}
```

### `v.clear()` — remove all elements
```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.clear();          // v is now empty {}
```

### `v.empty()` — check if vector is empty
```cpp
vector<int> v = {1, 2};
cout << v.empty();   // Output: 0 (false) — has elements

v.clear();
cout << v.empty();   // Output: 1 (true) — empty
```

---

## Summary Table — All Vector Functions

| Function | Description |
|----------|-------------|
| `push_back(val)` | Insert val at the end |
| `emplace_back(val)` | Insert val at the end (faster) |
| `pop_back()` | Remove last element |
| `insert(pos, val)` | Insert val at position pos |
| `insert(pos, n, val)` | Insert n copies of val at pos |
| `insert(pos, begin, end)` | Insert a range from another container |
| `erase(pos)` | Remove element at pos (iterator) |
| `erase(start, end)` | Remove range [start, end) — end is exclusive |
| `size()` | Number of elements currently in vector |
| `front()` | First element |
| `back()` | Last element |
| `clear()` | Remove all elements |
| `empty()` | Returns true if vector has no elements |
| `swap(v2)` | Swap contents with another vector |
| `begin()` | Iterator to first element |
| `end()` | Iterator to one past last element |
| `rbegin()` | Reverse iterator to last element |
| `rend()` | Reverse iterator to one before first |
| `v[i]` | Access element at index i |
| `v.at(i)` | Access element at index i (alternate) |

---

## Key Points to Remember

- Vector is **dynamic** — size increases automatically when needed.
- Elements are stored in **contiguous memory** (like an array).
- `begin()` points to the first element; `end()` points **one past** the last element.
- `emplace_back` is **faster** than `push_back` — prefer it.
- In `erase(start, end)`, **start is included, end is excluded**.
- All functions learned here (size, clear, empty, swap, begin, end) apply to **almost every other STL container**.
