# Data-Structure-ASU 📚

Lecture and practice implementations for core data structures in C++ 🚀

This repository is organized as independent mini-projects. Each folder focuses on one topic, with a small demo program in a main file.

## Repository Layout 🗂️

- ArrayList: Template-based dynamic array implementation with append, insert, remove, indexing, and expansion.
- LinkedList: Singly linked list with insertion/deletion, random access by index, node moving, and cycle detection utilities.
- Stack: Array-based stack with push/pop and dynamic expansion.
- Queue: Array-based queue with an interactive task organizer example.
- LinkedStack: Linked-list-based stack used to reverse characters in each word of a sentence.
- BST: Binary Search Tree with insertion, search, traversal orders, and deletion.
- Brainstorm Tasks: Standalone algorithm exercises (currently includes Stock Span) 💡.
- Class & Pointers: Introductory examples for classes, pointers, and dynamic allocation.
- BTS STL: STL notes and examples (currently commented reference code).
- Practice: Small C++ experiments and pointer basics.

## Prerequisites 🧰

- C++ compiler with C++11 or newer support
- On Windows (as used in this repo):
  - g++ from MinGW, or
  - MSVC cl.exe
- Optional: Visual Studio Code with C/C++ extension

## Build and Run ⚙️

Because each folder is independent, compile the target file inside that folder.

### Option 1: VS Code Task 🖥️

Use the existing build task:

- C/C++: g++.exe build active file

Steps:

1. Open the file you want to run (for example, LinkedList/main.cpp).
2. Run Build Task in VS Code.
3. Execute the generated exe from the same folder.

### Option 2: g++ in Terminal 💻

Open a terminal in the target folder, then compile the main file.

Example (LinkedList):

```bash
g++ -g main.cpp -o main.exe
./main.exe
```

Example (Queue):

```bash
g++ -g main.cpp -o main.exe
./main.exe
```

Notes:

- Many demos include implementation files directly in main.cpp using includes like "SomeClass.cpp".
- For those demos, compiling only main.cpp is expected and sufficient.

## What Each Module Demonstrates 🧠

### ArrayList

- Custom dynamic array growth strategy
- Insert/remove at index
- Comparison with std::vector usage in the demo

### LinkedList

- Node-based linear structure
- Insert and delete by position
- Cycle detection brainstorming and demonstration
- Optional cycle creation/breaking helpers for testing

### Stack (Array)

- LIFO operations
- Capacity expansion
- Applied example: decimal-to-binary conversion

### Queue (Array)

- FIFO operations
- Full/empty checks
- Applied example: interactive task organizer
- Comparison snippet using std::deque

### LinkedStack

- LIFO with linked nodes (dynamic memory)
- Word-level reversal by pushing characters until a delimiter

### BST

- Insert and contains operations
- Traversal orders: InOrder, PreOrder, PostOrder
- Node removal cases in binary search trees

### Brainstorm Tasks

- Stock Span problem solved in O(n) using a monotonic stack

## Known Notes 📝

- BTS STL/main.cpp is currently kept as commented educational reference and is not directly runnable as-is.
- Some introductory files intentionally discuss pointer pitfalls and undefined behavior scenarios for learning.

## Suggested Learning Path 🛤️

1. Class & Pointers
2. ArrayList
3. LinkedList
4. Stack and Queue
5. LinkedStack
6. BST
7. Brainstorm Tasks

## Contributing 🤝

This is a coursework-style repository. If you extend it, consider:

- Keeping each topic in its own folder
- Adding one focused main demo per concept
- Documenting complexity and edge cases next to new implementations

## License 📄

No license file is currently included.
If you plan to share or reuse this code publicly, add a license file at the repository root.
