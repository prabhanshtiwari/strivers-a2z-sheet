# 04 — Check Palindrome Number

## Problem Statement

Write a program to determine if a given number is a **palindrome** or not.

- Print `true` if it is a palindrome
- Print `false` otherwise

---

## Definition of Palindrome Number

> A number is called a **palindrome** if its **reverse is exactly equal to itself**.

### Examples

| Number | Reverse | Palindrome? |
|--------|---------|-------------|
| 121    | 121     | ✅ Yes      |
| 1331   | 1331    | ✅ Yes      |
| 11     | 11      | ✅ Yes      |
| 7      | 7       | ✅ Yes      |
| 123    | 321     | ❌ No       |
| 7789   | 9877    | ❌ No       |

---

## Intuition

We already know how to **reverse a number** (from the previous problem).

So the algorithm is:
1. Compute the reverse of the number
2. Compare the reversed number with the **original** number
3. If they are equal → palindrome; else → not palindrome

---

## ⚠️ Important Pitfall — Preserve the Original N

When we run the digit extraction loop, we keep dividing N by 10.
**At the end of the loop, N becomes 0.**

So we **cannot** compare the reversed number with N directly after the loop!

### Solution: Store a Duplicate of N Before the Loop

```cpp
int dup = n;    // save original value BEFORE the loop modifies n
```

After the loop, compare `reverseNum` with `dup` (not `n`).

---

## Step-by-Step Walkthrough (N = 121)

```
dup = 121  (saved before loop)

Digit extraction loop:
  reverseNum starts at 0
  Step 1: lastDigit = 1, reverseNum = 0*10 + 1 = 1,  n = 12
  Step 2: lastDigit = 2, reverseNum = 1*10 + 2 = 12, n = 1
  Step 3: lastDigit = 1, reverseNum = 12*10 + 1 = 121, n = 0

After loop:
  reverseNum = 121
  dup        = 121
  121 == 121 → TRUE → Palindrome!
```

## Step-by-Step Walkthrough (N = 123)

```
dup = 123  (saved before loop)

reverseNum after loop = 321

321 == 123 → FALSE → Not a Palindrome
```

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int n) {
    int dup = n;          // IMPORTANT: save a copy of original n
                          // because the loop will reduce n to 0

    int reverseNum = 0;   // will hold the reversed number

    while (n > 0) {       // loop until all digits are processed
        int lastDigit = n % 10;                     // extract last digit
        reverseNum = (reverseNum * 10) + lastDigit; // build reversed number
        n = n / 10;                                 // remove last digit
    }

    // compare reversed number with the ORIGINAL number (dup)
    // NOT with n (which is now 0)
    if (dup == reverseNum) {
        return true;   // palindrome: reverse equals original
    } else {
        return false;  // not a palindrome
    }
}

int main() {
    int n;
    cin >> n;

    if (isPalindrome(n)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
```

---

## Dry Run Table (N = 1331)

| Step | n    | lastDigit | reverseNum | n after /10 |
|------|------|-----------|------------|-------------|
| init | 1331 | —         | 0          | —           |
| 1    | 1331 | 1         | 1          | 133         |
| 2    | 133  | 3         | 13         | 13          |
| 3    | 13   | 3         | 133        | 1           |
| 4    | 1    | 1         | 1331       | 0           |
| end  | 0    | loop ends | 1331       | —           |

`reverseNum (1331) == dup (1331)` → **Palindrome ✅**

---

## Time Complexity

| Aspect | Value |
|--------|-------|
| Time Complexity | **O(log₁₀ N)** |
| Space Complexity | O(1) |

---

## Key Takeaways

1. A palindrome number's reverse equals the number itself
2. Use the reverse-number logic from Problem 03
3. **Always save a duplicate of N before the loop** — the loop destroys N
4. Compare `reverseNum` with `dup`, never with `n` after the loop
5. Time complexity: **O(log₁₀ N)**
