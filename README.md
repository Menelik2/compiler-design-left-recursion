# left-recursion-
 Left Recursion and Why It Must Be Removed for Top-Down Parsers

 # Left Recursion and Top-Down Parsing (C++)

This repository explains **left recursion**, why it must be removed for **top-down parsers**, and demonstrates the solution using **C++ (LL(1) parsing)**.

## 📌 Topics Covered
- What is left recursion
- Direct and indirect left recursion
- Why top-down parsers fail with left recursion
- Removal of left recursion
- LL(1) grammar transformation
- Recursive descent / predictive parsing
- C++ implementation

## 🧠 Theory
Left recursion occurs when a non-terminal symbol appears as the leftmost symbol in its own production.

Example:
E → E + T | T
Top-down parsers such as **Recursive Descent** and **LL(1)** cannot handle left recursion because it causes **infinite recursion**.

## 🔄 Grammar Transformation
Original grammar:
E → E + T | T


After removing left recursion:
E → T E'
E' → + T E' | ε


## 💻 Implementation
The `src/` folder contains:
- Tokenizer for arithmetic expressions
- LL(1) parser implementation
- Main driver program

## ▶️ How to Run
```bash
g++ src/*.cpp -o parser
./parser
