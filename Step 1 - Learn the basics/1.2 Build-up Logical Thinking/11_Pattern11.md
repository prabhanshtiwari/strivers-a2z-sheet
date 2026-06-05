# Pattern 11 — Binary Triangle (0-1 Alternating Pattern)

## What It Looks Like

For `n = 5`:
```
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 1` to `i <= n` (1-based indexing).

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 1 → 1 element
- Row 2 → 2 elements
- Row 3 → 3 elements
- ...
- Row i → i elements

This is the same structure as Pattern 2 (right angle triangle).
Inner loop: `j = 1` to `j <= i`

### Rule 3 — Print Inside Inner Loop
- This is where the **key observation** comes in.
- Values alternate between 0 and 1 within each row.
- But the starting value on each row depends on the **row parity**:
  - Odd rows (1, 3, 5, ...) → start with `1`
  - Even rows (2, 4, ...) → start with `0`

**The Flip Trick:**
- Maintain a variable `start` that holds the current value to print.
- After each print, flip it: `start = 1 - start`
  - `1 - 1 = 0` (flips 1 to 0)
  - `1 - 0 = 1` (flips 0 to 1)

**Setting the initial `start` for each row:**
```
If row i is even → start = 0
If row i is odd  → start = 1
```

### Rule 4 — Symmetry?
- No cross-row symmetry needed; the alternation handles itself.

---

## Dry Run (n = 5)

| i (row) | Start | Values printed |
|---------|-------|----------------|
| 1 (odd) | 1 | `1` |
| 2 (even) | 0 | `0 1` |
| 3 (odd) | 1 | `1 0 1` |
| 4 (even) | 0 | `0 1 0 1` |
| 5 (odd) | 1 | `1 0 1 0 1` |

---

## C++ Code

```cpp
void printPattern11(int n) {

    // Outer loop: iterates over each ROW (1-based: 1 to n)
    for (int i = 1; i <= n; i++) {

        // Determine the starting value for this row
        // Even row → start with 0; Odd row → start with 1
        int start;
        if (i % 2 == 0) {
            start = 0; // Even rows begin with 0
        } else {
            start = 1; // Odd rows begin with 1
        }

        // Inner loop: runs 'i' times (right-angle triangle structure)
        for (int j = 1; j <= i; j++) {

            cout << start << " "; // Print current value (0 or 1)

            // Flip the value for next iteration
            // 1 - 1 = 0, and 1 - 0 = 1 → elegant flip trick
            start = 1 - start;
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern11(int n) {

    // Outer loop: each ROW from 1 to n
    for (int i = 1; i <= n; i++) {

        // Set starting value based on row parity
        int start = (i % 2 == 0) ? 0 : 1;

        // Inner loop: i elements per row
        for (int j = 1; j <= i; j++) {
            System.out.print(start + " "); // Print current bit

            start = 1 - start; // Flip: 0→1 or 1→0
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
| Elements on row `i` | `i` (same as Pattern 2) |
| Outer loop | `i = 1` to `i <= n` |
| Inner loop | `j = 1` to `j <= i` |
| Starting value | `1` if i is odd, `0` if i is even |
| Flip formula | `start = 1 - start` |

---

## The Flip Trick Explained

```
start = 1 - start;

If start = 1:  1 - 1 = 0  (flips to 0)
If start = 0:  1 - 0 = 1  (flips to 1)
```

This is a classic **bit-flip** trick. You could also write:
```cpp
start ^= 1; // XOR with 1 also flips 0 and 1
```

---

## Key Takeaway

> Pattern 11 builds on the right-angle triangle structure (Pattern 2) but adds a **stateful printing mechanism** — the `start` variable maintains state between iterations and gets flipped after each print. The key insights are:
> 1. Same loop structure as Pattern 2
> 2. Starting value depends on row parity (odd/even row)
> 3. The elegant flip: `start = 1 - start`
