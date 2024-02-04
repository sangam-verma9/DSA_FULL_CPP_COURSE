#include<bits/stdc++.h>
using namespace std;
int findpivote(int *arr,int s,int e){
    int mid=(s+e)/2;
    while(s<e){
        if(arr[mid]>arr[e]){
            s=mid+1;
        }
        else if(arr[mid]<arr[e]){
            e=mid;
        }
        mid=(s+e)/2;
    }
    return s;
}
int main() {
int arr[7]={4,5,6,7,8,2,3};
int p=findpivote(arr,0,6);
cout<<p;
return 0;
}