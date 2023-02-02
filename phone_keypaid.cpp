#include<bits/stdc++.h>
using namespace std;
void solve(string s,int index,string *mapping, string output,vector<string>&ans){
    if (index>=s.length()){
        ans.push_back(output);
        return;
    }
    int num=s[index]-'0';
    string p=mapping[num];
    for (int i=0;i<p.length();i++){
        output.push_back(p[i]);
        solve(s,index+1,mapping,output,ans);
        //backtrack
        output.pop_back();
    }
}
int main() {
string s;
cin>>s;
vector <string> ans;
string output="";
string mapping [10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int index =0;
solve (s,index,mapping,output,ans);
for (int i=0; i<ans.size()-1;i++){
    cout<<ans[i]<<" ";
}
return 0;
}