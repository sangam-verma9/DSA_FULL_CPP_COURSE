#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtFirst(Node*&head,int data){
    Node* temp=new Node (data);
    temp->next=head;
    head=temp;
    
}
void insertAtLast(Node*&head, int data){
    Node* temp =new Node (data);
    Node* curr= head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}
void insertAtAnyPosition(Node*&head, int data,int position){
    if (position ==1){
    insertAtFirst(head,data);
    return;
    }
    Node* temp=head;
    int size=1;
    while (size<position-1){
        size++;
        temp=temp->next;
    }

    if (temp->next==NULL){
        insertAtLast(head,data);
        return;
    }
    // if(position<1 ||position>size+1){
    //     cout<<"error 404"<<endl;
    //     return;
    // }
    
    Node* nodetoinsert=new Node (data);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

}
//delete node
void deletenode(Node*&head, int position){
    if (position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;
        while (cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* head){
    while (head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main() {
    Node obj1 (2);
    Node* head=&obj1;
    insertAtFirst(head,3);
    insertAtLast(head,4);
    insertAtLast(head,5);
    insertAtLast(head,6);
    insertAtFirst(head,7);
    insertAtAnyPosition(head,10,3);
    deletenode(head,5);


    print(head);

return 0;
}