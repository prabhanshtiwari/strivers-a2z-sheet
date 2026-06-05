# Pattern 6 — Inverted Right-Angled Triangle (Numbers, Decreasing)

## What It Looks Like

For `n = 5`:
```
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 1` to `i <= n`.

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 1 → prints `1 2 3 4 5` (5 numbers)
- Row 2 → prints `1 2 3 4` (4 numbers)
- Row 3 → prints `1 2 3` (3 numbers)
- Row 4 → prints `1 2` (2 numbers)
- Row 5 → prints `1` (1 number)

Observation: **Row `i` prints numbers from 1 to `n - i + 1`.**

Inner loop: `j = 1` to `j <= n - i + 1`

### Rule 3 — Print Inside Inner Loop
- Print `j` (the inner loop variable) — gives 1, 2, 3...
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed.

---

## Dry Run (n = 4)

| i (row) | j range | Output      |
|---------|---------|-------------|
| 1       | 1 to 4  | `1 2 3 4`   |
| 2       | 1 to 3  | `1 2 3`     |
| 3       | 1 to 2  | `1 2`       |
| 4       | 1 to 1  | `1`         |

---

## C++ Code

```cpp
void printPattern6(int n) {

    // Outer loop: iterates over each ROW (1-based: 1 to n)
    for (int i = 1; i <= n; i++) {

        // Inner loop: j goes from 1 to (n - i + 1)
        // This means the count decreases by 1 each row
        // Row 1: j goes 1 to n    (prints n numbers)
        // Row 2: j goes 1 to n-1  (prints n-1 numbers)
        // Row n: j goes 1 to 1    (prints just 1)
        for (int j = 1; j <= n - i + 1; j++) {

            cout << j << " "; // Print j — the incrementing number (1, 2, 3...)
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern6(int n) {

    // Outer loop: each ROW from 1 to n
    for (int i = 1; i <= n; i++) {

        // Inner loop: decreasing count, always starting from 1
        for (int j = 1; j <= n - i + 1; j++) {
            System.out.print(j + " ");
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
| Numbers on row `i` | `1` to `n - i + 1` |
| Outer loop range | `i = 1` to `i <= n` |
| Inner loop range | `j = 1` to `j <= n - i + 1` |
| What is printed | `j` (inner loop variable, always starts at 1) |

---

## Comparison: Patterns 5 and 6

| Feature | Pattern 5 | Pattern 6 |
|---------|-----------|-----------|
| Loop structure | Same | Same |
| What's printed | `*` (star) | `j` (number 1..count) |
| Example row 1 | `* * * * *` | `1 2 3 4 5` |

---

## Key Takeaway

> Pattern 6 is to Pattern 5 what Pattern 3 is to Pattern 2 — the **same loop structure**, but instead of printing stars, we print the value of `j`. The decreasing formula `n - i + 1` remains the same; only the print statement changes.
