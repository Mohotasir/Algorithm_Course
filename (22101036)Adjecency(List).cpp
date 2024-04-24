#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, edges;
    cout << "Enter the maximum number of vertices: ";
    cin >> V;
    vector<vector<int>> adjList(V);

    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << " : ";
        cin >> u >> v;

        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Please enter vertices within range [0, " << V - 1 << "]." << endl;
            i--;
        } else {

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " :";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << " -> " << adjList[i][j];
        }
        cout << endl;
    }

    return 0;
}

