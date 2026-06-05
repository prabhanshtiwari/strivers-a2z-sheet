# Pattern 15 — Inverted Alphabet Triangle

## What It Looks Like

For `n = 5`:
```
A B C D E
A B C D
A B C
A B
A
```

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- The pattern has **5 rows** (for n=5).
- Outer loop runs from `i = 0` to `i < n` (0-based).

### Rule 2 — Connect Columns to Rows (Inner Loop)
- Row 0 → `A B C D E` (5 characters, from A to E)
- Row 1 → `A B C D` (4 characters, from A to D)
- Row 2 → `A B C` (3 characters, from A to C)
- Row 3 → `A B` (2 characters, from A to B)
- Row 4 → `A` (1 character, just A)

Each row starts at `A` and ends at `A + (n - 1 - i)`.

**Derivation:**
- Row 0 ends at `A + (n-1-0) = A + 4 = E` ✓
- Row 1 ends at `A + (n-1-1) = A + 3 = D` ✓
- Row 4 ends at `A + (n-1-4) = A + 0 = A` ✓

Inner loop: `ch = 'A'` to `ch <= 'A' + (n - 1 - i)`

### Rule 3 — Print Inside Inner Loop
- Print `ch` (the character loop variable).
- Print `endl` after inner loop.

### Rule 4 — Symmetry?
- No symmetry needed. This is the inverted version of Pattern 14.

---

## Dry Run (n = 5, 0-based)

| i | End char formula | End char | Output |
|---|-----------------|----------|--------|
| 0 | A + (5-1-0) = A+4 | E | `A B C D E` |
| 1 | A + (5-1-1) = A+3 | D | `A B C D` |
| 2 | A + (5-1-2) = A+2 | C | `A B C` |
| 3 | A + (5-1-3) = A+1 | B | `A B` |
| 4 | A + (5-1-4) = A+0 | A | `A` |

---

## C++ Code

```cpp
void printPattern15(int n) {

    // Outer loop: iterates over each ROW (0-based: 0 to n-1)
    for (int i = 0; i < n; i++) {

        // Inner loop: characters from 'A' to 'A' + (n - 1 - i)
        // Row 0: A to A+(n-1) = full alphabet up to E (for n=5)
        // Row 1: A to A+(n-2) = up to D
        // Row n-1: A to A+0  = just A
        // Formula: (n - 1 - i) ensures decreasing end point each row
        for (char ch = 'A'; ch <= (char)('A' + (n - 1 - i)); ch++) {

            cout << ch << " "; // Print character inside inner loop
        }

        cout << endl; // Move to next line after completing current row
    }
}
```

---

## Java Code

```java
static void printPattern15(int n) {

    // Outer loop: each ROW from 0 to n-1
    for (int i = 0; i < n; i++) {

        // Inner loop: decreasing character range
        for (char ch = 'A'; ch <= (char)('A' + (n - 1 - i)); ch++) {
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
| Starting character per row | Always `A` |
| Ending character on row `i` (0-indexed) | `'A' + (n - 1 - i)` |
| Characters on row `i` | `n - i` characters |
| Outer loop | `i = 0` to `i < n` |

---

## Pattern 14 vs Pattern 15 (Mirror)

| Property | Pattern 14 (Increasing) | Pattern 15 (Decreasing) |
|----------|------------------------|------------------------|
| End character | `'A' + i` (grows) | `'A' + (n-1-i)` (shrinks) |
| Row 0 | `A` (shortest) | `A B C ... n chars` (longest) |
| Row n-1 | `A B ... n chars` (longest) | `A` (shortest) |

---

## Key Takeaway

> Pattern 15 is the inverted version of Pattern 14. The only change is the **upper bound of the inner loop**: instead of `'A' + i` (which grows), we use `'A' + (n-1-i)` (which shrinks). This mirrors the relationship between Pattern 2 (increasing stars) and Pattern 5 (decreasing stars) — same concept, just applied to characters.
