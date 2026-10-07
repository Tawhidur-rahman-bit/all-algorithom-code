#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    int INF = 1000000000;

    vector<vector<int>> dist(V, vector<int>(V, INF));

    // Distance from a node to itself
    for(int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
    }

    // Input edges
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = w;
    }

    // Floyd-Warshall
    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
            }
        }
    }

    // Print matrix
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}