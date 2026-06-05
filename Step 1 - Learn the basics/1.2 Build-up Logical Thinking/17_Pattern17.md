# Pattern 17 — Alphabet Pyramid (A at center, expanding)

## What It Looks Like

For `n = 5`:
```
    A
   A B A
  A B C B A
 A B C D C B A
A B C D E D C B A
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 0` to `i < n`.

### Rule 2 — Connect Columns to Rows (Three Inner Loops)
Same structure as Pattern 7 (Star Pyramid) — three parts per row:
1. **Leading spaces**: `n - i - 1` spaces
2. **Characters**: `2*i + 1` total characters (with symmetry)
3. (Trailing spaces — not needed for this visual)

**From Pattern 7**, we know:
- Spaces = `n - i - 1`
- Total characters = `2 * i + 1`

### Rule 3 — Print Inside Inner Loops

#### The Character Symmetry Challenge

For `i = 2` (row 2): `A B C B A` (5 characters)
- Characters: A → B → C → B → A (goes up then comes back down)
- The **midpoint** is at character index `(2*i+1) / 2 + 1 = i + 1`

**Strategy:** Use a character variable `ch` that:
- Increments (`ch++`) for the first half of the row
- Decrements (`ch--`) for the second half

**Breakpoint** (where to switch from `++` to `--`):
- Total chars = `2*i + 1`
- Half = `(2*i + 1) / 2` = `i` (integer division)
- So for `j` from 1 to `(2*i+1)`: if `j <= i + 1` → increment, else decrement

### Rule 4 — Symmetry?
- **YES!** Each row is symmetric around its middle character.
- The middle character is `'A' + i` (the highest character on that row).

---

## Dry Run (n = 5, 0-based)

| i | Spaces | Total chars | Characters |
|---|--------|------------|------------|
| 0 | 4 | 1 | `A` |
| 1 | 3 | 3 | `A B A` |
| 2 | 2 | 5 | `A B C B A` |
| 3 | 1 | 7 | `A B C D C B A` |
| 4 | 0 | 9 | `A B C D E D C B A` |

---

## C++ Code

```cpp
void printPattern17(int n) {

    // Outer loop: iterates over each ROW (0-based: 0 to n-1)
    for (int i = 0; i < n; i++) {

        // --- PART 1: Print leading spaces ---
        // Same formula as Pattern 7: (n - i - 1) spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " "; // Print single space
        }

        // --- PART 2: Print characters with symmetry ---
        // Total characters to print = 2 * i + 1
        // Characters go A → B → ... → (A+i) → ... → B → A
        // 'ch' starts at 'A', increments to the midpoint, then decrements back

        char ch = 'A'; // Start from 'A' every row

        // breakPoint: position at which we start decrementing
        // After the midpoint (j > i+1), ch decrements
        int breakPoint = i + 1; // The middle position (1-based count)

        for (int j = 1; j <= 2 * i + 1; j++) {
            cout << ch << " "; // Print current character

            // Decide whether to increment or decrement
            if (j <= breakPoint) {
                ch++; // Still going up toward the peak character
            } else {
                ch--; // Past the peak — coming back down toward 'A'
            }
        }

        cout << endl; // Move to next line
    }
}
```

---

## Java Code

```java
static void printPattern17(int n) {

    // Outer loop: each ROW from 0 to n-1
    for (int i = 0; i < n; i++) {

        // Part 1: Leading spaces
        for (int j = 0; j < n - i - 1; j++) {
            System.out.print(" ");
        }

        // Part 2: Characters with symmetry
        char ch = 'A';
        int breakPoint = i + 1; // Switch from increment to decrement after this

        for (int j = 1; j <= 2 * i + 1; j++) {
            System.out.print(ch + " ");

            if (j <= breakPoint) ch++;
            else ch--;
        }

        System.out.println(); // New line
    }
}
```

---

## Key Observations

| Property | Formula |
|----------|---------|
| Total rows | `n` |
| Leading spaces on row `i` | `n - i - 1` |
| Total characters on row `i` | `2 * i + 1` |
| Peak character on row `i` | `'A' + i` |
| Breakpoint (switch from ++ to --) | `i + 1` |

---

## Pattern 7 vs Pattern 17

| Feature | Pattern 7 (Star Pyramid) | Pattern 17 (Alphabet Pyramid) |
|---------|--------------------------|-------------------------------|
| Spaces | `n - i - 1` | Same |
| Count | `2*i + 1` | Same |
| Print | `*` (static) | `ch` (changes: A→peak→A) |
| Complexity | Low | Higher (needs ch tracking) |

---

## Key Takeaway

> Pattern 17 uses the **same pyramid structure** as Pattern 7 but replaces the static star with a **dynamically changing character** that ascends to the peak (`'A' + i`) and descends back. The breakpoint `i + 1` divides the row into ascending and descending halves, directly applying **Rule 4 (Symmetry)** within each row.
