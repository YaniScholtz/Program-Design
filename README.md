# C++ Object-Oriented Practical Projects

This repository contains  C++ practical assignments designed to demonstrate core concepts in object-oriented programming, memory management, and dynamic data structures.

---

## 1. Building Occupancy System (Prac1)

Reads data from a text file (`building.data`) and processes it to display which individuals are present on specific floors. The system handles:

- String parsing and integer conversion
- Dynamic 2D arrays for storing occupants
- File reading and memory allocation
- Sorting and selective output

### Skills:
- File I/O
- String manipulation
- Dynamic memory allocation
- Pointer-based 2D array usage

---

##  2. Matrix Class (Prac2)

Implements a `Matrix` class with support for:

- Dynamic 3D matrix creation
- Row and column resizing
- Safe memory management via constructors and destructors
- Clean separation of logic via class methods

### Skills:
- 3D pointer arrays
- Constructors/destructors
- Custom resizing logic
- Encapsulation

---

## ♟ 3. Chessboard Simulation (Prac3)

Implements a `Chessboard` class using dynamic 2D arrays of `Chesspiece` pointers, with:

- Custom deep-copy constructor
- Operator overloading (`=`, `+=`)
- Piece addition and removal
- Safe memory handling in destruction

### Skills:
- Inheritance and polymorphism (via `Chesspiece`)
- Deep copy logic
- Operator overloading
- Dynamic memory management

---

##  Array Processing with Inheritance (Prac4)

This practical demonstrates advanced object-oriented programming through the use of a `TwoDArray` base class and three derived classes:

- `CountArray`: Counts the number of elements in each row
- `SumArray`: Calculates the sum of elements in each row
- `SortArray`: Returns a sorted version of each row

Each derived class overrides the subscript operator (`operator[]`) to perform its unique operation when indexing.

### Files:
- `TwoDArray.cpp` – Base class for 2D dynamic arrays with conversion overloads
- `CountArray.cpp` – Inherits from `TwoDArray` to count row sizes
- `SumArray.cpp` – Inherits from `TwoDArray` to sum row elements
- `SortArray.cpp` – Inherits from `TwoDArray` to sort row elements
- `Task1.cpp` – Tests deep copying, memory management, and type conversions
- `Task2.cpp` – Tests polymorphic behaviour with `CountArray`, `SumArray`, and `SortArray`
- `main.cpp` – Runs both Task1 and Task2 test suites

### Skills:
- Inheritance and operator overloading
- Deep copying and safe memory handling
- Reusability via base class abstraction
- Modular and testable C++ design

## Number Testing Framework (Prac5)

This practical demonstrates advanced inheritance and polymorphism using a modular number testing system.  

### Key Components:
- `IsEvenOdd` – Checks if a number is even
- `IsPrimeNumber` – Checks if a number is prime
- `IsDivisible` – Checks if a number is divisible by a given value
- `IsGreater` – Checks if a number is greater than a given value
- `IsSmaller` – Checks if a number is smaller than a given value
- `TesterInterface` – Manages a dynamic array of testers and supports adding, cloning, removing, and evaluating testers

### Concepts Demonstrated:
- Abstract base classes and virtual functions
- Inheritance (Value-dependent vs. Value-independent testers)
- Deep copying via custom copy constructors
- Operator overloading
- Runtime object tracking and dynamic memory management

### How it Works:
1. A `TesterInterface` is initialized with a maximum number of testers.
2. Testers (e.g. `IsPrimeNumber`, `IsGreater(10)`) are added to the interface.
3. A number is evaluated against all testers — it passes only if it passes every test.
4. Failed testers can be queried, counted, or removed.

### Files:
- `main.cpp` – Sets up and runs the test interface
- `TesterInterface.cpp` – Interface logic and memory management
- `NumberTester.cpp` – Abstract base class
- `ValueDependantTester.cpp`, `ValueIndependantTester.cpp` – Intermediate classes
- `IsEvenOdd.cpp`, `IsPrimeNumber.cpp`, `IsDivisible.cpp`, `IsGreater.cpp`, `IsSmaller.cpp` – Individual testers


##  Cargo & Passenger Loading System (Prac6)

This practical simulates loading cargo, passengers, and secret cargo onto planes using templated data structures, exception handling, and polymorphism.

### Key Components:
- **Plane<T>** – Templated class that stores objects with weight and value
- **Controller<T>** – Controls the loading, tracks value, and generates summaries
- **Cargo** – Regular cargo with weight and value
- **Passenger** – Passenger with ID, ticket price, and weight
- **SecretCargo** – Cargo that hides value and throws access exceptions
- **Exception classes** – Custom exceptions for:
  - Overweight loading (`AboveWeightEx`)
  - Accessing secret or unauthorised cargo (`UnauthorisedEx`)
  - Handling undervalued cargo (`UndervaluedEx`)

### Concepts Demonstrated:
- Class templates and dynamic memory
- Object-oriented inheritance and method overriding
- Exception throwing and catching
- Polymorphic method calls on a variety of objects

### Files:
- `main.cpp` – Runs tests for Cargo, Passenger, and SecretCargo scenarios
- `Cargo.cpp`, `Passenger.cpp`, `SecretCargo.cpp` – Implement various `Loadable` object types
- `Controller.cpp` – Logic for managing and validating plane content
- `Exceptions.cpp` – Custom error-handling logic

 ## Calendar Management System (Prac7)

This practical builds a custom calendar management tool using a linked list of `Event` objects and demonstrates dynamic object creation, deletion, and filtering.

