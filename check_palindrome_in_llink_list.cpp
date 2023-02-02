#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>v){
    int n=v.size();
    int s=0;
    int e=n-1;
    while (s<=e){
        if (v[s]!=v[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
bool check_palindrome(Node*head){
    Node* temp=head;
    vector<int>v;
    while (temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    return check(v);
}
// second method
Node* getmid(Node*head){
    Node* fast=head->next;
    Node* slow=head;
    while (fast!=NULL && fast->next!=NULL){
        fast=fast->next ->next;
        slow=slow->next;

    }
    return slow;
}
Node* reverse (Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    while (curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    return prev;
}
bool check_palindrome2 (Node* head){
    if (head==NULL || head->next==NULL){
        return true;
    }
    Node* mid=getmid(head);
    Node* temp=mid->next;
    Node* head2=reverse(temp);
    Node* head1=head;
    while (head1!=NULL && head2!=NULL){
        if (head1->data!= head2->data)
        return false;

        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
int main() {
// link list
return 0;
}