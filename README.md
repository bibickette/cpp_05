🇫🇷 Version française disponible [ici](README_FR.md)

---

# Project presentation - `cpp_05`

## **Description**

This module introduces **exceptions** in C++ and focuses on handling errors safely and correctly.

Through these exercises, the goal is to learn how to throw, catch, and propagate exceptions, how to create custom exception classes, and how to ensure proper resource management even when errors occur. This reinforces **robust object-oriented design**.

---

## Languages & Technologies

**Language**

- C++ (C++98 standard)

**Technologies**

- Makefile

---

## Key Concepts

- Exception handling (`try`, `catch`, `throw`)
- Standard exceptions (`std::exception`)
- Custom exception classes
- Resource safety and memory management
- Strong exception safety guarantee
- Exception hierarchy and slicing

---

## Exercices Overview

### ex00. Mommy, when I grow up, I want to be a bureaucrat!

Introduction to basic exception handling:

- Handling standard exceptions
- Using `try`, `catch`, and `throw`

### ex01. Form up, maggots!

Creating and using custom exception classes:

- Implementing the `what()` method
- Throwing and catching custom exceptions

### ex02. No, you need form 28B, not 28C...

Ensuring resource safety and proper object management during exceptions:

- Proper constructor/destructor usage
- Avoiding memory leaks

### ex03. At least this beats coffee-making

Working with multiple exception levels and inheritance:

- Catching exceptions by base class type
- Understanding exception slicing
- Organizing error handling cleanly

---

## Compilation rules

All exercises are compiled using the following flags :

- `-Wall`
- `-Wextra`
- `-Werror`
- `-std=c++98`

---

# Using `cpp_05`

## How to use `cpp_05`

_Note : this repository contains only the `cpp_05` module. It is part of the global [cpp_modules](https://github.com/bibickette/cpp_modules) repository, which regroups all C++ modules._

1. Clone `cpp_05` in a folder first : `git clone https://github.com/bibickette/cpp_05.git`
2. Move into the repository : `cd cpp_05`
3. Compile the module : `make`; this will compile all exercises contained in the module
4. You can now move into each exercices and run the corresponding executable

---

_Project validation date : March 19, 2025_
