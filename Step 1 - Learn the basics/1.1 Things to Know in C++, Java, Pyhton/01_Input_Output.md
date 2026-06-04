# C++ Basic Input and Output

## 1. The Skeleton of a C++ Program

Every C++ program follows a fixed skeleton structure. This structure stays **constant** across all programs you'll ever write in C++.

```cpp
#include <bits/stdc++.h>   // Includes ALL C++ standard libraries at once
using namespace std;        // Allows using standard functions without "std::" prefix

int main() {
    // Your code goes here
    return 0;               // Signals successful program termination
}
```

### Why `#include <bits/stdc++.h>`?

- Instead of writing `#include <iostream>`, `#include <string>`, `#include <math.h>` etc. separately, this **single line includes everything**.
- It saves time. Yes, it takes slightly more compile time, but that is negligible compared to program run time.
- You can Google what libraries are inside it if you're curious, but you **don't need to know the internals**.

> **Tip from Striver:** Do NOT dig deep into why every syntax works the way it does when you're just starting out. Learn the basics first, move forward, and depth comes naturally with practice.

---

## 2. Output — Printing to Screen

Use `cout` (Console OUT) to print anything to the screen.

### Basic Print

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Hey Striver";   // Prints: Hey Striver
    return 0;
}
```

### Printing Multiple Items on Same Line

```cpp
int main() {
    cout << "Hey Striver" << "Hey Raj";   // Output: Hey StriverHey Raj
    return 0;
}
```

### Printing on New Lines — `\n` vs `endl`

Both `\n` and `endl` move output to the next line:

```cpp
int main() {
    cout << "Hey Striver" << "\n";   // Using \n (faster)
    cout << "Hey Raj" << endl;       // Using endl (slightly slower, but same result)
    return 0;
}
```

> **Key Difference:** `\n` is **faster** than `endl` because `endl` also flushes the output buffer. Prefer `\n` in competitive programming. Both are commonly used, so recognize both.

### Printing Multiple Things on One `cout`

```cpp
int main() {
    cout << "Hey Raj" << endl
         << "Hey Raj" << endl
         << "Hey Raj" << endl;
    // Output:
    // Hey Raj
    // Hey Raj
    // Hey Raj
    return 0;
}
```

---

## 3. `using namespace std` — Why It Matters

Without `using namespace std`, you'd have to write:

```cpp
std::cout << "Hey Striver";
std::cin >> x;
```

With `using namespace std`, `std::` is **automatically assumed** for all standard functions:

```cpp
cout << "Hey Striver";   // No std:: needed!
cin >> x;
```

> The `std::` prefix refers to the **standard namespace** where functions like `cout`, `cin`, `endl` live.

---

## 4. Input — Taking Values from User

Use `cin` (Console IN) to take input from the user.

### Taking a Single Integer Input

```cpp
int main() {
    int x;              // Declare a variable to store input
    cin >> x;           // User types a number; it gets stored in x

    cout << "Value of x is " << x << endl;
    // If user enters 10, Output: Value of x is 10
    return 0;
}
```

### Taking Two Variables as Input

```cpp
int main() {
    int x, y;           // Declare two variables

    cin >> x >> y;      // User can enter on same line or different lines

    cout << "Value of x and y: " << x << " " << y << endl;
    // If user enters: 5 10
    // Output: Value of x and y: 5 10
    return 0;
}
```

> **Note:** Whether you give inputs on the **same line** (separated by space) or on **different lines**, `cin` handles both. The first `cin` fills the first variable, the second fills the second.

---

## 5. Common Libraries You Should Know

| Library | Purpose |
|---|---|
| `#include <iostream>` | Input/Output (cin, cout) |
| `#include <string>` | String handling |
| `#include <math.h>` | Mathematical functions (sqrt, pow, etc.) |
| `#include <bits/stdc++.h>` | **All libraries combined** (recommended) |

---

## 6. Comments in C++

Comments are lines that the compiler **ignores** — they help explain your code.

```cpp
// This is a single-line comment — compiler skips this line entirely

/* This is a
   multi-line comment
   spanning multiple lines */

int x = 10;   // You can also put inline comments after code
```

---

## 7. Complete Example — Taking Input and Printing Output

```cpp
#include <bits/stdc++.h>    // Include all libraries
using namespace std;         // Use standard namespace

int main() {
    int a, b;                // Declare two integer variables

    cin >> a >> b;           // Take two integers as input

    // Print both values with labels
    cout << "Value of a: " << a << "\n";
    cout << "Value of b: " << b << "\n";
    cout << "Sum: " << a + b << "\n";

    return 0;                // End program successfully
}
```

**If user enters:** `5 7`

**Output:**
```
Value of a: 5
Value of b: 7
Sum: 12
```

---

## 8. Key Takeaways

- `#include <bits/stdc++.h>` — includes everything; use it always
- `using namespace std;` — avoids writing `std::` before every function
- `cout << ...` — prints output to screen
- `cin >> ...` — reads input from user
- `\n` and `endl` both go to new line; `\n` is faster
- `int main()` and `return 0;` are mandatory parts of the skeleton
- **Do not over-analyze** the internals when starting; just use and move forward
