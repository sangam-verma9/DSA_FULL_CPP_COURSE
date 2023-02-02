#include<bits/stdc++.h>
using namespace std;
bool isSame(Node* r1, Node* r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    else if (r1==NULL && r2 !=NULL){
        return false;
    }
    else if(r1!=NULL && r2 ==NULL){
        return false;
    }

    bool left=isSame(r1->left, r2->left);
    bool right=isSame(r1->right, r2->right);
    bool value= r1->data == r2->data;
    if(left && right && value){
        return true;
    }
    else {
        return false;
    }
}
int main() {

return 0;
}