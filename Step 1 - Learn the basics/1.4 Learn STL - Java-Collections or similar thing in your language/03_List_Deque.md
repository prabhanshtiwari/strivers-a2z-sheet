# C++ STL — List and Deque

---

## List

### What is a List?

A `list` is a container that is **exactly like a vector** with one major addition: it supports **front operations** (push and pop from the front) efficiently.

Internally, a list is implemented as a **doubly linked list**.

| Feature | Vector | List |
|---------|--------|------|
| Internal structure | (dynamic array / singly linked list) | Doubly linked list |
| `push_front` | Very costly (shifts all elements) | Very cheap — O(1) |
| `push_back` | O(1) | O(1) |
| Random access `v[i]` | O(1) | Not supported |

---

### Declaring a List

```cpp
list<int> ls;       // declares an empty list of integers
list<string> ls;    // list of strings
```

---

### Inserting Elements

```cpp
list<int> ls;

ls.push_back(2);     // ls = {2}       — inserts 2 at the back
ls.emplace_back(4);  // ls = {2, 4}    — inserts 4 at the back (faster than push_back)

ls.push_front(5);    // ls = {5, 2, 4} — inserts 5 at the FRONT (very efficient in list)
ls.emplace_front(6); // ls = {6, 5, 2, 4} — inserts 6 at the front (faster than push_front)
```

> **Key advantage of list over vector:** `push_front` is **very cheap** in a list because it's a doubly linked list — no shifting needed. In a vector, inserting at the front is **costly** because all elements must shift right.

---

### All Functions

All the functions from vector work identically in list:

```cpp
ls.begin();     // iterator to first element
ls.end();       // iterator one past last element
ls.rbegin();    // reverse iterator to last element
ls.rend();      // reverse iterator before first
ls.size();      // number of elements
ls.clear();     // removes all elements
ls.empty();     // true if list is empty
ls.swap(ls2);   // swaps two lists
ls.front();     // first element
ls.back();      // last element
ls.pop_back();  // removes last element
ls.pop_front(); // removes first element
ls.insert(pos, val);   // insert at position
ls.erase(pos);         // erase at position
```

> Everything from vector applies — just remember list **adds** `push_front` and `emplace_front`.

---

## Deque (Double-Ended Queue)

### What is a Deque?

A **deque** (pronounced "deck") is similar to both list and vector. It supports efficient insertions and deletions **at both ends** (front and back).

```cpp
deque<int> dq;

dq.push_back(1);    // insert at back
dq.push_front(2);   // insert at front
dq.pop_back();      // remove from back
dq.pop_front();     // remove from front
dq.back();          // access last element
dq.front();         // access first element
```

All other functions (`size`, `clear`, `empty`, `swap`, `begin`, `end`, iterators) are the same as vector and list.

---

## Summary

| Container | push\_back | push\_front | Random Access |
|-----------|-----------|------------|--------------|
| **vector** | O(1) | O(n) — costly | Yes — `v[i]` |
| **list** | O(1) | O(1) — cheap | No |
| **deque** | O(1) | O(1) — cheap | Yes — `dq[i]` |
