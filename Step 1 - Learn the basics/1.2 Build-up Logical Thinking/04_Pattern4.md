# Pattern 4 — Right-Angled Triangle (Row Number Repeated)

[Problem Link](https://www.naukri.com/code360/problems/triangle_6573690?leftPanelTabValue=PROBLEM)

## What It Looks Like

For `n = 5`:
```
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 1` to `i <= n` (1-based indexing).

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 1 → prints `1` one time
- Row 2 → prints `2` two times
- Row 3 → prints `3` three times
- Row 4 → prints `4` four times
- Row 5 → prints `5` five times

Observation: **Row `i` prints the value `i` exactly `i` times.**

Inner loop: `j = 1` to `j <= i`

### Rule 3 — Print Inside Inner Loop
- Print `i` (the **outer** loop variable, NOT `j`) — because the row number is what we repeat.
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed.

---

## Dry Run (n = 4)

| i (row) | j values    | Value printed | Output    |
|---------|------------|---------------|-----------|
| 1       | 1          | 1             | `1`       |
| 2       | 1, 2       | 2             | `2 2`     |
| 3       | 1, 2, 3    | 3             | `3 3 3`   |
| 4       | 1, 2, 3, 4 | 4             | `4 4 4 4` |

---

## C++ Code

```cpp
void printPattern4(int n) {

    // Outer loop: iterates over each ROW (1-based indexing: 1 to n)
    for (int i = 1; i <= n; i++) {

        // Inner loop: runs 'i' times (j = 1 to i)
        // The number of repetitions equals the row number
        for (int j = 1; j <= i; j++) {

            cout << i << " "; // Print 'i' (the row number), NOT 'j'
                               // This is the key difference from Pattern 3
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern4(int n) {

    // Outer loop: each ROW from 1 to n
    for (int i = 1; i <= n; i++) {

        // Inner loop: repeat 'i' times
        for (int j = 1; j <= i; j++) {
            System.out.print(i + " "); // Print row number 'i', not 'j'
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
| Values printed on row `i` | `i` repeated `i` times |
| Outer loop range | `i = 1` to `i <= n` |
| Inner loop range | `j = 1` to `j <= i` |
| What is printed | `i` (outer loop variable — row number) |

---

## Comparison: Patterns 2, 3, and 4

| Pattern | Loop Structure | What's Printed | Example (row 3) |
|---------|---------------|----------------|-----------------|
| Pattern 2 | `j <= i` | `*` | `* * *` |
| Pattern 3 | `j <= i` | `j` | `1 2 3` |
| Pattern 4 | `j <= i` | `i` | `3 3 3` |

> All three share the **same loop structure** — only what's printed changes!

---

## Key Takeaway

> Pattern 4 vs Pattern 3: The loop structure is **identical**. The only change is printing `i` instead of `j`. This shows the power of **Rule 3** — the loop structure (Rules 1 & 2) determines *how many times* to print, while Rule 3 determines *what* to print.
