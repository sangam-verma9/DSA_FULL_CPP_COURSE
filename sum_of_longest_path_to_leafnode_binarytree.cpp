#include<bits/stdc++.h>
using namespace std;
void solve(Node* root,int len, int & maxlen, int sum,int & maxsum){
    if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=sum;
        }
        else if(len==maxlen){
            maxsum=max(maxsum,sum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,len+1,maxlen,sum,maxsum);
    solve(root->right,len+1,maxlen,sum,maxsum);
}
int sumoflongpath(Node* root){
    int maxlen=0;
    int len=0;
    int maxsum=0;
    int sum=0;
    solve(root,len,maxlen,sum,maxsum);
    return maxsum;
}
int main() {

return 0;
}