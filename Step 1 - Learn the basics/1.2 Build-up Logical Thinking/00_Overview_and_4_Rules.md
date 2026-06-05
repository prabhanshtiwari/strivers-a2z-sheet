# Striver's A2Z DSA — Step 1.2: Pattern Problems (Overview)

## Why Patterns Matter in DSA

Before diving into Data Structures and Algorithms (DSA), it is **essential** to master loops.
Every major DSA topic — Dynamic Programming, Graphs, Trees, Arrays, Binary Search — relies heavily on loops.

> **"If you do not understand loops in depth, if you cannot improvise with loops, there will be a problem when you do DSA."**

Patterns are the **best way to master loops** because:
- They force you to think in terms of nested loops.
- They train you to connect rows and columns logically.
- They build the intuition needed for complex DSA problems.

> **Note:** Pattern questions are **NOT asked** in top-tier product-based company interviews (like FAANG). They may appear in service-based company interviews (e.g., TCS). Their purpose is purely to **sharpen your loop logic**.

---

## The 4 Golden Rules for Printing Any Pattern

These 4 rules apply to **every single pattern** you will ever print. Memorize them.

---

### Rule 1 — Outer Loop: Count the Number of Lines (Rows)

- Look at the pattern and count how many rows it has.
- That count determines your **outer loop**.
- Example: If there are 5 rows → `for(int i = 0; i < n; i++)`

```
Outer loop  →  controls ROWS
```

---

### Rule 2 — Inner Loop: Focus on Columns and Connect to Rows

- Look at each row and count how many elements (columns) are printed.
- **Connect** that column count to the row number (`i`).
- Example: If row `i` prints `i+1` stars → `for(int j = 0; j <= i; j++)`

```
Inner loop  →  controls COLUMNS
              must be connected to the row variable (i)
```

---

### Rule 3 — Print Inside the Inner Loop

- Whatever character, number, or symbol you are printing goes **inside** the inner loop.
- After the inner loop finishes (end of one row), print a **newline** (`endl` in C++ / `System.out.println()` in Java).

```cpp
cout << "*";          // inside inner loop
cout << endl;         // outside inner loop, inside outer loop
```

---

### Rule 4 — Observe Symmetry (Optional, but Important)

- Some patterns are **symmetrical** (top half mirrors bottom half).
- When you spot symmetry, you only need to figure out the logic for **one half** and mirror it.
- This rule is **optional** — only applicable to certain patterns (e.g., diamond, pyramid shapes).

---

## General Template (C++)

```cpp
void printPattern(int n) {
    // Outer loop: runs for each ROW
    for (int i = 0; i < n; i++) {

        // Inner loop: runs for each COLUMN in the current row
        for (int j = 0; j < /* formula connected to i */; j++) {
            cout << "* "; // Print inside inner loop
        }

        cout << endl; // Move to next line after each row
    }
}
```

---

## Online Compilers & Test Cases

When solving patterns on online judges (like Code Studio by Coding Ninjas, LeetCode, etc.):

- You only need to **write the function** — not `int main()`.
- The platform's backend handles multiple **test cases** automatically.
- Example backend structure:
  ```cpp
  int main() {
      int t;
      cin >> t;          // number of test cases
      while (t--) {
          int n;
          cin >> n;
          printPattern(n); // your function is called for each test case
      }
  }
  ```
- Always check if the expected output requires **spaces** between characters.

---

## List of All 22 Patterns

| File | Pattern Description |
|------|-------------------|
| `01_Pattern1.md` | Solid Rectangle of Stars |
| `02_Pattern2.md` | Right-Angled Triangle (Stars, increasing) |
| `03_Pattern3.md` | Right-Angled Triangle (Numbers 1..row) |
| `04_Pattern4.md` | Right-Angled Triangle (Row number repeated) |
| `05_Pattern5.md` | Inverted Right-Angled Triangle (Stars, decreasing) |
| `06_Pattern6.md` | Inverted Right-Angled Triangle (Numbers) |
| `07_Pattern7.md` | Pyramid (Star) |
| `08_Pattern8.md` | Inverted Pyramid (Star) |
| `09_Pattern9.md` | Diamond (Pyramid + Inverted Pyramid) |
| `10_Pattern10.md` | Half Diamond / Rhombus Star |
| `11_Pattern11.md` | Binary Triangle (0-1 Pattern) |
| `12_Pattern12.md` | Number Butterfly / Symmetric Number Triangle |
| `13_Pattern13.md` | Continuous Number Right Triangle |
| `14_Pattern14.md` | Alphabets Right Triangle (A,AB,ABC...) |
| `15_Pattern15.md` | Inverted Alphabet Triangle |
| `16_Pattern16.md` | Alphabet Triangle (Same letter per row) |
| `17_Pattern17.md` | Alphabet Pyramid |
| `18_Pattern18.md` | Reverse Alphabet Triangle |
| `19_Pattern19.md` | Symmetric Butterfly Star |
| `20_Pattern20.md` | Symmetric Hollow Butterfly |
| `21_Pattern21.md` | Hollow Rectangle |
| `22_Pattern22.md` | Number Matrix / Spiral-like Border Numbers |
