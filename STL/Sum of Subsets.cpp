#include <bits/stdc++.h>
using namespace std;

bool flag = 0;
void PrintSubsetSum(int i, int n, int set[], int targetSum,
					vector<int>& subset)
{
	if (targetSum == 0) {
		flag = 1;
		cout << "[ ";
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i] << " ";
		}
		cout << "]";
		return;
	}

	if (i == n) {
		return;
	}
	PrintSubsetSum(i + 1, n, set, targetSum, subset);
	if (set[i] <= targetSum) {
		subset.push_back(set[i]);
		PrintSubsetSum(i + 1, n, set, targetSum - set[i],
					subset);
		subset.pop_back();
	}
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int set[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> subset;
    cout << "Output:" << endl;
    PrintSubsetSum(0, n, set, targetSum, subset);

    if (!flag) {
        cout << "There is no such subset with the target sum." << endl;
    }

    return 0;
}

