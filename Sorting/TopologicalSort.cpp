#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int visited[], stack<int> &st, vector<int> adj[]){
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]){
    int visited[V] = {0};
    stack<int> st;

    for(int i = 0; i<V;i++){
        if(!visited[i]){
            dfs(i, visited, st, adj);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


int main(){
    int V = 6;
    vector<int> adj[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topoSort(V, adj);

    cout << "Topological Sort: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;

}