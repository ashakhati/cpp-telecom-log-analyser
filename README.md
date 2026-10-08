# Telecom Log Analyzer

A small modern C++ project that analyzes telecom event logs and generates overall and per-UE handover statistics.

The project is designed to practice **modern C++ concepts** using a realistic telecom/LTE/5G-style scenario.

## Features

* Analyze telecom handover events
* Count total handovers
* Count successful handovers
* Count failed handovers
* Maintain statistics for each UE
* Use STL containers
* Demonstrate modern C++ features
* Build the project using CMake

## Example Events

The project works with events such as:

```text
UE 101 -> HANDOVER_SUCCESS
UE 101 -> HANDOVER_SUCCESS
UE 102 -> HANDOVER_FAILURE
UE 103 -> HANDOVER_FAILURE
UE 104 -> HANDOVER_SUCCESS
```

## Example Output

```text
Handover Statistics
-------------------
Total handovers : 5
Successful      : 3
Failed          : 2

UE Statistics
-------------
UE 104 total=1 success=1 failed=0
UE 103 total=1 success=0 failed=1
UE 102 total=1 success=0 failed=1
UE 101 total=2 success=2 failed=0
```

> The order of UEs may vary because `std::unordered_map` does not guarantee iteration order.

## Project Structure

```text
telecom-log-analyzer/
│
├── CMakeLists.txt
├── README.md
│
└── src/
    ├── LogEvent.h
    ├── LogEvent.cpp
    ├── logAnalyzer.h
    ├── logAnalyzer.cpp
    └── main.cpp
```

## C++ Concepts Used

### Core C++

* `struct`
* `class`
* `enum class`
* `const`
* references
* `auto`
* range-based `for`
* structured bindings

### STL

* `std::vector`
* `std::string`
* `std::unordered_map`
* STL algorithms

### Modern C++

* `const auto&`
* Type deduction with `auto`
* References
* Structured bindings
* Type-safe `enum class`

### C++ Design

* Header/source file separation
* Encapsulation
* Class member functions
* Separation of data and processing logic

### Build System

* CMake
* GCC / G++

## Design

The project uses `en
