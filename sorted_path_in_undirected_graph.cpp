// Shortest path in an unweighted graph
// we want to find sorted path between s to t and there are total n houses and there are m bidirectonal roads
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    vector<int>ans;
	unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;

    //bfs
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;

    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
                parent[i]=front;
            }
        }
    }

    // operation on parent 
    int currnode=t;
    ans.push_back(t);
    while(currnode!=s){
        currnode=parent[currnode];
        ans.push_back(currnode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
	
	
}
int main() {

return 0;
}