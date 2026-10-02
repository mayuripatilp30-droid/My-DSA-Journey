#include <iostream>
using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};

int parent[10];

int findParent(int vertex)
{
    while(parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }

    return vertex;
}

void unionSet(int u, int v)
{
    int parentU = findParent(u);
    int parentV = findParent(v);

    parent[parentV] = parentU;
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[20];

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < e; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

        for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

        for(int i = 0; i < e - 1; i++)
    {
        for(int j = 0; j < e - i - 1; j++)
        {
            if(edges[j].weight > edges[j + 1].weight)
            {
                swap(edges[j], edges[j + 1]);
            }
        }
    }

    int totalCost = 0;
    int selectedEdges = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for(int i = 0; i < e && selectedEdges < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        int parentU = findParent(u);
        int parentV = findParent(v);

        if(parentU != parentV)
        {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(u, v);

            selectedEdges++;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
