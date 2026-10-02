#include <iostream>
using namespace std;

int partition(int arr[], int st, int end)
{
    int pivot = arr[end];
    int i = st - 1;

    for(int j = st; j < end; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);

    return i + 1;
}

void quickSort(int arr[], int st, int end)
{
    if(st < end)
    {
        int pivotIndex = partition(arr, st, end);

        quickSort(arr, st, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main()
{
    int arr[] = {5, 2, 8, 1, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
