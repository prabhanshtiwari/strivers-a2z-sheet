# 08 — GCD / HCF (Greatest Common Divisor / Highest Common Factor)

## Problem Statement

Given two numbers N1 and N2, find their **GCD** (Greatest Common Divisor), also called **HCF** (Highest Common Factor).

---

## Definition

> **GCD / HCF** of two numbers is the **largest number that divides both** of them completely.

### Examples

```
N1 = 9,  N2 = 12

Factors of 9:  1, 3, 9
Factors of 12: 1, 2, 3, 4, 6, 12

Common factors: 1, 3
Largest common factor = 3

GCD(9, 12) = 3
```

```
N1 = 11, N2 = 13

Factors of 11: 1, 11
Factors of 13: 1, 13

Common factor: 1

GCD(11, 13) = 1
```

```
N1 = 20, N2 = 40

20 is a factor of both → GCD(20, 40) = 20
```

> **Note:** The GCD is always at least 1, because 1 divides every number.
> One of the numbers can itself be the GCD (e.g., GCD(20, 40) = 20).

---

## Approach 1 — Brute Force (O(min(N1, N2)))

### Intuition

Loop from 1 to `min(N1, N2)`. Any number greater than the smaller of the two cannot divide both.

For each `i`, if it divides both N1 and N2, update GCD.

The last value that divides both (since we go in increasing order) will be the largest.

```cpp
#include <bits/stdc++.h>
using namespace std;

// Brute force: loop from 1 to min(N1, N2)
int gcdBrute(int n1, int n2) {
    int gcd = 1;                          // GCD is at least 1 (1 divides everything)

    // only need to check up to the smaller number
    for (int i = 1; i <= min(n1, n2); i++) {
        if (n1 % i == 0 && n2 % i == 0) { // if i divides both n1 and n2
            gcd = i;                       // update gcd — keep replacing with larger values
                                           // since i increases, the last valid i is the largest
        }
    }

    return gcd;
}
```

### Alternative — Loop Backwards and Break Early

```cpp
// Start from min(N1,N2) and go down — first valid i IS the GCD, break immediately
int gcdBrute2(int n1, int n2) {
    for (int i = min(n1, n2); i >= 1; i--) {   // start from the maximum possible GCD
        if (n1 % i == 0 && n2 % i == 0) {       // if i divides both
            return i;                            // this is the GCD — return and stop
        }
    }
    return 1;   // fallback (will never reach here since 1 always divides both)
}
```

### Time Complexity

| Aspect | Value |
|--------|-------|
| Time | **O(min(N1, N2))** |
| Space | O(1) |

> **Worst case:** GCD = 1 (e.g., N1 = 11, N2 = 13 → loop runs all the way to 11)

---

## Approach 2 — Euclidean Algorithm (O(log_φ min(N1, N2)))

### The Euclidean Algorithm

The **Euclidean Algorithm** states:

```
GCD(N1, N2) = GCD(N1 - N2, N2)    where N1 > N2
```

Or in general notation:

```
GCD(A, B) = GCD(A - B, B)         where A > B
```

> A mathematical proof exists (available online), but for DSA you only need to understand and apply it.

### Proof by Induction (with an example)

```
N1 = 20, N2 = 15

GCD(20, 15) = 5   (we know this)

Euclidean: GCD(20-15, 15) = GCD(5, 15)
GCD(5, 15) = 5    ← same answer ✓
```

### The Problem with Repeated Subtraction

For large differences (e.g., A = 52, B = 10):

```
GCD(52, 10) → GCD(42, 10) → GCD(32, 10) → GCD(22, 10) → GCD(12, 10) → GCD(2, 10)
→ GCD(10, 2) → GCD(8, 2) → GCD(6, 2) → GCD(4, 2) → GCD(2, 2) → GCD(0, 2)
```

That's **11 steps**! We subtracted 10 five times from 52 to reach 2.

### Optimization — Replace Subtraction with Modulo

Subtracting B from A repeatedly until A < B is the **same** as `A % B`:

```
52 - 10 - 10 - 10 - 10 - 10 = 2
52 % 10 = 2   ← same result, one step!
```

So the improved Euclidean Algorithm:

```
GCD(A, B) = GCD(A % B, B)    where A > B
```

### Termination Condition

```
GCD(A, 0) = A    (if one number becomes 0, the other IS the GCD)
```

### Walkthrough for N1 = 20, N2 = 15

