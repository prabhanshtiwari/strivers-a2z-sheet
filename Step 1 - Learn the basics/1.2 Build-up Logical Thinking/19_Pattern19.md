# Pattern 19 — Hollow Symmetric Rhombus (Open Diamond)

## What It Looks Like

For `n = 5`:
```
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
```

---

## Key Observation Before Starting

> This pattern has **2n total rows** — because the narrowest row (`*        *`) appears **twice**:
> once as the last row of the upper half and once as the first row of the lower half.
> It is split cleanly into an **upper half** and a **lower half**, each running `n` rows (0-indexed: `i = 0` to `n-1`).

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 4 — Observe Symmetry FIRST

The pattern is **vertically symmetric** around its middle:
- **Upper half** (rows 1 to n): stars decrease, spaces increase — the shape "opens up"
- **Lower half** (rows n+1 to 2n): stars increase, spaces decrease — the shape "closes back"

Because of this symmetry, we write **two separate loops** — one for each half.

### Rule 1 — Count the Rows (Outer Loop)
- Each half has **n rows**.
- Both halves use `i = 0` to `i < n` (0-based indexing).
- Total rows printed = `n + n = 2n`.

### Rule 2 — Connect Columns to Rows

Each row has exactly **three parts**: `stars | spaces | stars`

Total width stays constant: `stars + spaces + stars = 2 * n` always.

---

## Upper Half Analysis (i = 0 to n-1)

| `i` | Stars formula `(n - i)` | Spaces formula `(2 * i)` | Row (n=5) |
|-----|------------------------|--------------------------|-----------|
| 0   | 5 - 0 = **5**          | 2 × 0 = **0**            | `**********` |
| 1   | 5 - 1 = **4**          | 2 × 1 = **2**            | `****  ****` |
| 2   | 5 - 2 = **3**          | 2 × 2 = **4**            | `***    ***` |
| 3   | 5 - 3 = **2**          | 2 × 3 = **6**            | `**      **` |
| 4   | 5 - 4 = **1**          | 2 × 4 = **8**            | `*        *` |

**Upper half formulas (0-based `i`):**
- Stars = `n - i` → starts at `n`, decreases by 1 each row
- Spaces = `2 * i` → starts at `0`, increases by 2 each row

**Verification (constant total width):** `(n-i) + 2*i + (n-i)` = `2n - 2i + 2i` = `2n` ✓

---

## Lower Half Analysis (i = 0 to n-1)

| `i` | Stars formula `(i + 1)` | Spaces formula `2*(n-i-1)` | Row (n=5) |
|-----|------------------------|---------------------------|-----------|
| 0   | 0 + 1 = **1**          | 2*(5-0-1) = **8**         | `*        *` |
| 1   | 1 + 1 = **2**          | 2*(5-1-1) = **6**         | `**      **` |
| 2   | 2 + 1 = **3**          | 2*(5-2-1) = **4**         | `***    ***` |
| 3   | 3 + 1 = **4**          | 2*(5-3-1) = **2**         | `****  ****` |
| 4   | 4 + 1 = **5**          | 2*(5-4-1) = **0**         | `**********` |

**Lower half formulas (0-based `i`):**
- Stars = `i + 1` → starts at `1`, increases by 1 each row
- Spaces = `2 * (n - i - 1)` → starts at `2*(n-1)`, decreases by 2 each row

**Verification (constant total width):** `(i+1) + 2*(n-i-1) + (i+1)` = `2i+2 + 2n-2i-2` = `2n` ✓

---

### Rule 3 — Print Inside the Inner Loops

Each half has **three inner loops** per row:
1. Print `stars` number of `*`
2. Print `spaces` number of ` `
3. Print `stars` number of `*` again

Then `endl` after all three loops, before moving to the next row.

---

## C++ Code (Striver's Exact Code — with detailed comments)

```cpp
void printPattern19(int n)
{
    // ===================== UPPER HALF =====================
    // i runs from 0 to n-1 (n rows total in the upper half)
    // As i increases: stars DECREASE, spaces INCREASE → shape opens up

    for (int i = 0; i < n; i++)
    {
        // --- Inner loop 1: Left stars ---
        // Stars = (n - i): n stars on row 0, then n-1, n-2, ... 1
        for (int j = 0; j < n - i; j++)
        {
            cout << "*"; // No space — stars form a solid block on the left
        }

        // --- Inner loop 2: Middle spaces ---
        // Spaces = 2 * i: 0 spaces on row 0, then 2, 4, 6, ... 2*(n-1)
        // Increases by 2 every row → hollow interior widens
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " "; // Hollow interior space
        }

        // --- Inner loop 3: Right stars ---
        // Same count as left stars (n - i) → symmetric around the center
        for (int j = 0; j < n - i; j++)
        {
            cout << "*"; // Mirror of the left side
        }

        cout << endl; // Move to next line after completing this row
    }

    // ===================== LOWER HALF =====================
    // i runs from 0 to n-1 (n rows total in the lower half)
    // As i increases: stars INCREASE, spaces DECREASE → shape closes back
    // The first row of lower half (i=0) prints stars=1, spaces=2*(n-1)
    // which is identical to the last row of the upper half → middle row repeated

    for (int i = 0; i < n; i++)
    {
        // --- Inner loop 1: Left stars ---
        // Stars = (i + 1): 1 star on row 0, then 2, 3, ... n
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*"; // Solid left block — grows each row
        }

        // --- Inner loop 2: Middle spaces ---
        // Spaces = 2 * (n - i - 1): 2*(n-1) on row 0, then ..., 2, 0
        // Decreases by 2 every row → hollow interior narrows
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " "; // Hollow interior space
        }

        // --- Inner loop 3: Right stars ---
        // Same count as left stars (i + 1) → symmetric around the center
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*"; // Mirror of the left side
        }

        cout << endl; // Move to next line after completing this row
    }
}
```

