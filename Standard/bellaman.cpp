#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8); // Initialize distances to "infinity"
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++) {
        bool changed = false;  // Track if any distance was updated

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                changed = true;
            }
        }

        // Print dist array after each iteration
        cout << "After iteration " << i + 1 << ": ";
        for (auto d : dist) {
            if (d == 1e8)
                cout << "INF ";
            else
                cout << d << " ";
        }
        cout << "\n";

        if (!changed) {
            cout << "No changes in this iteration. Early stopping...\n";
            break;
        }
    }

    // Check for negative weight cycle
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return { -1 }; // Indicate negative cycle detected
        }
    }

    return dist;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E;) {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;

        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid edge. Vertices must be between 0 and " << V - 1 << ". Please re-enter.\n";
            continue; // Retry this edge
        }

        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
        i++; // Move to next edge if input is valid
    }

    int source = 0; // You can change source vertex here or take input from user

    cout << "\nRunning Bellman-Ford from source vertex " << source << "...\n\n";

    vector<int> dist = bellman_ford(V, edges, source);

    if (dist.size() == 1 && dist[0] == -1) {
        cout << "Graph contains a negative weight cycle. Shortest paths not defined.\n";
    } else {
        cout << "\nShortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e8)
                cout << "Vertex " << i << ": INF\n";
            else
                cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}