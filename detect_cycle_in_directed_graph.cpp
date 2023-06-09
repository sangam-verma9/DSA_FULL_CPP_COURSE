#include<bits/stdc++.h>
using namespace std;
bool dfscycle(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,unordered_map<int,list<int>>&adj){
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cyclrdetect=dfscycle(neighbour,visited,dfsvisited,adj);
            if(cyclrdetect){
                return true;
            }
        }
        else if(dfsvisited[neighbour]){
            return true;
        }
    }
    dfsvisited[node]=false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // adjecency list
    unordered_map<int,list<int>>adj;
    for(auto i: edges){
        int u= i.first;
        int v=i.second;
        adj[u].push_back(v);
    }
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsvisited;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool check=dfscycle(i,visited,dfsvisited,adj);
            if(check)
            return true;
        }
    }
    return false;
    
}
int main() {

return 0;
}
