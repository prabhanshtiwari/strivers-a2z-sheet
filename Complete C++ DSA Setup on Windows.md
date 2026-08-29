# Complete C++ DSA Setup on Windows — My Configuration Notes

## 1. Goal

Set up **C++ for DSA practice** on Windows so that I can:

> **Open any `.cpp` file → press `F5` → it automatically compiles and runs.**

My setup uses:

* **MSYS2**
* **UCRT64**
* **GCC / G++**
* **GDB**
* **VS Code**
* **Microsoft C/C++ extension**

---

# Part 1 — Install MSYS2

## 2. Install MSYS2

Download and install MSYS2.

The default installation location was used:

```text
C:\msys64
```

MSYS2 provides the native Windows GCC toolchain and package manager `pacman`. 

After installation, use the **MSYS2 UCRT64** terminal.

---

# Part 2 — Install the C++ Compiler

## 3. Install GCC

In **MSYS2 UCRT64**, install GCC:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

MSYS2's documentation uses this package for the UCRT64 GCC compiler. 

Verify:

```bash
gcc --version
```

GCC should display its installed version. 

---

## 4. Check G++

For C++ programming, verify the C++ compiler:

```bash
g++ --version
```

Check its location:

```bash
which g++
```

My output was:

```text
/ucrt64/bin/g++
```

Therefore the Windows location is:

```text
C:\msys64\ucrt64\bin\g++.exe
```

---

# Part 3 — Add G++ to Windows PATH

## 5. Why PATH was needed

Initially, running this in Windows Command Prompt:

```bash
g++ main.cpp -o main
```

gave:

```text
'g++' is not recognized as an internal or external command,
operable program or batch file.
```

The reason was that Windows couldn't find the MSYS2 compiler.

---

## 6. Add MSYS2 UCRT64 to PATH

Add this directory to the Windows **User Path**:

```text
C:\msys64\ucrt64\bin
```

### Steps

```text
Windows
  ↓
Search "Environment Variables"
  ↓
Edit the system environment variables
  ↓
Environment Variables
  ↓
User variables
  ↓
Path
  ↓
Edit
  ↓
New
```

Add:

```text
C:\msys64\ucrt64\bin
```

Then click **OK**.

Restart VS Code/terminal.

Now verify from Windows Command Prompt or VS Code terminal:

```bash
g++ --version
```

It should work.

---

# Part 4 — Install GDB

## 7. Why GDB is needed

`g++` **compiles** the C++ program.

`gdb` is the debugger that VS Code uses when running through **F5**.

Initially, F5 gave a GDB-related error because GDB wasn't actually installed in the UCRT64 environment.

---

## 8. Install GDB

In **MSYS2 UCRT64**, run:

```bash
pacman -S mingw-w64-ucrt-x86_64-gdb
```

Then verify:

```bash
which gdb
```

My output:

```text
/ucrt64/bin/gdb
```

Check the version:

```bash
gdb --version
```

My installed version:

```text
GNU gdb (GDB) 17.2
```

Finally verify the executable:

```bash
ls -l /ucrt64/bin/gdb.exe
```

It exists at:

```text
/ucrt64/bin/gdb.exe
```

Therefore Windows can access it at:

```text
C:\msys64\ucrt64\bin\gdb.exe
```

---

# Part 5 — Install VS Code

## 9. Install VS Code

Install **Visual Studio Code**.

Then install the Microsoft:

**C/C++ extension**

from the VS Code Extensions panel.

Shortcut:

```text
Ctrl + Shift + X
```

Search:

```text
C/C++
```

Install the Microsoft extension.

---

# Part 6 — My DSA Project

## 10. DSA folder

My DSA project is located at:

```text
C:\Users\Prabhansh Tiwari\OneDrive\Desktop\DSA\strivers-a2z-sheet
```

I open this folder directly in VS Code.

Example:

```text
strivers-a2z-sheet/
│
├── .vscode/
│   ├── launch.json
│   └── tasks.json
│
├── main.cpp
├── 01-largest-element.cpp
├── 02-second-largest.cpp
└── ...
```

---

# Part 7 — Configure `tasks.json`

## 11. What is `tasks.json`?

`tasks.json` tells VS Code:

> **How should I compile my C++ file?**

Create:

```text
.vscode/tasks.json
```

Use:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build C++",
            "type": "shell",
            "command": "C:\\msys64\\ucrt64\\bin\\g++.exe",
            "args": [
                "-std=c++17",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "problemMatcher": [
                "$gcc"
            ]
        }
    ]
}
```

### Important parts

```text
C:\msys64\ucrt64\bin\g++.exe
```

This explicitly tells VS Code which C++ compiler to use.

```text
-std=c++17
```

Compiles using the C++17 standard.

```text
${file}
```

Means:

> The currently open file.

```text
${fileDirname}
```

Means:

> The folder containing the current file.

```text
${fileBasenameNoExtension}.exe
```

Creates an executable using the current file's name.

For example:

```text
01-largest-element.cpp
```

becomes:

```text
01-largest-element.exe
```

---

# Part 8 — Configure `launch.json`

## 12. What is `launch.json`?

`launch.json` tells VS Code:

> **What should happen when I press F5?**

Create:

```text
.vscode/launch.json
```

Use:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C++ F5",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\msys64\\ucrt64\\bin\\gdb.exe",
            "preLaunchTask": "Build C++"
        }
    ]
}
```

---

# Part 9 — How F5 Works

The most important line is:

```json
"preLaunchTask": "Build C++"
```

This connects `launch.json` to `tasks.json`.

Therefore, when I press:

```text
F5
```

VS Code does:

```text
             F5
              ↓
      Read launch.json
              ↓
     Run "Build C++" task
              ↓
          g++ compiles
              ↓
       .exe is created
              ↓
       GDB launches it
              ↓
       Program starts
              ↓
       I enter my input
              ↓
       I see the output
```

So I **don't need to manually run**:

```bash
g++ main.cpp -o main
```

every time.

---

# Part 10 — My Final Workflow for Striver A2Z

For every DSA problem:

### Step 1

Create/open a `.cpp` file.

Example:

```text
largest-element.cpp
```

### Step 2

Write the solution.

### Step 3

Press:

```text
F5
```

### Step 4

Test the program.

That's it.

---

# Final Setup Checklist

```text
[✓] MSYS2 installed
[✓] UCRT64 environment
[✓] GCC installed
[✓] G++ installed
[✓] G++ added to Windows PATH
[✓] GDB installed
[✓] GDB verified
[✓] VS Code installed
[✓] Microsoft C/C++ extension installed
[✓] tasks.json configured
[✓] launch.json configured
[✓] F5 configured
```

### The two files I should never accidentally delete

```text
.vscode/tasks.json
.vscode/launch.json
```

Those two files contain the configuration that makes **F5 → compile → run** work.

And the key paths are:

```text
Compiler:
C:\msys64\ucrt64\bin\g++.exe

Debugger:
C:\msys64\ucrt64\bin\gdb.exe
```

**Your C++ DSA environment is now completely set up for your Striver A2Z practice.**
