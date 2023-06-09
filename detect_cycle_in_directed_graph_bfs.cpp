#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
   unordered_map<int,list<int>>adj;
    for(int i=0 ; i<edges.size();i++){
        int u= i.first-1;
        int v=i.second-1;
        adj[u].push_back(v);
    }

    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    // push all element which have 0 indegree
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    // do bfs
    int cnt=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cnt++;

        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    if(cnt==n){
        return 0;
    }
    else return 1;
}
using namespace std;
int main() {

return 0;
}