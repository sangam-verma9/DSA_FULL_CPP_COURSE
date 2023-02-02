#include<bits/stdc++.h>
using namespace std;
int sum(Node*root){
    if(root==NULL){
        return 0;
    }
    int left=sum(root->left);
    int right=sum(root->right);
    int ans=left+right+root->data;
    return ans;
}

bool sumtree(Node*root){
    if(root==NULL){
        return true;
    }
    if(root->next==NULL){
        return true;
    }
    bool left=sumtree(root->left);
    bool right=sumtree(root->right);
    bool ans=(sum(root->left)+sum(root->right))==root->data;
    if(left && right && ans){
        return true;
    }
    else{
        return false;
    }
}
pair<bool,int> sumTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    if(root->next==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int> left=sumTreeFast(root->left);
    pair<bool,int> right=sumTreeFast(root->right);
    bool leftans=left.first;
    bool rightans=right.first;
    int leftsum=left.second;
    int rightsum=right.second;
    bool sum=root->data==(leftsum+rightsum);
    pair<bool,int> ans;
    if(leftans && rightans && sum){
        ans.first=true ;
        ans.second=root->data+leftsum+rightsum;
    }
    else{
        ans.first=false;
    }
    return ans;

}
int main() {

return 0;
}