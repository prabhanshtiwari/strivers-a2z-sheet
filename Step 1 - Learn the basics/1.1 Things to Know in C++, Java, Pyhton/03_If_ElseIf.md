# If, Else, and Else-If Statements in C++

## What Are Conditional Statements?

Conditional statements allow your program to **make decisions**. They execute certain lines of code **only if** a condition is true.

Think of it in plain English:
> "If you are older than 18, you are an adult. Otherwise, you are not."

In C++, we express this exact logic using `if`, `else`, and `else if`.

---

## 1. Basic `if` Statement

```cpp
if (condition) {
    // This block runs ONLY if the condition is true
}
```

### Example — Check if Number is Positive

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;

    if (num > 0) {
        cout << "Number is positive" << "\n";   // Only runs if num > 0
    }

    return 0;
}
```

> **Note:** The `else` is NOT mandatory. If the `if` condition is false and there's no `else`, the program simply skips the block and continues.

---

## 2. `if`-`else` Statement

```cpp
if (condition) {
    // Runs if condition is TRUE
} else {
    // Runs if condition is FALSE
}
```

### Problem: Check if a Person is an Adult

> Take age as input. Print "You are an adult" if age ≥ 18, else print "You are not an adult".

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int age;
    cin >> age;    // Take age from user

    if (age >= 18) {
        // Condition true: age is 18 or more
        cout << "You are an adult" << "\n";
    } else {
        // Condition false: age is less than 18
        cout << "You are not an adult" << "\n";
    }

    return 0;
}
```

**Test Cases:**
- Input `20` → Output: `You are an adult`
- Input `15` → Output: `You are not an adult`
- Input `18` → Output: `You are an adult`

---

## 3. `if`-`else if`-`else` — Multiple Conditions

When you have **more than two** possible outcomes, chain `else if` blocks.

```cpp
if (condition1) {
    // Runs if condition1 is TRUE
} else if (condition2) {
    // Runs if condition1 is FALSE and condition2 is TRUE
} else if (condition3) {
    // Runs if condition1 and condition2 are FALSE, condition3 is TRUE
} else {
    // Runs if ALL conditions above are FALSE
}
```

### Why Use `else if` Instead of Multiple `if`?

**BAD — Multiple `if` (Inefficient):**
```cpp
// Every single if is checked, even after a match is found
// Wastes time for large inputs
if (marks < 25) { cout << "F"; }
if (marks >= 25 && marks <= 44) { cout << "E"; }
if (marks >= 45 && marks <= 49) { cout << "D"; }
// ... continues checking ALL conditions even if first was true
```

**GOOD — `else if` (Efficient):**
```cpp
// Once a match is found, ALL remaining conditions are SKIPPED
if (marks < 25) {
    cout << "F";
} else if (marks <= 44) {  // We KNOW marks >= 25 at this point
    cout << "E";
} else if (marks <= 49) {  // We KNOW marks >= 45 at this point
    cout << "D";
}
// No redundant checks!
```

> **Key Insight:** When using `else if`, once a condition is true, the program immediately **skips all remaining else-if and else blocks**. This saves time, especially with many conditions.

---

## 4. Problem — Grading System

