#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAXI = 1e9;

void printPath(int node, vector<int>& parent) {
    if (node == -1) return;
    if (parent[node] != -1)
        printPath(parent[node], parent);
    cout << node << " ";
}

void bellmanFord(vector<vector<int>>& edges, int V, int src) {
    vector<int> dist(V, MAXI);
    vector<int> parent(V, -1);
    dist[src] = 0;

    // Relax all edges (V - 1) times
    for (int i = 0; i < V - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != MAXI && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }

        cout << "Iteration: " << i + 1 << endl;
        for (int j = 0; j < V; j++) {
            cout << "Updated dist[" << j << "]=";
            if (dist[j] == MAXI) cout << "INF";
            else cout << dist[j];
            cout << endl;
        }
        cout << endl;
    }

    // Check for negative weight cycle
    bool negativeCycle = false;
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] != MAXI && dist[u] + w < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative cycle detected!!" << endl;
        return;
    }

    // Print final distances and paths
    cout << "\nFinal Shortest Distances and Paths from Source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : Distance = ";
        if (dist[i] == MAXI) {
            cout << "INF, Path = None";
        } else {
            cout << dist[i] << ", Path = ";
            printPath(i, parent);
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> edges;
    cout << "Enter edges in format (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    bellmanFord(edges, V, src);
    return 0;
}