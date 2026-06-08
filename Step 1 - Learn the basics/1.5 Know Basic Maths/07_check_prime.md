# 07 — Check for Prime Number

## Problem Statement

Given a number N, determine if it is a **prime number** or not.

---

## Definition of Prime Number

> ⚠️ **WRONG definition (common mistake):**
> "A number divisible by 1 and itself."
>
> This is wrong because by this definition, **1 would be prime** (divisible by 1 and itself).
> But 1 is **NOT** a prime number!

> ✅ **CORRECT definition:**
> **A number that has exactly TWO factors: 1 and itself.**

### Examples

| Number | Factors | Prime? |
|--------|---------|--------|
| 11     | 1, 11   | ✅ Yes (exactly 2 factors) |
| 13     | 1, 13   | ✅ Yes |
| 5      | 1, 5    | ✅ Yes |
| 1      | 1       | ❌ No (only 1 factor, not 2) |
| 4      | 1, 2, 4 | ❌ No (3 factors) |
| 8      | 1, 2, 4, 8 | ❌ No (4 factors) |
| 17     | 1, 17   | ✅ Yes |

---

## Approach 1 — Brute Force (O(N))

### Intuition

Count all factors from 1 to N. If the count is exactly **2**, the number is prime.

```cpp
#include <bits/stdc++.h>
using namespace std;

// Brute force: count factors from 1 to n
bool isPrime(int n) {
    int count = 0;                      // count how many numbers divide n

    for (int i = 1; i <= n; i++) {      // check every number from 1 to n
        if (n % i == 0) {               // if i divides n completely (no remainder)
            count++;                    // it's a factor, increment count
        }
    }

    // A prime number has EXACTLY 2 factors (1 and itself)
    return count == 2;
}

int main() {
    int n;
    cin >> n;
    cout << (isPrime(n) ? "Prime" : "Not Prime");
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

### Key Observation (from Print All Divisors)

We already know that divisors come in pairs, and if we loop until √N, we find **all** factors.

So to count factors, we only need to loop until √N and count each pair.

### C++ Code (Optimized)

```cpp
#include <bits/stdc++.h>
using namespace std;

// Optimized: count factors only up to sqrt(n)
bool isPrime(int n) {
    int count = 0;                      // count of factors

    // loop while i*i <= n (equivalent to i <= sqrt(n))
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {               // i is a divisor of n
            count++;                    // count the smaller divisor (i)

            if (n / i != i) {           // if the paired divisor is different from i
                                        // (avoids counting square root twice)
                count++;                // count the paired divisor (n/i)
            }
        }
    }

    // A prime number has EXACTLY 2 factors
    return count == 2;
}

int main() {
    int n;
    cin >> n;
    cout << (isPrime(n) ? "Prime" : "Not Prime");
    return 0;
}
```

### Walkthrough for N = 11 (Prime)

| i  | i*i | ≤ 11? | 11 % i == 0? | count |
|----|-----|-------|--------------|-------|
| 1  | 1   | ✅    | ✅ (11/1=11, 11≠1) | 2 (both 1 and 11 counted) |
| 2  | 4   | ✅    | ❌           | 2 |
| 3  | 9   | ✅    | ❌           | 2 |
| 4  | 16  | ❌    | stop         | 2 |

`count == 2` → **Prime ✅**

### Walkthrough for N = 4 (Not Prime)

| i  | i*i | ≤ 4? | 4 % i == 0? | count |
|----|-----|------|-------------|-------|
| 1  | 1   | ✅   | ✅ (4/1=4, 4≠1) | 2 (count 1 and 4) |
| 2  | 4   | ✅   | ✅ (4/2=2, 2==2) | 3 (only count 2, not twice since 4/2=2=i) |

`count == 3 ≠ 2` → **Not Prime ❌**

---

## Summary: Why √N is Enough

From the Print All Divisors problem:

```
N = 36 divisors visualization:

 i  :  1   2   3   4   6  |  9  12  18  36
N/i : 36  18  12   9   6  |  6   4   3   1
                          ↑
                        √36 = 6 (the boundary)
```

- Left side (i ≤ √N): unique small divisors
- Right side (N/i > √N): mirror of left side

Looping only to √N and counting pairs gives the **complete factor count**.

---

## Time Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(N)** | O(1) |
| Optimized (√N) | **O(√N)** | O(1) |

---

## Key Takeaways

1. **Correct definition:** A prime number has **exactly 2 factors** (1 and itself)
2. 1 is **NOT** prime (it has only 1 factor)
3. Brute force: loop 1 to N, count factors → O(N)
4. Optimized: loop 1 to √N, count pairs → O(√N)
5. Use `i * i <= n` instead of `i <= sqrt(n)` to avoid function call overhead
6. The √N optimization works because divisors always come in pairs
