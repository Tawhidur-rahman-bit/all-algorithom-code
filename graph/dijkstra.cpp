#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    // Adjacency List
    vector<vector<pair<int, int>>> adj(n);

    // Input edges
    for (int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Source node
    int source;
    cin >> source;

    // Initially all distances are infinity
    vector<int> dist(n, 1e9);

    // Min Priority Queue
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Distance of source = 0
    dist[source] = 0;

    // {distance, node}
    pq.push({0, source});

    while (!pq.empty()) {

        // Take the smallest distance
        int d = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        // Check all neighbors of u
        for (auto edge : adj[u]) {

            int v = edge.first;
            int w = edge.second;

            // Can we get a shorter path?
            if (dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;

                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {

        cout << "Distance from "
             << source << " to "
             << i << " = "
             << dist[i] << endl;
    }

    return 0;
}