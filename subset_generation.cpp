#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>v,int index,int size,vector<int> s,vector<vector<int>>& ans){
    if(index>=size){
        ans.push_back(s);
        return;
    }
    solve(v,index+1,size,s,ans);
    s.push_back(v[index]);
    solve(v,index+1,size,s,ans);
    s.pop_back();
   
}
int main() {
vector<int>v={1,2,3};
int size=v.size();
vector<vector<int>>ans;
vector<int> s;
int index=0;
solve(v,index,size,s,ans);


cout<<"[";
for(auto s:ans){
    cout<<"[";
    for(auto i:s){
        cout<<i<<" ";
    }
     cout<<"]";
}
cout<<"]";


return 0;
}