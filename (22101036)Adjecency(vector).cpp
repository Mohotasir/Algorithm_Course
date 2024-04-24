#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, edges;
    cout << "Enter the maximum number of vertices: ";
    cin >> V;
   vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    cout << "Enter the number of edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertices! Please enter vertices within range [0, " << V - 1 << "]." << endl;
            i--;
        } else {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

