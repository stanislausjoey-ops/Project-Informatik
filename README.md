# Praktikum Informatik 1 : Introduction to C++ Programming

**Course:** Praktikum Informatik 1 (PI1) – Summer Semester 2024  
**Institution:** RWTH Aachen University, Institute for Human-Machine Interaction  
**Language:** C++  
**IDE:** Eclipse CDT / Qt Creator  

**Overview**

This repository contains my implementations for all nine assignments completed as part of the *Praktikum Informatik 1* course at RWTH Aachen University. The course provided a structured, hands on introduction to C++ programming, covering fundamental language concepts through to advanced object-oriented design and GUI development.

**Labs & Key Concepts**

- **Project 1 – Data Types, Operators & Structures**  
  Implemented programs to explore C++ primitive data types, arithmetic operators, and explicit type casting. Built structured data types (`struct`) to group related data and applied them in practical console applications.

- **Project 2 – Control Flow, Pointers, References & Functions**  
  Implemented both recursive and iterative algorithms for computing Fibonacci numbers. Worked with arrays, pointers, references, dynamic memory allocation, and modular function design. Applied advanced debugger features (breakpoints, step-into, step-over) for systematic error analysis.

- **Project 3– Complex Projects, Testing & Documentation**  
  Developed a fully functional, two-player *Reversi* board game using a test-driven development (TDD) approach. Implemented core game logic functions (possible moves validation, turn execution, win detection) independently, verified each function with unit tests, and produced code documentation using Doxygen.

- **Project 4 – Introduction to Classes (OOP)**  
  Designed and implemented a `Vektor` class encapsulating a 3D mathematical vector with private member variables and public methods for length calculation, normalization, scalar multiplication, and dot/cross products. Applied constructors, destructors, initializer lists, access specifiers, the `this` pointer, and include guards.

- **Project 5 – Dynamic Data Structures**  
  Built a singly linked list from scratch in C++ to implement a simple student database. Extended the list with backward traversal, element insertion at arbitrary positions, and reverse-order output, gaining practical experience with pointer-based memory management.

- **Project 6 – Standard Template Library (STL) & File I/O**  
  Refactored the student database from Lab 5 to use `std::vector` and STL algorithms. Implemented iterators and reverse iterators for traversal, and added file I/O functionality using `std::ifstream`/`std::ofstream` to persist and reload student records.

- **Project 7 – Operator Overloading & STL Algorithms**  
  Extended the student management system with overloaded comparison operators (`<`, `>`, `==`) based on student ID, enabling the use of STL sorting and searching algorithms (`std::sort`, `std::find`). Overloaded the stream output operator (`<<`) for clean, formatted console output.

- **Project 8 – Inheritance & Polymorphism**  
  Designed a media management system for a library (*Bücherei Bücherwurm*) using an inheritance hierarchy: a base class `Medium` with derived classes `Buch` (Book), `Magazin` (Magazine), and `DVD`. Implemented polymorphic behavior via virtual functions, introduced pure virtual methods to enforce an abstract interface, applied late binding, and overloaded operators for formatted output of all borrowed media.

- **Project 9 – GUI Programming with Qt**  
  Developed a graphical map application using the Qt framework. Designed a GUI with Qt Designer featuring labels, line edits, push buttons, and a `QGraphicsView` canvas. Implemented a `City` class and a `Street` class, each capable of rendering itself onto a `QGraphicsScene`. Loaded map data from file via an abstract `MapIo` interface, and integrated the **Dijkstra shortest-path algorithm** to compute and visually highlight optimal routes between cities on the map.

---

## Skills Demonstrated

- **C++ Core:** data types, control structures, pointers, references, dynamic memory, templates
- **OOP:** encapsulation, inheritance, polymorphism, abstract classes, virtual functions
- **STL:** `vector`, iterators, `sort`, `find`, stream-based file I/O
- **Software Engineering:** test-driven development, Doxygen documentation, modular project structure
- **GUI Development:** Qt framework, signals & slots, `QGraphicsScene`, event-driven programming
- **Algorithms:** recursion, Fibonacci computation, Reversi game logic, Dijkstra's algorithm
- **Tooling:** Eclipse CDT, Qt Creator, MinGW GCC compiler, GDB debugger
