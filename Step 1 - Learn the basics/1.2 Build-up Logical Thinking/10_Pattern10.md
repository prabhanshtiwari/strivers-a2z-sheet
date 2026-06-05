# Pattern 10 — Half Diamond / Rhombus Star

## What It Looks Like

For `n = 5`:
```
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- Total rows = `n + (n - 1)` = `2n - 1` = 9 rows for n=5.
- Outer loop runs from `i = 1` to `i < 2*n` (i.e., `i = 1` to `2n - 1`).

### Rule 2 — Connect Columns to Rows (Inner Loop)
Analyze the number of stars per row:

| Row (1-based) | Stars | i value |
|--------------|-------|---------|
| 1            | 1     | 1 |
| 2            | 2     | 2 |
| 3            | 3     | 3 |
| 4            | 4     | 4 |
| 5            | 5     | 5 |
| 6            | 4     | 6 |
| 7            | 3     | 7 |
| 8            | 2     | 8 |
| 9            | 1     | 9 |

**Observation (Rule 4 — Symmetry!):**
- The pattern is symmetric around row 5 (= n).
- **First half** (i ≤ n): Stars = `i` (simple, matches row number)
- **Second half** (i > n): Stars = `2*n - i`
  - i=6: 2*5 - 6 = 4 ✓
  - i=7: 2*5 - 7 = 3 ✓
  - i=9: 2*5 - 9 = 1 ✓

This is implemented using a **ternary or if-else** on the `stars` variable.

### Rule 3 — Print Inside Inner Loop
- Print `*` inside the inner loop.
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- **YES!** Symmetric around the middle row (`i = n`).
- Use conditional logic: if `i <= n`, stars = `i`; else stars = `2*n - i`.

---

## Dry Run (n = 5)

| i | Condition | Stars formula | Stars count |
|---|-----------|--------------|-------------|
| 1 | i ≤ n     | i = 1         | 1 |
| 3 | i ≤ n     | i = 3         | 3 |
| 5 | i ≤ n     | i = 5         | 5 |
| 6 | i > n     | 2*5-6 = 4     | 4 |
| 8 | i > n     | 2*5-8 = 2     | 2 |

---

## C++ Code

```cpp
void printPattern10(int n) {

    // Outer loop: runs for 2n-1 rows total (1 to 2n-1)
    for (int i = 1; i < 2 * n; i++) {

        // Determine how many stars to print on this row
        // Uses Rule 4 (Symmetry): two different formulas for each half
        int stars;
        if (i <= n) {
            stars = i;         // First half: row number = star count (increasing)
        } else {
            stars = 2 * n - i; // Second half: mirror formula (decreasing)
                               // e.g., n=5, i=6 → 2*5-6 = 4 stars
        }

        // Inner loop: print 'stars' number of stars
        for (int j = 1; j <= stars; j++) {
            cout << "* "; // Print star inside inner loop
        }

        cout << endl; // Move to next line after each row
    }
}
```

---

## Java Code

```java
static void printPattern10(int n) {

    // Outer loop: 2n-1 rows total
    for (int i = 1; i < 2 * n; i++) {

        // Determine star count based on which half we're in
        int stars = (i <= n) ? i : 2 * n - i;

        // Print stars
        for (int j = 1; j <= stars; j++) {
            System.out.print("* ");
        }

        System.out.println(); // New line
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Total rows | `2n - 1` |
| Outer loop | `i = 1` to `i < 2*n` |
| Stars (first half, i ≤ n) | `i` |
| Stars (second half, i > n) | `2*n - i` |
| Symmetry point | Row `n` (middle row) |

---

## Comparison: Pattern 9 vs Pattern 10

| Feature | Pattern 9 (Diamond) | Pattern 10 (Half Diamond) |
|---------|--------------------|--------------------------| 
| Spaces | Yes (centered) | No |
| Star arrangement | Centered/symmetric | Left-aligned |
| Shape | Full diamond | Half diamond (right triangle shape) |

---

## Key Takeaway

> Pattern 10 introduces the concept of **conditional formulas** inside the outer loop. The stars variable uses an `if-else` (or ternary) to pick between two formulas — one for the increasing half and one for the decreasing half. This is a direct application of **Rule 4 (Symmetry)**: once you identify the symmetry point (`i = n`), write separate formulas for each half.
