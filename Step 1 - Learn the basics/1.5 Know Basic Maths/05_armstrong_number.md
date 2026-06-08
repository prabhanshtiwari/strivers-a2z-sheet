# 05 — Armstrong Number

## Problem Statement

Given a number N, determine if it is an **Armstrong number** (also called a Narcissistic number).

---

## Definition of Armstrong Number

> A number is called an **Armstrong number** if the **sum of cubes of its digits** equals the number itself.

### Examples

| Number | Calculation | Result | Armstrong? |
|--------|-------------|--------|------------|
| 371    | 3³ + 7³ + 1³ = 27 + 343 + 1 | 371 | ✅ Yes |
| 1634   | 1³ + 6³ + 3³ + 4³ = 1 + 216 + 27 + 64 | 308? | Let's check... |
| 153    | 1³ + 5³ + 3³ = 1 + 125 + 27 | 153 | ✅ Yes |
| 35     | 3³ + 5³ = 27 + 125 | 152 ≠ 35 | ❌ No |

> **Note from the transcript:** The example `1634` was mentioned as `1³ + 6³ + 3³ + 5³ = 1634`. In the standard definition, Armstrong numbers use the number of digits as the power. For the purpose of this course, cubing is used for all digits.

---

## Intuition

We use **digit extraction** again!

1. Extract each digit using `% 10`
2. Cube the digit and add to a running sum
3. After all digits are processed, compare the sum with the original number

---

## Step-by-Step Walkthrough (N = 371)

```
dup = 371   (save original)

sum = 0

Step 1: lastDigit = 1, sum = 0 + 1*1*1 = 1,   n = 37
Step 2: lastDigit = 7, sum = 1 + 7*7*7 = 344, n = 3
Step 3: lastDigit = 3, sum = 344 + 3*3*3 = 371, n = 0

Loop ends.

sum (371) == dup (371) → TRUE → Armstrong Number! ✅
```

## Step-by-Step Walkthrough (N = 35)

```
dup = 35

sum = 0

Step 1: lastDigit = 5, sum = 0 + 5*5*5 = 125, n = 3
Step 2: lastDigit = 3, sum = 125 + 3*3*3 = 152, n = 0

Loop ends.

sum (152) ≠ dup (35) → FALSE → Not Armstrong ❌
```

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to check if N is an Armstrong number
bool isArmstrong(int n) {
    int dup = n;    // IMPORTANT: save original value before the loop destroys n
    int sum = 0;    // will accumulate the sum of cubes of each digit

    while (n > 0) {
        int lastDigit = n % 10;                    // extract the last digit

        // cube the digit and add it to sum
        // lastDigit * lastDigit * lastDigit = lastDigit³
        sum = sum + (lastDigit * lastDigit * lastDigit);

        n = n / 10;                                // remove the last digit
    }

    // compare the sum of cubes with the original number
    if (sum == dup) {
        return true;   // Armstrong number
    } else {
        return false;  // not an Armstrong number
    }
}

int main() {
    int n;
    cin >> n;

    if (isArmstrong(n)) {
        cout << "Armstrong Number";
    } else {
        cout << "Not an Armstrong Number";
    }

    return 0;
}
```

---

## Dry Run Table (N = 153)

| Step | n   | lastDigit | lastDigit³ | sum | n after /10 |
|------|-----|-----------|-----------|-----|-------------|
| init | 153 | —         | —         | 0   | —           |
| 1    | 153 | 3         | 27        | 27  | 15          |
| 2    | 15  | 5         | 125       | 152 | 1           |
| 3    | 1   | 1         | 1         | 153 | 0           |
| end  | 0   | loop ends | —         | 153 | —           |

`sum (153) == dup (153)` → **Armstrong ✅**

---

## Common Armstrong Numbers

Some well-known Armstrong numbers (where power = number of digits):
- **1-digit:** 1, 2, 3, 4, 5, 6, 7, 8, 9
- **3-digit:** 153, 370, 371, 407
- **4-digit:** 1634, 8208, 9474

---

## Time Complexity

| Aspect | Value |
|--------|-------|
| Time Complexity | **O(log₁₀ N)** |
| Space Complexity | O(1) |

The loop runs once per digit, and number of digits ≈ log₁₀ N.

---

## Key Takeaways

1. Armstrong number: **sum of cubes of digits = the number itself**
2. Use digit extraction to get each digit, cube it, and accumulate in `sum`
3. **Save a duplicate of N** before the loop (same reason as palindrome problem)
4. Compare `sum` with `dup` (the original N)
5. Time complexity: **O(log₁₀ N)**
