# C++ STL — Stack, Queue, and Priority Queue

---

## Stack

### What is a Stack?

A **stack** follows the **LIFO** principle:
> **Last In, First Out** — The element that was inserted **last** comes out **first**.

Think of a stack of plates — you always pick from the top.

```
        ┌───┐
        │ 5 │  ← top (last inserted, first to come out)
        ├───┤
        │ 3 │
        ├───┤
        │ 3 │
        ├───┤
        │ 2 │
        ├───┤
        │ 1 │  ← bottom (first inserted, last to come out)
        └───┘
```

> **Important:** There is **no index-based access** in a stack. You cannot do `s[0]` or `s[1]`.

---

### Declaring a Stack

```cpp
stack<int> st;   // declares an empty stack of integers
```

---

### Stack Functions

#### `push(val)` — insert element
```cpp
stack<int> st;
st.push(1);      // stack: {1}
st.push(2);      // stack: {1, 2}
st.push(3);      // stack: {1, 2, 3}
st.push(3);      // stack: {1, 2, 3, 3}
st.emplace(5);   // emplace is same as push — stack: {1, 2, 3, 3, 5}
```

#### `top()` — peek at the top element (does NOT remove)
```cpp
cout << st.top();   // Output: 5   — returns the last inserted element
// 5 is still in the stack after this call
```

#### `pop()` — remove the top element
```cpp
st.pop();           // removes 5 (the top)
cout << st.top();   // Output: 3   — now 3 is at the top
```

#### `size()` — number of elements
```cpp
cout << st.size();   // Output: 4   — four elements remain
```

#### `empty()` — check if stack is empty
```cpp
cout << st.empty();   // Output: 0 (false) — stack has elements
```

#### `swap(st2)` — swap two stacks
```cpp
stack<int> st1, st2;
st1.push(1); st1.push(2);
st2.push(3); st2.push(4);
st1.swap(st2);
// st1 now has {3, 4}
// st2 now has {1, 2}
```

---

### Time Complexity of Stack Operations

| Operation | Time Complexity |
|-----------|----------------|
| `push` | O(1) — constant |
| `pop` | O(1) — constant |
| `top` | O(1) — constant |

> All stack operations run in **constant time O(1)**.

---

## Queue

### What is a Queue?

A **queue** follows the **FIFO** principle:
> **First In, First Out** — The element that was inserted **first** comes out **first**.

Think of a ticket queue at a train station — the first person to arrive gets the ticket first.

```
Front                        Back
 ┌───┬───┬───┐
 │ 1 │ 2 │ 4 │
 └───┴───┴───┘
  ↑ pop/front        push ↑
```

---

### Declaring a Queue

```cpp
queue<int> q;   // declares an empty queue of integers
```

---

### Queue Functions

```cpp
queue<int> q;
q.push(1);    // q = {1}        — inserts 1 at the back
q.push(2);    // q = {1, 2}     — inserts 2 at the back
q.push(4);    // q = {1, 2, 4}  — inserts 4 at the back
```

#### Modifying the back element
```cpp
q.back() += 5;
// q.back() accesses the last element (4) and adds 5 → 9
// q = {1, 2, 9}
```

#### `front()` — access first element (does NOT remove)
```cpp
cout << q.front();   // Output: 1   — just reads, does not delete
```

#### `back()` — access last element (does NOT remove)
```cpp
cout << q.back();    // Output: 9
```

#### `pop()` — remove the front element (FIFO — front goes first)
```cpp
q.pop();             // removes 1 (the front)
cout << q.front();   // Output: 2   — now 2 is at the front
```

#### `size()` and `empty()`
```cpp
cout << q.size();    // number of elements
cout << q.empty();   // true if queue is empty
```

---

### Time Complexity of Queue Operations

| Operation | Time Complexity |
|-----------|----------------|
| `push` | O(1) |
| `pop` | O(1) |
| `front` | O(1) |
| `back` | O(1) |

---

## Priority Queue

### What is a Priority Queue?

In a priority queue, the element with the **highest priority stays at the top**. By default, the **maximum element** has the highest priority.

> **Max Heap (default):** Largest element is always at the top.

Internally, a **tree structure (heap)** is maintained — not a linear array.

---

### Max Heap — Default Behavior

```cpp
priority_queue<int> pq;   // default: max heap

pq.push(5);    // pq top: 5
pq.push(2);    // pq top: 5  (5 > 2)
pq.push(8);    // pq top: 8  (8 is now largest)
pq.push(10);   // pq top: 10 (10 is now largest)
pq.push(3);    // pq top: 10 (3 goes in, but 10 stays on top)
```

#### `top()` — access the maximum element
```cpp
cout << pq.top();   // Output: 10  — always the largest element
```

#### `pop()` — remove the top (maximum) element
```cpp
pq.pop();           // removes 10
cout << pq.top();   // Output: 8   — 8 is now the largest remaining
```

#### `push(val)`, `size()`, `empty()` — same as stack/queue

---

### Min Heap — Minimum element at top

To get the **minimum element at the top**, use this special syntax:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
//                               ^^^^^^^^^^^
//                               This flips it to min heap
```

```cpp
pq.push(5);
pq.push(2);
pq.push(8);
pq.push(10);

cout << pq.top();   // Output: 2   — minimum element is now at top
```

> **Max Heap** = default `priority_queue<int>` — largest on top
> **Min Heap** = `priority_queue<int, vector<int>, greater<int>>` — smallest on top

---

### Time Complexity of Priority Queue Operations

| Operation | Time Complexity |
|-----------|----------------|
| `push` | O(log n) |
| `top` | O(1) |
| `pop` | O(log n) |

---

## Summary — Stack vs Queue vs Priority Queue

| Feature | Stack | Queue | Priority Queue |
|---------|-------|-------|----------------|
| Order | LIFO | FIFO | Priority (max/min) |
| Insert | `push` | `push` | `push` |
| Remove | `pop` (from top) | `pop` (from front) | `pop` (from top) |
| Peek | `top()` | `front()` and `back()` | `top()` |
| Index access | No | No | No |
| Push complexity | O(1) | O(1) | O(log n) |
| Pop complexity | O(1) | O(1) | O(log n) |
| Top/front complexity | O(1) | O(1) | O(1) |