### Key Components:
- **Event** – Represents a calendar event with ID, type, start, and end time.
- **Calendar** – Maintains a sorted singly linked list of `Event` objects and supports:
  - Creating and deleting events
  - Filtering events by ID, start time, end time, or type
  - Finding the next upcoming event
  - Printing the calendar contents using `operator<<`

### Features Demonstrated:
- Pointer-based linked list management
- Class constructors, destructors, and operator overloading
- Deep filtering with optional parameters (using pointers)
- Formatted event output

### Files:
- `main.cpp` – Runs multiple calendar test scenarios (create, display, remove, filter)
- `Calendar.cpp` – Event list management with filtering, sorting, and printing
- `Event.cpp` – Event definition and stream output formatting

##  Sortable Linked List (Prac8)

This practical implements a generic doubly linked list using C++ templates. The list can dynamically store and sort values in either ascending or descending order. It also allows for value removal and retrieval of sorted elements.

### Key Components:
- **SortNode<T>** – A doubly linked list node storing a value and pointers to `next` and `prev`.
- **SortList<T>** – A templated list class with:
  - `add()` – Add a node to the list
  - `remove(val)` – Remove the node with the specified value
  - `sort()` – Sorts the list in ascending or descending order
  - `setAsc(bool)` – Sets the sort direction
  - `print()` – Returns a comma-separated string of values

### Features Demonstrated:
- Template classes
- Dynamic memory and linked list manipulation
- Sorting using value comparisons
- Operator overloading and output formatting

### Files:
- `SortNode.cpp` – Node class for templated doubly linked list
- `SortList.cpp` – List class with sorting and value-based operations
- `main.cpp` – Demonstrates list creation, sorting, removing values, and printing in both ascending and descending order

##  Stack-Based Arithmetic Calculator (Prac9)

This practical implements a generic calculator using stacks and templated operator classes. It supports evaluating arithmetic expressions using dynamically stacked values and custom operator classes (`+`, `-`, `*`), with support for both `int` and `double` types.

### Key Components:
- **Calculator<T>** – Main calculator class that manages:
  - A `Stack<T>` for values
  - A `Stack<Operator<T>*>` for operators
  - Custom `calculate()` logic to evaluate expressions
- **Operator<T>** – Abstract base class for all operators
- **PlusOperator**, **MinusOperator**, **MultiplyOperator** – Operator subclasses that override `operator()` and implement `clone()`
- **Stack<T>** – Custom templated stack implementation with deep copying, `contains()`, and `reverse()`

### Features Demonstrated:
- Templates and polymorphism
- Stack operations (push, pop, reverse, top)
- Operator overloading via function objects
- Dynamic memory and cloning with virtual functions

### Files:
- `main.cpp` – Contains multiple test cases for stacks and calculator (int and double)
- `Calculator.cpp` – Templated calculator logic using two internal stacks
- `Stack.cpp` – Templated stack implementation
- `Operator.cpp`, `PlusOperator.cpp`, `MinusOperator.cpp`, `MultiplyOperator.cpp` – Custom operator classes with override logic

  ---

##  Genetic Algorithm Framework (Assignment1)

This practical implements a full-featured **Genetic Algorithm** in C++, capable of evolving a population of chromosomes over multiple generations based on a custom fitness function.

### Key Components:
- **Chromosome** – A boolean gene sequence with:
  - Fitness calculation
  - Crossover and mutation logic
  - Custom toString() representation
- **FitnessFunction** – Calculates the fitness score as the ratio of `true` values to total genes
- **GA** – The genetic algorithm core class, implementing:
  - Selection and inverse selection
  - Crossover and mutation
  - Population evolution
  - Accuracy, standard deviation, and diversity metrics
- **RandomGenerator** – Seeded random boolean generator
- **Benchmarking** – Performance evaluation over multiple runs and generations

### Files:
- `main.cpp` – Demonstrates fitness benchmarking and multiple generations
- `Chromosome.cpp` – Core DNA representation with crossover and mutation
- `FitnessFunction.cpp` – Fitness score logic
- `GA.cpp` – Genetic algorithm logic and benchmarking
- `RandomGenerator.cpp` – Pseudo-random boolean generator

### Features Demonstrated:
- Object-oriented design with deep copying
- Genetic operators (selection, crossover, mutation)
- Fitness tracking and statistical analysis
- Evolution-based benchmarking and runtime testing

##  Matrix and Vector Arithmetic (Assignment2)

This practical implements advanced matrix and vector arithmetic using class-based design and extensive operator overloading. It includes:

- Safe file reading
- Exception-safe access
- Linear equation solving via Gaussian elimination
- Power, transpose, and scalar operations

### Key Components:
- **Matrix** – 2D dynamic array with:
  - Operator overloads for `+`, `-`, `*`, `/`, `^`, `~`, `|`, `[]`, and `()`
  - Gaussian elimination and linear system solving via overloaded `|` and `|=`
  - Exception handling for invalid dimensions, division by zero, and index out-of-bounds
- **Vector** – 1D array class with matching scalar and element-wise operations
- **Arithmetic (base class)** – Interface for shared functionality between Matrix and Vector
- **main.cpp** – Runs full test suite:
  - File reading
  - Vector/Matrix creation
  - Arithmetic operations
  - Solving systems of linear equations

### Features Demonstrated:
- Deep copy constructors and assignment
- Exception handling
- Operator chaining
- Matrix multiplication and power
- Row-wise access via `[][]` and element-wise access via `()`
- Transpose (`~`), matrix power (`^`), and system solve (`|`)

### Files:
- `main.cpp` – Task 1: constructors and accessors  
  Task 2: arithmetic operations  
  Task 3: solving Ax = b using Gaussian elimination  
- `matrix.cpp`, `vector.cpp` – Core logic and overloads  
- `arithmetic.cpp` – Abstract base class

- 
