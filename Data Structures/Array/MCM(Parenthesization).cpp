#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printOrder(vector<vector<int>>& bracket, int i, int j) {
    if (i == j) {
        cout << "A" << i << " ";
        return;
    }

    cout << "(";
    printOrder(bracket, i, bracket[i][j]);
    printOrder(bracket, bracket[i][j] + 1, j);
    cout << ")";
}

void matrixChainOrder(vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices

    // Create matrices to store minimum number of scalar multiplications and the bracket for optimal order


    // Initialize dp array with zeros for the diagonal and set bracket diagonal to zero
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        bracket[i][i] = i;
    }

    // Chain length 'l' varies from 2 to n
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of scalar multiplications: " << dp[1][n] << endl;
    cout << "Optimal Order: ";
    printOrder(bracket, 1, n);
    cout << endl;
}

int main() {
    int numMatrices;
    cout << "Enter the number of matrices: ";
    cin >> numMatrices;

    vector<int> dimensions(numMatrices + 1);
    cout << "Enter the dimensions of each matrix:" << endl;
    for (int i = 0; i <= numMatrices; i++) {
        cout << "Dimension " << i + 1 << ": ";
        cin >> dimensions[i];
    }

    matrixChainOrder(dimensions);

    return 0;
}

