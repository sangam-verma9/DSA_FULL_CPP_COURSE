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
Node* solve(int in[],int post[],int& index,int instart, int inend,int n){
    if(index<0 ||instart>inend){
        return NULL;
    }
    int data=post[index--];
    Node* root=new Node(data);
    int p=findposition(in,n,data);
    root->right=solve(in,post,index,p+1,inend,n);// In inorder and postorser we contruct right part first so here right call first than left
    root->left=solve(in,post,index,instart,p-1,n);
    return root;
}
Node* buildTree(int in[],int post[],int n){
    int index=n-1;
    Node* root= solve(in,post,index,0,n-1,n);
    return root;
};
int main() {

return 0;
}