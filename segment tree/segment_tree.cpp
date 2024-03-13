#include<bits/stdc++.h>
using namespace std;
int arr[10000],seg[4*100000];
void buildTree(int ind, int low, int high)
{
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    buildTree(2 * ind + 1, low, mid);
    buildTree(2 * ind + 2, mid + 1, high);
    int left=seg[ind*2+1];
    int right=seg[ind*2+2];
    seg[ind]=max(left,right);
}
int query(int ind,int low,int high,int ql,int qr){
    if(low>=ql && high<=qr){
        return seg[ind];
    }
    if(qr<low || ql>high){
        return INT_MIN;
    }
    int mid=(low+high)/2;
    int left=query(ind*2+1,low,mid,ql,qr);
    int right=query(ind*2+2,mid+1,high,ql,qr);
    return max(left,right);
}

// update one node
void updateNode(int ind,int low,int high,int i,int val){
    //no overlap 
    if(i<low || i>high){
        return;
    }
    // reached to leaf node
    if(low==high){
        seg[ind]=val;
        return;
    }
    // i is lying in range low and high 
    int mid=(low+high)/2;
    updateNode(ind*2+1,low,mid,i,val);
    updateNode(ind*2+2,mid+1,high,i,val);
    seg[ind]=max(seg[ind*2+1],seg[ind*2+2]);

}

// Range update node you will be given a range rs and re and you have to increment every node by inc
void updateRange(int ind,int low,int high,int rs,int re,int inc){
    // no overlar
    if(re<low || rs>high){
        return ;
    }
    // reached to leaf node
    if(left==high){
        seg[ind]+=inc;
        return;
    }
    // lying in range low and high
    int mid=(low+high)/2;
    updateRange(ind*2+1,low,mid,rs,re,inc);
    updateRange(ind*2+2,mid+1,high,rs,re,inc);
    seg[ind]=max(seg[ind*2+1],seg[ind*2+2]);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(0,0,n-1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<query(0,0,n-1,a,b)<<endl;
    }
    

return 0;
}