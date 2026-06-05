# C++ STL — Pairs

> Part of the **utility library** in C++ STL.

---

## What is a Pair?

A `pair` is a container that stores **exactly two values** together under one variable name. Each value can be of **any data type** (int, double, string, char, or even another pair).

---

## Declaring a Pair

```cpp
pair<int, int> p = {1, 3};
// p stores: (1, 3)
// first data type  → int  (stores 1)
// second data type → int  (stores 3)
```

You can use any data types:
```cpp
pair<int, string>    p1 = {1, "Raj"};
pair<double, char>   p2 = {3.14, 'A'};
pair<string, string> p3 = {"Hello", "World"};
```

---

## Accessing Elements of a Pair

Use `.first` to access the first element and `.second` to access the second element.

```cpp
pair<int, int> p = {1, 3};

cout << p.first;   // Output: 1   — accesses the first element
cout << p.second;  // Output: 3   — accesses the second element
```

---

## Nested Pairs (Storing More Than Two Values)

A pair can only hold **two** elements directly. To store **three or more** values, use **nested pairs** — put a pair as the second element.

### Storing 3 values

```cpp
pair<int, pair<int, int>> p = {1, {3, 4}};
// Stores: 1, 3, 4
// p.first          = 1   — the outer first element
// p.second.first   = 3   — first element of the inner pair
// p.second.second  = 4   — second element of the inner pair
```

Accessing nested pair elements:
```cpp
cout << p.first;          // Output: 1
cout << p.second.first;   // Output: 3
cout << p.second.second;  // Output: 4
```

### Storing 4+ values

You can continue nesting:
```cpp
pair<int, pair<int, pair<int, int>>> p = {1, {2, {3, 4}}};
// p.first                    = 1
// p.second.first             = 2
// p.second.second.first      = 3
// p.second.second.second     = 4
```

> **Rule:** Every time you need one more value, wrap the "second" in another pair.

---

## Array of Pairs

`pair` is a valid data type and can be used as the element type of an array.

```cpp
pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
// Index 0 → (1, 2)
// Index 1 → (3, 4)
// Index 2 → (5, 6)
```

Accessing elements:
```cpp
cout << arr[1].second;   // Output: 4   — access index 1, then .second
```

Step-by-step:
- `arr[1]` → the pair `{3, 4}` at index 1
- `.second` → the value `4`

---

## Summary Table

| Syntax | Meaning |
|--------|---------|
| `pair<T1, T2> p = {a, b}` | Declares a pair with values a and b |
| `p.first` | Accesses the first value |
| `p.second` | Accesses the second value |
| `pair<T1, pair<T2, T3>>` | Nested pair to store 3 values |
| `p.second.first` | First value of the inner pair |
| `p.second.second` | Second value of the inner pair |
| `pair<T1, T2> arr[]` | Array where each element is a pair |

---

## Key Points to Remember

- Pair is part of the **utility library** (included automatically with `bits/stdc++.h`).
- The two elements are called **first** and **second** — always.
- Data types of first and second can be **different**.
- Pairs can be **nested** to hold more than 2 values.
- Pairs can be used as the **data type of an array**.
