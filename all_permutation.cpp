#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>input,int index){
    if(index>=input.size()){
        
        for (int i=0; i<input.size();i++){
            cout<<input[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=index;i<input.size(); i++){
        swap(input[index],input[i]);
        solve(input,index+1);
        //backtrack
        swap(input[index],input[i]);
    }
}
int main() {
vector<int>input={1,2,3};
int index=0;
solve(input,index);


return 0;
}