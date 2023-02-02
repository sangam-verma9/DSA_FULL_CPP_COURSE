#include<bits/stdc++.h>
using namespace std;
int findposition(int in[],int n,int data){
    for(int i=0;i<n;i++){
        if(data==in[i]){
            return i;
        }
    }
    return -1;
}
Node* solve(int in[],int pre[],int& index,int instart, int inend,int n){
    if(index>=n ||instart>inend){
        return NULL;
    }
    int data=pre[index];
    Node* root=new Node(data);
    int p=findposition(in,n,data);
    root->left=solve(in,pre,index+1,instart,p-1,n);
    root->right=solve(in,pre,index+1,p+1,inend,n);
    return root;
}
Node* buildTree(int in[],int pre[],int n){
    int index=0;
    Node* root= solve(in,pre,index,0,n-1,n);
    return root;
};
int main() {

return 0;
}