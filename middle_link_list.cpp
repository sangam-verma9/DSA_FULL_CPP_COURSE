#include<bits/stdc++.h>
using namespace std;
int len(Node* head){
    int cnt=0;
    while (head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
Node *findMiddle(Node *head) {
    // Write your code here
    int ans=len(head)/2;
    int c=0;
    while (c<ans){
        head=head->next;
        c++;
    }
    return head;
}
int main() {
//link list
return 0;
}