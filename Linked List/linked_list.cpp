#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int num){
        this->value=num;
        this->next=NULL;
    }

};
// Insert node at first
void insertfirst(Node* &head,int d){
    //create new node 
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
// Insert node at tail
void inserttail(Node * &tail,int d){
    //create new node 
    Node* temp=new Node(d);
    tail->next=temp;
    tail =temp;

}
// Insert any position 
void insertanyposition( Node* &head ,Node* &tail, int index, int d){
    //Insert at start
    if(index==1){
        insertfirst(head,d);
        return;
    }
    Node* temp=head;
    int count=1;
    while (count<index-1){
        temp=temp->next;
        count++;
    }
    // Insert at tail
    if(temp->next==NULL){
        inserttail(tail,d);
        return;
    }
    // creating a node
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

}
void print(Node* &head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }cout<<endl;

}

int main(){
  /* Node node1(10);
   cout<<node1.value<<endl;
   cout<<node1.next<<endl; */

   Node *node1=new Node(10);
   Node* head=node1;
   Node* tail=node1;
  // cout<<node1->value<<endl;
  // cout<<node1->next<<endl;
  insertfirst(head,15);
  inserttail(tail,20);
  insertanyposition(head,tail,4,45);

   print(head);
return 0;
}