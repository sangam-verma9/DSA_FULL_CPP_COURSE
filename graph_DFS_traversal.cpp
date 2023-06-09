//given a undirected and diconnected graph ans v vertices ans e edges you have to print graph through dfs
#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,vector<int>&component,int node){
    component.push_back(node);
    visited[node]=1;
    // every connected graph recursive call
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(adj,visited,component,i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>ans;
    unordered_map<int,bool>visited;
    unordered_map<int,list<int>>adj;
    // crete adj list
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // traverse all component for disconnected graph
    for(int i=0;i<V;i++){
        vector<int>component;
        if(!visited[i]){
            dfs(adj,visited,component,i);
            ans.push_back(component);
        }
    }
    return ans;
}
int main() {
    //vector<vector<int>> ans=depthFirstSearch(V,E,edges);
return 0;
}