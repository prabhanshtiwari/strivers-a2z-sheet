# What Are Arrays and Strings in C++?

## Why Do We Need Arrays?

Imagine you need to store 50 numbers. Declaring 50 separate variables (`a`, `b`, `c`, ... ) is impractical:

```cpp
// BAD — Can't scale to 50 or 500 numbers
int a, b, c, d;
cin >> a >> b >> c >> d;
```

**Arrays** solve this by storing **multiple values of the same type** under a single name, accessed by index.

---

## Part 1: One-Dimensional Arrays

### Declaration and Size

```cpp
// Syntax: datatype arrayName[size];
int arr[5];    // An integer array that can hold 5 values
```

**How it looks in memory (conceptually):**

```
Index:  [0]  [1]  [2]  [3]  [4]
Value:  [ ]  [ ]  [ ]  [ ]  [ ]
```

- The array has **5 boxes** (indices 0 through 4)
- **First index is always 0** — this is called **zero-based indexing**
- Last index = size - 1 (for size 5, last index is 4)

---

### Storing Values — Manual Assignment

```cpp
int arr[5];
arr[0] = 3;    // Store 3 at index 0
arr[1] = 4;    // Store 4 at index 1
arr[2] = 5;    // Store 5 at index 2
arr[3] = 7;    // Store 7 at index 3
arr[4] = 9;    // Store 9 at index 4
```

---

### Taking Array Input via `cin`

```cpp
int arr[5];
// Taking each element one by one — fine for small arrays
cin >> arr[0];
cin >> arr[1];
cin >> arr[2];
cin >> arr[3];
cin >> arr[4];
```

---

### Combining Arrays with For Loops (Best Practice)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int arr[5];

    // Take input using loop — i goes from 0 to 4
    for (int i = 0; i < n; i++) {
        cin >> arr[i];    // arr[0], arr[1], ..., arr[4] each gets a value
    }

    // Print all elements using loop
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";    // Print each element with a space
    }
    cout << "\n";

    return 0;
}
```

**If input is:** `3 4 5 7 9`
**Output:** `3 4 5 7 9`

---

### Accessing and Modifying Elements

```cpp
int arr[5] = {3, 4, 5, 7, 9};

// Access a specific element
cout << arr[3] << "\n";      // Output: 7 (4th element, index 3)

// Modify an element — add 10 to it
arr[3] += 10;                // arr[3] is now 17 (7 + 10)
cout << arr[3] << "\n";      // Output: 17

// Replace element entirely
arr[3] = 16;                 // arr[3] is now 16
cout << arr[3] << "\n";      // Output: 16
```

> You can treat `arr[i]` exactly like a regular variable — read it, write to it, do math on it.

---

### Important: Data Type Consistency

All elements in an array **must be the same data type**:

```cpp
int arr[5];
arr[0] = 7.7;    // 7.7 gets TRUNCATED to 7 (decimal dropped!)
// Output: 7 (not 7.7)

double darr[5];
darr[0] = 7.7;   // Now 7.7 is stored correctly
// Output: 7.7
```

---

### Memory Layout

```
arr[0] → stored at memory address, say, 1000
arr[1] → stored at memory address 1004  (right after arr[0])
arr[2] → stored at memory address 1008  (right after arr[1])
arr[3] → stored at memory address 1012
arr[4] → stored at memory address 1016
```

> **Key Fact:** Array elements are stored in **consecutive memory addresses**.
> The first element's address is random (assigned by the system), but all subsequent elements are guaranteed to follow immediately after.

---

## Part 2: Two-Dimensional Arrays (2D Arrays)

A 2D array is an **array of arrays** — think of it as a grid or matrix with rows and columns.

### Declaration

```cpp
// Syntax: datatype arrayName[rows][columns];
int A[3][5];    // 3 rows, 5 columns = 15 total elements
```

**Visual representation:**

```
         Col0  Col1  Col2  Col3  Col4
Row 0: [  ]   [  ]   [  ]   [  ]   [  ]
Row 1: [  ]   [  ]   [  ]   [  ]   [  ]
Row 2: [  ]   [  ]   [  ]   [  ]   [  ]
```

### Indexing

```
A[0][0]  A[0][1]  A[0][2]  A[0][3]  A[0][4]
A[1][0]  A[1][1]  A[1][2]  A[1][3]  A[1][4]
A[2][0]  A[2][1]  A[2][2]  A[2][3]  A[2][4]
```

- Format: `A[row][column]`
- Row and column indexing both start at **0**

### Accessing and Assigning Values

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[3][5];    // 3 rows, 5 columns

    // Assign a value at row 1, column 3
    A[1][3] = 78;
    cout << A[1][3] << "\n";    // Output: 78

    // Uninitialized elements contain GARBAGE values!
    cout << A[1][2] << "\n";    // Output: some random number (undefined)

    return 0;
}
```

