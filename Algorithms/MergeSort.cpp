#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    int b[high-low+1];
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            b[k]=arr[j];
            k++;
            j++;
        }

    }

    while(i<=mid)
    {
        b[k]=arr[i];
        k++;
        i++;
    }

    while(j<=high)
    {
        b[k]=arr[j];
        k++;
        j++;
    }

    for(int k=0; k<high-low+1; k++)
    {
        arr[low+k]=b[k];
    }

}
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    else
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }

}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
     cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array is \n";
    printArray(arr, n);
    return 0;
}
