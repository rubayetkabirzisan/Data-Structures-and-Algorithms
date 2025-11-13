#include <iostream>
#include <algorithm>

const int MAX_VERTICES = 1000; // Maximum number of vertices in the graph

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E; // Number of vertices and edges in the graph
    Edge edges[MAX_VERTICES];

    Graph(int v, int e) {
        V = v;
        E = e;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        edges[E].src = src;
        edges[E].dest = dest;
        edges[E].weight = weight;
        E++;
    }
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Find the root of the subset using path compression
int findRoot(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = findRoot(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union two subsets using rank (union by rank)
void unionSets(Subset subsets[], int x, int y) {
    int xroot = findRoot(subsets, x);
    int yroot = findRoot(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function to sort edges by weight in non-decreasing order
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(Graph graph) {
    Edge result[MAX_VERTICES]; // Stores the edges in the minimum spanning tree
    Subset subsets[MAX_VERTICES]; // Array to store subsets for union-find

    // Sort all the edges in non-decreasing order of their weight
    std::sort(graph.edges, graph.edges + graph.E, compareEdges);

    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges array

    // Initialize subsets with single elements
    for (int v = 0; v < graph.V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Build the minimum spanning tree
    while (e < graph.V - 1 && i < graph.E) {
        Edge nextEdge = graph.edges[i++];
        int x = findRoot(subsets, nextEdge.src);
        int y = findRoot(subsets, nextEdge.dest);

        // If including this edge doesn't form a cycle, add it to the result
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the minimum spanning tree
    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (int j = 0; j < e; j++) {
        std::cout << result[j].src << " -- " << result[j].dest << " : " << result[j].weight << std::endl;
    }
}

int main() {
    int V = 6; // Number of vertices
    int E = 8; // Number of edges

    Graph graph(V, E);

    // Add edges to the graph
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 6);
    graph.addEdge(2, 5, 5);

    // Find and print the minimum spanning tree
    kruskalMST(graph);

    return 0;
}

