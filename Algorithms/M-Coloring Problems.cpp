#include <iostream>
#include <vector>

using namespace std;

bool issafetoassign(int i, int j, vector<vector<int>>& graph, vector<int>& color, int v) {
    for (int k = 0; k < v; k++) {
        if (graph[i][k] == 1 && color[k] == j) {
            return false;
        }
    }
    return true;
}

bool fnc(vector<vector<int>>& graph, int m, int v, vector<int>& color, int i) {
    if (i == v) {
        return true;
    }

    for (int j = 0; j < m; j++) {
        if (issafetoassign(i, j, graph, color, v)) {
            color[i] = j;
            if (fnc(graph, m, v, color, i + 1)) {
                return true;
            }
            color[i] = -1;
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m, int v, vector<int>& color) {
    return fnc(graph, m, v, color, 0);
}

int main() {
    int v, m;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of colors: ";
    cin >> m;

    vector<vector<int>> graph(v, vector<int>(v, 0));
    vector<int> color(v, -1);

    cout << "Enter the adjacency matrix (0 or 1):" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> graph[i][j];
        }
    }

    if (graphColoring(graph, m, v, color)) {
        cout << "Graph can be colored with " << m << " colors. Colors assigned to vertices:" << endl;
        for (int i = 0; i < v; i++) {
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
        }
    } else {
        cout << "Graph cannot be colored with " << m << " colors." << endl;
    }

    return 0;
}
