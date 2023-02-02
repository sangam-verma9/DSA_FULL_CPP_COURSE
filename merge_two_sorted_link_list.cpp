#include<bits/stdc++.h>
using namespace std;
Node* merge(Node* &head1, Node*& head2){
    if (head1==NULL){
        return head2;
    }
    if (head2==NULL){
        return head1;
    }
    if (head1->next==NULL){
        head1->next=head2;
        return head1;
    }
    Node* start1=head1;
    Node* start2=head2;
    Node* next1=head1->next;
    Node* next2=head2->next;
    while (next1!=NULL && start2!=NULL){
        if ((start1->data <=start2->data)&& (start2->data <=next1->data)){
            start1->next=start2;
            next2=start2->next;
            start2->next=next1;
            start1=start2;
            start2=next2;
        }
        else{
            start1=next1;
            next1=next1->next;
            if (next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return head1;
}

int main() {
// two link list
// LIST1 LIST2
Node* head1;
Node* head2;
Node* head;
if (head1->data <= head2->data){
    head=merge(head1,head2);
}
else{
    head=merge(head2,head1);
}
return 0;
}