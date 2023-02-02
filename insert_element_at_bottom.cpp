#include<bits/stdc++.h>
using namespace std;
void inserAtBottom(stack<int>s,int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int num=s.top();
    s.pop();
    inserAtBottom(s,n);
    s.push(num);
}
int main() {

return 0;
}