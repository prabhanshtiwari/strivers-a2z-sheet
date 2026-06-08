# 06 — Print All Divisors

## Problem Statement

Given a number N, print **all divisors (factors)** of N in sorted order.

A **divisor** of N is any number that divides N completely (leaves remainder 0).

### Example

```
N = 36
Divisors: 1, 2, 3, 4, 6, 9, 12, 18, 36
```

---

## Approach 1 — Brute Force (O(N))

### Intuition

All divisors of N lie between **1 and N** (nothing greater than N can divide N).

So: loop from `i = 1` to `i = N`, and check if `N % i == 0`.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Brute force: loop from 1 to N and check each number
void printDivisors(int n) {
    for (int i = 1; i <= n; i++) {           // loop through all numbers from 1 to n
        if (n % i == 0) {                    // if i divides n with zero remainder
            cout << i << " ";               // then i is a divisor, print it
        }
    }
}

int main() {
    int n;
    cin >> n;
    printDivisors(n);
    return 0;
}
```

### Time Complexity

| Aspect | Value |
|--------|-------|
| Time | **O(N)** |
| Space | O(1) |

---

## Approach 2 — Optimized using √N (O(√N))

### Key Mathematical Observation

For every divisor `i` of N, there is a corresponding **paired divisor** `N/i`.

```
N = 36:

i = 1  →  paired divisor = 36/1 = 36    (1 × 36 = 36)
i = 2  →  paired divisor = 36/2 = 18    (2 × 18 = 36)
i = 3  →  paired divisor = 36/3 = 12    (3 × 12 = 36)
i = 4  →  paired divisor = 36/4 = 9     (4 × 9  = 36)
i = 6  →  paired divisor = 36/6 = 6     (6 × 6  = 36) ← both same!
```

Visualizing:
```
Small half:  1   2   3   4   6  ← loop only until here (√36 = 6)
             |   |   |   |   |
Large half: 36  18  12   9   6  ← get these for free as N/i
```

> The **orange line** (division point) is at √N.
> Everything beyond √N is just a repetition of the pairs already found below √N.
> So looping only until **√N** gives ALL divisors!

### Special Case — Perfect Square Root

When `i = √N` (e.g., i = 6 for N = 36):
- `i == N/i` (both are 6)
- We must **not print it twice** — add a check `if (N/i != i)` before printing the paired divisor

### C++ Code (Optimized)

```cpp
#include <bits/stdc++.h>
using namespace std;

// Optimized: loop only till sqrt(N), use paired divisors
void printDivisors(int n) {
    vector<int> ls;    // use a vector (dynamic list) since we don't know the number of divisors in advance

    // loop while i*i <= n (equivalent to i <= sqrt(n), avoids calling sqrt() each iteration)
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {                   // if i is a divisor of n
            ls.push_back(i);                // add i to the list (the smaller divisor)

            if (n / i != i) {               // check: the paired divisor must be different from i
                                            // (avoids duplicating the square root case, e.g. 6×6 for 36)
                ls.push_back(n / i);        // add the paired divisor n/i (the larger divisor)
            }
        }
    }

    sort(ls.begin(), ls.end());             // sort the list because divisors come out unordered
                                            // (we get pairs like 1,36 then 2,18 then 3,12...)

    // print all divisors in sorted order
    for (int x : ls) {
        cout << x << " ";
    }
}

int main() {
    int n;
    cin >> n;
    printDivisors(n);
    return 0;
}
```

### Why `i * i <= n` Instead of `i <= sqrt(n)`?

```cpp
// This calls sqrt() function every loop iteration — extra overhead
for (int i = 1; i <= sqrt(n); i++) { ... }

// This avoids the function call — equivalent and faster
for (int i = 1; i * i <= n; i++) { ... }
```

Both are equivalent logically, but `i * i <= n` avoids the repeated `sqrt()` function call.

### Walkthrough for N = 36

| i  | i*i | i*i ≤ 36? | 36 % i == 0? | Divisor added (i) | Paired (36/i) | Same? |
|----|-----|-----------|--------------|-------------------|---------------|-------|
| 1  | 1   | ✅        | ✅           | 1                 | 36            | No → add both |
| 2  | 4   | ✅        | ✅           | 2                 | 18            | No → add both |
| 3  | 9   | ✅        | ✅           | 3                 | 12            | No → add both |
| 4  | 16  | ✅        | ✅           | 4                 | 9             | No → add both |
| 5  | 25  | ✅        | ❌           | —                 | —             | — |
| 6  | 36  | ✅        | ✅           | 6                 | 6             | **Yes → add only 6** |
| 7  | 49  | ❌        | stop loop    | —                 | —             | — |

List before sorting: `[1, 36, 2, 18, 3, 12, 4, 9, 6]`
After sorting: `[1, 2, 3, 4, 6, 9, 12, 18, 36]` ✓

---

## Time Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(N)** | O(1) |
| Optimized | **O(√N + d·log d)** | O(d) |

Where `d` = number of divisors.

The full time complexity of the optimized approach is:
```
O(√N)            ← for the loop
+ O(d · log d)   ← for sorting d divisors
+ O(d)           ← for printing d divisors
```

But the **key improvement** is that the loop itself is only `O(√N)` instead of `O(N)`.

---

## Key Takeaways

1. All divisors lie between 1 and N → brute force loops N times (O(N))
2. Divisors come in **pairs**: if `i` divides N, then `N/i` also divides N
3. Both paired divisors are on **opposite sides of √N**
4. Looping only until **√N** and collecting both `i` and `N/i` gives all divisors
5. Special case: when `i == N/i` (perfect square root), only add once
6. Use `i * i <= n` instead of `i <= sqrt(n)` to avoid repeated function calls
7. **Sort the result** since divisors are collected out of order
8. Use a `vector` (dynamic array) since number of divisors is unknown ahead of time
