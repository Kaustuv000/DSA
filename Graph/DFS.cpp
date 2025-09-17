#include <iostream>
#include <vector>
using namespace std;


void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited){
    visited[node] = true;
    cout << node << " ";

    for(int neighbor: adjList[node]){
        if (!visited[neighbor]){
            dfs(neighbor, adjList, visited);
        }
    }
}


int main(){
    int n = 6; 
    vector<vector<int>> adjList(n);

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}
    };
    

    for (auto e : edges) {
        int u = e.first;
        int v = e.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }   

    vector<bool> visited(n, false);
    dfs(0, adjList, visited);

    return 0;
}