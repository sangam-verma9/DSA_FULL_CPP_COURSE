#include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&s,int size, int count){
    // base case
    if (count ==size/2){
        s.pop();
        return ;
    }
    int a= s.top();
    s.pop();
    solve(s,size,count+1);
    s.push(a);
}
void delete_middle(stack<int>&s; int size){
    int count =0;
    solve(s,size,count);
}
int main() {

return 0;
}