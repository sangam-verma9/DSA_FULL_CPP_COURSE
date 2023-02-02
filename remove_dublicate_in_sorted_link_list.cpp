#include<bits/stdc++.h>
using namespace std;
void remove_dublicate(Node*&head){
    if (head==NULL){
        return ;
    }
    Node *curr=head;
    while (curr!=NULL){
        if ((curr->next!=NULL)&& (curr->data==curr->next->data)){
            Node* nodetodelete=curr->next;
            curr->next=curr->next->next;
            delete nodetodelete;
        }
        else{
            curr=curr->next;
        }
    }
}
int main() {
//link list
return 0;
}