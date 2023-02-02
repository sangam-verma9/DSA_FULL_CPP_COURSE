// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
#include<bits/stdc++.h>
using namespace std;
int totalcount(Node* root){
    if(root==NULL){
        return 0;
    }
    int ans=1+totalcount(root->left)+totalcount(root->right);
    return ans;
}
bool iscompletebinarytree(Node* root,int cnt, int index){
    if(root==NULL){
        return true;
    }
    if(index>=cnt){
        return false;
    }
    else{
        bool left=iscompletebinarytree(root->left,cnt,2*index+1);
        bool right=iscompletebinarytree(root->right,cnt,2*index+2);
        if(left && right){
            return true;
        }
        else return false;
    }

}
bool ismaxorder(Node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    else if(root->right==NULL){
        if(root->data >root->left->data){
            return true;
        }
        else return false;
    }
    else{
        bool left=ismaxorder(root->left);
        bool right=ismaxorder(root->right);

        if(left && right && root->data >root->left->data && root->data > root->right->data){
            return true;
        }
        else return false;
    }
}
bool isBinaryTreeHeap(Node* root){
    int index=0;
    int cnt=totalcount(root);
    if(isCBT(root,cnt,index) && ismaxorder(root)){
        return true;
    }
    else return false;
}
int main() {
    
return 0;
}