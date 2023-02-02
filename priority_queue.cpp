#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[5]={2,4,9,6,1};
    int n=5;
    // this priority queue is maxheap 
    priority_queue<int>pq; 
    for(int i=0;i<5;i++){
        pq.push(arr[i]);
    }
    for(int i=0;i<5;i++){
        int top=pq.top();    // output = 9 6 4 2 1 for maxheap 
        pq.pop();
        cout<<top<<" ";
    }
    cout<<endl;
    // this priority queue is for minheap 
    priority_queue<int, vector<int>,greater<int>>minheap;
    for(int i=0;i<5;i++){
        minheap.push(arr[i]);
    }
    for(int i=0;i<5;i++){
        int top=minheap.top();   // output= 1 2 4 6 9 for minheap
        minheap.pop();
        cout<<top<<" ";
    }

    
return 0;
}