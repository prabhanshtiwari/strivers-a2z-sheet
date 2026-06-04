# Functions — Pass by Value and Pass by Reference in C++

## What Are Functions?

A **function** is a named block of code that performs a specific task. Think of it like a food delivery app — you give it an order (input), it does the work, and brings you food (output). You don't need to know how it works internally; you just call it.

### Why Use Functions?

1. **Modularity:** Break large programs into smaller, manageable pieces
2. **Readability:** Name functions clearly so code is self-explanatory
3. **Reusability:** Write once, call multiple times instead of repeating code

---

## 1. Types of Functions

There are four main types, based on two axes:
- Does it **return** something or not? (`void` vs return type)
- Does it **take parameters** or not?

| Type | Returns | Parameters |
|---|---|---|
| Void, Non-parameterized | No | No |
| Void, Parameterized | No | Yes |
| Return, Non-parameterized | Yes | No |
| Return, Parameterized | Yes | Yes |

---

## 2. Void Function — No Return Value

A `void` function performs an action but **doesn't return any value**.

### Non-Parameterized Void Function (No Input)

```cpp
#include <bits/stdc++.h>
using namespace std;

// Define function OUTSIDE main
// 'void' means: this function does something but returns nothing
// Empty () means: takes no parameters
void printName() {
    cout << "Hey Striver\n";    // Just prints; no return
}

int main() {
    printName();    // CALL the function; execution jumps here, runs it, comes back

    return 0;
}
```

**Output:** `Hey Striver`

---

### Parameterized Void Function (With Input)

```cpp
#include <bits/stdc++.h>
using namespace std;

// This function TAKES a string 'name' as parameter
// It prints a greeting using whatever name is passed
void printName(string name) {
    cout << "Hey " << name << "\n";    // Uses the parameter
}

int main() {
    string name1, name2;
    cin >> name1 >> name2;    // e.g., Aman Raj

    printName(name1);    // Prints: Hey Aman
    printName(name2);    // Prints: Hey Raj — reusing same function!

    return 0;
}
```

**Input:** `Aman Raj`
**Output:**
```
Hey Aman
Hey Raj
```

> **Reusability in action:** Instead of writing `cout << "Hey " << name1` and `cout << "Hey " << name2` separately, we call one function twice with different values.

---

## 3. Return Function — Returns a Value

When a function **computes something and gives you the result**, it needs a return type and a `return` statement.

### Syntax

```cpp
returnType functionName(parameters) {
    // do work
    return result;    // Send result back to caller
}
```

### Example — Sum of Two Numbers

```cpp
#include <bits/stdc++.h>
using namespace std;

// Returns an int (the sum)
// Takes two int parameters
int sum(int num1, int num2) {
    int num3 = num1 + num2;    // Compute sum
    return num3;               // Send result back to whoever called this function
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;    // e.g., 5 and 6

    // Call sum(); execution PAUSES here, jumps to sum(), computes, comes back with result
    int result = sum(num1, num2);    // result = 11

    cout << result << "\n";    // Output: 11

    return 0;
}
```

**Execution flow for `sum(5, 6)`:**
```
main() → calls sum(5, 6) → jumps to sum()
  Inside sum(): num1=5, num2=6 → num3 = 5+6 = 11 → return 11
Back in main(): result = 11 → print 11
```

---

## 4. CRITICAL: Every Non-Void Function Must Return

If a function declares a return type (like `int`), it **must return a value in every possible code path**:

```cpp
// DANGEROUS — missing return in some cases
int maxmax(int num1, int num2) {
    if (num1 >= num2) {
        return num1;    // Returns when num1 >= num2
    }
    // What if num1 < num2? Nothing is returned → UNDEFINED BEHAVIOR (garbage value)
}
```

**Fix — Always return in all paths:**

```cpp
int maxmax(int num1, int num2) {
    if (num1 >= num2) {
        return num1;    // Returns if num1 is greater or equal
    }
    return num2;        // Returns if num2 is greater (covers all remaining cases)
}
```

> **Rule:** If your function has a return type other than `void`, make sure **every possible branch** ends with a `return` statement.

---

## 5. Built-in Functions

C++ provides many built-in functions:

```cpp
int a = 5, b = 10;

// min() — returns the smaller value
cout << min(a, b) << "\n";    // Output: 5

// max() — returns the larger value
cout << max(a, b) << "\n";    // Output: 10
```

> You can write your own `max` function, but **avoid naming it `max`** — that name is already taken by C++'s built-in. Use a different name like `maxmax` or `findMax`.

---

## 6. Pass By Value — A Copy is Sent

When you call a function and pass a variable, **C++ sends a COPY** of that variable, not the original.

### What This Means:

