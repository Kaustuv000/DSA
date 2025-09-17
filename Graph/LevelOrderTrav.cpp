#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

void LevelOrder(int start, const vector<vector<int>>& adjList, int n){
    vector<int> level(n, -1);
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(start);
    level[start] = 0;
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout <<  "Node"<< node << ", Level: " << level[node]<<endl;

        for (int neighbor : adjList[node]){
            if (!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
                level[neighbor] = level[node] + 1;
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


    cout<< "Level Order Traversal:- "<< endl;
    LevelOrder(0, adjList, n);
    cout << endl;

    return 0;

}