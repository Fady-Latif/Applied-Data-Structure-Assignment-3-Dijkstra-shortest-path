# Assignment 3: Dijkstra & Floyd–Warshall (C++)

**Course:** Applied Data Structures  
**Name:** Fady Latif  
**Student ID:** 900241677  

---

## Project Description

This project implements two classic shortest-path algorithms on a weighted directed graph:

- **Dijkstra's Algorithm** – computes shortest paths from a single source node using a min-heap priority queue.
- **Repeated Dijkstra** – runs Dijkstra from every node to produce an All-Pairs Shortest Path (APSP) matrix.
- **Floyd–Warshall Algorithm** – uses dynamic programming to compute shortest paths between all pairs of nodes in O(n³).

The graph is loaded from `graph.txt` (100 nodes, 9900 edges) and results from both APSP methods are compared to verify correctness.

---

## Project Structure

```
root/
├── Code_library/
│   ├── graph.h
│   ├── graph.cpp
│   ├── dijkstra.h
│   ├── floyd.h
│   ├── dijkstra_floyd.cpp   ← main implementation file
│   ├── graph.txt
│   └── CMakeLists.txt
├── Google_tests/
│   ├── CMakeLists.txt
│   └── Testcases.cpp
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

## How to Build and Run

### Requirements
- CMake 3.24 or higher
- A C++17-compatible compiler (GCC, Clang, or MSVC)
- Visual Studio 2022 (recommended on Windows)

### Build Steps (VS Code with CMake Tools extension)

1. Open the project root folder in VS Code
2. Press `Ctrl + Shift + P` → **CMake: Select a Kit** → choose Visual Studio Community 2022
3. Press `Ctrl + Shift + P` → **CMake: Delete Cache and Reconfigure**
4. Press `Ctrl + Shift + P` → **CMake: Build**

### Build Steps (Terminal)

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
```

### Run the Main Program

```bash
./build/Release/Code_library_run.exe    # Windows
./build/Code_library_run                # Mac/Linux
```

Expected output:
```
Repeated Dijkstra time: X ms
Floyd-Warshall time: X ms
MATCH
```

---

## How to Run Tests

After building, run:

```bash
./build/Google_tests/Release/Google_tests.exe    # Windows
./build/Google_tests/Google_tests                # Mac/Linux
```

All 3 test cases should pass:

| Test | Description |
|------|-------------|
| `GraphLoadTest` | Verifies the graph loads 100 nodes and 9900 edges |
| `DijkstraTest` | Verifies single-source shortest paths from node 0 |
| `CompareAlgorithms` | Verifies Repeated Dijkstra and Floyd–Warshall produce identical results |

---

## Algorithm Details

### Dijkstra's Algorithm
Uses a min-heap priority queue to greedily select the next closest unvisited node. Time complexity: **O((V + E) log V)** per run.

### Repeated Dijkstra (APSP)
Runs Dijkstra from every node, producing a full n×n distance matrix. Time complexity: **O(V · (V + E) log V)**.

### Floyd–Warshall
Triple nested loop over all intermediate nodes k, checking if the path i→k→j is shorter than the current best i→j. Time complexity: **O(V³)**.

---

## Assumptions & Notes

- The graph is directed and weighted with non-negative weights, making Dijkstra valid.
- Edge weights of `1e9` represent infinity (no direct connection).
- An overflow guard `if (dist[i][k] < 1e9 && dist[k][j] < 1e9)` in Floyd–Warshall prevents integer overflow when summing two infinity values.
- The graph file path is resolved relative to the source file using `std::filesystem`, so the project runs correctly from any working directory.
