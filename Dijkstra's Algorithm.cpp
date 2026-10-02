#include <iostream>
using namespace std;

#define INF 9999

void dijkstra(int graph[10][10], int n, int source)
{
    int distance[10];
    int visited[10];

    // Initially
    for(int i = 0; i < n; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
    }

    // Distance from source to itself
    distance[source] = 0;

    // Repeat for all vertices
    for(int count = 0; count < n - 1; count++)
    {
        int minDistance = INF;
        int u = -1;

        // Find unvisited vertex with minimum distance
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0 && distance[i] < minDistance)
            {
                minDistance = distance[i];
                u = i;
            }
        }

        // Mark vertex as visited
        visited[u] = 1;

        // Update distances of adjacent vertices
        for(int v = 0; v < n; v++)
        {
            if(visited[v] == 0 &&
               graph[u][v] != 0 &&
               distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Display result
    cout << "\nShortest distances from vertex "
         << source << ":\n";

    for(int i = 0; i < n; i++)
    {
        cout << "Vertex " << i
             << " = " << distance[i] << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter weighted adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(graph, n, source);

    return 0;
}
