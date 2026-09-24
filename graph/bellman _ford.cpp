#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edge;

    // Input all edges
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edge.push_back({u, v, w});
    }

    int source;
    cin >> source;

    // Initially all distances are infinity
    vector<int> dist(V, 1000000000);

    // Source to source = 0
    dist[source] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = edge[j][0];
            int v = edge[j][1];
            int w = edge[j][2];

            if(dist[u] != 1000000000 &&
               dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative weight cycle
    for(int j = 0; j < E; j++)
    {
        int u = edge[j][0];
        int v = edge[j][1];
        int w = edge[j][2];

        if(dist[u] != 1000000000 &&
           dist[u] + w < dist[v])
        {
            cout << "Negative Weight Cycle Exists";
            return 0;
        }
    }

    // Print shortest distances
    for(int i = 0; i < V; i++)
    {
        cout << "Distance from " << source
             << " to " << i
             << " = " << dist[i] << endl;
    }

    return 0;
}