# 01 — Digit Extraction (Core Concept)

## What is Digit Extraction?

Given a number like **7789**, digit extraction means isolating each individual digit:
- 9 (units place)
- 8 (tens place)
- 7 (hundreds place)
- 7 (thousands place)

This concept is the **foundation** of almost all Basic Maths problems.

---

## How Does It Work?

### Step 1 — Extract the Last Digit using Modulo 10

**Key Observation:**
> All numbers divisible by 10 end with a zero: 10, 20, 30, 40, 100, ...

The `%` (modulo) operator returns the **remainder** after division.

So `N % 10` always gives you the **last digit** of N.

```
7789 % 10 = 9
  └─ Because 7789 ÷ 10 = 778 remainder 9
```

### Step 2 — Remove the Last Digit using Integer Division by 10

```
7789 / 10 = 778.9  →  integer part = 778
```

By dividing by 10 and taking the integer portion, we **chop off** the last digit.

### Repeat Until N Becomes 0

```
N = 7789 → last digit = 9,  N becomes 778
N = 778  → last digit = 8,  N becomes 77
N = 77   → last digit = 7,  N becomes 7
N = 7    → last digit = 7,  N becomes 0
N = 0    → STOP (loop ends)
```

> ⚠️ Note: Digits are extracted in **REVERSE ORDER** (from last digit to first digit).

---

## Pseudo Code

```
take N from user

while N > 0:
    lastDigit = N % 10      // extract the last digit
    print(lastDigit)         // use the digit as needed
    N = N / 10               // remove the last digit (integer division)
```

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;                        // take input from user

    while (n > 0) {                  // loop runs until all digits are extracted
        int lastDigit = n % 10;      // % 10 gives the last digit (remainder when divided by 10)
        cout << lastDigit << " ";    // print or use the extracted digit
        n = n / 10;                  // integer division removes the last digit
    }

    return 0;
}
```

### Dry Run for N = 7789

| Iteration | N    | `N % 10` (last digit) | `N / 10` (new N) |
|-----------|------|-----------------------|-----------------|
| 1         | 7789 | 9                     | 778             |
| 2         | 778  | 8                     | 77              |
| 3         | 77   | 7                     | 7               |
| 4         | 7    | 7                     | 0               |
| 5         | 0    | loop ends             | —               |

**Output:** `9 8 7 7`

---

## Time Complexity

| Aspect | Value |
|--------|-------|
| Time Complexity | **O(log₁₀ N)** |
| Space Complexity | O(1) |

### Why O(log₁₀ N)?

The loop divides N by 10 every iteration.

- For N = 7789: the loop runs **4 times** (log₁₀ 7789 ≈ 3.89 ≈ 4)
- For N = 100:  the loop runs **3 times** (log₁₀ 100 = 2, but includes 100 → 10 → 1 → 0)

> **Rule:** Whenever a loop performs division by a constant `k` each iteration, the time complexity is **O(log_k N)**.

---

## Key Takeaways

1. `N % 10` → gives the **last digit**
2. `N / 10` (integer division) → **removes** the last digit
3. Loop runs while `N > 0`
4. Digits come out in **reverse order**
5. Time complexity is **O(log₁₀ N)** because we divide by 10 each time
