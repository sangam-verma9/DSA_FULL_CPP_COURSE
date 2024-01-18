#include<bits/stdc++.h>
using namespace std;
int arr[10000],seg[4*100000];
void create(int ind,int low,int high){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    create(2*ind+1,low,mid);
    create(2*ind+2,mid+1,high);
    int lowele=seg[ind*2+1];
    int highele=seg[ind*2+2];
    seg[ind]=max(lowele,highele);
    
}
int query(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r){
        return seg[ind];
    }
    if(r<low || l>high){
        return INT_MIN;
    }
    int mid=(low+high)/2;
    int left=query(ind*2+1,low,mid,l,r);
    int right=query(ind*2+2,mid+1,high,l,r);
    return max(left,right);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    create(0,0,n-1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<query(0,0,n-1,a,b)<<endl;
    }

return 0;
}