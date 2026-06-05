# Pattern 20 — Symmetric Hollow Butterfly / Sandglass

## What It Looks Like

For `n = 5`:
```
* * * * * * * * * *
* * * *   * * * *
* * *     * * *
* *       * *
*         *
* *       * *
* * *     * * *
* * * *   * * * *
* * * * * * * * * *
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- Total rows = `2n - 1` = 9 rows for n=5.
- Single outer loop: `i = 1` to `2*n - 1`.

### Rule 4 — Symmetry (Check First!)
- **YES!** The pattern is symmetric around the middle row.
- Middle row (row `n`) = the narrowest row.
- But unlike Pattern 19, we can use a **single loop** with a conditional formula.

### Rule 2 — Connect Columns to Rows

Each row has: **stars → spaces → stars**

**Full analysis (1-indexed, i = 1 to 2n-1):**

| i | Stars | Spaces |
|---|-------|--------|
| 1 | n=5   | 0      |
| 2 | 4     | 2      |
| 3 | 3     | 4      |
| 4 | 2     | 6      |
| 5 | 1     | 8      |
| 6 | 2     | 6      |
| 7 | 3     | 4      |
| 8 | 4     | 2      |
| 9 | 5     | 0      |

**Stars formula (using conditional, same as Pattern 10):**
- If `i <= n`: stars = `n - i + 1`
  - i=1: 5-1+1 = 5 ✓, i=2: 5-2+1=4 ✓
- If `i > n`: stars = `i - n + 1`
  - i=6: 6-5+1=2 ✓, i=9: 9-5+1=5 ✓

**Spaces formula:**
- If `i <= n`: spaces = `2 * (i - 1)` (increases by 2)
  - i=1: 0 ✓, i=2: 2 ✓, i=5: 8 ✓
- If `i > n`: spaces = `2 * (2*n - i - 1)` (decreases by 2)
  - i=6: 2*(10-6-1)=2*3=6 ✓, i=9: 2*(10-9-1)=0 ✓

**Alternatively, manage `spaces` as a variable:**
- Initialize `spaces = 0`
- If `i <= n`: increase spaces by 2 after each row
- If `i > n`: decrease spaces by 2 after each row

### Rule 3 — Print Inside Inner Loops
Three inner loops per row:
1. Stars
2. Spaces
3. Stars

---

## Dry Run Key Rows (n = 5, 1-based)

| i | Condition | Stars | Spaces | Row Output |
|---|-----------|-------|--------|------------|
| 1 | i ≤ n | 5 | 0 | `* * * * * * * * * *` |
| 3 | i ≤ n | 3 | 4 | `* * *     * * *` |
| 5 | i = n | 1 | 8 | `*         *` |
| 7 | i > n | 3 | 4 | `* * *     * * *` |
| 9 | i > n | 5 | 0 | `* * * * * * * * * *` |

---

## C++ Code

```cpp
void printPattern20(int n) {

    // Initialize spaces variable to track middle spaces
    int spaces = 2 * n - 2; // Initial value: 2n-2 (for n=5: 8... wait, see note below)
    // Actually: spaces starts at 0 for the first row (full stars, no gaps)
    // We'll use a different tracking approach: start at 0, adjust direction

    // Actually from analysis: for i <= n, spaces = 2*(i-1)
    // Let's use explicit formula approach for clarity

    // Outer loop: runs for 2n-1 rows
    for (int i = 1; i <= 2 * n - 1; i++) {

        // --- Determine star count based on which half we're in ---
        int stars;
        if (i <= n) {
            stars = n - i + 1; // First half: decreasing stars (n, n-1, ..., 1)
        } else {
            stars = i - n + 1; // Second half: increasing stars (2, 3, ..., n)
        }

        // --- Determine space count based on which half we're in ---
        int numSpaces;
        if (i <= n) {
            numSpaces = 2 * (i - 1); // First half: spaces increase (0, 2, 4, ..., 2n-2)
        } else {
            numSpaces = 2 * (2 * n - i - 1); // Second half: spaces decrease
        }

        // --- Inner loop 1: Print left stars ---
        for (int j = 1; j <= stars; j++) {
            cout << "* "; // Left star
        }

        // --- Inner loop 2: Print middle spaces ---
        for (int j = 1; j <= numSpaces; j++) {
            cout << " "; // Space
        }

        // --- Inner loop 3: Print right stars ---
        for (int j = 1; j <= stars; j++) {
            cout << "* "; // Right star
        }

        cout << endl; // Move to next line
    }
}
```

---

## Alternative: Variable-Tracking Approach

```cpp
void printPattern20(int n) {

    int spaces = 0; // Start with 0 spaces (first row is all stars)

    for (int i = 1; i <= 2 * n - 1; i++) {

        // Determine star count (same conditional logic as Pattern 10)
        int stars = (i <= n) ? (n - i + 1) : (i - n + 1);

        // Print left stars
        for (int j = 1; j <= stars; j++) cout << "* ";

        // Print middle spaces
        for (int j = 1; j <= spaces; j++) cout << " ";

        // Print right stars
        for (int j = 1; j <= stars; j++) cout << "* ";

        cout << endl;

        // Update spaces:
        // First half (i < n): spaces increase by 2
        // Second half (i >= n): spaces decrease by 2
        if (i < n) {
            spaces += 2; // Moving toward the narrow middle
        } else {
            spaces -= 2; // Moving away from the narrow middle
        }
    }
}
```

---

## Java Code

```java
static void printPattern20(int n) {

    int spaces = 0;

    for (int i = 1; i <= 2 * n - 1; i++) {

        int stars = (i <= n) ? (n - i + 1) : (i - n + 1);

        // Left stars
        for (int j = 1; j <= stars; j++) System.out.print("* ");

        // Middle spaces
        for (int j = 1; j <= spaces; j++) System.out.print(" ");

        // Right stars
        for (int j = 1; j <= stars; j++) System.out.print("* ");

        System.out.println();

        if (i < n) spaces += 2;
        else spaces -= 2;
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Total rows | `2n - 1` |
| Stars (i ≤ n) | `n - i + 1` (decreasing) |
| Stars (i > n) | `i - n + 1` (increasing) |
| Spaces (i ≤ n) | `2 * (i - 1)` (increasing) |
| Spaces (i > n) | `2 * (2n - i - 1)` (decreasing) |

---

## Pattern 19 vs Pattern 20

| Feature | Pattern 19 (Butterfly grows outward) | Pattern 20 (Inverted — shrinks then grows) |
|---------|--------------------------------------|---------------------------------------------|
| Middle row | Widest (most stars) | Narrowest (fewest stars) |
| Stars | Increase then decrease | Decrease then increase |
| Spaces | Decrease then increase | Increase then decrease |

---

## Key Takeaway

> Pattern 20 requires managing **two variables simultaneously** (stars + spaces) with conditional logic based on which half of the pattern you're in. The insight from Pattern 10 (using conditional formulas for the two halves) is directly applicable here, extended with an additional spaces variable. Always trace through a few rows to verify your formulas before coding.
