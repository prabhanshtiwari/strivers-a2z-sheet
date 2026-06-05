# Pattern 5 — Inverted Right-Angled Triangle (Stars, Decreasing)

## What It Looks Like

For `n = 5`:
```
* * * * *
* * * *
* * *
* *
*
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 1` to `i <= n`.

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 1 → 5 stars
- Row 2 → 4 stars
- Row 3 → 3 stars
- Row 4 → 2 stars
- Row 5 → 1 star

Observation: **Row `i` prints `n - i + 1` stars.**

Derivation of formula:
- Row 1: `5 - 1 + 1 = 5` ✓
- Row 2: `5 - 2 + 1 = 4` ✓
- Row 3: `5 - 3 + 1 = 3` ✓
- Row 5: `5 - 5 + 1 = 1` ✓

Inner loop: `j = 0` to `j < n - i + 1`

### Rule 3 — Print Inside Inner Loop
- Print `*` inside the inner loop.
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed (this is the inverted version of Pattern 2).

---

## Dry Run (n = 5, 1-based)

| i (row) | Formula: `n-i+1` | Stars |
|---------|-----------------|-------|
| 1       | 5-1+1 = 5       | `* * * * *` |
| 2       | 5-2+1 = 4       | `* * * *`   |
| 3       | 5-3+1 = 3       | `* * *`     |
| 4       | 5-4+1 = 2       | `* *`       |
| 5       | 5-5+1 = 1       | `*`         |

---

## C++ Code (1-based indexing)

```cpp
void printPattern5(int n) {

    // Outer loop: iterates over each ROW (1-based: 1 to n)
    for (int i = 1; i <= n; i++) {

        // Inner loop: runs for (n - i + 1) times
        // When i=1 (first row): runs n times (most stars)
        // When i=n (last row):  runs 1 time  (fewest stars)
        // Formula derivation: total rows = n, current row = i
        //   → stars = n - i + 1
        for (int j = 0; j < n - i + 1; j++) {

            cout << "* "; // Print star inside inner loop
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

## C++ Code (0-based indexing — alternative)

```cpp
void printPattern5(int n) {

    // Outer loop: 0-based indexing (i = 0 to n-1)
    for (int i = 0; i < n; i++) {

        // Inner loop: runs for (n - i) times
        // When i=0 (first row): runs n times
        // When i=n-1 (last row): runs 1 time
        for (int j = 0; j < n - i; j++) {

            cout << "* "; // Print star
        }

        cout << endl; // New line
    }
}
```

---

## Java Code

```java
static void printPattern5(int n) {

    // Outer loop: each ROW from 1 to n
    for (int i = 1; i <= n; i++) {

        // Inner loop: decreasing number of stars
        // Stars on row i = n - i + 1
        for (int j = 0; j < n - i + 1; j++) {
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
| Number of rows | `n` |
| Stars on row `i` (1-indexed) | `n - i + 1` |
| Stars on row `i` (0-indexed) | `n - i` |
| Outer loop range | `i = 1` to `i <= n` |
| Inner loop range | `j = 0` to `j < n - i + 1` |

---

## Pattern 2 vs Pattern 5 (Mirror Relationship)

| Property | Pattern 2 (Increasing) | Pattern 5 (Decreasing) |
|----------|----------------------|----------------------|
| Row 1 | 1 star | n stars |
| Row n | n stars | 1 star |
| Formula | `j <= i` | `j < n - i + 1` |
| Direction | Bottom-heavy | Top-heavy |

---

## Key Takeaway

> Pattern 5 is the **vertical flip** of Pattern 2. The trick is to derive the correct formula: `n - i + 1`. Start by looking at how many columns each row has, then find the mathematical relationship with the row number `i`.
