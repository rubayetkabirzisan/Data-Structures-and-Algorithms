#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] >= pivot && i <= high)
        {
            i++;
        }
        while (arr[j] < pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

int quickselect(vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex < k - 1)
        {
            return quickselect(arr, pivotIndex + 1, high, k);
        }
        else
        {
            return quickselect(arr, low, pivotIndex - 1, k);
        }
    }
    return -1;
}

int findKthLargest(vector<int> &arr, int k)
{
    return quickselect(arr, 0, arr.size() - 1, k);
}

int main()
{
    int n, k;
    cout << "Enter the size of the array and integer k: ";
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "K th largest element: " << findKthLargest(arr, k) << endl;

}
