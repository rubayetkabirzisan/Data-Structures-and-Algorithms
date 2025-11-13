#include <iostream>
#include <queue>
using namespace std;
const int MAX_VERTICES = 100;
class Edge
{
public:
    int vertex;
    int weight;

    Edge(int v, int w) : vertex(v), weight(w) {}
};

class Graph
{
public:
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    Graph(int n) : numVertices(n)
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int weight)
    {
        adjacencyMatrix[u][v] = weight;
        adjacencyMatrix[v][u] = weight;
    }

    void prim(int startVertex)
    {
        bool visited[MAX_VERTICES] = {false};
        int minDist[MAX_VERTICES];
        int parent[MAX_VERTICES];

        for (int i = 0; i < numVertices; i++)
        {
            minDist[i] = INT_MAX;
            parent[i] = -1;
        }

        minDist[startVertex] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, startVertex));

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            visited[u] = true;

            for (int v = 0; v < numVertices; v++)
            {
                if (adjacencyMatrix[u][v] > 0 && !visited[v] && adjacencyMatrix[u][v] < minDist[v])
                {
                    minDist[v] = adjacencyMatrix[u][v];
                    parent[v] = u;
                    pq.push(make_pair(minDist[v], v));
                }
            }
        }

        cout << "Minimum Spanning Tree:" << endl;
        for (int i = 1; i < numVertices; i++)
        {
            cout << "Edge: " << parent[i] << " - " << i << ", Weight: " << adjacencyMatrix[parent[i]][i] << endl;
        }
    }
};

int main()
{
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 3, 5);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 3);

    int startVertex = 0;
    graph.prim(startVertex);

    return 0;
}
