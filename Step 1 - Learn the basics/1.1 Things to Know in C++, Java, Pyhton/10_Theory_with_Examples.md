# Time Complexity & Space Complexity — Complete Theory Notes
> **Source:** Striver's A to Z DSA Course — Step 1.1 (Lecture Transcript)
> **Topic:** Time Complexity, Space Complexity, Big O Notation

---

## Table of Contents
1. [Why is Time Complexity Required?](#1-why-is-time-complexity-required)
2. [What is Time Complexity?](#2-what-is-time-complexity)
3. [Big O Notation](#3-big-o-notation)
4. [Three Golden Rules for Computing Big O](#4-three-golden-rules-for-computing-big-o)
5. [Best Case, Average Case & Worst Case](#5-best-case-average-case--worst-case)
6. [Practical Examples — Computing Time Complexity](#6-practical-examples--computing-time-complexity)
7. [Other Notations: Theta (Θ) and Omega (Ω)](#7-other-notations-theta-θ-and-omega-ω)
8. [Space Complexity](#8-space-complexity)
9. [Auxiliary Space vs Input Space](#9-auxiliary-space-vs-input-space)
10. [Important Interview Practice: Never Modify Input](#10-important-interview-practice-never-modify-input)
11. [Competitive Programming Time Limit Guide](#11-competitive-programming-time-limit-guide)
12. [Quick Summary Cheat Sheet](#12-quick-summary-cheat-sheet)

---

## 1. Why is Time Complexity Required?

### The Problem with Using "Time Taken"

When you write a piece of code and run it on a machine, it takes some amount of time — say 1 second, 2 seconds, or 5 seconds.

**Can we call this "time taken" as the Time Complexity of the code?**

> ❌ **NO.** Time taken is **never** equal to time complexity.

### Proof with an Example

Take the **same piece of code** and run it on two different machines:

| Machine | Time Taken |
|---|---|
| Old Windows PC (low config) | 2 seconds |
| New MacBook (high config) | 1 second |
| Some other new machine | < 1 second |

The code hasn't changed — only the machine changed. So the time changes depending on the **system configuration**.

> **Conclusion:** Time taken depends on the machine/system. Therefore, it cannot be a reliable measure of a program's efficiency.

---

## 2. What is Time Complexity?

> **Definition:**
> Time Complexity is the **rate at which the time taken increases with respect to the input size**.

It is **not** about how many seconds a code takes. It's about **how time scales** as the input grows.

### Visualising With a Graph

Consider plotting time (y-axis) vs input size (x-axis) for two machines running the same code:

```
Time (seconds)
^
5 |
4 |     * (Old Windows at input=20)
3 |   *
2 | *       <- slope θ1 (Old Windows rate)
1 |   * (MacBook at input=20)
  +----+----+----+-----> Input Size
       10   20   30   40
```

- For Old Windows: input 10 → 2s, input 20 → 4s, input 30 → 6s (steep slope)
- For MacBook: input 10 → 1s, input 20 → 2s, input 40 → 3s (gentler slope)

The **slope (rate of increase)** is what we call the **Time Complexity**.
Both machines show the same *rate* for the same code — they just differ in absolute time.

> **Key Insight:** Time Complexity captures how much *more* time a code takes as input grows — independent of which machine it's running on.

---

## 3. Big O Notation

Since time complexity is NOT measured in seconds, we need a mathematical notation to express it.

> **Big O Notation** is the standard way to express time complexity in interviews, examinations, and professional software engineering.

### Syntax

```
O( expression )
```
- Capital letter **O**
- Open parenthesis, write the expression, close parenthesis
- The expression represents the number of operations (steps) the code takes

### Simple Example — Manual Step Counting

```cpp
// For loop running 5 times, printing a name each iteration
for (int i = 1; i < 5; i++) {
    cout << "Raj";        // Step: print
    // i++ also happens   // Step: increment
    // i < 5 is checked   // Step: comparison
}
```

**Counting steps manually:**
- Each iteration: 1 comparison + 1 print + 1 increment = **3 steps**
- Total iterations: 5
- Total steps: 5 × 3 = **15 steps**
- Time Complexity = **O(15)**

But numbers alone aren't useful. We express it in terms of **n** (input size).

### Expressing in Terms of n

```cpp
// Same loop but running up to n
for (int i = 1; i <= n; i++) {
    cout << "Raj";
}
```

- Loop runs **n** times
- Each iteration has **3 operations** (increment, comparison, print)
- Total = **3n** operations
- Time Complexity = **O(3n)**

> Later, using the three rules below, this simplifies to **O(n)**.

---

## 4. Three Golden Rules for Computing Big O

These three rules are used to simplify Big O expressions when analyzing code:

---

### Rule 1: Always Compute in Terms of the Worst Case

Always calculate the time complexity for the **worst possible input** your code might receive.

*(This is explained in detail in Section 5 below.)*

---

### Rule 2: Avoid Constants

Constants (fixed numbers multiplied or added) are **ignored** in Big O.

**Why?** Because when input size `n` is very large (e.g., n = 10⁵), constants become insignificant.

**Proof:**

Consider the expression:  
`4n³ + 3n² + 8`

With n = 10⁵:
- `4n³` = 4 × 10¹⁵  *(enormous)*
- `3n²` = 3 × 10¹⁰  *(relatively tiny compared to 4n³)*
- `8`   = 8          *(completely negligible)*

Adding 8 to 4 × 10¹⁵ makes absolutely no difference — it's like adding ₹1 to ₹1,000,000.

**Practical code example:**

```cpp
int x = 2;             // 1 operation (constant)

// Loop runs n times, 3 operations per iteration
for (int i = 0; i < n; i++) {
    // some code
}
// Total = 3n + 1
// After rule: O(3n + 1) → O(3n) → O(n)
//             ↑ drop the constant 1
//                           ↑ drop the constant multiplier 3
```

> **Final Rule:** `O(3n + 1)` → drop the `+1` (constant term) → `O(3n)` → drop the `3` (constant multiplier) → **O(n)**

---

### Rule 3: Avoid Lower-Order Terms

When multiple terms exist, **keep only the largest (dominant) term** and drop all smaller ones.

**Why?** The smaller terms are insignificant compared to the dominant term for large n.

**Proof:**

`4n³ + 3n² + 8`  with n = 10⁵:
- `4n³` = 4 × 10¹⁵
- `3n²` = 3 × 10¹⁰

Is adding 3 × 10¹⁰ to 4 × 10¹⁵ significant? No!  
10¹⁵ dwarfs 10¹⁰ — it's like adding 10,000 to 1,000,000,000,000,000.

> **Final Result:** `O(4n³ + 3n² + 8)` → drop constants and lower terms → **O(n³)**

---

## 5. Best Case, Average Case & Worst Case

Consider this grade-checking code snippet (pseudo-code):

```
if marks < 25:
    print "Grade D"
else if marks < 45:
    print "Grade C"
else if marks < 65:
    print "Grade B"
else:
    print "Grade A"
```

### Best Case
> The scenario where the program takes the **least** amount of time.

**Example:** `marks = 10`

Execution:
1. Check `marks < 25` → **True** → print "Grade D" → STOP

Operations: 1 check + 1 print = **2 operations**  
Best Case Time Complexity = **O(2)**

---

### Worst Case
> The scenario where the program takes the **most** amount of time.

**Example:** `marks = 70`

Execution:
1. Check `marks < 25` → False
2. Check `marks < 45` → False
3. Check `marks < 65` → False
4. Go to `else` → print "Grade A"

Operations: 3 checks + 1 print = **4 operations**  
Worst Case Time Complexity = **O(4)**

---

### Average Case
> The **median** between best and worst case. `(Best + Worst) / 2`

Average = (2 + 4) / 2 = **3 operations**

---

### Why Do We Always Use Worst Case?

> **The answer is about scalability.**

When building a system, do you build it for **1 user** or **1 million users**?

You always build for 1 million (the worst that can happen), because you want your system to **scale**.

Similarly, when analyzing code — we always think about the **worst possible input** the program could encounter. That way, we guarantee our code handles every scenario.

> **Rule:** Time Complexity is always expressed as the **Worst Case** scenario.

---

## 6. Practical Examples — Computing Time Complexity

### Example 1: Nested For Loops (Both run to n)

```cpp
// Outer loop: runs from i=0 to i<n → runs n times
for (int i = 0; i < n; i++) {

    // Inner loop: runs from j=0 to j<n → runs n times FOR EACH value of i
    for (int j = 0; j < n; j++) {
        // some block of code (constant time, ignored)
    }
}
```

**Analysis (trace through manually):**

| Value of i | Inner loop (j) runs | Iterations |
|---|---|---|
| i = 0 | j = 0, 1, 2, ..., n-1 | n times |
| i = 1 | j = 0, 1, 2, ..., n-1 | n times |
| i = 2 | j = 0, 1, 2, ..., n-1 | n times |
| ... | ... | ... |
| i = n-1 | j = 0, 1, 2, ..., n-1 | n times |

Total = n × n = **n² iterations**

> **Time Complexity = O(n²)**

---

### Example 2: Nested For Loops (Inner runs to i)

```cpp
// Outer loop: runs from i=0 to i<n → runs n times
for (int i = 0; i < n; i++) {

    // Inner loop: runs from j=0 to j<=i → runs (i+1) times
    for (int j = 0; j <= i; j++) {
        // some block of code (constant time, ignored)
    }
}
```

**Analysis (trace through manually):**

| Value of i | Inner loop (j) runs | Iterations |
|---|---|---|
| i = 0 | j = 0 | 1 time |
| i = 1 | j = 0, 1 | 2 times |
| i = 2 | j = 0, 1, 2 | 3 times |
| i = 3 | j = 0, 1, 2, 3 | 4 times |
| ... | ... | ... |
| i = n-1 | j = 0 to n-1 | n times |

Total iterations = 1 + 2 + 3 + ... + n

**Using the formula for sum of first n natural numbers:**

```
Sum = n × (n + 1) / 2
    = n²/2 + n/2
```

**Applying the rules:**
- `n²/2 + n/2`
- Drop lower term `n/2` → `n²/2`
- Drop constant `1/2` → `n²`

> **Time Complexity = O(n²)**

---

## 7. Other Notations: Theta (Θ) and Omega (Ω)

| Notation | Full Name | What it Represents | Also Called |
|---|---|---|---|
| **O** (Big O) | Big O Notation | **Worst Case** / Upper Bound | Upper Bound |
| **Θ** (Theta) | Theta Notation | **Average Case** | Tight Bound |
| **Ω** (Omega) | Omega Notation | **Best Case** / Lower Bound | Lower Bound |

> **Important for Interviews:**
> In interviews, coding rounds, and competitive programming — **only Big O (worst case) is asked**.
> Theta and Omega are primarily for academic/semester examinations.
> You will never be asked the mathematical limit derivation of Big O in a technical interview.

---

## 8. Space Complexity

> **Definition:**  
> Space Complexity is the **total memory space** your program uses.

Just like time complexity, space complexity:
- **Cannot be expressed in KB, MB, or GB** — it varies by machine
- **Must be expressed using Big O notation**

```
Space Complexity = Auxiliary Space + Input Space
```

---

## 9. Auxiliary Space vs Input Space

### Input Space
The memory used to **store the inputs** given to the program.

### Auxiliary Space
The **extra memory** used by the program to **solve the problem** — variables, arrays, etc. created internally.

### Example

```
// Taking two inputs: a and b
Input a   →  Input Space
Input b   →  Input Space

c = a + b →  Variable c is the Auxiliary Space
             (you created c to solve/store the result)
```

- Input Space = 2 variables (a, b)
- Auxiliary Space = 1 variable (c)
- Total Space Complexity = **O(3)** ≈ **O(1)** (constant, since it doesn't grow with n)

---

### Array Example

```cpp
int arr[n];   // Array of size n
```

- This consumes **O(n)** space
- In an interview, you say: *"The space complexity is O(n) since I'm using an array of size n."*

---

## 10. Important Interview Practice: Never Modify Input

### The Problem with Modifying Input

Consider adding two numbers a and b:

```
// BAD APPROACH (saves space but is wrong in practice):
b = a + b    // Store sum back in b — input b is now changed!

// GOOD APPROACH:
c = a + b    // Use a new variable c — inputs a and b are untouched
```

### Why is Modifying Input Bad?

In real-world software engineering (e.g., at a large company):
- You are given a dataset
- That same data may be **used in multiple other places** in the system
- If you modify it, you **corrupt the data for everyone else**

> **Golden Rule:** Never modify the input given to you, unless the interviewer explicitly says you may.

### What to Say in Interviews

> *"I'm taking an extra variable/array to avoid modifying the input data, since in a production system the same data may be referenced elsewhere."*

**Will using O(2n) instead of O(n) space get you rejected?**

> No. Using O(2n) (an extra array) vs O(n) is not a concern. The interviewer appreciates that you understand data safety. You will NOT be rejected for this.

---

## 11. Competitive Programming Time Limit Guide

When solving problems on platforms like LeetCode, CodeStudio, GFG, or in company coding rounds:

> **Standard Rule:**
> Most servers execute approximately **10⁸ (100 million) operations per second**.

| Time Limit Given | Maximum Operations Allowed |
|---|---|
| 1 second | ~10⁸ operations |
| 2 seconds | ~2 × 10⁸ operations |
| 5 seconds | ~5 × 10⁸ operations |

> ⚠️ **Common Mistake:** Do NOT calculate 2 seconds as 10⁸ × 10⁸ = 10¹⁶. It is **2 × 10⁸**.

### How to Use This in Practice

If the time limit is **1 second**, your code's Big O (after removing constants and lower terms) should be roughly **O(10⁸)** or better.

**Example:**
- If your code is O(n²) and n = 10⁴, that's 10⁸ operations — right at the limit for 1 second.
- If your code is O(n²) and n = 10⁵, that's 10¹⁰ operations — this will **TLE (Time Limit Exceed)**.

---

## 12. Quick Summary Cheat Sheet

### Time Complexity Rules at a Glance

| Rule | What To Do | Why |
|---|---|---|
| Use Worst Case | Always analyze the hardest possible input | You build systems for scale, not the happy path |
| Avoid Constants | Drop multipliers like 3 in O(3n) → O(n) | Constants are insignificant for large n |
| Avoid Lower Terms | Drop n² in O(n³ + n²) → O(n³) | Lower terms are dominated by higher ones |

### Common Time Complexities (Fastest to Slowest)

| Big O | Name | Example |
|---|---|---|
| O(1) | Constant | Single statement, array access |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Single loop |
| O(n log n) | Linearithmic | Merge sort |
| O(n²) | Quadratic | Nested loop (both to n) |
| O(n³) | Cubic | Triple nested loop |
| O(2ⁿ) | Exponential | Recursive Fibonacci (naive) |

### Space Complexity at a Glance

| Scenario | Space Complexity |
|---|---|
| Fixed number of variables | O(1) |
| Array of size n | O(n) |
| 2D matrix of size n × n | O(n²) |
| Recursion depth d | O(d) |

### Key Formulas Discussed

```
Sum of first n natural numbers:
  1 + 2 + 3 + ... + n = n(n+1)/2 ≈ O(n²)

Space Complexity:
  Total = Auxiliary Space + Input Space

Server Throughput:
  ~10⁸ operations per second
```

---

> **Final Note from the Lecture:**
> Time and space complexity will become second nature as you solve more problems across data structures and algorithms. The deeper complexities like O(log n), O(n log n), etc. will naturally appear as you progress through problems involving recursion, backtracking, trees, and graphs. The goal right now is to have the **fundamentals crystal clear**.
