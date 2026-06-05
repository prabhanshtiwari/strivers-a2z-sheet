# Pattern 2 — Right-Angled Triangle (Stars, Increasing)

## What It Looks Like

For `n = 5`:
```
*
* *
* * *
* * * *
* * * * *
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 0` to `i < n`.

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 0 → 1 star
- Row 1 → 2 stars
- Row 2 → 3 stars
- Row 3 → 4 stars
- Row 4 → 5 stars

Observation: **Number of stars on row `i` = `i + 1`** (0-based indexing).

So the inner loop runs from `j = 0` to `j <= i`.

### Rule 3 — Print Inside Inner Loop
- Print `*` (with a space) inside the inner loop.
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed.

---

## Dry Run (n = 4, zero-based)

| i (row) | j values    | Stars printed |
|---------|------------|---------------|
| 0       | 0          | `*`           |
| 1       | 0, 1       | `* *`         |
| 2       | 0, 1, 2    | `* * *`       |
| 3       | 0, 1, 2, 3 | `* * * *`     |

---

## C++ Code

```cpp
void printPattern2(int n) {

    // Outer loop: iterates over each ROW (0 to n-1)
    for (int i = 0; i < n; i++) {

        // Inner loop: runs from 0 to i (inclusive)
        // This means: row 0 → 1 star, row 1 → 2 stars, ..., row i → i+1 stars
        for (int j = 0; j <= i; j++) {

            cout << "* "; // Print star inside inner loop
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern2(int n) {

    // Outer loop: iterates over each ROW
    for (int i = 0; i < n; i++) {

        // Inner loop: j goes from 0 to i — creates the increasing triangle
        for (int j = 0; j <= i; j++) {
            System.out.print("* ");
        }

        System.out.println(); // New line after each row
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Number of rows | `n` |
| Stars on row `i` (0-indexed) | `i + 1` |
| Outer loop range | `i = 0` to `i < n` |
| Inner loop range | `j = 0` to `j <= i` |

---

## Key Takeaway

> The **critical connection** between inner and outer loop: the inner loop runs `j <= i`, meaning the number of stars printed equals the current row number + 1. This is the core concept of **Rule 2** — connecting columns to rows.
