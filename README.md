# Search Algorithm Benchmark (C++)

## Overview
This project implements and benchmarks several classic search algorithms on sorted integer sequences using C++.  
The main goal is to compare **empirical runtimes** against their **theoretical time complexities**.

The algorithms included are:
- **Linear Search**
- **Binary Search**
- **Jump Search**
- **Exponential Search**

All benchmarks use 20,000 random queries on increasing input sizes to observe how runtimes scale in practice.

---

## Theoretical Time Complexity

| Algorithm           | Best Case | Average Case | Worst Case |
|--------------------|-----------|--------------|------------|
| Linear Search      | O(1)      | O(n)         | O(n)       |
| Binary Search      | O(1)      | O(log n)     | O(log n)   |
| Jump Search        | O(1)      | O(√n)        | O(√n)      |
| Exponential Search | O(1)      | O(log n)     | O(log n)   |

---

## How It Works

1. The program generates a sorted array of even integers for each size  
   n ∈ {1000, 10000, 100000, 1000000}.
2. It generates 20,000 random queries per dataset using a fixed seed for reproducibility.
3. Each algorithm is timed using `clock()` for all queries.
4. Results are printed in tabular format for comparison.

---

## Compile & Run

```bash
g++ -O2 -std=c++17 main.cpp -o bench
./bench


Search Benchmark (ms for 20000 queries)
Size    Linear  Binary  Jump    Expo
1000    27.598  1.360   4.631   2.630
10000   219.485 2.287   11.487  2.592
100000  1925.03 2.833   32.188  3.226
1000000 18322.6 3.676   100.742 4.478


## Interpretation

- Linear Search scales approximately linearly with input size, consistent with O(n).
- Binary and Exponential Search show minimal growth across large inputs, aligning with O(log n).
- Jump Search demonstrates intermediate scaling behavior, matching O(√n).

Overall, the empirical results closely reflect theoretical complexity expectations.

## Limitations
- Timing uses clock(), which measures CPU time rather than wall-clock time.
- Cache and hardware-level optimizations are not explicitly analyzed.
- Only integer equality search is evaluated.

## Future Improvements
-Add high-resolution timing with std::chrono.
- Export results to CSV and visualize runtime growth.
- Benchmark additional search methods (e.g., interpolation search).
