# Pattern 8 — Inverted Star Pyramid

## What It Looks Like

For `n = 5`:
```
*********
 *******
  *****
   ***
    *
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 0` to `i < n`.

### Rule 2 — Connect Columns to Rows (Three Inner Loops)
The pattern is: **spaces → stars** per row.

Break down by row (0-indexed):

| Row `i` | Spaces | Stars |
|---------|--------|-------|
| 0       | 0      | 9     |
| 1       | 1      | 7     |
| 2       | 2      | 5     |
| 3       | 3      | 3     |
| 4       | 4      | 1     |

**Formula for spaces** (leading): `i`
- i=0: 0 spaces ✓
- i=1: 1 space ✓
- i=4: 4 spaces ✓

**Formula for stars**: `2 * (n - i) - 1` = `2*n - 2*i - 1`
- i=0: 2*5 - 0 - 1 = 9 ✓
- i=1: 2*5 - 2 - 1 = 7 ✓
- i=4: 2*5 - 8 - 1 = 1 ✓

### Rule 3 — Print Inside Inner Loops
1. Print `i` spaces
2. Print `2*(n-i) - 1` stars
- Print `endl` after both inner loops.

### Rule 4 — Symmetry?
- Pattern 8 is the **vertical flip** of Pattern 7.

---

## Dry Run (n = 5, 0-based)

| i | Spaces (i) | Stars (2*(n-i)-1) | Row output |
|---|-----------|-------------------|------------|
| 0 | 0         | 9                 | `* * * * * * * * *` |
| 1 | 1         | 7                 | ` * * * * * * *` |
| 2 | 2         | 5                 | `  * * * * *` |
| 3 | 3         | 3                 | `   * * *` |
| 4 | 4         | 1                 | `    *` |

---

## C++ Code

```cpp
void printPattern8(int n) {

    // Outer loop: iterates over each ROW (0 to n-1)
    for (int i = 0; i < n; i++) {

        // --- PART 1: Print leading spaces ---
        // Formula: i spaces (increases by 1 each row)
        // Row 0 → 0 spaces, Row 1 → 1 space, ..., Row n-1 → n-1 spaces
        for (int j = 0; j < i; j++) {
            cout << " "; // Print a single space
        }

        // --- PART 2: Print stars ---
        // Formula: (2 * (n - i) - 1) stars
        // Equivalent to: 2*n - 2*i - 1
        // Row 0 → 2n-1 stars (most), Row n-1 → 1 star (fewest)
        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            cout << "*"; 
        }

        cout << endl; // Move to next line
    }
}
```

---

## Java Code

```java
static void printPattern8(int n) {

    // Outer loop: each ROW from 0 to n-1
    for (int i = 0; i < n; i++) {

        // Part 1: Leading spaces (increases: 0, 1, 2, ..., n-1)
        for (int j = 0; j < i; j++) {
            System.out.print(" ");
        }

        // Part 2: Stars (decreases: 2n-1, 2n-3, ..., 3, 1)
        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            System.out.print("*");
        }

        System.out.println(); // New line
    }
}
```

---

## Key Observations

| Property | Formula |
|----------|---------|
| Total rows | `n` |
| Leading spaces on row `i` | `i` |
| Stars on row `i` | `2 * (n - i) - 1` |
| Outer loop | `i = 0` to `i < n` |

---

## Pattern 7 vs Pattern 8 (Mirror Relationship)

| Property | Pattern 7 (Pyramid) | Pattern 8 (Inverted Pyramid) |
|----------|--------------------|-----------------------------|
| Spaces | `n - i - 1` (decreasing) | `i` (increasing) |
| Stars | `2*i + 1` (increasing) | `2*(n-i) - 1` (decreasing) |
| Direction | Points up | Points down |

---

## Combining Tip

> Pattern 7 + Pattern 8 combined = **Diamond** (Pattern 9). You can literally call printPattern7(n) followed by printPattern8(n) to get the diamond!

---

## Key Takeaway

> Pattern 8 is the **upside-down version** of Pattern 7. Notice how the formulas are swapped: spaces become `i` (instead of `n-i-1`), and stars become `2*(n-i)-1` (instead of `2*i+1`). In Pattern 7 the spaces shrink and stars grow; in Pattern 8 the spaces grow and stars shrink.
