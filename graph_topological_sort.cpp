// A directed acyclic graph (DAG) is a directed graph that contaion no cycle.Topological sort of DAG is linear orderig
//of vertices such that for every edge directed to vertex 'u' to vertex 'v' ,vertex 'u' comes before vertex 'v' in the
// ordering. Topological sort is not possible if graph is not DAG. 
#include<bits/stdc++.h>
using namespace std;
void toposort(int node,unordered_map<int,bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    
    for(auto neighbour :adj[node]){
        if(!visited[neighbour]){
            toposort(neighbour,visited,s,adj);
        }
    }

    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>>adj;
    for(int i=0; i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }

    // call dfs topological sort for all component
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            toposort(i,visited,s,adj);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main() {

return 0;
}