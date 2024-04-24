#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
void DFS(int start) {
    int V = adjList.size();
    vector<bool> visited(V, false);
    stack<int> stck;
    stck.push(start);
    while (!stck.empty()) {
        int current = stck.top();
        stck.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
            for (int i = adjList[current].size() - 1; i >= 0; i--) {
                int neighbor = adjList[current][i];
                if (!visited[neighbor]) {
                    stck.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int V, edges;
    cout << "Enter the number of vertices: ";
    cin >> V;
     adjList.resize(V);

    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter edges:" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start;
    cout << "Enter the starting vertex for DFS: ";
    cin >> start;

    cout << "DFS traversal starting from vertex " << start << ": ";
    DFS( start);

    return 0;
}

