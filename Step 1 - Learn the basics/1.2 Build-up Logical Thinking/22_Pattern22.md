# Pattern 22 — Number Matrix (Distance-Based Border Numbers)

## What It Looks Like

For `n = 4`:
```
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- Total rows = `2n - 1` = 7 for n=4.
- Total columns = `2n - 1` = 7 for n=4.
- Outer loop: `i = 0` to `i < 2*n - 1`.

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Inner loop also: `j = 0` to `j < 2*n - 1`.

### Rule 3 — What to Print

**Key Insight:** Each cell value = `n - min(distance from all 4 borders)`

For each cell at position `(i, j)` in a `(2n-1) × (2n-1)` grid:
- The last index = `2n - 2`

**Compute 4 distances:**
1. **Top distance** = `i` (distance from top row)
2. **Left distance** = `j` (distance from left column)
3. **Bottom distance** = `(2n - 2) - i` (distance from bottom row)
4. **Right distance** = `(2n - 2) - j` (distance from right column)

**Minimum distance** = `min(top, left, bottom, right)`

**Cell value** = `n - minimum_distance`

### Why This Works

Think of the matrix as concentric frames. The outermost frame has value `n`, the next inner frame has `n-1`, and so on, with the center having value `1`.

The **minimum distance from any border** tells you how "deep" inside the matrix you are. Subtracting that from `n` gives the value.

---

## Verification (n = 4, grid is 7×7)

Grid positions (0-indexed), last index = 6.

**Center cell `(3, 3)`:**
- Top = 3, Left = 3, Bottom = 6-3 = 3, Right = 6-3 = 3
- min = 3
- Value = 4 - 3 = 1 ✓ (center)

**Corner cell `(0, 0)`:**
- Top = 0, Left = 0, Bottom = 6, Right = 6
- min = 0
- Value = 4 - 0 = 4 ✓ (outermost border)

**Cell `(1, 3)`:**
- Top = 1, Left = 3, Bottom = 5, Right = 3
- min = 1
- Value = 4 - 1 = 3 ✓

---

## Step-by-Step Formula Derivation

```
Matrix size: (2n-1) × (2n-1)
Last index: (2n-1-1) = (2n-2)

For cell (i, j):
  top    = i
  left   = j
  bottom = (2n-2) - i
  right  = (2n-2) - j

  min_dist = min(min(top, bottom), min(left, right))
  value    = n - min_dist
```

---

## C++ Code

```cpp
void printPattern22(int n) {

    // Grid dimensions: (2n-1) × (2n-1)
    // Last valid index: (2n-2)
    int lastIndex = 2 * n - 2;

    // Outer loop: iterates over each ROW
    for (int i = 0; i <= lastIndex; i++) {

        // Inner loop: iterates over each COLUMN
        for (int j = 0; j <= lastIndex; j++) {

            // Compute distance from each of the 4 borders
            int top    = i;             // Distance from the top border
            int left   = j;             // Distance from the left border
            int bottom = lastIndex - i; // Distance from the bottom border
            int right  = lastIndex - j; // Distance from the right border

            // Find the MINIMUM of all 4 distances
            // min() in C++ takes only 2 args, so we nest them
            int minDist = min(min(top, bottom), min(left, right));

            // Cell value = n - minimum distance
            // Outermost cells (min=0) get value n
            // Center cell (min = n-1) gets value 1
            cout << n - minDist << " ";
        }

        cout << endl; // Move to next line after each row
    }
}
```

---

## Java Code

```java
static void printPattern22(int n) {

    int lastIndex = 2 * n - 2; // Last row/column index

    // Outer loop: each ROW
    for (int i = 0; i <= lastIndex; i++) {

        // Inner loop: each COLUMN
        for (int j = 0; j <= lastIndex; j++) {

            // Distance from each border
            int top    = i;
            int left   = j;
            int bottom = lastIndex - i;
            int right  = lastIndex - j;

            // Minimum distance from any border
            int minDist = Math.min(Math.min(top, bottom), Math.min(left, right));

            // Print the value
            System.out.print((n - minDist) + " ");
        }

        System.out.println(); // New line
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Grid size | `(2n-1) × (2n-1)` |
| Last index | `2n - 2` |
| Outer loop | `i = 0` to `i <= 2n-2` |
| Inner loop | `j = 0` to `j <= 2n-2` |
| Cell value formula | `n - min(top, left, bottom, right)` |

---

## Alternative Mental Model: "Onion Layers"

Think of the matrix like concentric rings of an onion:
```
Outermost ring → value n   (0 steps from border)
Next ring      → value n-1 (1 step from border)
...
Center         → value 1   (n-1 steps from border)
```

The minimum distance tells you exactly which "ring" you're in.

---

## The Smart Shortcut (Mentioned in Lecture)

The lecturer also described a **two-step approach**:
1. Subtract `n` from every value to get an intermediate matrix with values like 0, 1, 2...
2. Use the intermediate matrix to compute cell values.
3. Then `current_value = n - intermediate_value`.

This is equivalent to the direct formula `n - minDist`.

---

## Key Takeaway

> Pattern 22 is the most mathematically sophisticated pattern. The key insight is the **minimum distance from 4 borders** formula. This is a classic 2D matrix problem technique — computing the "depth" of each cell from the nearest edge. This exact concept appears in DSA problems like finding the largest rectangle in a histogram, spiral matrices, and more. Mastering this formula is genuinely useful for DSA.