> **Warning:** Elements you **don't initialize** contain garbage values — whatever leftover data is in that memory location. Always initialize or check before using.

### Reading/Printing 2D Arrays with Nested Loops

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows = 3, cols = 5;
    int A[3][5];

    // Input: fill entire 2D array
    for (int i = 0; i < rows; i++) {         // Loop through each row
        for (int j = 0; j < cols; j++) {     // Loop through each column
            cin >> A[i][j];
        }
    }

    // Output: print entire 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";    // New line after each row
    }

    return 0;
}
```

> **Where is 2D array used?** Matrix problems, graph problems, grid-based problems — very common in DSA!

---

## Part 3: Strings

A string stores a **sequence of characters**. Internally, each character is stored at a separate index, just like an array.

### Declaration

```cpp
string s = "string";   // s holds the word "string"
```

**Character-level view:**
```
Index: [0]  [1]  [2]  [3]  [4]  [5]
Char:  's'  't'  'r'  'i'  'n'  'g'
```

---

### Accessing Individual Characters

```cpp
string s = "string";

cout << s[0] << "\n";    // Output: s  (first character)
cout << s[1] << "\n";    // Output: t
cout << s[2] << "\n";    // Output: r
```

---

### Finding String Length

```cpp
string s = "string";

// Method 1: s.size()
int len = s.size();

// Method 2: s.length()
int len2 = s.length();

cout << len << "\n";     // Output: 6

// Access last character using length
cout << s[len - 1] << "\n";   // Output: g (last character)
```

---

### Modifying Characters in a String

```cpp
string s = "string";

// Change character at index 0 from 's' to 'z'
s[0] = 'z';               // Use SINGLE QUOTES for characters

cout << s << "\n";         // Output: ztring
```

> **Important:** You must assign a **character** (single quotes) to a string index, not a string (double quotes). Assigning `s[0] = "z"` (double quotes) causes an **error**.

---

### Complete String Operations Example

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Striver";

    // Print entire string
    cout << s << "\n";                 // Output: Striver

    // Print individual characters
    cout << s[0] << "\n";             // Output: S
    cout << s[6] << "\n";             // Output: r (index 6 = last)

    // Find length
    int n = s.size();
    cout << "Length: " << n << "\n";  // Output: Length: 7

    // Print last character
    cout << s[n - 1] << "\n";        // Output: r

    // Modify a character
    s[0] = 'Z';
    cout << s << "\n";               // Output: Ztriver

    return 0;
}
```

---

## Part 4: Key Differences — Arrays vs Strings

| Feature | Array | String |
|---|---|---|
| Stores | Same-type values | Characters |
| Index starts at | 0 | 0 |
| Access individual element | `arr[i]` | `s[i]` |
| Get length/size | Manually tracked | `s.size()` or `s.length()` |
| Modify element | `arr[i] = newVal` | `s[i] = 'c'` (char only) |
| Memory | Consecutive addresses | Consecutive (same as array) |

---

## Part 5: Arrays Are Always Passed by Reference

When you pass an array to a function, **the original is always modified** (unlike regular variables which are passed by value/copy):

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function receives the array — no '&' needed; arrays pass by reference automatically
void doSomething(int arr[], int n) {
    arr[0] += 100;    // Modifies the ORIGINAL array
}

int main() {
    int n = 5;
    int arr[5] = {5, 10, 12, 30, 9};

    cout << "Before: " << arr[0] << "\n";    // Output: 5

    doSomething(arr, n);

    cout << "After: " << arr[0] << "\n";     // Output: 105 — original was changed!

    return 0;
}
```

> **Very Important:** Arrays in C++ **always pass by reference** to functions — no `&` symbol needed. Whatever you do to the array inside the function will affect the original array.

---

## Key Takeaways

- Arrays store **multiple values of the same type** under one name
- **Zero-based indexing**: first element is at index `0`, last at index `size - 1`
- Array elements are stored in **consecutive memory addresses**
- **Garbage values**: uninitialized array elements contain random values
- 2D arrays are grids accessed by `arr[row][column]`
- Strings store characters at indices, just like arrays
- Use `s.size()` or `s.length()` to get string length
- Strings store characters — use **single quotes** when assigning to `s[i]`
- Arrays are **always passed by reference** to functions (originals get modified)
