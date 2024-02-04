#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>adj;

    void addedge(int u,int v,bool directed){
        // direction-0 =undirected
        //direction -1 =directed

        // for directed ans undirected both exists
        adj[u].push_back(v);
        // for undirected only
        if(directed==0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

};
int main() {
    graph g;
    int n,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<endl<<"Enter number of edges: ";
    cin>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        //crete edge for undirected graph
        g.addedge(x,y,0);
    }
    //printing 
    g.print();   /* output
                Enter number of nodes: 5

                Enter number of edges: 6
                0 1
                1 2
                2 3
                3 1
                3 4
                0 4
                4 -> 3, 0,
                0 -> 1, 4,
                1 -> 0, 2, 3,
                2 -> 1, 3,
                3 -> 2, 1, 4,*/


return 0;
}