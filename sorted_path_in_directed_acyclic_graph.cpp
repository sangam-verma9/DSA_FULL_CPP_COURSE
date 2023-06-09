#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adj;
    void createedge(int u, int v, int w){
        pair<int,int>p=make_pair(v,w);
        adj[u].push_back(p);
    }
    void topologicalsort(int node,stack<int>&s,unordered_map<int,bool>&visited){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i.first]){
                topologicalsort(i.first,s,visited);
            }
        }
        s.push(node);
    }
    void printgraph(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<"["<<j.first<<","<<j.second<<"]";
            }
            cout<<endl;
        }
    }

    void getsortedpath(int src,vector<int>&sortdis,stack<int>&s){
        sortdis[src]=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(sortdis[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if((sortdis[top]+i.second) <sortdis[i.first]){
                        sortdis[i.first]=sortdis[top]+i.second;
                    }
                }
            }
        }
    }
};
int main() {
    Graph g;
    g.createedge(0,1,5);
    g.createedge(0,2,3);
    g.createedge(1,2,2);
    g.createedge(1,3,6);
    g.createedge(2,3,7);
    g.createedge(2,4,4);
    g.createedge(2,5,2);
    g.createedge(3,4,-1);
    g.createedge(4,5,-2);

    // print graph
    g.printgraph();

    int n=6;
    //topological sort
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.topologicalsort(i,s,visited);
        }
    }

    int src=1;
    vector<int>sortdis(n,INT_MAX);
    g.getsortedpath(src,sortdis,s);

    // printing vector of sortedis
    for(int i=0;i<n;i++){
        cout<<sortdis[i]<<" ";
    }
return 0;
}