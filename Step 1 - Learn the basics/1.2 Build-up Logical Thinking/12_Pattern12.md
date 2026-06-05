# Pattern 12 — Number Butterfly / Symmetric Number Triangle

## What It Looks Like

For `n = 4`:
```
1      1
12    21
123  321
12344321
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **4 rows** (for n=4).
- Outer loop runs from `i = 1` to `i <= n`.

### Rule 2 — Connect Columns to Rows
Each row has three parts:
1. **Left numbers** (ascending): `1, 2, ..., i`
2. **Middle spaces**: decreasing count
3. **Right numbers** (descending): `i, i-1, ..., 1`

**Analyzing the spaces:**

| Row i | Spaces |
|-------|--------|
| 1     | 6 |
| 2     | 4 |
| 3     | 2 |
| 4     | 0 |

**Formula for spaces:** `2 * (n - 1)` starts at `2*(n-1)` and decreases by 2 each row.

Or: Initial spaces = `2 * (n - 1)`, then subtract 2 after each row.

Alternatively: spaces = `2 * (n - i)`
- i=1: 2*(4-1) = 6 ✓
- i=2: 2*(4-2) = 4 ✓
- i=4: 2*(4-4) = 0 ✓

### Rule 3 — Print Inside Inner Loops
Three separate inner loops:
1. Print `j` from 1 to `i` (ascending numbers)
2. Print spaces (decreasing count per row)
3. Print `j` from `i` down to 1 (descending numbers)

---

## Dry Run (n = 4)

| i | Left side | Spaces | Right side |
|---|-----------|--------|------------|
| 1 | `1` | 6 spaces | `1` |
| 2 | `1 2` | 4 spaces | `2 1` |
| 3 | `1 2 3` | 2 spaces | `3 2 1` |
| 4 | `1 2 3 4` | 0 spaces | `4 3 2 1` |

---

## C++ Code

```cpp
void printPattern12(int n) {

    // Calculate initial spaces: 2*(n-1)
    // This will decrease by 2 after each row
    int spaces = 2 * (n - 1);

    // Outer loop: iterates over each ROW (1-based: 1 to n)
    for (int i = 1; i <= n; i++) {

        // --- PART 1: Print ascending numbers (left side) ---
        // Goes from 1 to i → e.g., row 3: prints 1 2 3
        for (int j = 1; j <= i; j++) {
            cout << j; // Print number without trailing space (managed carefully)
        }

        // --- PART 2: Print middle spaces ---
        // Number of spaces = 2*(n-i), decreases by 2 each row
        for (int j = 1; j <= spaces; j++) {
            cout << " "; // Print a space
        }

        // --- PART 3: Print descending numbers (right side) ---
        // Goes from i down to 1 → e.g., row 3: prints 3 2 1
        for (int j = i; j >= 1; j--) {
            cout << j; // Print number in reverse order
        }

        cout << endl; // Move to next line after completing current row

        // Reduce spaces by 2 for the next row
        spaces -= 2;
    }
}
```
---

## C++ Code (Interview Preferred)

```cpp
void printPattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Left half: 1 to i
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // Middle spaces
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }

        // Right half: i to 1
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }
}
```

---

## Java Code

```java
static void printPattern12(int n) {

    int spaces = 2 * (n - 1); // Initial spaces formula

    // Outer loop: each ROW from 1 to n
    for (int i = 1; i <= n; i++) {

        // Part 1: Ascending numbers (1 to i)
        for (int j = 1; j <= i; j++) {
            System.out.print(j);
        }

        // Part 2: Middle spaces (2*(n-i) spaces)
        for (int j = 1; j <= spaces; j++) {
            System.out.print(" ");
        }

        // Part 3: Descending numbers (i down to 1)
        for (int j = i; j >= 1; j--) {
            System.out.print(j);
        }

        System.out.println(); // New line

        spaces -= 2; // Reduce spaces by 2 each row
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Number of rows | `n` |
| Left numbers on row `i` | `1, 2, ..., i` |
| Spaces on row `i` | `2 * (n - i)` |
| Right numbers on row `i` | `i, i-1, ..., 1` |
| Outer loop | `i = 1` to `i <= n` |

---

## Alternative Formula for Spaces

Instead of maintaining a `spaces` variable, you can compute directly:
```cpp
int numSpaces = 2 * (n - i); // For row i (1-indexed)
```

Both approaches produce the same result.

---

## Key Takeaway

> Pattern 12 requires **three inner loops** per row. The challenge is computing the space count. Two approaches work:
> 1. **Track a variable** (`spaces`) and decrement it by 2 each row.
> 2. **Direct formula**: `2 * (n - i)`.
> The descending right side (`j--`) is a simple variation of the ascending left side (`j++`).
