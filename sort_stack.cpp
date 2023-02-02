#include<bits/stdc++.h>
using namespace std;
void insertsortedorder(stack<int>&s, int num){
    if((s.empty())|| (num>=s.top())){
        s.push(num);
        return;
    }
    int num1=s.top();
    s.pop();
    insertsortedorder(s,num);
    s.push(num1);

}
void sortstack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int num=s.top();
    s.pop();
    sortstack(s);
    insertsortedorder(s,num);
}
int main() {

return 0;
}