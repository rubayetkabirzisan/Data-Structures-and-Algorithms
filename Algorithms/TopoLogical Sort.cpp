#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

void topoSort(int node, vector<bool> &visited, stack<int> &s, vector<list<int>> &adj) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topoSort(neighbor, visited, s, adj);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V) {
    vector<list<int>> adj(V);

    for (const vector<int> &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;
    cout << "Enter the number of edges (E): ";
    cin >> E;

    vector<vector<int>> edges(E);

    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    vector<int> sortedOrder = topologicalSort(edges, V);

    cout << "Topological Sorting: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }

    return 0;
}
