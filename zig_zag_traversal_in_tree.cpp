#include<bits/stdc++.h>
using namespace std;
// print levelwise
Node* printlevelwise(Node* root){
    if(root==NULL){
        return root;
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
// print zig-zag
void printzigzag(Node* root){
    vector<int>result;
    if(root==NULL){
        return result;
    }
    else{
        queue<Node*>q;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>temp(size);
            for(int i=0; i<size; i++){
                Node* front=q.front();
                if(lefttoright){
                    temp[i]=front->data;
                }
                else{
                    temp[size-i-1]=front->data;
                }
                q.pop();
                if(front->left!=NULL){
                  q.push(front->left);
                }
                if(front->right!=NULL){
                  q.push(front->right);
                }
            }
           
            for(auto i:temp){
                result.push_back(i);
            }
            lefttoright=!lefttoright;

        }
        return result;
    }
}
int main() {

return 0;
}