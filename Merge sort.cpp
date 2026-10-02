#include <iostream>
using namespace std;

void merge(int arr[], int st, int mid, int end)
{
    int temp[100];

    int i = st;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= end)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int x = 0; x < k; x++)
    {
        arr[st + x] = temp[x];
    }
}

void mergeSort(int arr[], int st, int end)
{
    if(st < end)
    {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, st, mid, end);
    }
}

int main()
{
    int arr[] = {11, 25, 5, 19, 16};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
