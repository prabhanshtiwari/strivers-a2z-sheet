# Striver's A2Z DSA Course — Basic Maths Notes

## Overview

These notes are derived from Striver's A2Z DSA course video on Basic Maths.
The course has **455 modules** and is considered one of the most in-depth DSA courses available.

## Why Basic Maths First?

- Starting with basic concepts allows your brain to build up gradually
- Advanced concepts are introduced in **Step 8** (Advanced Mathematics)
- The current step focuses on foundational maths needed to solve DSA problems

---

## Topics Covered (Files)

| File | Topic |
|------|-------|
| `01_digit_extraction.md` | Core concept: Extracting digits from a number |
| `02_count_digits.md` | Problem: Count the number of digits in N |
| `03_reverse_number.md` | Problem: Reverse a given number |
| `04_palindrome_number.md` | Problem: Check if a number is a palindrome |
| `05_armstrong_number.md` | Problem: Check if a number is an Armstrong number |
| `06_print_all_divisors.md` | Problem: Print all divisors/factors of N |
| `07_check_prime.md` | Problem: Check if a number is prime |
| `08_gcd_hcf.md` | Problem: Find GCD/HCF using Euclidean Algorithm |

---

## The Single Most Important Concept

> **Digit Extraction** is the backbone of almost every problem in this section.
> If you understand how to extract digits, you can solve all the above problems.

### Quick Recap of Digit Extraction

```
N = 7789

Step 1: N % 10  → 9   (last digit), then N = N / 10 → 778
Step 2: N % 10  → 8   (last digit), then N = N / 10 → 77
Step 3: N % 10  → 7   (last digit), then N = N / 10 → 7
Step 4: N % 10  → 7   (last digit), then N = N / 10 → 0
Step 5: N == 0  → STOP
```

---

## Time Complexity Quick Reference

| Problem | Brute Force | Optimized |
|---------|------------|-----------|
| Count Digits | O(log₁₀ N) | O(1) using log formula |
| Reverse Number | O(log₁₀ N) | — |
| Palindrome Check | O(log₁₀ N) | — |
| Armstrong Number | O(log₁₀ N) | — |
| Print All Divisors | O(N) | O(√N) |
| Check Prime | O(N) | O(√N) |
| GCD / HCF | O(min(N1, N2)) | O(log_φ min(N1, N2)) |

---

## Key Time Complexity Rule

> **Whenever a loop performs division (or modulo), the time complexity is LOGARITHMIC.**
>
> - Dividing by 10 every iteration → **O(log₁₀ N)**
> - Dividing by 2 every iteration → **O(log₂ N)**
> - Dividing by 5 every iteration → **O(log₅ N)**
>
> If the number of iterations depends on **division**, the complexity is **NOT O(N)** — it is **O(log N)**.
