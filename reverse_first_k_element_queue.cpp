#include<bits/stdc++.h>
using namespace std;
queue<int> reverse_k_elem(queue<int>&q,int k ){
    stack<int>s;
    for(int i=0;i<k; i++){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int element= s.top();
        q.push(element);
    }
    int t= q.size()-k;
    while(t--){
        int element=q.front();
        q.pop();
        q.push(element);
    }
}
int main() {

return 0;
}