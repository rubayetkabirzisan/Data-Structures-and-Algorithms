#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        st.erase(st.begin());

        for (auto neighbor : adj[topNode])
        {
            int neighborNode = neighbor.first;
            int neighborWeight = neighbor.second;

            if (nodeDistance + neighborWeight < dist[neighborNode])
            {
                auto record = st.find(make_pair(dist[neighborNode], neighborNode));
                if (record != st.end())
                {
                    st.erase(record);
                }

                dist[neighborNode] = nodeDistance + neighborWeight;
                st.insert(make_pair(dist[neighborNode], neighborNode));
            }
        }
    }

    return dist;
}

int main()
{
    int vertices, edges, source;

    // Get user input for the number of vertices, edges, and source node
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the source node: ";
    cin >> source;

    vector<vector<int>> vec(edges);
    cout << "Enter edge information (from to weight):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[i] = {u, v, w};
    }

    vector<int> result = dijkstra(vec, vertices, edges, source);

    for (int i = 0; i < vertices; i++)
    {
        cout << "Shortest distance from source to node " << i << ": " << result[i] << endl;
    }

    return 0;
}
