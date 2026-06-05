# C++ STL — Set, Multiset, Unordered Set, Map, Multimap, Unordered Map

---

## Set

### What is a Set?

Remember just **two things** about a set:
1. **Sorted** — elements are always stored in ascending order.
2. **Unique** — duplicate elements are NOT stored.

Internally, a **tree structure** is maintained (not linear storage).

---

### Declaring and Inserting

```cpp
set<int> st;

st.insert(1);    // st = {1}
st.emplace(2);   // st = {1, 2}
st.insert(2);    // duplicate! — NOT inserted, st stays {1, 2}
st.insert(4);    // st = {1, 2, 4}
st.insert(3);    // st = {1, 2, 3, 4} — inserted in sorted position
```

> Even though 3 was inserted after 4, the set automatically maintains sorted order: `{1, 2, 3, 4}`.

---

### Iterating Over a Set

```cpp
set<int> st = {1, 2, 3, 4, 5};

// Method 1: Iterator loop
for (auto it = st.begin(); it != st.end(); it++) {
    cout << *it << " ";    // dereference to get value
}
// Output: 1 2 3 4 5

// Method 2: Range-based for loop (most common)
for (auto it : st) {
    cout << it << " ";
}
// Output: 1 2 3 4 5
```

---

### `find(val)` — Find an element

Returns an **iterator** pointing to the element if found; returns `st.end()` if NOT found.

```cpp
set<int> st = {1, 2, 4, 5};

auto it = st.find(3);       // 3 is NOT in set
if (it == st.end()) {
    cout << "Not found";    // Output: Not found
    // it points to st.end() — one past the last element
}

auto it2 = st.find(2);      // 2 IS in set
// it2 points to the memory location of 2
cout << *it2;               // Output: 2
```

---

### `count(val)` — Count occurrences

Since set only stores unique elements:
- Returns **1** if the element exists.
- Returns **0** if it does not exist.

```cpp
set<int> st = {1, 2, 3, 4};

cout << st.count(1);   // Output: 1  — exists
cout << st.count(6);   // Output: 0  — does not exist
```

Useful to check membership: `if (st.count(x)) { /* x exists */ }`

---

### `erase(val)` — Remove an element

```cpp
set<int> st = {1, 2, 4, 5};

st.erase(5);    // removes 5 by value
// st = {1, 2, 4}

// You can also erase by iterator:
auto it = st.find(2);
st.erase(it);   // removes element at iterator position
// st = {1, 4}
```

### Erasing a range
```cpp
set<int> st = {1, 2, 3, 4, 5};

auto it1 = st.find(2);   // iterator to 2
auto it2 = st.find(4);   // iterator to 4

st.erase(it1, it2);
// Erases from it1 (inclusive) to it2 (EXCLUSIVE)
// Deletes: 2 and 3. Does NOT delete 4.
// st = {1, 4, 5}
```

---

### Time Complexity of Set Operations

| Operation | Time Complexity |
|-----------|----------------|
| `insert` | O(log n) |
| `erase` | O(log n) |
| `find` | O(log n) |
| `count` | O(log n) |

---

### Other Set Functions

```cpp
st.size();      // number of elements
st.empty();     // true if set is empty
st.clear();     // removes all elements
st.swap(st2);   // swaps two sets
// lower_bound and upper_bound also available (see separate reference)
```

---

## Multiset

### What is a Multiset?

A multiset is like a set but allows **duplicate elements**:
1. **Sorted** — elements still stored in sorted order.
2. **NOT unique** — multiple copies of the same value are allowed.

```cpp
multiset<int> ms;

ms.insert(1);   // ms = {1}
ms.insert(1);   // ms = {1, 1}   — duplicate allowed!
ms.insert(1);   // ms = {1, 1, 1}
ms.insert(2);   // ms = {1, 1, 1, 2}
ms.insert(3);   // ms = {1, 1, 1, 2, 3}
```

---

### Erasing from Multiset

#### `erase(val)` — Erases ALL occurrences
```cpp
multiset<int> ms = {1, 1, 1, 2, 3};
ms.erase(1);
// ALL three 1s are removed!
// ms = {2, 3}
```

#### Erase only ONE occurrence (using iterator)
```cpp
multiset<int> ms = {1, 1, 1, 2, 3};

ms.erase(ms.find(1));
// ms.find(1) returns iterator to the FIRST occurrence of 1
// Only that ONE occurrence is erased
// ms = {1, 1, 2, 3}
```

#### Erase two occurrences
```cpp
multiset<int> ms = {1, 1, 1, 2, 3};

auto it = ms.find(1);   // iterator to first 1
ms.erase(it, next(it, 2));
// Erases from first 1 (inclusive) to 2 positions forward (exclusive)
// Deletes two 1s
// ms = {1, 2, 3}
```

---

### `count(val)` in Multiset
```cpp
multiset<int> ms = {1, 1, 1, 2};
cout << ms.count(1);   // Output: 3   — counts all occurrences of 1
```

---

## Unordered Set

### What is an Unordered Set?

Like a set, but:
1. **Unique** — no duplicates.
2. **NOT sorted** — elements stored in **random/unpredictable order**.

```cpp
unordered_set<int> us;

us.insert(1);
us.insert(5);
us.insert(2);
us.insert(3);
us.insert(6);
// Stored in some random order — NOT necessarily {1, 2, 3, 5, 6}
```

---

### Time Complexity of Unordered Set

