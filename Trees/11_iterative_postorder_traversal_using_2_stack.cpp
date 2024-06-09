#include<bits/stdc++.h>
using namespace std;
class Sloution{
    public:
    vector<int>iterativePostorder(Node* root){
        vector<int>ans;
        stack<Node*>s1,s2;
        s.push(root);
        while(!s1.empty()){
            Node* curr=s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left){
                s1.push(curr->left);
            }
            if(curr->right){
                s1.push(curr->right);
            }
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->data);
            s2.pop();
        }
        return ans;
    }
};
int main(){

return 0;
}