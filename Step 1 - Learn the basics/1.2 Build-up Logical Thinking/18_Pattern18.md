# Pattern 18 — Reverse Alphabet Triangle (Starting from E)

## What It Looks Like

For `n = 5`:
```
E
D E
C D E
B C D E
A B C D E
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 0` to `i < n` (0-based).

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 0 → 1 character: `E`
- Row 1 → 2 characters: `D E`
- Row 2 → 3 characters: `C D E`
- Row 3 → 4 characters: `B C D E`
- Row 4 → 5 characters: `A B C D E`

**Observation:**
- Each row **always ends at `E`** (the last character = `'A' + (n-1)`).
- The **starting character** decreases each row:
  - Row 0: starts at E = `'A' + (n-1) - 0` = `'A' + (n-1-0)`
  - Row 1: starts at D = `'A' + (n-1) - 1` = `'A' + (n-1-1)`
  - Row i: starts at `'A' + (n - 1 - i)`, ends at `'E'` = `'A' + (n-1)`

**Alternatively (simpler):** think of it as starting from `'E' - i` and going to `'E'`.
- Row 0: `'E' - 0` to `'E'` → just `E`
- Row 1: `'E' - 1` to `'E'` → `D E`
- Row i: `'E' - i` to `'E'`

For general n: `'A' + (n-1) - i` to `'A' + (n-1)`

Inner loop: `ch = 'A' + (n - 1 - i)` to `ch <= 'A' + (n - 1)` (i.e., to `ch <= 'E'` for n=5)

### Rule 3 — Print Inside Inner Loop
- Print `ch` (the character loop variable).
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed.

---

## Dry Run (n = 5, 0-based, last char = 'E')

| i | Start char | End char | Output |
|---|-----------|----------|--------|
| 0 | E-0 = E | E | `E` |
| 1 | E-1 = D | E | `D E` |
| 2 | E-2 = C | E | `C D E` |
| 3 | E-3 = B | E | `B C D E` |
| 4 | E-4 = A | E | `A B C D E` |

---

## C++ Code

```cpp
void printPattern18(int n) {

    // Outer loop: iterates over each ROW (0-based: 0 to n-1)
    for (int i = 0; i < n; i++) {

        // Inner loop: characters from ('E' - i) to 'E'
        // In general form: from ('A' + n - 1 - i) to ('A' + n - 1)
        //
        // 'E' here represents the last character = 'A' + (n-1)
        // Starting point goes: E, D, C, B, A  (moves left each row)
        // Ending point is always 'E' (rightmost letter)
        for (char ch = (char)('A' + n - 1 - i); ch <= (char)('A' + n - 1); ch++) {

            cout << ch << " "; // Print character, incrementing through the alphabet
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Alternative Code (Using 'E' directly for n=5)

```cpp
void printPattern18(int n) {

    // lastChar is the character at the end of the alphabet range (for n=5, it's 'E')
    char lastChar = 'A' + n - 1;

    for (int i = 0; i < n; i++) {

        // Start from (lastChar - i), go up to lastChar
        // Row 0: E to E       → just 'E'
        // Row 1: D to E       → 'D', 'E'
        // Row n-1: A to lastChar  → full alphabet
        for (char ch = lastChar - i; ch <= lastChar; ch++) {
            cout << ch << " ";
        }

        cout << endl;
    }
}
```

---

## Java Code

```java
static void printPattern18(int n) {

    char lastChar = (char)('A' + n - 1); // e.g., 'E' for n=5

    // Outer loop: each ROW from 0 to n-1
    for (int i = 0; i < n; i++) {

        // Inner loop: from (lastChar - i) to lastChar
        for (char ch = (char)(lastChar - i); ch <= lastChar; ch++) {
            System.out.print(ch + " ");
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
| Last character (always) | `'A' + (n-1)` |
| Starting character on row `i` | `'A' + (n - 1 - i)` |
| Characters on row `i` | `i + 1` |
| Outer loop | `i = 0` to `i < n` |

---

## Comparison: Pattern 14 vs Pattern 18

| Property | Pattern 14 | Pattern 18 |
|----------|-----------|-----------|
| Start char | Always `'A'` | `'A' + (n-1-i)` (changes) |
| End char | `'A' + i` (changes) | Always `'A' + (n-1)` |
| Row 0 | `A` | `E` (for n=5) |
| Row n-1 | `A B C D E` | `A B C D E` |
| Direction | Top-narrow | Bottom-narrow |

---

## Key Takeaway

> Pattern 18 is the **right-aligned** version of Pattern 14. Instead of starting at `A` each time, we **end at the last character** (`E` for n=5) and **vary the starting point**. The starting character retreats one step toward `A` each row. This requires the inner loop starting point `ch = lastChar - i` to be the variable part, while the ending point stays fixed.
