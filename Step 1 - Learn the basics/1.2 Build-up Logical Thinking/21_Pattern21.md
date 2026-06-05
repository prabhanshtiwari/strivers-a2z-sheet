# Pattern 21 — Hollow Rectangle / Square Border

## What It Looks Like

For `n = 5`:
```
* * * * *
*       *
*       *
*       *
* * * * *
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **n rows** and **n columns** (for n=5: 5×5 grid).
- Outer loop: `i = 0` to `i < n`.

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Inner loop always runs **n times**: `j = 0` to `j < n`.

### Rule 3 — Print Inside Inner Loop
**Key observation:** We only print `*` when we're at a **boundary position**.

**Boundary conditions:**
- `i == 0` → first row (top border) → all stars
- `i == n-1` → last row (bottom border) → all stars
- `j == 0` → first column (left border) → star
- `j == n-1` → last column (right border) → star

If **none** of these are true → the cell is in the interior → print a **space**.

```
Boundary → print '*'
Interior → print ' '
```

### Rule 4 — Symmetry?
- The rectangle has 4-fold symmetry (top/bottom, left/right borders), but we handle it all with simple boundary conditions — no special symmetry logic needed.

---

## Index Grid Visualization (n = 4)

```
     j=0  j=1  j=2  j=3
i=0:  *    *    *    *      ← first row, all stars
i=1:  *    ' '  ' '  *     ← middle rows, only j=0 and j=n-1 are stars
i=2:  *    ' '  ' '  *
i=3:  *    *    *    *      ← last row, all stars
```

---

## Dry Run Logic (n = 4)

For any cell `(i, j)`, print `*` if:
```
i == 0          →  top border
i == n-1        →  bottom border
j == 0          →  left border
j == n-1        →  right border
```

Otherwise, print a space `' '`.

---

## C++ Code

```cpp
void printPattern21(int n) {

    // Outer loop: iterates over each ROW (0-based: 0 to n-1)
    for (int i = 0; i < n; i++) {

        // Inner loop: iterates over each COLUMN (0-based: 0 to n-1)
        for (int j = 0; j < n; j++) {

            // Check if current position (i, j) is on any border
            if (i == 0       // Top border (first row)
             || i == n - 1   // Bottom border (last row)
             || j == 0       // Left border (first column)
             || j == n - 1)  // Right border (last column)
            {
                cout << "* "; // On the border → print star
            } else {
                cout << "  "; // Interior position → print space (with padding)
            }
        }

        cout << endl; // Move to next line after each row
    }
}
```

---

## Java Code

```java
static void printPattern21(int n) {

    // Outer loop: each ROW
    for (int i = 0; i < n; i++) {

        // Inner loop: each COLUMN
        for (int j = 0; j < n; j++) {

            // Boundary check: print star if on any edge
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                System.out.print("* ");
            } else {
                System.out.print("  "); // Interior: two spaces for alignment
            }
        }

        System.out.println(); // New line
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Total rows | `n` |
| Total columns | `n` |
| Outer loop | `i = 0` to `i < n` |
| Inner loop | `j = 0` to `j < n` |
| Print `*` when | `i==0` OR `i==n-1` OR `j==0` OR `j==n-1` |
| Print ` ` when | none of the above conditions are true |

---

## Key Concept: Boundary Conditions

This pattern introduces a **conditional print** inside the inner loop — instead of always printing the same thing, we decide what to print based on the position `(i, j)`.

```cpp
// Decision logic:
if (on boundary) → '*'
else             → ' '
```

This technique (using boundary conditions) is fundamental in:
- Matrix problems in DSA
- Spiral matrix
- Rotating matrices
- Flood fill algorithms

---

## Key Takeaway

> Pattern 21 is the first pattern where the **print decision depends on the position** `(i, j)`. The condition `i==0 || i==n-1 || j==0 || j==n-1` elegantly captures all four borders of the rectangle. This concept — checking boundary conditions in a 2D grid — is a **cornerstone technique** in DSA matrix problems.
