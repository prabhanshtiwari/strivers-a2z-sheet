# For Loops in C++

## Why Do We Need Loops?

Imagine you need to print your name 500 times. Writing `cout << "Striver"` 500 times is not feasible.

**Without loop:**
```cpp
cout << "Striver\n";
cout << "Striver\n";
cout << "Striver\n";
// ... repeat 500 times — impractical!
```

**With for loop:**
```cpp
for (int i = 1; i <= 500; i++) {
    cout << "Striver\n";   // This single line runs 500 times!
}
```

> **Core Idea:** A loop lets you write the same line(s) of code **once** and have them execute **multiple times** automatically.
>
> **Striver's Note:** If you don't know for loops, you can't do anything in DSA. It is the single most important concept. Master it.

---

## 1. For Loop Syntax

```cpp
for (initialization; condition; update) {
    // Code to repeat
}
```

**Three parts of the for loop:**

| Part | Purpose | When It Runs |
|---|---|---|
| `initialization` | Declare and set starting value | **Once**, at the very beginning |
| `condition` | Check if loop should continue | **Before every iteration** |
| `update` | Change the variable | **After every iteration** |

---

## 2. How a For Loop Executes — Step by Step

```cpp
for (int i = 1; i <= 5; i++) {
    cout << "Striver\n";
}
```

**Execution trace:**

```
Step 1: i = 1 (initialization runs ONCE)
Step 2: Is 1 <= 5? YES → run loop body → print "Striver"
Step 3: i++ → i = 2
Step 4: Is 2 <= 5? YES → run loop body → print "Striver"
Step 5: i++ → i = 3
Step 6: Is 3 <= 5? YES → run loop body → print "Striver"
Step 7: i++ → i = 4
Step 8: Is 4 <= 5? YES → run loop body → print "Striver"
Step 9: i++ → i = 5
Step 10: Is 5 <= 5? YES → run loop body → print "Striver"
Step 11: i++ → i = 6
Step 12: Is 6 <= 5? NO → EXIT loop
```

**Output:** `Striver` printed **5 times**

---

## 3. Basic Examples

### Print Name N Times

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Print "Priyo" 10 times
    for (int i = 1; i <= 10; i++) {
        cout << "Priyo\n";    // Runs once per iteration
    }
    return 0;
}
```

### Print Numbers 1 to 10

```cpp
int main() {
    for (int i = 1; i <= 10; i++) {
        cout << i << "\n";    // Print the current value of i
    }
    return 0;
}
```

**Output:** 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

---

## 4. Scope of Loop Variable

The variable declared inside `for(int i = ...)` is only accessible **within the loop**:

```cpp
int main() {
    for (int i = 1; i <= 5; i++) {
        cout << i << "\n";    // i is accessible here
    }
    // cout << i;    // ERROR! i does not exist outside the loop

    return 0;
}
```

**To use `i` after the loop, declare it outside:**

```cpp
int main() {
    int i;                    // Declared OUTSIDE the loop
    for (i = 1; i <= 5; i++) {
        cout << i << "\n";
    }
    cout << "Final i: " << i << "\n";    // i = 6 (the value that failed the condition)
    return 0;
}
```

**Output of final `i`:** `6` (the loop stopped when `i` became 6 because `6 <= 5` is false)

---

## 5. Reverse For Loop (Counting Down)

```cpp
int main() {
    // Count down from 5 to 0
    for (int i = 5; i >= 0; i--) {
        cout << i << "\n";    // i decreases each iteration
    }
    return 0;
}
```

**Output:** 5, 4, 3, 2, 1, 0

---

## 6. Custom Step Size

You're NOT limited to `i++` (increment by 1). You can increment by any amount:

```cpp
int main() {
    // Increment by 5 each time: 1, 6, 11, 16, 21
    for (int i = 1; i <= 25; i += 5) {
        cout << i << "\n";
    }
    return 0;
}
```

**Output:** 1, 6, 11, 16, 21

> **Key Insight:** How you increment doesn't matter. What matters is that the loop runs the **correct number of times**. Design your condition based on how many iterations you need.

---

## 7. For Loop with If Condition Inside

You can place **any code** inside a for loop, including `if`-`else`:

```cpp
int main() {
    // Print only even numbers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {          // Check if i is even
            cout << i << "\n";
        }
    }
    return 0;
}
```

**Output:** 2, 4, 6, 8, 10

---

## 8. For Loop with Arrays

The most common real-world use of for loops is iterating over arrays:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int arr[5];

    // INPUT: take n values into array using loop
    for (int i = 0; i < n; i++) {
        cin >> arr[i];    // arr[0], arr[1], ..., arr[4]
    }

    // OUTPUT: print all values using loop
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
```

> Notice: for arrays, the loop goes from `i = 0` to `i < n` (not `i <= n`), because the last valid index is `n-1`.

---

## 9. Nested For Loops

A for loop **inside** another for loop — commonly used for 2D arrays and pattern printing.

```cpp
int main() {
    // Nested loop: outer runs 3 times, inner runs 5 times for each outer iteration
    for (int i = 0; i < 3; i++) {              // Outer loop: rows
        for (int j = 0; j < 5; j++) {          // Inner loop: columns
            cout << "* ";
        }
        cout << "\n";    // New line after each row
    }
    return 0;
}
```

**Output:**
```
* * * * *
* * * * *
* * * * *
```

> **Tip:** The inner loop **completes all its iterations** for every single iteration of the outer loop. For the example above: outer runs 3 times; for each, inner runs 5 times → total 15 `*` printed.

---

## 10. Complete Example — Sum of Array Elements

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;             // Take size of array

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];    // Fill array with input
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];    // Add each element to sum
    }

    cout << "Sum: " << sum << "\n";

    return 0;
}
```

---

## 11. Key Takeaways

- `for` loop structure: `for (init; condition; update) { body }`
- Initialization runs **once**; condition and update run **every iteration**
- Loop stops when the **condition becomes false**
- Variable declared inside `for(int i = ...)` has **scope only inside the loop**
- For arrays, loop from `i = 0` to `i < n` (zero-based indexing)
- You can use **any update** — `i++`, `i--`, `i += 5`, etc.
- Loops can contain `if`-`else`, other loops, function calls — **any code**
- **Nested for loops** are used for patterns and 2D arrays
- `for` loop is the **foundation of DSA** — master it completely
