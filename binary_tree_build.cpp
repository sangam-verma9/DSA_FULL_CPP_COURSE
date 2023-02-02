#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildtree(Node*root){
    cout<<"Enter data: ";
    int n;
    cin>>n;
    root=new Node(n);
    if(n==-1){
        return NULL;
    }
    //left part
    cout<<"For left node of "<<n<<" "<<endl;
    root->left=buildtree(root->left);

    //right part
    cout<<"For right node of "<<n<<" "<<endl;
    root->right=buildtree(root->right);

    return root;   

}
Node* buildtreelevelwise(Node* root){

    queue<Node*>q;
    int d;
    cout<<"Enter data: ";
    cin>>d;
    root =new Node(d);
    q.push(root);
    while (!q.empty()){
        Node* front =q.front();
        q.pop();
        cout<<"Enter data for left node "<<front->data<<": \n";
        int leftdata;
        cin>>leftdata;
        if(leftdata !=-1){
            front->left= new Node(leftdata);
            q.push(front->left);
        }

       cout<<"Enter data for right node "<<front->data<<": \n";
        int rightdata;
        cin>>rightdata;
        if(rightdata !=-1){
            front->right= new Node(rightdata);
            q.push(front->right);
        }
    }
    return root;
}
void preorder(Node* root){
  
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void inorder(Node* root){
  
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void postorder(Node* root){
  
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
// print level wise without endl
void printlevelwise1(Node* root){
    if(root==NULL){
        return ;
    }
    else{
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* front =q.front();
            cout<<front->data;
            q.pop();
            if(front->left!=NULL){
            q.push(front->left);
            }
            if(front->right!=NULL){
            q.push(front->right);
            }

        }
    }
}
// print level wise
void printlevelwise(Node*root){

    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){

        Node* front= q.front();
        q.pop();
      
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
      
    }

}
// height of tree
int height (Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
// diameter of tree
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right)+1;
    int ans=max(op1,max(op2,op3));
    return ans;
}
// check tree balance or not
bool isBalance(Node* root){
    if(root==NULL){
        return true;
    }
    bool left=isBalance(root->left);
    bool right=isBalance(root->right);
    bool ans=abs (height(root->left)-height(root->right))<=1;
    if(left && right && ans){
        return true;
    }
    else{
        return false;
    }
}
int main() {
    // Node* root =new Node(1);
    // cout<<root->data;
    Node* root=NULL;
    // root= buildtree(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // printlevelwise(root);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1 
    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1
   root = buildtreelevelwise(root);
   cout<<endl;
   printlevelwise(root);
   cout<<endl;
   int height1=height(root);
   cout<<height1<<endl;
   int diameter1=diameter(root);
   cout<<diameter1<<endl;
   bool balanceornot=isBalance(root);
   cout<<balanceornot<<endl;

return 0;
}