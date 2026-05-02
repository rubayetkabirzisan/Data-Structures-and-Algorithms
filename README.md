# Data Structures and Algorithms

A personal C++ reference repository covering the core data structures and algorithms studied in a university DSA course. Each file is a standalone, compilable implementation — no external dependencies, just standard C++.

---

## Repository Structure

```
Data-Structures-and-Algorithms/
├── Data Structures/
│   ├── Array/
│   ├── Linked List/
│   ├── Stack/
│   ├── Queue/
│   ├── BST/
│   ├── Heap/
│   ├── Hash Table/
│   ├── TRIE/
│   ├── Segment Tree.cpp
│   └── Skip List.cpp
├── Algorithms/
├── Dynamic Programming/
├── STL/
├── Patterns/
└── Practice/
```

---

## Contents

### Data Structures

| Topic | Files | Notes |
|---|---|---|
| **Array** | `202214054_DAL.cpp`, `202214054_SAL.cpp`, `Assignment01`, `MCM(Ex)`, `MCM(Parenthesization)` | Dynamic and static array lists; Matrix Chain Multiplication |
| **Linked List** | `Sll.cpp`, `LInked_List.cpp` – `LInked_List6.cpp`, `Linked_List2.cpp`, `Linked_List4.cpp` | Singly linked list and multiple progressive implementations |
| **Stack** | `Stack.cpp`, `202214054.cpp` | Array-based stack; lab assignment |
| **Queue** | `Queue.cpp`, `Queue_V.cpp`, `Queue_L.cpp`, `Queue_C_V.cpp`, `Queue_C_L.cpp`, `Priority Queue.cpp` | Linear, circular (array & linked), and priority queue variants |
| **BST** | `Binary Search Tree.cpp`, `BST.CPP`, `202214054_BST.cpp` | Standard BST; extended version using a `Book` struct with ISBN-keyed operations |
| **Heap** | `Heap.cpp`, `Problem_No1_202214054.cpp` | Min/Max heap; lab problem |
| **Hash Table** | `Hashtable.cpp`, `Hash_Table_Assignment.cpp` | Hash table with chaining; assignment variant |
| **Trie** | `Trie.cpp`, `TRIE_Lab.cpp` | Prefix tree; lab version |
| **Segment Tree** | `Segment Tree.cpp` | Range query with point updates |
| **Skip List** | `Skip List.cpp` | Probabilistic linked list for fast search |

### Algorithms

| Algorithm | File |
|---|---|
| Breadth-First Search | `BFS.cpp` |
| Depth-First Search | `DFS.cpp` |
| Dijkstra's Shortest Path | `Dijkstra.cpp` |
| Bellman-Ford | `Bellman Ford.cpp` |
| Prim's MST | `MST(P).cpp`, `202214054(Prim's).cpp` |
| Kruskal's MST | `MST(k).cpp` |
| Topological Sort (DFS) | `TopoLogical Sort.cpp` |
| Topological Sort (BFS / Kahn's) | `TopoLogicalSort(BFS).cpp` |
| Merge Sort | `MergeSort.cpp` |
| Quick Sort | `QuickSort.cpp` |
| 0/1 Knapsack | `Knapsack.cpp` |
| Longest Common Subsequence | `LCS.cpp` |
| Longest Palindromic Subsequence | `LPS.cpp` |
| N-Queens Problem | `N Queens Problems.cpp` |
| M-Coloring Problem | `M-Coloring Problems.cpp` |
| FCFS Process Scheduling | `FCFS_Process_Scheduling_Algorithm.cpp` |
| Round-Robin Process Scheduling | `RNR_PSA.cpp` |

### Dynamic Programming

| Problem | File |
|---|---|
| Matrix Chain Multiplication | `MCM.cpp` |

### STL Practice

Standalone programs exploring C++ STL containers and patterns:

- `Vectors.cpp` — vector operations and iteration
- `Pairs.cpp` — `std::pair` usage
- `Vector Nesting.cpp` — 2D vectors
- `Subset Generate.cpp` — subset generation using bitmask
- `Sum of Subsets.cpp` — subset sum
- `Maximum Coins.cpp` — greedy/DP coin problem

### Patterns

Nested loop output patterns (`Pattern.cpp` through `Pattern 8.cpp`) — typical introductory loop exercises.

### Practice

Miscellaneous scratch files and previous exam/lab solutions (`Prev1.cpp` – `Prev4.cpp`).

---

## Getting Started

All files use standard C++ (C++14/17). Compile any file with g++:

```bash
g++ -std=c++17 -o output "Algorithms/BFS.cpp"
./output
```

No build system or package manager is needed.

---

## Topics Covered at a Glance

- **Linear structures** — arrays, linked lists, stacks, queues
- **Tree structures** — BST, heap, trie, segment tree, skip list
- **Graph algorithms** — BFS, DFS, Dijkstra, Bellman-Ford, Prim, Kruskal, topological sort
- **Sorting** — merge sort, quick sort
- **Dynamic programming** — LCS, LPS, knapsack, MCM
- **Backtracking** — N-Queens, M-coloring
- **OS scheduling** — FCFS, round-robin
- **Hashing** — hash table with chaining
- **C++ STL** — vectors, pairs, bitmask subsets

---
