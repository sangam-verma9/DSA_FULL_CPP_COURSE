#include<bits/stdc++.h>
using namespace std;
Node* solve(Node* root,int node, int k){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* left=solve(root->left,node, k);
    Node* right=solve(root->right,node,k);
    if(left!=NULL && right==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return left;
    }
    if(left==NULL && right!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return right;
    } 
    return NULL;
}
int kthancestor(Node* root, int node,int k){
    Node* ans=solve(root,node,k);
    if(ans==NULL|| ans->data==node){
        return -1;
    }
    return ans->data;
}
int main() {

return 0;
}