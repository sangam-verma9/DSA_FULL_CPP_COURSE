#include<bits/stdc++.h>
using namespace std;
void printLeft(Node* root, vector<int>&ans){
    if((root==NULL)||(root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left!=NULL){
        printLeft(root->left,ans);
    }
    else{
        printLeft(root->right, ans);
    }
}
void printleaf(Node* root, vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    printleaf(root->left,ans);
    printleaf(root->right,ans);
}
void printRight(Node* root,vector<int>&ans){
    if((root==NULL)||(root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right!=NULL){
        printRight(root->right,ans);
    }
    else{
        printRight(root->left,ans);
    }
    ans.push_back(root->data);
}
void boundarytraversel(Node* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    // left part ke liye print
    printLeft(root->left,ans);
    // leaf node ke liye
    printleaf(root->left,ans);
    printleaf(root->right,ans);
    // right part ke liye
    printRight(root->right, ans);
    return ans;
}
int main() {

return 0;
}