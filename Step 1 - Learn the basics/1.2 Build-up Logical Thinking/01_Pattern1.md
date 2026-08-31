# Pattern 1 — Solid Rectangle of Stars

[Problem Link](https://www.naukri.com/code360/problems/n-forest_6570177)

## What It Looks Like

For `n = 4`:
```
* * * *
* * * *
* * * *
* * * *
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **4 rows** (for n=4).
- Outer loop runs from `i = 0` to `i < n`.

### Rule 2 — Connect Columns to Rows (Inner Loop)
- On **every single row**, we print exactly **4 stars** (= n stars).
- The number of columns does NOT change with the row.
- So the inner loop also runs from `j = 0` to `j < n` (no dependency on `i`).

### Rule 3 — Print Inside Inner Loop
- Print `*` (with a space) inside the inner loop.
- Print `endl` after the inner loop to move to the next row.

### Rule 4 — Symmetry?
- No symmetry needed here. Simple uniform grid.

---

## Dry Run (n = 4)

| i (row) | j values         | Output        |
|---------|-----------------|---------------|
| 0       | 0, 1, 2, 3      | `* * * *`     |
| 1       | 0, 1, 2, 3      | `* * * *`     |
| 2       | 0, 1, 2, 3      | `* * * *`     |
| 3       | 0, 1, 2, 3      | `* * * *`     |

---

## C++ Code

```cpp
void printPattern1(int n) {

    // Outer loop: iterates over each ROW (0 to n-1)
    for (int i = 0; i < n; i++) {

        // Inner loop: iterates over each COLUMN (always 0 to n-1)
        // Note: inner loop count does NOT depend on 'i' here
        for (int j = 0; j < n; j++) {

            cout << "* "; // Print a star with a space inside inner loop
        }

        cout << endl; // After completing one full row, move to next line
    }
}
```

---

## Java Code

```java
static void printPattern1(int n) {

    // Outer loop: iterates over each ROW
    for (int i = 0; i < n; i++) {

        // Inner loop: iterates over each COLUMN
        for (int j = 0; j < n; j++) {
            System.out.print("* "); // Print star inside inner loop
        }

        System.out.println(); // Move to next line after each row
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Number of rows | `n` |
| Number of columns per row | `n` (constant, no dependency on row) |
| What's printed | `*` (star) |
| Outer loop range | `i = 0` to `i < n` |
| Inner loop range | `j = 0` to `j < n` |

---

## Key Takeaway

> This is the **simplest** pattern. Both loops run the same number of times (`n`), and the inner loop has **no dependency on the outer loop variable `i`**. This is the only pattern where the column count is completely independent of the row count.
