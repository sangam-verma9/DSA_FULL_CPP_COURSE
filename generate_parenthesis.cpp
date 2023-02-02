#include<bits/stdc++.h>
using namespace std;
void solve(int open, int close, string s , vector<string>&ans){
    // cout<<s<<endl;
    if(open==0 && close==0){
        ans.push_back(s);
        return;
    }
    if(open>0){
        s.push_back('(');
        solve(open-1,close,s,ans);
        s.pop_back();
    }
    if(close>0){
        if(open<close){
            s.push_back(')');
            solve(open,close-1,s,ans);
            s.pop_back();
        }
    }
}
int main() {
int n;
cin>>n;
int open =n,close=n;
string s="";
vector<string>ans;
solve(open,close,s,ans);

cout<<"finally "<<endl;
for(auto i:ans){
    cout<<i<<" ";
}
return 0;
}