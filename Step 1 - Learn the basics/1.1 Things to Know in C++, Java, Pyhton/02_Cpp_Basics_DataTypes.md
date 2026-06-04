# C++ Basics — Data Types

## What Are Data Types?

When you take input or work with values in a program, you need a **place to store** them. That storage container is defined by a **data type**.

A data type tells C++:
- What **kind** of value to store (number, decimal, text, character)
- How much **memory** to allocate
- What **range** of values it can hold

> **Striver's Rule:** Do NOT dig deep into the exact internal representation of data types at this stage. Just know what they store and their approximate ranges.

---

## 1. Integer Types — Whole Numbers

Used to store numbers **without** a decimal point: `10`, `-5`, `0`, `1000`.

### `int` — Standard Integer

```cpp
int x = 10;       // Assign directly
int y;
cin >> y;         // Or take from user input

cout << x << "\n";   // Output: 10
```

**Approximate Range:** `-10^9` to `10^9` (roughly ±1 billion)

---

### `long` — Larger Integer

```cpp
long x = 100000000000L;   // Stores larger numbers than int
cin >> x;
cout << x << "\n";
```

**Approximate Range:** `-10^12` to `10^12`

---

### `long long` — Largest Integer Type

```cpp
long long x = 1000000000000000LL;   // Very large numbers
cin >> x;
cout << x << "\n";
```

**Approximate Range:** `-10^18` to `10^18`

---

### When to Use Which?

| Data Type | Approx Range | Use When |
|---|---|---|
| `int` | ±10^9 | Default for most problems |
| `long` | ±10^12 | Number exceeds 10^9 |
| `long long` | ±10^18 | Number exceeds 10^12 (e.g., 10^13) |

> **Striver's Tip:** You don't need to remember exact ranges. Just remember: if the problem has numbers around 10^13, switch from `int` to `long long`. Memorize the rounded-off values.

**Why not always use `long long`?**
- Every data type takes memory. `long long` takes more memory than `int`.
- Using `long long` to store `10` wastes memory.
- Choose the smallest type that fits your data.

---

## 2. Decimal Types — Numbers with Decimal Points

Used to store values like `5.6`, `3.14`, `-0.001`.

### `float` — Single Precision Decimal

```cpp
float x = 5.6f;     // 'f' suffix optional
float y = 5;        // You can store whole numbers in float too
cout << y << "\n";  // Output: 5
```

### `double` — Double Precision Decimal (Preferred)

```cpp
double x = 5.6;
double y = 5;       // Integers can also be stored in double
cout << x << "\n";  // Output: 5.6
```

> **Note:** `double` has higher precision than `float`. In DSA, `double` is preferred whenever decimal values are needed.

---

## 3. String — Sequence of Characters

Used to store text like `"Hello"`, `"Striver"`, `"Hey Raj"`.

### Basic String Input/Output

```cpp
string s;
cin >> s;         // Takes ONE word (stops at space)
cout << s << "\n";
```

> **Important:** `cin >> s` only reads until the first **space**. If you type `"Hey Striver"`, only `"Hey"` is stored.

### Taking Multiple Words Separately

```cpp
string s1, s2;
cin >> s1 >> s2;                         // s1 = "Hey", s2 = "Striver"
cout << s1 << " " << s2 << "\n";         // Output: Hey Striver
```

### Taking a Full Line (with spaces) — `getline`

```cpp
string str;
getline(cin, str);          // Reads the ENTIRE line including spaces

cout << str << "\n";        // Output: Hey Striver I am cool
```

> `getline` reads until the user presses **Enter**. It captures spaces and gives you the full line as one string.

---

## 4. Character — Single Character

Used to store a single character: `'H'`, `'A'`, `'z'`, `'5'`.

```cpp
char ch;
cin >> ch;            // Reads single character
cout << ch << "\n";

// Or assign directly
char c = 'G';         // Single quotes for characters
cout << c << "\n";    // Output: G
```

> **Key Rule:** Characters use **single quotes** `'A'`. Strings use **double quotes** `"Hello"`.
>
> There are **256 characters** in the character set — all can be stored using `char`.
>
> A `char` takes **less memory** than `string` for a single character, so prefer `char` when storing only one character.

---

## 5. Complete Example — All Data Types Together

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Integer types
    int age = 20;                        // Whole number, small range
    long population = 7800000000L;       // Larger whole number
    long long bigNum = 9000000000000LL;  // Very large whole number

    // Decimal types
    float pi_approx = 3.14f;            // Less precise decimal
    double pi_precise = 3.14159265358;  // More precise decimal

    // Text types
    char grade = 'A';                   // Single character
    string name = "Striver";           // Multiple characters

    // Print all
    cout << "Age: " << age << "\n";
    cout << "Population: " << population << "\n";
    cout << "Big Number: " << bigNum << "\n";
    cout << "Pi (float): " << pi_approx << "\n";
    cout << "Pi (double): " << pi_precise << "\n";
    cout << "Grade: " << grade << "\n";
    cout << "Name: " << name << "\n";

    return 0;
}
```

---

## 6. Type Conversion (Implicit)

If you store a decimal in an `int`, the decimal part is **trimmed** (not rounded):

```cpp
int arr[5];
// If you try to store 7.7 in an int array:
arr[0] = 7.7;       // Gets stored as 7 (decimal part dropped)
cout << arr[0];     // Output: 7
```

> The data type you declare is the **law**. Any value that doesn't fit gets truncated or converted to fit.

---

## 7. Summary Table

| Type | Stores | Example Value | Approx Range |
|---|---|---|---|
| `int` | Whole number | `10`, `-5` | ±10^9 |
| `long` | Larger whole number | `10000000000` | ±10^12 |
| `long long` | Very large whole number | `10^17` | ±10^18 |
| `float` | Decimal (less precise) | `3.14f` | ~7 digits |
| `double` | Decimal (more precise) | `3.141592` | ~15 digits |
| `char` | Single character | `'A'` | 256 chars |
| `string` | Text / word / sentence | `"Hello"` | Any length |

---

## 8. Key Takeaways

- Choose the **smallest fitting data type** to save memory
- Use `int` by default; upgrade to `long long` when numbers exceed ~10^9
- Use `double` for decimal values (more precise than `float`)
- `char` uses single quotes; `string` uses double quotes
- `cin >>` stops at space for strings; use `getline(cin, s)` for full line input
- These data types are **all you need** to solve 99% of DSA problems
