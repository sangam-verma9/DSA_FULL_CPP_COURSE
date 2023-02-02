#include<bits/stdc++.h>
using namespace std;
queue<int> reverse(queue<int>&q){
    stack<int>s;
    while (!q.empty()){
        int element=q.front();
        s.push(element);
        q.pop();
    }
    while (!s.empty()){
        int element =s.top();
        q.push(element);
        s.pop();
    }
    return q;
}
// we also reverse a queue with using recusion
int main() {

return 0;
}