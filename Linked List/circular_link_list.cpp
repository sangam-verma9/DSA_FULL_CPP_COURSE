#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertANode(Node* &tail,int data, int element){
    //empty list
    if (tail==NULL){
        Node * newnode =new Node(data);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        Node * curr =tail;
        while (curr->data != element){
            curr=curr->next;
        }
        Node* temp=new Node(data);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node*tail){
    Node*temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while (tail!=temp);

}
//delete node
void deletenode(Node*&tail,int element){
    if (tail==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        Node* prev=tail;
        Node* curr= prev->next;
        while (curr->data!=element){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //1 node then
        if(curr==prev){
            tail=NULL;
        }
        //2 node then 
        elif(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
        
    }
}
int main() {
Node* tail=NULL;
insertANode(tail,5,3);
insertANode(tail,10,5);
print(tail);


return 0;
}