#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &stack,int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }
    int ch=stack.top();
    stack.pop();
    insertAtBottom(stack,num);
    stack.push(ch);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if (stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,num);
}
int main() {

return 0;
}