# Pattern 16 — Alphabet Triangle (Same Letter Per Row)

## What It Looks Like

For `n = 5`:
```
A
B B
C C C
D D D D
E E E E E
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 0` to `i < n` (0-based).

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 0 → 1 character
- Row 1 → 2 characters
- Row 2 → 3 characters
- Row i → (i+1) characters

Same right triangle structure: inner loop runs `i+1` times.
Inner loop: `j = 0` to `j <= i`

### Rule 3 — Print Inside Inner Loop
- On row `i`, the **same** character is repeated.
- The character for row `i` is `'A' + i`.
  - Row 0: `'A' + 0 = 'A'` → prints `A`
  - Row 1: `'A' + 1 = 'B'` → prints `B B`
  - Row 2: `'A' + 2 = 'C'` → prints `C C C`
- Print `'A' + i` inside the inner loop.
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed.

---

## Dry Run (n = 5, 0-based)

| i | Character (`'A'+i`) | Count (i+1) | Output |
|---|--------------------|-----------  |--------|
| 0 | A | 1 | `A` |
| 1 | B | 2 | `B B` |
| 2 | C | 3 | `C C C` |
| 3 | D | 4 | `D D D D` |
| 4 | E | 5 | `E E E E E` |

---

## C++ Code

```cpp
void printPattern16(int n) {

    // Outer loop: iterates over each ROW (0-based: 0 to n-1)
    for (int i = 0; i < n; i++) {

        // Compute the character for this entire row
        // Row 0 → 'A', Row 1 → 'B', ..., Row i → 'A' + i
        char ch = 'A' + i;

        // Inner loop: runs (i+1) times — right angle triangle structure
        // All elements in this row are the SAME character (ch)
        for (int j = 0; j <= i; j++) {

            cout << ch << " "; // Print the row's character (same throughout the row)
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern16(int n) {

    // Outer loop: each ROW from 0 to n-1
    for (int i = 0; i < n; i++) {

        char ch = (char)('A' + i); // Character for this row

        // Inner loop: same character repeated (i+1) times
        for (int j = 0; j <= i; j++) {
            System.out.print(ch + " "); // Same char for entire row
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
| Character on row `i` (0-indexed) | `'A' + i` |
| Repetitions on row `i` | `i + 1` |
| Outer loop | `i = 0` to `i < n` |
| Inner loop | `j = 0` to `j <= i` |

---

## Comparison: Patterns 4, 14, and 16

| Feature | Pattern 4 | Pattern 14 | Pattern 16 |
|---------|-----------|-----------|-----------|
| What's printed | Row number `i` | Incrementing char `ch++` | Same char `'A'+i` |
| Row 3 example | `3 3 3` | `A B C` | `C C C` |
| Key variable | `i` (outer) | `ch` (inner, incrementing) | `'A' + i` (constant within row) |

---

## Key Takeaway

> Pattern 16 is the alphabet equivalent of Pattern 4. In Pattern 4, we printed the row number `i` repeatedly. Here, we print the character `'A' + i` repeatedly. The loop structure is identical — only the print expression changes. This highlights how **one formula change** can produce an entirely different visual pattern.
