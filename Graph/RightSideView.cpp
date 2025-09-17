#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

using namespace std;


vector<int> rightSideView(int start, const vector<vector<int>>& adjList, int n) {
    vector<bool> visited(n, false);
    vector<int> rightView;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int levelSize = q.size(); // number of nodes at this level
        int lastNode = -1;

        for (int i = 0; i < levelSize; ++i) {
            int node = q.front();
            q.pop();
            lastNode = node;

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        if (lastNode != -1) {
            rightView.push_back(lastNode); // last node of current level
        }
    }

    return rightView;
}



int main() {
    int n = 6;
    vector<vector<int>> adjList(n);
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}
    };

    for (auto e : edges) {
        int u = e.first;
        int v = e.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected
    }

    vector<int> rightView = rightSideView(0, adjList, n);

    cout << "Right Side View: ";
    for (int node : rightView) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