```cpp
#include <bits/stdc++.h>
using namespace std;

void doSomething(int number) {
    // 'number' is a COPY — not the original
    cout << number << "\n";    // Print: 10
    number += 5;
    cout << number << "\n";    // Print: 15
    number += 5;
    cout << number << "\n";    // Print: 20
}

int main() {
    int num = 10;

    doSomething(num);    // A COPY of num (value 10) is sent

    // Back in main, num is still 10 — the original was never touched!
    cout << "In main: " << num << "\n";    // Output: 10

    return 0;
}
```

**Output:**
```
10
15
20
In main: 10
```

**Why?**
```
main's num = 10  →  sits at memory address 1000
A COPY of num (also = 10)  →  sent to doSomething, stored at address 2000
doSomething modifies address 2000 (the copy)
main's address 1000 is untouched → still 10
```

### Pass By Value with String

```cpp
void changeString(string s) {
    s[0] = 'T';            // Modifies the COPY
    cout << s << "\n";    // Output: Taj
}

int main() {
    string s = "Raj";
    changeString(s);
    cout << s << "\n";    // Output: Raj (original unchanged!)
    return 0;
}
```

---

## 7. Pass By Reference — The Original is Sent

To allow a function to **modify the original variable**, pass it **by reference** using `&`:

```cpp
void doSomething(string &s) {    // '&' means: work on the ORIGINAL, not a copy
    s[0] = 'T';                  // Modifies the ORIGINAL string
    cout << s << "\n";           // Output: Taj
}

int main() {
    string s = "Raj";
    doSomething(s);
    cout << s << "\n";    // Output: Taj — original WAS modified!
    return 0;
}
```

### Pass By Reference with Integer

```cpp
#include <bits/stdc++.h>
using namespace std;

void doSomething(int &num) {     // '&' — reference to original
    cout << num << "\n";         // Print: 10
    num += 5;
    cout << num << "\n";         // Print: 15
    num += 5;
    cout << num << "\n";         // Print: 20
}

int main() {
    int num = 10;

    doSomething(num);    // The ORIGINAL num is passed

    // num was modified inside the function!
    cout << "In main: " << num << "\n";    // Output: 20

    return 0;
}
```

**Output:**
```
10
15
20
In main: 20
```

---

## 8. Pass By Value vs Pass By Reference — Side-by-Side

```cpp
void byValue(int x) {
    x = 100;                   // Modifies only the local copy
}

void byReference(int &x) {
    x = 100;                   // Modifies the ORIGINAL variable
}

int main() {
    int a = 10, b = 10;

    byValue(a);
    cout << a << "\n";         // Output: 10 (unchanged)

    byReference(b);
    cout << b << "\n";         // Output: 100 (changed!)

    return 0;
}
```

---

## 9. Arrays — Always Passed By Reference

Arrays are a **special case** — they are **always passed by reference**, even without the `&` symbol. Whatever you do to an array inside a function **always affects the original**:

```cpp
#include <bits/stdc++.h>
using namespace std;

// Array passed WITHOUT '&' — but still modifies original!
void doSomething(int arr[], int n) {
    // Print all elements (inside function)
    for (int i = 0; i < n; i++) {
        cout << "Inside function: " << arr[i] << "\n";
    }

    // Modify first element
    arr[0] += 100;    // This modifies the ORIGINAL array

    cout << "Value inside function after change: " << arr[0] << "\n";    // 105
}

int main() {
    int n = 5;
    int arr[5] = {5, 10, 12, 30, 9};

    cout << "Before: " << arr[0] << "\n";    // Output: 5

    doSomething(arr, n);

    cout << "After: " << arr[0] << "\n";     // Output: 105 — CHANGED!

    return 0;
}
```

> **Rule:** For arrays — no `&` needed; they always go by reference.
> For all other types (int, string, etc.) — add `&` to pass by reference.

---

## 10. Summary Table

| Passing Method | Syntax | What's Sent | Can Modify Original? |
|---|---|---|---|
| Pass by Value | `void f(int x)` | A copy | No |
| Pass by Reference | `void f(int &x)` | The original | Yes |
| Array (always reference) | `void f(int arr[], int n)` | The original array | Yes (always) |

---

## 11. Return Types Can Be Anything

Functions can return any data type:

```cpp
int sumFunc(int a, int b) { return a + b; }          // Returns int
double avgFunc(double a, double b) { return (a+b)/2; } // Returns double
string greet(string name) { return "Hello " + name; }  // Returns string
// Can also return vectors, arrays, etc.
```

---

## 12. Key Takeaways

- Functions = reusable, modular, readable code blocks
- `void` functions perform actions but don't return a value
- Return functions compute and send back a result using `return`
- **Every non-void function must return a value** in all code paths
- **Pass by value**: a copy is sent; original unchanged; default behavior
- **Pass by reference** (`&`): the original is sent; changes persist after function call
- **Arrays are always passed by reference** — no `&` needed
- For `vector`, `map`, `list`, etc., you **do need `&`** to pass by reference
- Function names cannot duplicate built-in names (`max`, `min`, etc.)
- Functions will be used **in every single DSA problem** — understand them deeply