```
GCD(20, 15):
  20 > 15 → apply: GCD(20 % 15, 15) = GCD(5, 15)

GCD(5, 15):
  15 > 5 → apply: GCD(15 % 5, 5) = GCD(0, 5)

GCD(0, 5):
  One of them is 0 → GCD = 5 ✓
```

### Walkthrough for N1 = 52, N2 = 10

```
GCD(52, 10) → GCD(52 % 10, 10) = GCD(2, 10)
GCD(2, 10)  → GCD(10 % 2, 2)   = GCD(0, 2)
GCD(0, 2)   → Answer = 2 ✓
```

---

## C++ Code — Euclidean Algorithm

```cpp
#include <bits/stdc++.h>
using namespace std;

// Euclidean algorithm: repeatedly apply modulo until one becomes 0
int gcd(int n1, int n2) {
    // continue as long as BOTH numbers are non-zero
    while (n1 > 0 && n2 > 0) {
        if (n1 > n2) {
            // n1 is larger: reduce n1 by taking n1 % n2
            // (equivalent to subtracting n2 from n1 repeatedly)
            n1 = n1 % n2;
        } else {
            // n2 is larger: reduce n2 by taking n2 % n1
            n2 = n2 % n1;
        }
    }

    // when one of them is 0, the other holds the GCD
    if (n1 == 0) {
        return n2;   // n1 became 0, so GCD is n2
    } else {
        return n1;   // n2 became 0, so GCD is n1
    }
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    cout << "GCD = " << gcd(n1, n2);
    return 0;
}
```

---

## Dry Run Table: GCD(9, 12)

| Step | n1 | n2 | Larger | Operation | n1 after | n2 after |
|------|----|----|--------|-----------|----------|----------|
| 1    | 9  | 12 | n2     | n2 = 12 % 9 = 3 | 9 | 3 |
| 2    | 9  | 3  | n1     | n1 = 9 % 3 = 0  | 0 | 3 |
| end  | 0  | 3  | n1==0  | → GCD = 3       | — | — |

**GCD(9, 12) = 3 ✓**

---

## Dry Run Table: GCD(52, 10)

| Step | n1 | n2 | Operation | n1 after | n2 after |
|------|----|----|-----------|----------|----------|
| 1    | 52 | 10 | n1 = 52 % 10 = 2 | 2  | 10 |
| 2    | 2  | 10 | n2 = 10 % 2  = 0 | 2  | 0  |
| end  | 2  | 0  | n2==0 → GCD = 2  | —  | —  |

**GCD(52, 10) = 2 ✓**

---

## Time Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force (ascending) | **O(min(N1, N2))** | O(1) |
| Brute Force (descending + break) | **O(min(N1, N2))** worst case | O(1) |
| Euclidean Algorithm | **O(log_φ min(N1, N2))** | O(1) |

### Why O(log_φ min(N1, N2)) for Euclidean?

- The modulo operation reduces the number significantly each step
- This is **division-based reduction** → logarithmic complexity
- The base is **φ (phi, the golden ratio ≈ 1.618)** because the worst case is related to Fibonacci numbers
- φ (phi) rather than log₁₀ or log₂ because A and B fluctuate — they're not always reduced by a fixed factor

> For interviews, just remember: **Euclidean Algorithm is O(log_φ min(N1, N2))**
> You don't need to memorize the proof, just the result.

---

## Key Rules to Remember

```
GCD(A, B) = GCD(A % B, B)    where A > B
GCD(A, 0) = A                 (termination condition)
```

---

## Why Modulo Replaces Repeated Subtraction

```
A = 52, B = 10

Subtraction approach:
52 - 10 = 42
42 - 10 = 32
32 - 10 = 22
22 - 10 = 12
12 - 10 = 2    ← same as 52 % 10 = 2
```

You subtracted B exactly `floor(A/B)` times. `A % B` does this in one step.

---

## Key Takeaways

1. GCD = the **largest number that divides both** N1 and N2
2. GCD always exists (minimum is 1, since 1 divides everything)
3. Brute force: loop from 1 to min(N1,N2) → **O(min(N1, N2))**
4. **Euclidean Algorithm:** `GCD(A,B) = GCD(A%B, B)` for A > B → **O(log_φ min(N1,N2))**
5. Stop when one number becomes **0** — the other number is the GCD
6. Modulo is equivalent to repeated subtraction, but much faster
7. Logarithmic complexity arises because modulo is division-based reduction
