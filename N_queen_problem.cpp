// there are n*n chess board ans n queen you have to place these queen such that no queen attack each other
// one queen attack if 1. queens are in same row 2. queens are in same column 3. queen are in digonal
#include<bits/stdc++.h>
using namespace std;
void addsol(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int col, int row,vector<vector<int>>&board,int n){
    int x=row;
    int y=col;

    // check for row
    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }
    // check for upper diagonal
    x=row;
    y=col;
    while(x>=0 && y>=0 ){
        if(board[x][y]==1){
            return false;
        }
        y--;
        x--;
    }
    // check for lower diagonal
    x=row;
    y=col;
    while(x<n && y>=0 ){
        if(board[x][y]==1){
            return false;
        }
        y--;
        x++;
    }
    return true;
}
void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    if(col==n){
        addsol(board,ans,n);
        return;
    }

    for(int row=0;row<n; row++){
        if(isSafe(col,row,board,n)){
            board[row][col]=1;
            //recusion
            solve(col+1,board,ans,n);
            //backtrack
            board[row][col]=0;
        }
    }
}
vector<vector<int>>nQueen(int n){
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;
    solve(0,board,ans,n);
    return ans;
}
int main() {
    vector<vector<int>>ans=nQueen(4);
    for(int i=0;i<ans.size(); i++){
        for(int j=0;j<ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}