#include<bits/stdc++.h>
using namespace std;
bool iscircular(Node*head){
    if (head==NULL || head->next==NULL){
        return true;
    }
    Node * temp=head->next;
    while (temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if (temp==head){
        return true;
    }
    else {
        return false;
    }

}
int main() {
// link list
return 0;
}