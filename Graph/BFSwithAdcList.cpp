#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <deque>
#include <queue>

using namespace std;


void bfs(int start , const vector<vector<int>>& adjList, vector<bool>& visited){
    queue<int> q;
    q.push(start);

    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for (int neighbor : adjList[node]){
            if (!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;

            }
        }
    }
}

int main(){
    int n = 6;
    vector<vector<int>> adjList(n);
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}
    };

    // building the adjacency list

    for (size_t i = 0; i<edges.size(); ++i){
        int u = edges[i].first;
        int v = edges[i].second;


        adjList[u].push_back(v);
        adjList[v].push_back(u); // for undirected graph

    }

    vector<bool> visited(n, false);
    // for printing the adjacency list


    // cout << adjList.size() << " nodes in the graph." << endl;
    // cout << "Adjacency List:" << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << i << ": ";
    //     for (int j : adjList[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }


    cout<< "BFS Traversal: ";
    bfs(0, adjList, visited);
    cout << endl;

    return 0;

}