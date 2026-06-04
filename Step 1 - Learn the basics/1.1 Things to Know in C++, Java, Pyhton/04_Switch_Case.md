# Switch Case Statements in C++

## What is a Switch Statement?

A `switch` statement is an **alternative to `if`-`else if`** for situations where you're checking a single variable against **many fixed values**. It is similar in function to chained `if`-`else if` blocks.

> **Striver's Note:** We generally don't use `switch` as often as `if`-`else` in DSA, but it is handy to know. `if`-`else` is usually preferred for better readability.

---

## 1. Syntax

```cpp
switch (variable) {
    case value1:
        // Code to run when variable == value1
        break;          // Exit the switch block
    case value2:
        // Code to run when variable == value2
        break;
    // ... more cases
    default:
        // Code to run if NO case matches
        break;
}
```

### How It Works:
1. The `switch` evaluates the variable
2. It **jumps directly** to the matching `case`
3. Executes code from that point **downward**
4. `break` exits the switch block immediately
5. If no case matches, `default` runs

---

## 2. The `break` Statement — Critical Concept

**Without `break`, switch "falls through"** — it keeps executing all cases below the matched one!

### Example Without `break` (Problem):

```cpp
int day = 5;
switch (day) {
    case 5:
        cout << "Friday";      // This runs (match found)
    case 6:
        cout << "Saturday";    // This ALSO runs! (no break)
    case 7:
        cout << "Sunday";      // This ALSO runs!
}
// Output: FridaySaturdaySunday  ← WRONG!
```

### Example With `break` (Correct):

```cpp
int day = 5;
switch (day) {
    case 5:
        cout << "Friday";      // This runs
        break;                 // EXIT switch immediately
    case 6:
        cout << "Saturday";    // Skipped
        break;
    case 7:
        cout << "Sunday";      // Skipped
        break;
}
// Output: Friday  ← CORRECT!
```

> **Key Rule:** Always put `break` at the end of each `case` (unless you intentionally want fall-through, which is rare).

---

## 3. The `default` Case

The `default` case runs when **none of the listed cases match** the variable.

```cpp
int day = 19;
switch (day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    // ...
    default:
        cout << "Invalid";    // Runs when no case matches
        break;
}
// Output: Invalid
```

> `default` is like the `else` in an `if`-`else` chain. It's optional but good practice to include it.
>
> `default` does NOT need a `break` if it's the last entry (the switch ends anyway), but it's good habit to include it.

---

## 4. Problem — Print Day Name from Day Number

> Take a number (1–7) as input. Print the corresponding day name.
> If input is outside 1–7, print "Invalid".

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int day;
    cin >> day;    // Take day number from user

    switch (day) {
        case 1:
            cout << "Monday" << "\n";
            break;    // Exit switch after printing Monday
        case 2:
            cout << "Tuesday" << "\n";
            break;
        case 3:
            cout << "Wednesday" << "\n";
            break;
        case 4:
            cout << "Thursday" << "\n";
            break;
        case 5:
            cout << "Friday" << "\n";
            break;
        case 6:
            cout << "Saturday" << "\n";
            break;
        case 7:
            cout << "Sunday" << "\n";
            break;
        default:
            // Runs if day is not between 1 and 7
            cout << "Invalid" << "\n";
            break;
    }

    return 0;
}
```

**Test Cases:**
- Input `1` → Output: `Monday`
- Input `5` → Output: `Friday`
- Input `7` → Output: `Sunday`
- Input `19` → Output: `Invalid`

---

## 5. What Happens After `break`?

When `break` is executed inside a `switch`, execution jumps to the **first line after the entire switch block**.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int day = 2;

    switch (day) {
        case 1:
            cout << "Monday" << "\n";
            break;
        case 2:
            cout << "Tuesday" << "\n";
            break;    // <-- Execution jumps here after this break
        case 3:
            cout << "Wednesday" << "\n";
            break;
        default:
            cout << "Invalid" << "\n";
            break;
    }

    // Execution resumes here after break
    cout << "Check: After switch block" << "\n";

    return 0;
}
```

**Output:**
```
Tuesday
Check: After switch block
```

---

## 6. Switch with Characters

Switch also works with `char` variables:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    char grade;
    cin >> grade;

    switch (grade) {
        case 'A':
            cout << "Excellent" << "\n";
            break;
        case 'B':
            cout << "Good" << "\n";
            break;
        case 'C':
            cout << "Average" << "\n";
            break;
        default:
            cout << "Invalid grade" << "\n";
            break;
    }

    return 0;
}
```

> **Note:** For `char`, write the value in **single quotes** inside `case`.

---

## 7. Switch vs If-Else — When to Use What?

| Feature | `switch` | `if`-`else if` |
|---|---|---|
| Variable comparison | Against fixed values only | Any condition/expression |
| Data types supported | `int`, `char` | Any type |
| Readability | Good for many fixed cases | Better for range checks |
| Commonly used in DSA | Less common | Very common |

> **Striver's Advice:** Know `switch` exists and understand how it works. In practice, most programmers prefer `if`-`else if` because it's more flexible and readable. Use `switch` when you have many specific fixed values to check (like day names, menu options).

---

## 8. Key Takeaways

- `switch(variable)` directly jumps to the matching `case` — efficient for many fixed values
- Always write `break` after each `case` to prevent fall-through
- `default` handles all cases that don't match any `case` — it's the `else` of switch
- `switch` works with `int` and `char` types
- Without `break`, all cases below the matched one will execute — this is called "fall-through"
- After `break`, execution continues at the first line **after** the switch block
- Prefer `if`-`else if` for range comparisons; use `switch` for specific fixed values
