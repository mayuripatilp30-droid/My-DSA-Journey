#include <iostream>
using namespace std;

void knapsack(int weight[], int profit[], int n, int capacity)
{
    double ratio[100];

    // Calculate profit/weight ratio
    for(int i = 0; i < n; i++)
    {
        ratio[i] = (double)profit[i] / weight[i];
    }

    // Sort according to ratio in descending order
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {
                swap(ratio[j], ratio[j + 1]);
                swap(weight[j], weight[j + 1]);
                swap(profit[j], profit[j + 1]);
            }
        }
    }

    double totalProfit = 0;

    // Select items
    for(int i = 0; i < n; i++)
    {
        if(weight[i] <= capacity)
        {
            capacity = capacity - weight[i];
            totalProfit = totalProfit + profit[i];
        }
        else
        {
            double fraction = (double)capacity / weight[i];

            totalProfit = totalProfit + profit[i] * fraction;

            capacity = 0;
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit << endl;
}

int main()
{
    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};

    int n = 3;
    int capacity = 50;

    knapsack(weight, profit, n, capacity);

    return 0;
}
