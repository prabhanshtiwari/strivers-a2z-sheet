# Pattern 19 — Symmetric Butterfly / Hourglass Star

## What It Looks Like

For `n = 5`:
```
*         *
* *       * *
* * *     * * *
* * * *   * * * *
* * * * * * * * * *
* * * *   * * * *
* * *     * * *
* *       * *
*         *
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- Total rows = `2n - 1` = 9 rows for n=5.
- The pattern is split into **two halves** (Rule 4 — Symmetry).

### Rule 4 — Symmetry (Applied First!)
- The pattern is **symmetric** around the middle row (row n).
- **Top half** (rows 0 to n-1): stars increase, spaces decrease.
- **Bottom half** (rows n to 2n-2): stars decrease, spaces increase.
- Use two separate loops (or two sections in one loop).

### Rule 2 — Connect Columns to Rows

Each row has: **stars → spaces → stars**

**Top half analysis (0-indexed, i = 0 to n-1):**

| i | Left Stars | Spaces | Right Stars |
|---|-----------|--------|-------------|
| 0 | 1 | 8 | 1 |
| 1 | 2 | 6 | 2 |
| 2 | 3 | 4 | 3 |
| 3 | 4 | 2 | 4 |
| 4 | 5 | 0 | 5 |

- Left stars = `i + 1` (or use 1-indexed: `i`)
  - Actually use `i` if 1-indexed (i starts from 1)
- Spaces = start at `2*(n-1)` = 8, decrease by 2 each row
- Right stars = same as left stars

**Formulas for top half (1-indexed, i = 1 to n):**
- Stars = `i`
- Spaces = `2 * (n - i)` = starts at `2*(n-1)` and decreases

**Bottom half (continuation, i = n-1 down to 1 in 1-indexed):**
- Stars = `i` (decreasing)
- Spaces = `2 * (n - i)` (increasing)
- The same formula works — just i goes from `n-1` back to `1`.

### Rule 3 — Print Inside Inner Loops
Three inner loops per row:
1. Print `stars` number of stars
2. Print `spaces` number of spaces
3. Print `stars` number of stars again
- Print `endl` after all three.

---

## Top Half Dry Run (n = 5, 1-based, i = 1 to 5)

| i | Stars (i) | Spaces (2*(n-i)) | Output |
|---|-----------|-----------------|--------|
| 1 | 1 | 8 | `*         *` |
| 2 | 2 | 6 | `* *       * *` |
| 3 | 3 | 4 | `* * *     * * *` |
| 4 | 4 | 2 | `* * * *   * * * *` |
| 5 | 5 | 0 | `* * * * * * * * * *` |

---

## C++ Code

```cpp
void printPattern19(int n) {

    // ===== TOP HALF =====
    // Rows: i = 1 to n (1-based)
    // Stars increase (1, 2, 3, ..., n), spaces decrease

    int spaces = 2 * (n - 1); // Initial spaces for top half: 2*(n-1)

    for (int i = 1; i <= n; i++) {

        // --- Inner loop 1: Print left stars ---
        // Number of stars = i (increases by 1 each row)
        for (int j = 1; j <= i; j++) {
            cout << "* "; // Left star
        }

        // --- Inner loop 2: Print middle spaces ---
        // Number of spaces decreases by 2 each row
        for (int j = 1; j <= spaces; j++) {
            cout << " "; // Space character
        }

        // --- Inner loop 3: Print right stars ---
        // Same count as left stars (symmetric)
        for (int j = 1; j <= i; j++) {
            cout << "* "; // Right star
        }

        cout << endl; // Move to next line

        spaces -= 2; // Reduce spaces by 2 for the next row
    }

    // ===== BOTTOM HALF =====
    // Rows: i = n-1 down to 1 (reverse of top half, minus the middle row)
    // Stars decrease, spaces increase

    spaces = 2; // Start with 2 spaces (just after the middle row)

    for (int i = n - 1; i >= 1; i--) {

        // --- Inner loop 1: Print left stars (decreasing) ---
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }

        // --- Inner loop 2: Print middle spaces (increasing) ---
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        // --- Inner loop 3: Print right stars (same as left) ---
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }

        cout << endl;

        spaces += 2; // Increase spaces by 2 for each subsequent row
    }
}
```

---

## Java Code

```java
static void printPattern19(int n) {

    // Top half
    int spaces = 2 * (n - 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) System.out.print("* ");
        for (int j = 1; j <= spaces; j++) System.out.print(" ");
        for (int j = 1; j <= i; j++) System.out.print("* ");
        System.out.println();
        spaces -= 2;
    }

    // Bottom half
    spaces = 2;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) System.out.print("* ");
        for (int j = 1; j <= spaces; j++) System.out.print(" ");
        for (int j = 1; j <= i; j++) System.out.print("* ");
        System.out.println();
        spaces += 2;
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Total rows | `2n - 1` |
| Top half rows | `n` |
| Bottom half rows | `n - 1` |
| Stars (top half, row i) | `i` (1-indexed) |
| Spaces (top half, row i) | `2 * (n - i)` |
| Stars (bottom half, row i) | `i` (decreasing, i from n-1 to 1) |
| Spaces (bottom half) | starts at 2, increases by 2 |

---

## The Space Management Trick

Instead of computing spaces with a formula each time, we **track a variable** and adjust it:
```cpp
// Top half: spaces starts at 2*(n-1), decreases by 2
spaces = 2 * (n - 1);
spaces -= 2; // at end of each row

// Bottom half: spaces starts at 2, increases by 2
spaces = 2;
spaces += 2; // at end of each row
```

---

## Key Takeaway

> Pattern 19 combines the space-star-space structure (from Pattern 7) with the top/bottom halves structure (from Pattern 10). It introduces **three inner loops per row** plus a **managed spaces variable** that changes direction between the two halves. Always decompose complex patterns into: identify parts (stars/spaces/stars), find formulas for each, write separate inner loops.
