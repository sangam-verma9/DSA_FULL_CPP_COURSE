// here given a undirected and diconnected graph and v vertiex and E edges you have to print this graph by BFS travesal 
#include<bits/stdc++.h>
using namespace std;
void createadjlist(unordered_map<int,list<int>>&adjlist,vector<pair<int, int>>& edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}
void bfs(unordered_map<int,list<int>>&adjlist,unordered_map<int,bool>&visited,vector<int>&ans,int vertex){
    queue<int>q;
    q.push(vertex);
    visited[vertex]=1;
    while(!q.empty()){
        int front =q.front();
        q.pop();
        // store in ans 
        ans.push_back(front);
        // treaverse all neighbour element
        for(auto i:adjlist[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }

    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int>ans;
    unordered_map<int,list<int>>adjlist;
    unordered_map<int,bool>visited;
    // now create adjlist
    createadjlist(adjlist,edges);
    // travese all component of graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjlist,visited,ans,i);
        }
    }
    return ans;

}
int main() {

    // vector<int> ans=BFS(vertex,edges);
return 0;
}