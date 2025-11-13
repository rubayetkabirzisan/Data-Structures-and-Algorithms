#include <iostream>
#include <climits>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

void bellmanFord(Edge* edges, int numEdges, int numVertices, int source) {
    int* distance = new int[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        distance[i] = INT_MAX;
    }

    distance[source] = 0;

    for (int i = 1; i < numVertices; ++i) {
        bool anyUpdate = false;
        for (int j = 0; j < numEdges; ++j) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                anyUpdate = true;
            }
        }

        if (!anyUpdate) {
            break;
        }
    }

    // Print the distances
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INT_MAX) {
            cout << "No path";
        } else {
            cout << distance[i];
        }
        cout << endl;
    }

    delete[] distance;
}

int main() {
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Edge* edges = new Edge[numEdges];

    cout << "Enter the edges in the format (source destination weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, numEdges, numVertices, source);

    delete[] edges;

    return 0;
}
