#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool dfsCycle(int node, int parent, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, node, adjList, visited))
                return true;
        } else if (neighbor != parent) {
            // Visited and not coming from parent → cycle
            return true;
        }
    }

    return false;
}

// This function checks for cycles in an undirected graph using DFS
bool hasCycleUndirected(int n, const vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            // node, parent , adjList, visited
            if (dfsCycle(i, -1, adjList, visited))
                return true;
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

    if (hasCycleUndirected(v, adjList))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}