---

## Java Code

```java
static void printPattern19(int n) {

    // ===== UPPER HALF =====
    // stars = n - i (decreasing), spaces = 2 * i (increasing)
    for (int i = 0; i < n; i++) {

        // Left stars (n - i of them)
        for (int j = 0; j < n - i; j++) System.out.print("*");

        // Middle spaces (2*i of them)
        for (int j = 0; j < 2 * i; j++) System.out.print(" ");

        // Right stars (n - i of them, mirror of left)
        for (int j = 0; j < n - i; j++) System.out.print("*");

        System.out.println(); // New line
    }

    // ===== LOWER HALF =====
    // stars = i + 1 (increasing), spaces = 2*(n-i-1) (decreasing)
    for (int i = 0; i < n; i++) {

        // Left stars (i+1 of them)
        for (int j = 0; j < i + 1; j++) System.out.print("*");

        // Middle spaces (2*(n-i-1) of them)
        for (int j = 0; j < 2 * (n - i - 1); j++) System.out.print(" ");

        // Right stars (i+1 of them, mirror of left)
        for (int j = 0; j < i + 1; j++) System.out.print("*");

        System.out.println(); // New line
    }
}
```

---

## Complete Dry Run (n = 5)

### Upper Half (i = 0 to 4)

| `i` | Stars `(n-i)` | Spaces `(2*i)` | Total width | Output |
|-----|--------------|----------------|-------------|--------|
| 0   | 5            | 0              | 5+0+5 = 10  | `**********` |
| 1   | 4            | 2              | 4+2+4 = 10  | `****  ****` |
| 2   | 3            | 4              | 3+4+3 = 10  | `***    ***` |
| 3   | 2            | 6              | 2+6+2 = 10  | `**      **` |
| 4   | 1            | 8              | 1+8+1 = 10  | `*        *` |

### Lower Half (i = 0 to 4)

| `i` | Stars `(i+1)` | Spaces `2*(n-i-1)` | Total width | Output |
|-----|--------------|-------------------|-------------|--------|
| 0   | 1            | 8                 | 1+8+1 = 10  | `*        *` |
| 1   | 2            | 6                 | 2+6+2 = 10  | `**      **` |
| 2   | 3            | 4                 | 3+4+3 = 10  | `***    ***` |
| 3   | 4            | 2                 | 4+2+4 = 10  | `****  ****` |
| 4   | 5            | 0                 | 5+0+5 = 10  | `**********` |

---

## Key Observations

| Property | Value |
|----------|-------|
| Total rows | `2 * n` |
| Rows per half | `n` (both loops: `i = 0` to `i < n`) |
| Upper — Stars formula | `n - i` |
| Upper — Spaces formula | `2 * i` |
| Lower — Stars formula | `i + 1` |
| Lower — Spaces formula | `2 * (n - i - 1)` |
| Total width (every row) | `2 * n` (constant — good sanity check) |
| Middle row repeated? | **YES** — upper's last row = lower's first row |

---

## Why the Middle Row Appears Twice

```
Upper half, last row  (i = n-1):
  stars = n - (n-1) = 1
  spaces = 2*(n-1)
  → *        *

Lower half, first row (i = 0):
  stars = 0 + 1 = 1
  spaces = 2*(n-0-1) = 2*(n-1)
  → *        *
```

Both produce **identical output** → the narrowest row is printed **twice**, giving the pattern `2n` total rows.

---

## Formula Symmetry Insight

| Property | Upper half | Lower half |
|----------|-----------|-----------|
| Loop variable | `i = 0` to `n-1` | `i = 0` to `n-1` |
| Stars | `n - i` (decreasing ↓) | `i + 1` (increasing ↑) |
| Spaces | `2 * i` (increasing ↑) | `2 * (n - i - 1)` (decreasing ↓) |
| Direction | Opens up | Closes back |

Stars and spaces always move in **opposite directions** within each half — when one goes up, the other goes down, keeping total width constant.

---

## Key Takeaway

> Pattern 19 is solved by splitting into two independent halves, each with its own clean 0-based loop (`i = 0` to `n-1`) and its own pair of formulas. The elegance lies in the **simplicity of each formula**: upper half uses `n-i` and `2*i`; lower half uses `i+1` and `2*(n-i-1)`. Three inner loops per row handle the three parts (left stars, spaces, right stars). The constant total width `2n` serves as a built-in correctness check for every row.
