#include<bits/stdc++.h>
using namespace std;
int main() {
string a="sdfgurh";
stack<char>s;
for (int i=0; i<a.size();i++){
    s.push(a[i]);
}
string ans="";
while (!s.empty()){
    char b=s.top();
    ans+=b;
    s.pop();
}
cout<<ans;
return 0;
}