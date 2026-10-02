#include <iostream>
using namespace std;

#define INF 9999

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter cost adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if(cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }

    int visited[10] = {0};

    visited[0] = 1;

    int edges = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while(edges < n - 1)
    {
        int min = INF;
        int u = -1;
        int v = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                for(int j = 0; j < n; j++)
                {
                    if(visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " : " << min << endl;

        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
