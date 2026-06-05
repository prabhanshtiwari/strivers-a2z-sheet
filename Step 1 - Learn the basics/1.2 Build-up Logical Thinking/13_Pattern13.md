# Pattern 13 — Continuous Number Right Triangle

## What It Looks Like

For `n = 5`:
```
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 1` to `i <= n`.

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 1 → 1 number
- Row 2 → 2 numbers
- Row 3 → 3 numbers
- ...
- Row i → i numbers

This is the same triangle structure as Pattern 2.
Inner loop: `j = 1` to `j <= i`

### Rule 3 — Print Inside Inner Loop
- This is where the key difference lies: numbers are **continuous** across rows.
- They don't reset to 1 each row — they keep incrementing globally.
- Solution: maintain a counter variable `num` initialized to 1, increment after each print.

### Rule 4 — Symmetry?
- No symmetry needed.

---

## Dry Run (n = 4)

| i (row) | j values | num values printed | Output |
|---------|---------|-------------------|--------|
| 1 | 1 | 1 | `1` |
| 2 | 1, 2 | 2, 3 | `2 3` |
| 3 | 1, 2, 3 | 4, 5, 6 | `4 5 6` |
| 4 | 1, 2, 3, 4 | 7, 8, 9, 10 | `7 8 9 10` |

---

## C++ Code

```cpp
void printPattern13(int n) {

    // 'num' is a counter that continuously increments across ALL rows
    // It does NOT reset to 1 at the start of each row
    int num = 1;

    // Outer loop: iterates over each ROW (1-based: 1 to n)
    for (int i = 1; i <= n; i++) {

        // Inner loop: runs 'i' times for row 'i'
        // (same structure as Pattern 2 — right angle triangle)
        for (int j = 1; j <= i; j++) {

            cout << num << " "; // Print current value of num

            num++; // Increment the global counter — moves to next number
                   // This counter does NOT reset between rows!
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern13(int n) {

    int num = 1; // Continuous counter across all rows

    // Outer loop: each ROW from 1 to n
    for (int i = 1; i <= n; i++) {

        // Inner loop: i elements per row
        for (int j = 1; j <= i; j++) {
            System.out.print(num + " "); // Print and increment
            num++;
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
| Elements on row `i` | `i` |
| Outer loop | `i = 1` to `i <= n` |
| Inner loop | `j = 1` to `j <= i` |
| What is printed | `num` (a continuously increasing counter) |
| `num` scope | **Outside** both loops — persists across rows |

---

## Critical Difference from Pattern 3

| Feature | Pattern 3 | Pattern 13 |
|---------|-----------|-----------|
| Loop structure | Same | Same |
| Counter variable | `j` (resets each row) | `num` (never resets) |
| Row 2 output | `1 2` | `2 3` |
| Row 3 output | `1 2 3` | `4 5 6` |

---

## Where `num` is Declared Matters!

```cpp
// WRONG: num resets to 1 at the start of every row
for (int i = 1; i <= n; i++) {
    int num = 1; // ← declared INSIDE outer loop → resets each row
    ...
}

// CORRECT: num persists across rows
int num = 1; // ← declared OUTSIDE outer loop → never resets
for (int i = 1; i <= n; i++) {
    ...
}
```

---

## Key Takeaway

> The critical insight in Pattern 13 is **scope of the counter variable**. By declaring `num` **outside** the outer loop, it persists across rows, giving us the continuous number sequence. This is a fundamental concept: variables declared outside loops maintain state, while variables declared inside loops reset each iteration.
