#include<bits/stdc++.h>

using namespace std;

int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int minPath = INT_MAX, min_index;

    for (int i = 0; i < dist.size(); i++) {
        if (!sptSet[i] && dist[i] <= minPath) {
            minPath = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<int> dijkstra(const vector<vector<int>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> sptSet(n, false);

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}

int main() {
    int node;
    cin >> node;
    vector<vector<int>> graph(node, vector<int>(node));

    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> shortest_distances = dijkstra(graph, 0);

    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < node; i++) {
        cout << i << " \t\t\t\t" << shortest_distances[i] << endl;
    }

    return 0;
}
