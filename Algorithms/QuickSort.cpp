#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i<j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    quicksort(arr, 0, n - 1);

    cout << "Sorted array : ";

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}
