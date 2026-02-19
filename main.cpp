#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;   // (r - 1) değil, (r - l) olmalı

        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int jumpSearch(int arr[], int n, int x) {
    int step = (int)sqrt(n);
    int prev = 0;

    while (prev < n && arr[min(step, n) - 1] < x) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == x) return i;   // arr[m] değil, arr[i]
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x) {
    if (n == 0) return -1;
    if (arr[0] == x) return 0;

    int i = 1;
    while (i < n && arr[i] <= x) i *= 2;

    int left = i / 2;
    int right = min(i, n - 1);

    int l = left, r = right;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

double elapsedMS(clock_t start, clock_t end) {
    return 1000.0 * (end - start) / CLOCKS_PER_SEC;
}

double measureLinear(int arr[], int n, int queries[], int qCount) {
    clock_t start = clock();
    for(int i = 0; i < qCount; i++) {
        linearSearch(arr, n, queries[i]);
    }
    clock_t end = clock();
    return elapsedMS(start,end);
}

double measureBinary(int arr[], int n, int queries[], int qCount) {
    clock_t start = clock();
    for (int i = 0; i < qCount; i++) {
        binarySearch(arr, n, queries[i]);
    }
    clock_t end = clock();
    return elapsedMS(start, end);
}

double measureJump(int arr[], int n, int queries[], int qCount) {
    clock_t start = clock();
    for (int i = 0; i < qCount; i++) {
        jumpSearch(arr, n, queries[i]);
    }
    clock_t end = clock();
    return elapsedMS(start, end);
}

double measureExpo(int arr[], int n, int queries[], int qCount) {
    clock_t start = clock();
    for (int i = 0; i < qCount; i++) {
        exponentialSearch(arr, n, queries[i]);
    }
    clock_t end = clock();
    return elapsedMS(start, end);
}

int main() {
    srand(42);

    int sizes[] = {1000, 10000, 100000, 1000000};
    int numSizes = 4;

    const int Q = 20000;
    int *queries = new int[Q];

    cout << "Search Benchmark (ms for " << Q << "queries)\n";
    cout << "Size\tLinear\tBinary\tJump\tExpo\n";

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];

        // array oluştur
        int *arr = new int[n];

        // sorted array: 0,2,4,6,... (binary/jump/expo için şart)
        for (int i = 0; i < n; i++) {
            arr[i] = i * 2;
        }

        int maxValue = arr[n - 1] + 1000;
        for (int i = 0; i < Q; i++) {
            queries[i] = rand() % (maxValue + 1);
        }

        // ölç
        double tLin = measureLinear(arr, n, queries, Q);
        double tBin = measureBinary(arr, n, queries, Q);
        double tJump = measureJump(arr, n, queries, Q);
        double tExp = measureExpo(arr, n, queries, Q);

        cout << n << "\t" << tLin << "\t" << tBin << "\t" << tJump << "\t" << tExp << "\n";

        delete[] arr;
    }

    delete[] queries;
    return 0;
}
