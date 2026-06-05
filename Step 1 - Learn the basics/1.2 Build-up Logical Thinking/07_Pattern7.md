# Pattern 7 — Star Pyramid (Equilateral Triangle)

## What It Looks Like

For `n = 5`:
```
    *
   * * *
  * * * * *
 * * * * * * *
* * * * * * * * *
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 0` to `i < n`.

### Rule 2 — Connect Columns to Rows (Three Inner Loops)
The pattern is made of three parts per row: **spaces → stars → spaces**

Break down by row (0-indexed):

| Row `i` | Spaces | Stars | (trailing spaces optional) |
|---------|--------|-------|---------------------------|
| 0       | 4      | 1     |
| 1       | 3      | 3     |
| 2       | 2      | 5     |
| 3       | 1      | 7     |
| 4       | 0      | 9     |

**Formula for spaces** (leading): `n - i - 1`
- i=0: 5-0-1 = 4 ✓
- i=1: 5-1-1 = 3 ✓
- i=4: 5-4-1 = 0 ✓

**Formula for stars**: `2*i + 1`
- i=0: 2*0+1 = 1 ✓
- i=1: 2*1+1 = 3 ✓
- i=2: 2*2+1 = 5 ✓
- i=4: 2*4+1 = 9 ✓

### Rule 3 — Print Inside Inner Loop
- Three separate inner loops:
  1. Print spaces: `n - i - 1` times
  2. Print stars: `2*i + 1` times
  3. (Optional trailing spaces)
- Print `endl` after all three inner loops.

### Rule 4 — Symmetry?
- Each row is **symmetric** around its center star. The leading spaces create the pyramid shape.

---

## Column Total Analysis

Total columns = `2*n - 1` (for n=5, that's 9 columns).

---

## Dry Run (n = 5, 0-based)

| i | Spaces (n-i-1) | Stars (2i+1) | Row output (conceptual) |
|---|----------------|--------------|------------------------|
| 0 | 4              | 1            | `    *` |
| 1 | 3              | 3            | `   * * *` |
| 2 | 2              | 5            | `  * * * * *` |
| 3 | 1              | 7            | ` * * * * * * *` |
| 4 | 0              | 9            | `* * * * * * * * *` |

---

## C++ Code

```cpp
void printPattern7(int n) {

    // Outer loop: iterates over each ROW (0 to n-1)
    for (int i = 0; i < n; i++) {

        // --- PART 1: Print leading spaces ---
        // Formula: (n - i - 1) spaces
        // Decreases by 1 each row → creates the pyramid indentation
        for (int j = 0; j < n - i - 1; j++) {
            cout << " "; // Print a single space (no star)
        }

        // --- PART 2: Print stars ---
        // Formula: (2 * i + 1) stars
        // Increases by 2 each row → creates odd-number sequence: 1, 3, 5, 7, 9...
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "* "; // Print star with space
        }

        // Move to next line after printing spaces and stars for this row
        cout << endl;
    }
}
```

---

## Java Code

```java
static void printPattern7(int n) {

    // Outer loop: each ROW from 0 to n-1
    for (int i = 0; i < n; i++) {

        // Part 1: Leading spaces (n - i - 1 spaces)
        for (int j = 0; j < n - i - 1; j++) {
            System.out.print(" ");
        }

        // Part 2: Stars (2*i + 1 stars)
        for (int j = 0; j < 2 * i + 1; j++) {
            System.out.print("* ");
        }

        System.out.println(); // New line after each row
    }
}
```

---

## Key Observations

| Property | Formula |
|----------|---------|
| Total rows | `n` |
| Leading spaces on row `i` | `n - i - 1` |
| Stars on row `i` | `2 * i + 1` |
| Total columns | `2 * n - 1` |
| Outer loop | `i = 0` to `i < n` |

---

## Why 3 Inner Loops?

The pattern has **three distinct sections per row**:
1. Leading spaces (shrink as rows increase)
2. Stars (grow as rows increase — by 2 each time)
3. (Trailing spaces if needed for alignment)

Each section needs its own inner loop with its own formula.

---

## Key Takeaway

> This is the first pattern requiring **multiple inner loops** per row. The key insight is to **decompose** the row into parts: spaces → stars → spaces. Find the formula for each part separately, then write a separate loop for each. The star count follows the odd number sequence `2i+1`, and the spaces follow `n-i-1`.
