#include <iostream>
#include <queue>
using namespace std;

void printPath(int shortestPath[], int startingVertex)
{
    int node = startingVertex;
    while (node != -1)
    {
        cout << node << " ";
        node = shortestPath[node];
    }
    cout << endl;
}

int main()
{
    int n = 9;
    int v[n];
    int g[n][n];
    int clr[n];
    int dist[n];
    int parent[n];
    int visitTime[n];
    int startTime[n];
    int endTime[n];
    int shortestPath[n];
    int numPaths[n];
    bool isCyclic = false;

    for (int i = 0; i < n; i++)
    {
        v[i] = i;
        clr[i] = 0;
        dist[i] = 0;
        parent[i] = -1;
        visitTime[i] = 0;
        startTime[i] = 0;
        endTime[i] = 0;
        shortestPath[i] = -1;
        numPaths[i] = 0;
        for (int j = 0; j < n; j++)
        {
            g[i][j] = 0;
        }
    }

    int numConnections;
    cout << "Enter the number of connections: ";
    cin >> numConnections;

    cout << "Enter the connections in the format 'source destination':" << endl;
    for (int i = 0; i < numConnections; i++)
    {
        int source, destination;
        cin >> source >> destination;
        g[source][destination] = 1;
    }

    queue<int> q;
    int startingVertex = 1; // Set the starting vertex

    q.push(startingVertex);
    clr[startingVertex] = 1;
    dist[startingVertex] = 0;
    visitTime[startingVertex] = 1;
    startTime[startingVertex] = 1;
    shortestPath[startingVertex] = startingVertex;
    numPaths[startingVertex] = 1;

    while (!q.empty())
    {
        int k = q.front();
        cout << "Node: " << v[k] << ", Distance: " << dist[k] << ", Parent: " << parent[k] << ", Visit Time: " << visitTime[k] << ", Start Time: " << startTime[k] << ", End Time: " << endTime[k] << ", Shortest Path: ";
        printPath(shortestPath, k);
        cout << "Number of Paths: " << numPaths[k] << endl;

        q.pop();

        if (clr[k] == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (g[k][i] == 1 && clr[i] == 0)
                {
                    q.push(i);
                    clr[i] = 1;
                    dist[i] = dist[k] + 1;
                    parent[i] = k;
                    visitTime[i] = visitTime[k] + 1;
                    startTime[i] = visitTime[i];
                    shortestPath[i] = k;
                    numPaths[i] = numPaths[k];
                }
                else if (g[k][i] == 1 && clr[i] == 1)
                {
                    if (dist[k] + 1 == dist[i])
                    {
                        numPaths[i] += numPaths[k];
                    }
                    if (parent[i] != k)
                    {
                        isCyclic = true;
                    }
                }
            }
            clr[k] = 2;
            endTime[k] = visitTime[k];
        }
    }

    if (isCyclic)
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph is acyclic." << endl;
    }

    // Additional functionalities
    cout << "Enter the source and destination vertices to find the shortest path between them: ";
    int source, destination;
    cin >> source >> destination;

    if (clr[source] == 0 || clr[destination] == 0)
    {
        cout << "Invalid source or destination vertex." << endl;
    }
    else
    {
        int currentNode = destination;
        cout << "Shortest path from " << source << " to " << destination << ": ";
        while (currentNode != source)
        {
            cout << currentNode << " ";
            currentNode = shortestPath[currentNode];
        }
        cout << source << endl;
        cout << "Distance: " << dist[destination] << endl;
        cout << "Number of paths: " << numPaths[destination] << endl;
    }

    return 0;
}
