# Pattern 3 — Right-Angled Triangle (Numbers 1 to Row Number)

## What It Looks Like

For `n = 5`:
```
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 1` to `i <= n` (1-based indexing used here).

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 1 → prints `1`
- Row 2 → prints `1 2`
- Row 3 → prints `1 2 3`
- Row 4 → prints `1 2 3 4`
- Row 5 → prints `1 2 3 4 5`

Observation: **Each row prints numbers from 1 up to the current row number.**

Inner loop: `j = 1` to `j <= i`

### Rule 3 — Print Inside Inner Loop
- Print `j` (the inner loop variable itself) — it naturally gives us 1, 2, 3...
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed.

---

## Dry Run (n = 4, one-based)

| i (row) | j values    | Output        |
|---------|------------|---------------|
| 1       | 1          | `1`           |
| 2       | 1, 2       | `1 2`         |
| 3       | 1, 2, 3    | `1 2 3`       |
| 4       | 1, 2, 3, 4 | `1 2 3 4`     |

---

## C++ Code

```cpp
void printPattern3(int n) {

    // Outer loop: iterates over each ROW (1-based indexing: 1 to n)
    for (int i = 1; i <= n; i++) {

        // Inner loop: j goes from 1 to i
        // j itself is the value we want to print (1, 2, 3, ... up to i)
        for (int j = 1; j <= i; j++) {

            cout << j << " "; // Print j (the column number) — gives 1, 2, 3...
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern3(int n) {

    // Outer loop: each ROW from 1 to n
    for (int i = 1; i <= n; i++) {

        // Inner loop: print numbers from 1 to i
        for (int j = 1; j <= i; j++) {
            System.out.print(j + " "); // j is the printed value
        }

        System.out.println(); // New line
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Number of rows | `n` |
| Values printed on row `i` | `1, 2, 3, ..., i` |
| Outer loop range | `i = 1` to `i <= n` |
| Inner loop range | `j = 1` to `j <= i` |
| What is printed | `j` (inner loop variable itself) |

---

## Difference from Pattern 2

| Feature | Pattern 2 | Pattern 3 |
|---------|-----------|-----------|
| Printed value | `*` (always same) | `j` (1, 2, 3...) |
| Loop structure | Same | Same |

---

## Key Takeaway

> The difference from Pattern 2 is simply **what we print**. Instead of a star, we print `j` — the inner loop variable itself. This naturally produces the sequence `1, 2, 3, ...` up to the row number. This is a great example of how **Rule 3** (print what you need inside the inner loop) changes everything while the loop structure stays the same.
