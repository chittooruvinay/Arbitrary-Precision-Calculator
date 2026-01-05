# Arbitrary-Precision-Calculator
🧮 Arbitrary Precision Calculator – C Project (Data Structures)

A C-based implementation of an Arbitrary Precision Calculator using Data Structures. This project performs arithmetic operations on very large numbers beyond the limits of built-in data types by storing digits individually and processing them manually.

📌 Features

Supports integers of unlimited length

Performs Addition, Subtraction, Multiplication, and Division

Handles positive and negative numbers

Digit-by-digit computation using linked lists

Accurate carry and borrow handling

Proper quotient and remainder calculation

Leading zero removal for clean output

🧠 How It Works
🔢 Number Representation

Each digit is stored in a node of a linked list

Numbers are stored in reverse order for efficient arithmetic

➕ Addition Logic

Add digits one by one from least significant digit

Carry is propagated across nodes

➖ Subtraction Logic

Compare operands to determine result sign

Borrow handled explicitly during subtraction

✖️ Multiplication Logic

Follows manual multiplication technique

Intermediate results are shifted and accumulated

➗ Division Logic

Uses long-division style repeated subtraction

Determines quotient digit by digit

Handles division by large numbers safely

🧩 Data Structures Used

Singly / Doubly Linked Lists

Dynamic memory allocation

Pointer-based traversal

🛠️ Technologies Used

C Programming

Data Structures

Bitwise and arithmetic logic

File-based input handling

📖 About

This project demonstrates how arithmetic operations can be implemented for numbers of arbitrary size without relying on native data types. It is useful in cryptography, scientific computing, and competitive programming, and serves as a strong demonstration of data structure fundamentals.
