# 02 — Count Digits

## Problem Statement

Given a number **N**, find and return the **count of digits** present in the number.

### Examples

| Input N | Output (Count) |
|---------|---------------|
| 156     | 3             |
| 7       | 1             |
| 7789    | 4             |

---

## Approach 1 — Using Digit Extraction (Brute Force / Primary Method)

### Intuition

We already know how digit extraction works. Every time we extract a digit (do `N % 10` and then `N / 10`), we are processing **one digit**.

So if we simply **count how many times** the extraction loop runs, that count equals the **number of digits**.

### How It Works

```
N = 7789

Iteration 1: extract 9  → counter = 1
Iteration 2: extract 8  → counter = 2
Iteration 3: extract 7  → counter = 3
Iteration 4: extract 7  → counter = 4
N becomes 0 → STOP

Answer: 4 digits
```

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to count the number of digits in N
int countDigits(int n) {
    int count = 0;           // initialize counter to 0

    while (n > 0) {          // loop until N becomes 0 (all digits processed)
        n = n / 10;          // remove the last digit (we don't need the digit value here)
        count++;             // increment counter for each digit removed
    }

    return count;            // return the total count of digits
}

int main() {
    int n;
    cin >> n;
    cout << countDigits(n);
    return 0;
}
```

> **Note:** The `n % 10` (modulo) line is removed here because we don't need the actual digit value — we just need to know **how many times** the loop runs.

### Dry Run for N = 7789

| Iteration | N (before) | `N / 10` (new N) | count |
|-----------|-----------|-----------------|-------|
| 1         | 7789      | 778             | 1     |
| 2         | 778       | 77              | 2     |
| 3         | 77        | 7               | 3     |
| 4         | 7         | 0               | 4     |
| 5         | 0         | loop ends       | 4     |

**Output:** `4`

---

## Approach 2 — Using Logarithm Formula (Mathematical Trick)

### Intuition

The number of digits in a number N can be calculated directly using:

```
count = (int)(log10(N) + 1)
```

### How It Works

```
log10(7789) = 3.89...
3.89 + 1   = 4.89
(int)(4.89) = 4    ← answer!
```

### Why This Works

- `log10(N)` tells you the **power of 10** needed to reach N
- For a 4-digit number: 1000 ≤ N ≤ 9999 → log10 gives 3.something
- Adding 1 and truncating to integer gives exactly 4

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to count digits using the logarithm formula
int countDigits(int n) {
    // log10(n) gives approx (digits - 1), so +1 gives exact digit count
    // (int) truncates the decimal part
    return (int)(log10(n) + 1);
}

int main() {
    int n;
    cin >> n;
    cout << countDigits(n);
    return 0;
}
```

> **Note:** `log10` requires `#include <cmath>` or `#include <bits/stdc++.h>`. If you get a "not declared" error, make sure your include is correct.

### Examples

| N    | log10(N) | log10(N) + 1 | int(...) | Digits |
|------|----------|--------------|----------|--------|
| 7    | 0.845    | 1.845        | 1        | 1 ✓    |
| 156  | 2.193    | 3.193        | 3        | 3 ✓    |
| 7789 | 3.891    | 4.891        | 4        | 4 ✓    |

---

## Comparison of Both Approaches

| Aspect | Approach 1 (Loop) | Approach 2 (log10) |
|--------|------------------|-------------------|
| Method | Digit extraction loop | Mathematical formula |
| Time Complexity | O(log₁₀ N) | O(1) |
| Space Complexity | O(1) | O(1) |
| Preferred | ✅ Primary approach (teaches the concept) | ✅ Quick one-liner |

---

## Time Complexity

| Approach | Time | Space |
|----------|------|-------|
| Loop-based | **O(log₁₀ N)** | O(1) |
| log10 formula | **O(1)** | O(1) |

### Why O(log₁₀ N) for the loop?

The loop divides N by 10 each iteration. The number of iterations = number of digits ≈ log₁₀ N.

---

## Key Takeaways

1. Use a **counter variable** inside the digit extraction loop to count digits
2. The `% 10` operation is not needed here — only `/ 10` matters
3. Alternatively, `(int)(log10(N) + 1)` gives the count in O(1)
4. **Primary concept to remember:** the digit extraction loop
