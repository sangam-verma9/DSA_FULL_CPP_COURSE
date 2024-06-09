#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int>iterativePostorder(Node* root){
        vector<int>ans;
        stack<Node*>s;
        Node* curr=root;
        while(curr!=NULL || !s.empty()){
            if(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            else{
                Node* temp=s.top()->right;
                if(temp==NULL){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && s.top()->right==temp){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}