> Rules: Below 25 → F, 25–44 → E, 45–49 → D, 50–59 → C, 60–69 → B, 70–100 → A.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int marks;
    cin >> marks;   // Take marks from user

    if (marks < 25) {
        // No need to check upper bound; any value here is definitely < 25
        cout << "F" << "\n";
    } else if (marks <= 44) {
        // We already know marks >= 25 (previous condition was false)
        // So we only check the upper bound
        cout << "E" << "\n";
    } else if (marks <= 49) {
        // We already know marks >= 45
        cout << "D" << "\n";
    } else if (marks <= 59) {
        // We already know marks >= 50
        cout << "C" << "\n";
    } else if (marks <= 69) {
        // We already know marks >= 60
        cout << "B" << "\n";
    } else {
        // All above conditions false, so marks >= 70
        cout << "A" << "\n";
    }

    return 0;
}
```

**Test Cases:**
- Input `85` → Output: `A`
- Input `24` → Output: `F`
- Input `50` → Output: `C`

---

## 5. Multiple Conditions with `&&` and `||`

### `&&` (AND) — Both conditions must be true

```cpp
if (marks >= 25 && marks <= 44) {
    // Runs only if marks is between 25 AND 44
    cout << "Grade E";
}
```

### `||` (OR) — At least one condition must be true

```cpp
if (age < 0 || age > 150) {
    // Runs if age is negative OR unrealistically large
    cout << "Invalid age";
}
```

---

## 6. Nested `if` Statements

You can place `if` conditions **inside** other `if` or `else if` blocks. These are called **nested if** statements.

### Problem — Job Eligibility with Retirement Check

> Rules:
> - Age < 18: Not eligible for job
> - 18 ≤ Age ≤ 54: Eligible for job
> - 55 ≤ Age ≤ 57: Eligible for job, but retirement soon
> - Age > 57: Retirement time

**Method 1 — Using `else if` chain:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int age;
    cin >> age;

    if (age < 18) {
        cout << "Not eligible for job" << "\n";
    } else if (age <= 54) {
        // We know age >= 18 here
        cout << "Eligible for the job" << "\n";
    } else if (age <= 57) {
        // We know age >= 55 here
        cout << "Eligible for the job, but retirement soon" << "\n";
    } else {
        // We know age > 57 here
        cout << "Retirement time" << "\n";
    }

    return 0;
}
```

**Method 2 — Using Nested `if` (same result, different structure):**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int age;
    cin >> age;

    if (age < 18) {
        cout << "Not eligible for job" << "\n";
    } else if (age <= 57) {
        // We know age is 18–57; eligible for sure
        cout << "Eligible for the job" << "\n";

        // NESTED if: Check if retirement is near
        if (age >= 55) {
            // Still within the outer else-if block (age 18–57)
            // But specifically checking if age >= 55
            cout << "But retirement soon" << "\n";
        }
    } else {
        cout << "Retirement time" << "\n";
    }

    return 0;
}
```

**Test Cases:**
- Input `55` → Output: `Eligible for the job` + `But retirement soon`
- Input `30` → Output: `Eligible for the job`
- Input `15` → Output: `Not eligible for job`
- Input `60` → Output: `Retirement time`

> **Key Point about Nested `if`:** Inside any `if` or `else if` block, you can write another complete `if`/`else if`/`else` structure. The inner conditions are only checked **after** the outer condition is already confirmed to be true.

---

## 7. Optimization Technique — Trimming Conditions

When using `else if`, you **don't need to repeat** the lower bound check:

```cpp
// REDUNDANT (works but wastes clarity):
} else if (marks >= 25 && marks <= 44) {

// OPTIMIZED (cleaner, using else if's implied guarantee):
} else if (marks <= 44) {   // >= 25 is already guaranteed by the previous else
```

As you chain `else if` blocks:
- The first `else if` already implies the first `if` was false
- So you only need to check the **new upper bound**

---

## 8. Summary

| Construct | When to Use |
|---|---|
| `if` | One condition to check |
| `if`-`else` | Two possible outcomes |
| `if`-`else if`-`else` | Three or more possible outcomes |
| Nested `if` | Additional conditions inside an already-true block |
| `&&` (AND) | Both conditions must be true |
| `||` (OR) | At least one condition must be true |

## 9. Key Takeaways

- `else` is **optional** after `if`
- Use `else if` instead of multiple `if` statements for **efficiency** — once a match is found, remaining conditions are skipped
- Inside any `if`/`else if` block, you can write another `if` — that's nested `if`
- When chaining `else if`, you can **trim redundant lower-bound checks** since they're implied
- `&&` requires both sides to be true; `||` requires at least one side to be true
