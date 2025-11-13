#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& subset, int i, vector<int>& nums, vector<vector<int>>& subsets) {
    if (i == nums.size()) {
        subsets.push_back(subset);
        return;
    }

    // ith element not in subset
    generateSubsets(subset, i + 1, nums, subsets);

    // ith element in subset
    subset.push_back(nums[i]);
    generateSubsets(subset, i + 1, nums, subsets);
    subset.pop_back();
}

int main() {
    vector<int> nums;

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<vector<int>> allSubsets;
    vector<int> emptySubset;
    generateSubsets(emptySubset, 0, nums, allSubsets);

    // Print all subsets
    for (const vector<int>& subset : allSubsets) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

