# Pattern 9 — Diamond (Pyramid + Inverted Pyramid)

## What It Looks Like

For `n = 5`:
```
    *
   * * *
  * * * * *
 * * * * * * *
* * * * * * * * *
 * * * * * * *
  * * * * *
   * * *
    *
```

---

## The Smart Observation

> **Pattern 9 = Pattern 7 (top half) + Pattern 8 (bottom half)**

You don't need to re-derive the logic! You already solved both halves:
- **Top half** = Star Pyramid (Pattern 7)
- **Bottom half** = Inverted Star Pyramid (Pattern 8)

This is a classic example of **combining two patterns** to form a new one.

---

## Step-by-Step Analysis (Using the 4 Rules)

### Rule 1 — Count the Rows (Outer Loop)
- Total rows = `n + (n-1)` = `2n - 1` (for n=5, that's 9 rows).
- But since we're combining two functions, each function runs for `n` rows.

### Rule 4 — Symmetry?
- YES! The pattern is **perfectly symmetric** around the middle row.
- This is exactly why we can split it into two separate patterns.

---

## C++ Code — Smart Combination Approach

```cpp
// We reuse Pattern 7 (pyramid) and Pattern 8 (inverted pyramid)
// This is the SMART way — combine existing patterns!

void printPattern7(int n) {
    // (Same code as Pattern 7 — Star Pyramid)
    for (int i = 0; i < n; i++) {
        // Leading spaces: n - i - 1 times
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        // Stars: 2*i + 1 times
        for (int j = 0; j < 2 * i + 1; j++) cout << "* ";
        cout << endl;
    }
}

void printPattern8(int n) {
    // (Same code as Pattern 8 — Inverted Star Pyramid)
    for (int i = 0; i < n; i++) {
        // Leading spaces: i times
        for (int j = 0; j < i; j++) cout << " ";
        // Stars: 2*(n-i)-1 times
        for (int j = 0; j < 2 * (n - i) - 1; j++) cout << "* ";
        cout << endl;
    }
}

void printPattern9(int n) {
    // TOP HALF: Print the upward pyramid (Pattern 7)
    printPattern7(n);

    // BOTTOM HALF: Print the inverted pyramid (Pattern 8)
    printPattern8(n);
}
```

---

## C++ Code — Single Function Approach

```cpp
void printPattern9(int n) {

    // --- TOP HALF (Rows 0 to n-1): Upward Pyramid ---
    for (int i = 0; i < n; i++) {
        // Leading spaces decrease row by row
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        // Stars increase (odd numbers: 1, 3, 5, ...)
        for (int j = 0; j < 2 * i + 1; j++) cout << "* ";
        cout << endl;
    }

    // --- BOTTOM HALF (Rows 0 to n-1): Inverted Pyramid ---
    for (int i = 0; i < n; i++) {
        // Leading spaces increase row by row
        for (int j = 0; j < i; j++) cout << " ";
        // Stars decrease (odd numbers: 2n-1, 2n-3, ..., 1)
        for (int j = 0; j < 2 * (n - i) - 1; j++) cout << "* ";
        cout << endl;
    }
}
```

---

## Java Code

```java
static void printPattern9(int n) {

    // TOP HALF: Upward Pyramid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) System.out.print(" ");
        for (int j = 0; j < 2 * i + 1; j++) System.out.print("* ");
        System.out.println();
    }

    // BOTTOM HALF: Inverted Pyramid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) System.out.print(" ");
        for (int j = 0; j < 2 * (n - i) - 1; j++) System.out.print("* ");
        System.out.println();
    }
}
```

---

## Key Observations

| Property | Value |
|----------|-------|
| Total rows | `2n - 1` |
| Top half rows | `n` |
| Bottom half rows | `n` (inverted) |
| Widest row | Middle row: `2n - 1` stars |

---

## Important Lesson: Pattern Combination

> **You don't always need to write patterns from scratch.** Sometimes, the smartest solution is to recognize that a complex pattern is just **two simpler patterns combined**.
>
> When you see symmetry (Rule 4), think: "Can I split this into two known patterns?"

---

## Key Takeaway

> Pattern 9 is a beautiful example of the **divide and conquer** philosophy applied to patterns. By recognizing it as Pattern 7 + Pattern 8, you can either call both functions directly or simply copy the code for each half. Always look for symmetry before writing new logic!
