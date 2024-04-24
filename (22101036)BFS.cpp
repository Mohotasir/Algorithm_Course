#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
void BFS(int s) {
    int V = adjList.size();
    vector<bool> visited(V, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (int i : adjList[current]) {

            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int V, edges;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> edges;
    adjList.resize(V);
    cout << "Enter edges :" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start;
    cout << "starting vertex: ";
    cin >> start;

    cout << "BFS traversal starting from vertex " << start << ": ";
    BFS(start);

    return 0;
}

