#include <bits/stdc++.h>
using namespace std;
vector<int> bellaman(int V, vector<vector<int>> &edges, int S)
{

  vector<int> dist(V, 1e8);
  dist[S] = 0;
  for (int i = 0; i < V - 1; i++)
  {
    bool changed = false;
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      if (dist[u] != 1e8 && dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        changed = true;
      }
    }
    cout << "After iteration: " << i + 1 << ":";
    for (int i = 0; i < V; i++)
    {
      if (dist[i] == 1e8)
      {
        cout << "INF ";
      }
      else
      {
        cout << dist[i] << " ";
      }
    }
    cout << endl;
    if (!changed)
    {
      cout << "NO changes in this iteration.Early stopping..." << endl;
      break;
    }
  }
  // for negative edge cycle detection
  for (auto it : edges)
  {
    int u = it[0];
    int v = it[1];
    int wt = it[2];
    if (dist[u] != 1e8 && dist[u] + wt < dist[v])
    {
      return {-1};
    }
  }
  return dist;
}

int main()
{
  int n;
  cout << "Enter the number of vertices:";
  cin >> n;
  int e;
  cout << "Enter the number of edges:";
  cin >> e;
  vector<vector<int>> edges(e, vector<int>(3));
  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cout << "Enter the edge " << i + 1 << ":";
    cin >> u >> v >> w;
    if (u >= n || v >= n)
    {
      cout << "Enter the valid edges...." << endl;
      return 1;
    }
    if (u < 0 || v < 0)
    {
      cout << "Enter the valid edges...." << endl;
      return 1;
    }
    edges[i][0] = u;
    edges[i][1] = v;
    edges[i][2] = w;
  }
  int src = 0;
  vector<int> distance(n, 1e8);
  distance = bellaman(n, edges, src);
  if (distance.size() == 1 || distance[0])
  {
    cout << "Negative cycle is detected and shortest path is not defined.." << endl;
  }
  else
  {
    cout << "shortest distance from source vertex " << src << ":" << endl;
    for (int i = 0; i < n; i++)
    {
      if (distance[i] == 1e8)
      {
        cout << "Vertex " << i << ": INF" << endl;
      }
      else
      {
        cout << "Vertex " << i << ": " << distance[i] << endl;
      }
    }
  }
  return 0;
}