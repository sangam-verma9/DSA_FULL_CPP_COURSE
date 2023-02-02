//Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>arr,int index,int size){
    int largecnt=index;
    int left=index*2+1;
    int right=index*2+2;
    if(left<size && arr[left]>arr[index]){
        largecnt=left;
    }
    if(right<size && arr[right]>arr[index]){
        largecnt=right;
    }
    if(index!=largecnt){
        swap(arr[largecnt],arr[index]);
        heapify(arr,largecnt,size);
    }

}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // step-1 merge two arrays
    vector<int>ans;
    ans=a;
    for(auto i:b){
        ans.push_back(i);
    }
    for(int i=ans.size()/2; i>=0; i--){
        heapify(ans,i,ans.size());
    }
    return ans;
}
int main() {
   
return 0;
}