| Operation | Average Case | Worst Case |
|-----------|-------------|-----------|
| `insert` | O(1) | O(n) — very rare |
| `erase` | O(1) | O(n) — very rare |
| `find` | O(1) | O(n) — very rare |

> The worst case O(n) happens only in extreme/rare scenarios. In practice, almost always O(1).

---

### What does NOT work in Unordered Set?

```cpp
// lower_bound and upper_bound do NOT work in unordered_set
// All other functions (insert, erase, find, count, size, empty) work the same
```

---

## Map

### What is a Map?

A map stores data as **key-value pairs**.

Real-world analogy: A roll number register — roll number is the **key**, student name is the **value**.

Key rules:
1. **Keys are unique** — no duplicate keys allowed.
2. **Keys are sorted** — stored in ascending order of key.
3. **Values can be duplicate** — two different keys can have the same value.
4. **Keys and values can be ANY data type** — int, double, string, pair, etc.

```
Key     Value
 1   →   "Raj"
 2   →   "Raj"     ← same value, different key — allowed
 3   →   "Priya"
```

---

### Declaring a Map

```cpp
map<int, int> mp;                     // key: int,   value: int
map<int, pair<int,int>> mp;           // key: int,   value: pair of ints
map<pair<int,int>, int> mp;           // key: pair,  value: int
map<string, int> mp;                  // key: string, value: int
```

---

### Inserting into a Map

```cpp
map<int, int> mp;

// Method 1: subscript operator
mp[1] = 2;           // key=1, value=2

// Method 2: emplace
mp.emplace(3, 1);    // key=3, value=1

// Method 3: insert with pair
mp.insert({2, 4});   // key=2, value=4

// Stored in sorted key order: {(1,2), (2,4), (3,1)}
```

---

### Accessing Map Values

```cpp
map<int, int> mp;
mp[1] = 2;
mp[2] = 4;
mp[3] = 1;

cout << mp[1];    // Output: 2   — access value at key 1
cout << mp[5];    // Output: 0   — key 5 doesn't exist → returns 0 (default value)
// WARNING: accessing mp[5] also CREATES a key 5 with value 0 in the map!
```

---

### Iterating Over a Map

```cpp
map<int, int> mp = {{1,2}, {2,4}, {3,1}};

// Each element is a pair — first = key, second = value
for (auto it : mp) {
    cout << it.first << " " << it.second << "\n";
}
// Output:
// 1 2
// 2 4
// 3 1
```

Using iterator:
```cpp
for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << " " << it->second << "\n";
    // Or: (*it).first  (*it).second
}
```

---

### `find(key)` — Find a key

```cpp
map<int, int> mp = {{1,2}, {2,4}, {3,1}};

auto it = mp.find(3);
// 'it' is an iterator pointing to the pair {3, 1}

cout << (*it).second;   // Output: 1   — value at key 3
// Equivalently: it->second

auto it2 = mp.find(5);  // key 5 doesn't exist
if (it2 == mp.end()) {
    cout << "Key not found";
}
```

---

### Other Map Functions

```cpp
mp.erase(key);         // erase by key value
mp.erase(iterator);    // erase by iterator
mp.size();             // number of key-value pairs
mp.empty();            // true if map is empty
mp.clear();            // removes all entries
mp.swap(mp2);          // swaps two maps
mp.count(key);         // 1 if key exists, 0 if not
// lower_bound and upper_bound also available
```

---

### Time Complexity of Map

| Operation | Time Complexity |
|-----------|----------------|
| `insert` | O(log n) |
| `erase` | O(log n) |
| `find` | O(log n) |
| `[]` access | O(log n) |

---

## Multimap

Like map, but allows **duplicate keys**:
- Keys can repeat.
- Still stored in sorted key order.

```cpp
multimap<int, int> mmp;
mmp.insert({1, 2});   // key=1, value=2
mmp.insert({1, 3});   // key=1, value=3 — duplicate key allowed!
// mmp = {(1,2), (1,3)}
```

---

## Unordered Map

Like map, but:
- **Keys are unique** (no duplicates).
- **NOT sorted** — stored in random order.
- Operations are O(1) average, O(n) worst case (rare).

```cpp
unordered_map<string, int> ump;
ump["apple"] = 3;
ump["banana"] = 5;
// Order of storage is unpredictable
```

---

## Summary Table — All Set/Map Variants

| Container | Sorted | Unique | Avg Complexity |
|-----------|--------|--------|----------------|
| `set` | Yes | Yes | O(log n) |
| `multiset` | Yes | No (duplicates OK) | O(log n) |
| `unordered_set` | No | Yes | O(1) avg |
| `map` | Yes (by key) | Keys unique | O(log n) |
| `multimap` | Yes (by key) | Keys can repeat | O(log n) |
| `unordered_map` | No | Keys unique | O(1) avg |

---

## Key Points to Remember

- `set.find(x)` returns `set.end()` if element is NOT found.
- `set.erase(val)` erases the element by value; `set.erase(iterator)` erases by position.
- In `erase(start, end)` — start is **included**, end is **excluded**.
- `map[key]` returns 0 for non-existent keys AND creates the entry — be careful.
- Prefer `map.find(key)` over `map[key]` when you just want to check existence.
- `multiset.erase(val)` erases **ALL** copies; use `erase(find(val))` for just one.
- `unordered_set` and `unordered_map` do NOT support `lower_bound` / `upper_bound`.
