#include<bits/stdc++.h>
using namespace std;
int totalcount(Node* root){
    if(root==NULL){
        return 0;
    }
    int ans=1+totalcount(root->left)+totalcount(root->right);
    retunr ans;
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
int main() {
    int index=0;
    int cnt=totalcount(root);
    bool iscomletebinarytree(root,cnt,index);
return 0;
}