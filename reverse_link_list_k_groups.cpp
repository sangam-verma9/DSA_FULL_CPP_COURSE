#include<bits/stdc++.h>
using namespace std;
Node* reverseKgroup(Node*&head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    int cnt=0;
    while (curr!=NULL && cnt<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
    }
    if(forward!=NULL ){
        head->next=reverseKgroup(forward,k);
    }
    return prev;
}
int main() {
    // link list

return 0;
}