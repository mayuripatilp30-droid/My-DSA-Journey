#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = 4;

    int totalCost = 0;

    while(n > 1)
    {
          for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

                int mergeCost = arr[0] + arr[1];

        totalCost = totalCost + mergeCost;

                arr[0] = mergeCost;

        for(int i = 1; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        n--;
    }

    cout << "Minimum Merge Cost = " << totalCost << endl;

    return 0;
}
