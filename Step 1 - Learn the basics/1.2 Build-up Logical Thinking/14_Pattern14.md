# Pattern 14 — Alphabet Right Triangle (A, AB, ABC...)

## What It Looks Like

For `n = 5`:
```
A
A B
A B C
A B C D
A B C D E
```

---

## Background: Character Arithmetic in C++

Characters in C++ are stored as their **ASCII values** (integers).

```
A = 65, B = 66, C = 67, D = 68, E = 69 ...
```

**Key operation:** `'A' + 2` = `'C'` (character arithmetic!)

You can loop over characters just like integers:
```cpp
for (char ch = 'A'; ch <= 'C'; ch++) {
    cout << ch; // Prints: A B C
}
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 0` to `i < n` (0-based indexing).

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 0 → `A` (1 character)
- Row 1 → `A B` (2 characters)
- Row 2 → `A B C` (3 characters)
- Row 3 → `A B C D` (4 characters)
- Row 4 → `A B C D E` (5 characters)

The characters always start at `A` and go up to `A + i`.

Inner loop: `ch = 'A'` to `ch <= 'A' + i`

### Rule 3 — Print Inside Inner Loop
- Print `ch` (the loop variable itself — a character).
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed.

---

## Dry Run (n = 4, 0-based)

| i | ch range | Characters printed |
|---|---------|-------------------|
| 0 | A to A+0 = A | `A` |
| 1 | A to A+1 = B | `A B` |
| 2 | A to A+2 = C | `A B C` |
| 3 | A to A+3 = D | `A B C D` |

---

## C++ Code

```cpp
void printPattern14(int n) {

    // Outer loop: iterates over each ROW (0-based: 0 to n-1)
    for (int i = 0; i < n; i++) {

        // Inner loop: loops over characters from 'A' to 'A' + i
        // 'A' + 0 = 'A' (row 0: just A)
        // 'A' + 1 = 'B' (row 1: A, B)
        // 'A' + 2 = 'C' (row 2: A, B, C)
        // Character arithmetic: adding an integer to a char gives next chars
        for (char ch = 'A'; ch <= (char)('A' + i); ch++) {

            cout << ch << " "; // Print the character inside inner loop
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern14(int n) {

    // Outer loop: each ROW from 0 to n-1
    for (int i = 0; i < n; i++) {

        // Inner loop: characters from 'A' to 'A' + i
        for (char ch = 'A'; ch <= (char)('A' + i); ch++) {
            System.out.print(ch + " "); // Print character
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
| Characters on row `i` (0-indexed) | `A` to `A + i` |
| Number of characters on row `i` | `i + 1` |
| Outer loop | `i = 0` to `i < n` |
| Inner loop variable type | `char` (not `int`) |
| Inner loop condition | `ch <= 'A' + i` |

---

## ASCII Intuition

```
Row i=0: A to A+0  →  just 'A'
Row i=1: A to A+1  →  'A', 'B'
Row i=2: A to A+2  →  'A', 'B', 'C'

'A' + 0 = 'A'  (65 + 0 = 65)
'A' + 1 = 'B'  (65 + 1 = 66)
'A' + 2 = 'C'  (65 + 2 = 67)
```

---

## Comparison: Pattern 3 vs Pattern 14

| Feature | Pattern 3 | Pattern 14 |
|---------|-----------|-----------|
| Loop structure | Same (right triangle) | Same |
| Data type | `int j` | `char ch` |
| Values | 1, 2, 3, ... | A, B, C, ... |
| Start value | 1 | 'A' |
| Condition | `j <= i` | `ch <= 'A' + i` |

---

## Key Takeaway

> Pattern 14 is essentially Pattern 3 but with **characters instead of numbers**. The loop structure is identical — only the data type and variable semantics change. The key concept is **character arithmetic**: you can add integers to characters in C++ to navigate through the alphabet, just like you'd do with numbers.
