#include <iostream>
#include <stack>
using namespace std;

const int SIZE = 5;
int g[SIZE][SIZE] = {{0}};
int v[SIZE];
int clr[SIZE] = {0};
int dist[SIZE] = {0};
int parent[SIZE] = {-1};
int visitTime = 0;
int startTime[SIZE] = {0};
int finishTime[SIZE] = {0};

void dfs_visit(int k)
{
    visitTime++;
    startTime[k] = visitTime;
    clr[k] = 1;

    for (int i = 0; i < SIZE; i++)
    {
        if (g[k][i] == 1 && clr[i] == 0)
        {
            dist[i] = dist[k] + 1;
            parent[i] = k;
            dfs_visit(i);
        }
    }

    clr[k] = 2;
    visitTime++;
    finishTime[k] = visitTime;
}

int main()
{
    int connections;
    cout << "Enter the number of connections: ";
    cin >> connections;

    cout << "Enter the connections (node1 node2):" << endl;
    for (int i = 0; i < connections; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        g[node1][node2] = 1;
        g[node2][node1] = 1;
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    dist[startNode] = 0;
    dfs_visit(startNode);

    cout << "Distances of all nodes from the starting node:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Node " << i << ": " << dist[i] << endl;
    }

    cout << "Start and Finish Times in the sequence of Node:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Node " << i << ": Start Time: " << startTime[i] << ", Finish Time: " << finishTime[i] << endl;
    }

    // Additional functionalities
    cout << "Enter the source and destination nodes to find the path between them: ";
    int source, destination;
    cin >> source >> destination;

    if (clr[source] == 0 || clr[destination] == 0)
    {
        cout << "Invalid source or destination node." << endl;
    }
    else
    {
        int currentNode = destination;
        cout << "Path from " << source << " to " << destination << ": ";
        stack<int> pathStack;
        while (currentNode != source)
        {
            pathStack.push(currentNode);
            currentNode = parent[currentNode];
        }
        cout << source << " ";
        while (!pathStack.empty())
        {
            cout << pathStack.top() << " ";
            pathStack.pop();
        }
        cout << endl;
    }

    // Check if the graph is connected
    bool isConnected = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (clr[i] == 0)
        {
            isConnected = false;
            break;
        }
    }

    if (isConnected)
    {
        cout << "The graph is connected." << endl;
    }
    else
    {
        cout << "The graph is not connected." << endl;
    }

    // Check if the graph is a tree
    bool isTree = true;
    for (int i = 0; i < SIZE; i++)
    {
        int count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (g[i][j] == 1)
                count++;
        }
        if (count > 1)
        {
            isTree = false;
            break;
        }
    }

    if (isTree)
    {
        cout << "The graph is a tree." << endl;
    }
    else
    {
        cout << "The graph is not a tree." << endl;
    }

    return 0;
}
