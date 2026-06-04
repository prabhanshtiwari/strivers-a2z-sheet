# While Loops in C++

## Overview

C++ provides three types of loops, all serving the same fundamental purpose — **execute code repeatedly**:

1. `for` loop
2. `while` loop
3. `do-while` loop

The **task** is the same for all; only the **syntax** changes.

---

## 1. While Loop

### Syntax

```cpp
initialization;            // Set starting value BEFORE the loop

while (condition) {        // Keep looping AS LONG AS condition is true
    // Code to repeat

    update;               // Change variable — otherwise infinite loop!
}
```

### How It Differs from For Loop

| Feature | `for` loop | `while` loop |
|---|---|---|
| Initialization | Inside `for(...)` | **Before** the loop |
| Condition | Inside `for(...)` | Inside `while(...)` |
| Update | Inside `for(...)` | **Last line inside** loop body |

---

## 2. Converting a For Loop to While Loop

**For loop version:**
```cpp
for (int i = 1; i <= 5; i++) {
    cout << "Striver\n";
}
```

**Equivalent while loop:**
```cpp
int i = 1;                  // Initialization BEFORE the loop

while (i <= 5) {            // Condition checked before each iteration
    cout << "Striver\n";   // Loop body — same code as before

    i++;                    // Update — LAST line inside the loop
}
```

Both produce the **exact same output**: "Striver" printed 5 times.

---

## 3. Step-by-Step Execution

```cpp
int i = 1;

while (i <= 5) {
    cout << "Striver " << i << "\n";
    i++;
}
```

**Execution trace:**
```
i = 1 → Check: 1 <= 5? YES → Print "Striver 1" → i++ → i = 2
i = 2 → Check: 2 <= 5? YES → Print "Striver 2" → i++ → i = 3
i = 3 → Check: 3 <= 5? YES → Print "Striver 3" → i++ → i = 4
i = 4 → Check: 4 <= 5? YES → Print "Striver 4" → i++ → i = 5
i = 5 → Check: 5 <= 5? YES → Print "Striver 5" → i++ → i = 6
i = 6 → Check: 6 <= 5? NO  → EXIT loop
```

**Pattern:** Check → Execute → Update → Check → Execute → Update...

---

## 4. While Loop with Arrays

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int arr[5] = {3, 4, 5, 7, 9};

    int i = 0;                   // Initialize index before loop

    while (i < n) {              // Loop until all elements are processed
        cout << arr[i] << " ";  // Print current element
        i++;                     // Move to next index
    }
    cout << "\n";

    return 0;
}
```

**Output:** `3 4 5 7 9`

---

## 5. When to Use While vs For?

- Use **`for`** when you know **exactly how many times** the loop should run
- Use **`while`** when the number of iterations depends on a **runtime condition** (e.g., user input, reading until end of data)

```cpp
// Example: Keep taking input until user enters -1
int num;
cin >> num;

while (num != -1) {          // Loop UNTIL user enters -1
    cout << "You entered: " << num << "\n";
    cin >> num;              // Take next input at end of loop
}
cout << "Exited loop\n";
```

---

## 6. Do-While Loop

### The Problem with Regular While

If the **condition is false from the start**, a regular `while` loop **never executes**:

```cpp
int i = 2;

while (i <= 1) {             // 2 <= 1 is immediately FALSE
    cout << "Striver\n";    // This NEVER runs
    i++;
}
// Output: nothing
```

### When You Need Guaranteed First Execution

Sometimes you want the loop body to run **at least once**, no matter what the condition is. This is where `do-while` comes in.

### Do-While Syntax

```cpp
do {
    // Code — runs FIRST, then condition is checked

    update;
} while (condition);         // Semicolon required!
```

> **Key Difference:** In `do-while`, the **body executes first**, then the condition is checked. In `while`, the **condition is checked first**.

---

## 7. Do-While Example

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 2;               // Condition (i <= 1) will be FALSE immediately

    do {
        cout << "Striver\n";  // Runs ONCE regardless of condition
        i++;
    } while (i <= 1);         // Checked AFTER the body runs; 3 <= 1 is false → exit

    return 0;
}
```

**Output:** `Striver` printed **once** (despite condition being false from the start)

**Execution trace:**
```
i = 2 → Enter do block (no condition check yet)
Print "Striver"
i++ → i = 3
Check: 3 <= 1? NO → EXIT loop
```

---

## 8. Do-While with Condition That Remains False

```cpp
int i = 2;

do {
    cout << "Striver " << i << "\n";   // Runs first
    i++;
} while (i <= 1);

// After loop:
cout << "Value of i: " << i << "\n";  // i = 3
```

**Output:**
```
Striver 2
Value of i: 3
```

The loop body ran exactly **once**, then checked the condition, found it false, and exited.

---

## 9. Do-While for Menu-Driven Programs

A very practical use of `do-while` is showing a menu that **must display at least once**:

```cpp
int choice;

do {
    // Show menu — must show at least once
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    // Handle choice
    if (choice == 1) cout << "Adding...\n";
    else if (choice == 2) cout << "Subtracting...\n";

} while (choice != 3);      // Keep showing menu until user picks 3

cout << "Goodbye!\n";
```

---

## 10. Comparison — All Three Loops

```cpp
// FOR LOOP
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}

// WHILE LOOP — same output
int i = 1;
while (i <= 5) {
    cout << i << " ";
    i++;
}

// DO-WHILE — same output (condition is true from start)
int j = 1;
do {
    cout << j << " ";
    j++;
} while (j <= 5);

// All three output: 1 2 3 4 5
```

---

## 11. Infinite Loop Warning

If you forget the `update` in a while loop, it runs forever:

```cpp
int i = 1;
while (i <= 5) {
    cout << "Striver\n";
    // i++ is MISSING — i always stays 1 — INFINITE LOOP!
}
```

> Always make sure your loop has a way to eventually make the condition **false**.

---

## 12. Key Takeaways

| Loop Type | Condition Checked | Body Runs at Least Once? | Best For |
|---|---|---|---|
| `for` | Before each iteration | Only if condition is true | Known number of iterations |
| `while` | Before each iteration | Only if condition is true | Condition-dependent loops |
| `do-while` | **After** first iteration | **Always yes** | Guaranteed first execution |

- `while` and `for` are interchangeable; choose based on readability
- `do-while` is unique — the body **always runs at least once**
- `do-while` **requires a semicolon** after the closing `while(condition);`
- Always include an `update` statement to avoid infinite loops
- Use `while` when looping until an unknown condition is met (e.g., user input)
- All loop types can contain `if`-`else`, other loops, function calls
