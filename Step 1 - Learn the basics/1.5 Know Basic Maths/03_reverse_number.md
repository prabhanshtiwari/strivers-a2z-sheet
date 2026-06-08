# 03 — Reverse a Number

## Problem Statement

Write a program to generate the **reverse** of a given number.

> **Note:** If a number has trailing zeros, its reverse will **not** include them.
> Example: reverse of `10400` is `401` (not `00401`).

### Examples

| Input N | Reversed |
|---------|----------|
| 7789    | 9877     |
| 121     | 121      |
| 10400   | 401      |

---

## Intuition

We already know digit extraction gives us digits in **reverse order**:
- From 7789 we get: 9, 8, 7, 7

We need to **build** the number 9877 from these digits as we extract them.

---

## The Key Formula

```
reverseNum = (reverseNum * 10) + lastDigit
```

### Why Multiply by 10?

At each step we have a digit to place. To "shift" the already-built number left by one place (make room for the new digit), we multiply by 10.

Then we add the new digit.

---

## Step-by-Step Walkthrough (N = 7789)

| Step | N    | lastDigit (`N%10`) | reverseNum (before) | reverseNum (after) = old × 10 + lastDigit | N after (`N/10`) |
|------|------|--------------------|---------------------|------------------------------------------|-----------------|
| 1    | 7789 | 9                  | 0                   | 0 × 10 + 9 = **9**                       | 778             |
| 2    | 778  | 8                  | 9                   | 9 × 10 + 8 = **98**                      | 77              |
| 3    | 77   | 7                  | 98                  | 98 × 10 + 7 = **987**                    | 7               |
| 4    | 7    | 7                  | 987                 | 987 × 10 + 7 = **9877**                  | 0               |
| 5    | 0    | loop ends          | —                   | —                                        | —               |

**Output:** `9877` ✓

---

## Why Does `reverseNum * 10` Work?

Imagine you've already built `9` and the next digit is `8`:
- You want the result to be `98`
- `9 * 10 = 90`, then `90 + 8 = 98` ✓

Next, you have `98` and digit `7`:
- You want `987`
- `98 * 10 = 980`, then `980 + 7 = 987` ✓

This pattern works because multiplying by 10 shifts all digits one place to the left (adds a zero at the unit place), and then adding the new digit fills that zero.

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to reverse a given number
int reverseNumber(int n) {
    int reverseNum = 0;          // will build up the reversed number here

    while (n > 0) {              // loop until all digits are processed
        int lastDigit = n % 10;  // extract the last digit using modulo 10

        // shift reverseNum left (multiply by 10) and place the new digit at unit position
        reverseNum = (reverseNum * 10) + lastDigit;

        n = n / 10;              // remove the last digit from n (integer division)
    }

    return reverseNum;           // return the fully reversed number
}

int main() {
    int n;
    cin >> n;
    cout << reverseNumber(n);
    return 0;
}
```

---

## Handling Trailing Zeros

The trailing zeros problem is handled **automatically** by this approach.

```
N = 10400
Digits extracted: 0, 0, 4, 0, 1

reverseNum after digit 0:  0 * 10 + 0 = 0
reverseNum after digit 0:  0 * 10 + 0 = 0
reverseNum after digit 4:  0 * 10 + 4 = 4
reverseNum after digit 0:  4 * 10 + 0 = 40
reverseNum after digit 1: 40 * 10 + 1 = 401
```

**Output:** `401` ✓ (leading zeros from the reverse are never built because `0 * 10 + 0 = 0`)

---

## Time Complexity

| Aspect | Value |
|--------|-------|
| Time Complexity | **O(log₁₀ N)** |
| Space Complexity | O(1) |

The loop runs once per digit, and the number of digits ≈ log₁₀ N.

---

## Key Takeaways

1. Digit extraction naturally gives digits in reverse order
2. Use `reverseNum = reverseNum * 10 + lastDigit` to build the reversed number
3. Multiplying by 10 "shifts" the current number left to make room for the new digit
4. Trailing zeros are handled automatically (0 × 10 + 0 = 0)
5. Time complexity: **O(log₁₀ N)**
