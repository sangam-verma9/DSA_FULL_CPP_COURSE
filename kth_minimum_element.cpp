//Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
#include<bits/stdc++.h>
using namespace std;
int kthsamllele(int arr[],int n,int k){
    priority_queue<int>pq;
    // step-1 push k element in pq
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    // step-2 if remaining ele are less than top ele of pq than pop one ele from pq ans push that ele
    for(int i=k; i<n; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }  
    // top element is kth minimum element  
    int ans=pq.top();
    return ans;
}
int main() {
    int arr[]={7,10,4,15,20};
    int k=4;
    int n=sizeof(arr)/sizeof(int);
    int ans=kthsamllele(arr,n,k);
    cout<<ans;
return 0;
}