#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detect(int src, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[src] = true;
    queue<pair<int, int>> q;
    
    // {current node, parent node}
    q.push({src, -1}); 
    // -1 indicates that the source node has no parent
    
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                // Found a back-edge to an already visited node that's not the parent
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int v, vector<vector<int>>& adjList) {
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (detect(i, adjList, visited)) {
                return true; // Cycle detected
            }
        }
    }

    return false;
}

int main() {
    int v = 5;
    vector<vector<int>> adjList(v);
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0} // cycle exists
        // To test no cycle: comment out {3, 0}
    };

    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected
    }

    if (isCycle(v, adjList))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}
