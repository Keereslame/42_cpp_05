# 📘 C++ Module 05 — Repetition & Exceptions

## 🎯 Module Objective

This module focuses on two fundamental concepts in C++:

* 🔁 **Exception handling**
* 🧱 **Advanced Object-Oriented Programming (inheritance, abstract classes, polymorphism)**

Through a deliberately painful bureaucratic system (yes, that’s the point 😄), you will learn how to design **robust, safe, and maintainable code**.

---

## ⚙️ Important Rules

* Required standard: **C++98**
* Compilation:

  ```bash
  c++ -Wall -Wextra -Werror -std=c++98
  ```
* ❌ Forbidden:

  * `printf`, `malloc`, `free`
  * STL (vector, map, etc.)
  * `using namespace std`
* ✅ Mandatory:

  * **Orthodox Canonical Form**
  * Proper memory management
  * Custom exceptions

---

## 🧠 Key Concepts to Master

---

### 1. ⚠️ Exceptions in C++

Exceptions allow you to handle errors **cleanly and safely** without breaking your program.

#### Why use exceptions?

* Separate business logic from error handling
* Avoid ambiguous return values
* Improve code readability

#### Basic syntax

```cpp
try {
    // risky code
} catch (std::exception &e) {
    std::cout << e.what() << std::endl;
}
```

#### Creating a custom exception

```cpp
class MyException : public std::exception {
public:
    const char* what() const throw() {
        return "Custom error";
    }
};
```

👉 Key ideas:

* Inherit from `std::exception`
* Override `what()`
* Use `throw` properly

---

### 2. 🧱 Orthodox Canonical Form

Every class should follow this structure:

```cpp
class MyClass {
public:
    MyClass();                             // default constructor
    MyClass(const MyClass &src);           // copy constructor
    MyClass &operator=(const MyClass &rhs); // assignment operator
    ~MyClass();                            // destructor
};
```

#### Why?

* Ensures safe object copying
* Prevents memory issues
* Fundamental in C++

---

### 3. 📊 Encapsulation

Core principle of OOP:

* Attributes → **private**
* Access through **getters/setters**

```cpp
private:
    int _value;

public:
    int getValue() const;
```

👉 Goal:

* Protect internal state
* Control how data is modified

---

### 4. 🧬 Inheritance

Allows you to create a hierarchy of classes.

```cpp
class Derived : public Base {
};
```

#### To understand:

* Code reuse
* Specialization of behavior
* `protected` vs `private`

---

### 5. 🧩 Abstract Classes

An abstract class contains **at least one pure virtual function**:

```cpp
class AForm {
public:
    virtual void execute() const = 0;
};
```

👉 It **cannot be instantiated**

#### Why?

* Define a **contract**
* Force derived classes to implement behavior

---

### 6. 🔄 Polymorphism

Allows you to use a common interface for different types.

```cpp
AForm* form = new ShrubberyCreationForm();
form->execute();
```

👉 The correct `execute()` is called thanks to **virtual functions**

---

### 7. 🧾 Operator Overloading

Example with `<<`:

```cpp
std::ostream &operator<<(std::ostream &out, const MyClass &obj);
```

👉 Useful for:

* Debugging
* Clean output formatting

---

### 8. 🔐 Const Correctness

Very important in this module:

```cpp
int getValue() const;
```

👉 Ensures the function does not modify the object.

---

## 📚 Exercise Structure

---

### 🧑‍💼 Ex00 — Bureaucrat

Goal:

* Understand **exceptions**
* Handle constrained attributes

Key ideas:

* Validation inside constructors
* Custom exceptions
* Invariants (grade between 1 and 150)

---

### 📄 Ex01 — Form

Goal:

* Interaction between classes
* Permission handling (grades)

Key ideas:

* Composition (Bureaucrat ↔ Form)
* Business logic + exceptions

---

### 🏛️ Ex02 — AForm & Inheritance

Goal:

* Learn **abstract classes**
* Implement polymorphism

Key ideas:

* Abstract base class
* Specialized derived classes
* `execute()` behavior

---

### 🤖 Ex03 — Intern

Goal:

* Dynamically create objects

Key ideas:

* Factory pattern (basic form)
* Avoid large `if/else`
* Map names to object creation

---

## 🚨 Common Pitfalls

* ❌ Forgetting `const`
* ❌ Poor exception handling
* ❌ Not following Orthodox Canonical Form
* ❌ Copying objects incorrectly
* ❌ Memory leaks (`new` without `delete`)
* ❌ Misusing inheritance

---

## 🧪 Tips for Success

* Test **edge cases**
* Use `std::cout` for debugging
* Compile frequently
* Read error messages carefully
* Make sure you understand every line you write

---

## 🧠 Module Philosophy

This module is not about just “making code work”, but about understanding:

* Why code should be structured properly
* How to handle errors cleanly
* How to build scalable systems

---

