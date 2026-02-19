# search-algorithm-benchmark
Benchmarking linear, binary, jump and exponential search algorithms in C++.


# Search Algorithm Benchmark (C++)

## Overview
This project benchmarks multiple search algorithms on sorted datasets and compares their runtime as input size grows.

Algorithms implemented:
- Linear Search
- Binary Search
- Jump Search
- Exponential Search

The program generates sorted arrays and runs 20,000 random queries to measure total runtime using a simple timer.

## Build & Run
```bash
g++ -O2 -std=c++17 main.cpp -o bench
./bench

| Dataset Size | Linear (ms) | Binary (ms) | Jump (ms) | Exponential (ms) |
| ------------ | ----------- | ----------- | --------- | ---------------- |
| 1,000        | 27.59       | 1.36        | 4.63      | 2.63             |
| 10,000       | 219.48      | 2.28        | 11.48     | 2.59             |
| 100,000      | 1925.03     | 2.83        | 32.18     | 3.22             |
| 1,000,000    | 18322.6     | 3.67        | 100.74    | 4.47             |


Observations

Linear search runtime grows rapidly with input size (O(n)).

Binary and Exponential search remain nearly constant (O(log n)).

Experimental results match theoretical time complexity expectations.
