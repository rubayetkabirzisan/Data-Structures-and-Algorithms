#include <bits/stdc++.h>
using namespace std;

int solvemem(vector<int>& weight, vector<int>& value, int index, int capacity, vector<vector<int>>& dp) {
    if (index < 0 || capacity == 0) {
        return 0;
    }

    if (weight[index] > capacity) {
        return solvemem(weight, value, index - 1, capacity, dp);
    }

    if (dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    int include = value[index] + solvemem(weight, value, index - 1, capacity - weight[index], dp);
    int exclude = solvemem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int knapsack(vector<int>& weight, vector<int>& value, int index, int capacity) {
    vector<vector<int>> dp(index, vector<int>(capacity + 1, -1));
    return solvemem(weight, value, index - 1, capacity, dp);
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    int capacity;
    cout << "Enter the maximum knapsack capacity: ";
    cin >> capacity;

    int maxVal = knapsack(weight, value, n, capacity); // Pass n instead of n-1

    cout << "The maximum value that can be obtained is: " << maxVal << endl;

    return 0;
}
