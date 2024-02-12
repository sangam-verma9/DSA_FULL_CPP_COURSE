//given a undirected graph with n verticed and m edges to have to find that cycle is present or not
#include<bits/stdc++.h>
using namespace std;
bool iscycleBFS(int node,unordered_map<int, bool>&visited,unordered_map<int,list<int>>&adj){
    unordered_map<int,int>parent;
    parent[node]=-1;
    visited[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour: adj[front]){
            if(visited[neighbour]==1 && parent[front]!=neighbour ){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
        
    }
    return false;
}
string cyclededection(vector<vector<int>>& edges,int n, int m){
    // create adgcencylist
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool>visited;
    // to handle diconnected graph
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=iscycleBFS(i,visited ,adj);
            if(ans){
                return "YES";
            }
            
        }
    }
    return "NO";
}
int main() {

return 0;
}