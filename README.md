# Search Algorithm Benchmark (C++)

## Overview
This project implements and benchmarks several classic search algorithms on sorted integer sequences using C++.  
The main goal is to compare **empirical runtimes** against their **theoretical time complexities**.

Algorithms:
- **Linear Search**
- **Binary Search**
- **Jump Search**
- **Exponential Search**

The benchmark runs **20,000 random queries** for multiple input sizes to observe scaling behavior.

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
1. Generate a sorted array of even integers for each size: `1000, 10000, 100000, 1000000`
2. Generate **20,000** random queries per dataset (fixed seed for reproducibility)
3. Time each algorithm using `clock()` over all queries
4. Print results in tabular form

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
- Binary and Exponential Search show minimal growth across large inputs, consistent with O(log n).
-Jump Search shows intermediate scaling behavior, consistent with O(√n).
-Overall, the empirical results closely reflect theoretical complexity expectations.

## Limitations
- Timing uses clock() (CPU time), not wall-clock time.
- Cache and hardware-level optimizations are not explicitly analyzed.
- Only integer equality search is evaluated.

## Future Improvements
-Use high-resolution timing via std::chrono.
-Export results to CSV and visualize runtime growth.
- Add additional search methods (e.g., interpolation search).
