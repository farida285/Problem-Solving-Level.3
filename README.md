# 🧩 Problem Solving — Level 3

A collection of **51 C++ exercises** covering 2D arrays (matrices), recursion, string manipulation, and file I/O with a bank client management system. Built as part of Dr. Mohamed Abu Hudhud's structured roadmap.

---

## 📁 Structure

```
Problem Solving Level.3/
├── MyLib.h                         # Custom utility library
├── #01 – #20  ── Matrix problems
├── #21 – #22  ── Fibonacci (iterative & recursive)
├── #23 – #44  ── String manipulation
└── #45 – #51  ── File I/O & Bank Client System
```

---

## 📚 Topics Covered

### 🔢 2D Arrays — Matrix Operations (`#01` – `#20`)

| # | Problem |
|---|---------|
| 01 | Generate a random 3×3 matrix |
| 02 | Sum each row in a 3×3 matrix |
| 03 | Sum each row and store results in an array |
| 04 | Sum each column in a 3×3 matrix |
| 05 | Sum each column and store results in an array |
| 06 | Fill a matrix with ordered sequential numbers |
| 07 | Transpose a matrix |
| 08 | Element-wise multiplication of two matrices |
| 09 | Print the middle row and middle column |
| 10 | Sum all elements in a matrix |
| 11 | Check if the sum of two matrices' elements are equal |
| 12 | Check if two matrices are identical (element-by-element) |
| 13 | Check if a matrix is an identity matrix |
| 14 | Check if a matrix is a scalar matrix |
| 15 | Count occurrences of a specific number in a matrix |
| 16 | Check if a matrix is sparse (more zeros than non-zeros) |
| 17 | Check if a number exists in a matrix |
| 18 | Find intersected (common) numbers between two matrices |
| 19 | Find the max and min values in a matrix |
| 20 | Check if a matrix is a palindrome matrix |

---

### 🔁 Recursion (`#21` – `#22`)

| # | Problem |
|---|---------|
| 21 | Print Fibonacci series (iterative) |
| 22 | Print Fibonacci series using recursion |

---

### 🔤 String Manipulation (`#23` – `#44`)

| # | Problem |
|---|---------|
| 23 | Print the first letter of each word |
| 24 | Capitalize the first letter of each word |
| 25 | Lowercase the first letter of each word |
| 26 | Convert all letters to upper or lower case |
| 27 | Invert the case of a single character |
| 28 | Invert the case of all letters in a string |
| 29 | Count uppercase and lowercase letters |
| 30 | Count occurrences of a letter in a string |
| 31 | Count a letter (with match-case option) |
| 32 | Check if a character is a vowel |
| 33 | Count vowels in a string |
| 34 | Print all vowels in a string |
| 35 | Print all words in a string |
| 36 | Count the number of words in a string |
| 37 | Split a string by a separator |
| 38 | Trim (left, right, and both) whitespace |
| 39 | Join a vector of strings with a separator |
| 40 | Join an array and a vector of strings |
| 41 | Reverse the words in a string |
| 42 | Replace a word in a string |
| 43 | Replace a word (with match-case option) |
| 44 | Remove all punctuation from a string |

---

### 🗂️ File I/O — Bank Client System (`#45` – `#51`)

| # | Problem |
|---|---------|
| 45 | Convert a client record (struct) to a delimited line |
| 46 | Convert a delimited line back to a client record |
| 47 | Add new clients and save them to a file |
| 48 | Read and display all clients from a file |
| 49 | Find a client by account number |
| 50 | Delete a client by account number |
| 51 | Update a client's data by account number |

> File records are stored using `#//#` as the field separator.

---

## 🛠️ Custom Library — `MyLib.h`

A personal header-only utility library with two namespaces:

### `mystring` namespace
- `MyIsUpper` / `MyIsLower` — character case checks
- `MyToUpper` / `MyToLower` — character case conversion
- `InvertChar` — invert a character's case
- `UpperAllString` / `LowerAllString` — convert entire string
- `CountInString` — count small, capital, or all characters (uses `enWhatCount` enum)
- `MyStringLength` — custom string length (manual null-terminator traversal)
- `IsVowel` / `CountVowel` — vowel detection and counting
- `CountEachWordInString` — word counter
- `SplitString` — split by any separator into a `vector<string>`
- `TrimLeft` / `TrimRight` / `Trim` — whitespace trimming
- `Join` — join a `vector<string>` with a separator

### `inputuser` namespace
- `IntegerNumber` — validated integer input
- `PositiveIntegerNumber` — validated positive integer input
- `PositiveShortNumberInRange` — integer input within a specified range
- `FloatNumber` — validated float input
- `YesOrNo` — yes/no prompt (accepts `y`, `yes`, `n`, `no`)
- `GetStringInSize` — string input with length constraints
- `InputStringFromUser` — full-line string input
- `InputCharFromUser` — single character input with validation

---

## ⚙️ How to Compile & Run

Any file can be compiled individually with `g++`:

```bash
g++ -o output "#01Random3x3Matrix.cpp"
./output
```

Files in `#45` – `#51` require no external dependencies beyond the C++ standard library.

---

## 🔗 GitHub

All projects from this roadmap are available at: [github.com/farida285](https://github.com/farida285)
