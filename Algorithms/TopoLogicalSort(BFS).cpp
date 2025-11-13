#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &adj, int v) {
    vector<int> inDegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }
    queue<int> q;

    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int neighbor : adj[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return result;
}
int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> sortedOrder = topologicalSort(adj, V);

    cout << "Topological Sorting: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }

    return 0;
}
