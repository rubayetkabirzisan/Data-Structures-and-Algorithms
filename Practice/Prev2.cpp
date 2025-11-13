#include <iostream>
using namespace std;

int binarySearch(int* P, int X, int start, int end) {
    if (start > end) {
        // Base case: No elements greater than X found
        return 0;
    }

    int mid = start + (end - start) / 2;

    if (P[mid] <= X) {
        // Discard the left half of the array
        return binarySearch(P, X, mid + 1, end);
    } else {
        // Count the number of elements greater than X in the right half
        return (end - mid) + binarySearch(P, X, start, mid - 1);
    }
}

int main() {
    int n;
    cin >> n;

    int* P = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }

    int X;
    cin >> X;

    int count = binarySearch(P, X, 0, n - 1);
    cout << count << endl;

    delete[] P;

    return 0;
}

