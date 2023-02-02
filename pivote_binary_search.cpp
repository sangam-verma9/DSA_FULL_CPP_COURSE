#include<iostream>
using namespace std;
int find_pivote(int *arr , int n){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    while (s<e){
       if(arr[mid]>=arr[s]){
        s=mid+1;
       }
       else{
        e=mid;
       }
       mid=(s+e)/2;
    }
    return e;
}
int main() {
int arr[]={7,10,1,2,3,5};
int n=sizeof(arr)/sizeof(int);
cout<<find_pivote(arr,n);
return 0;
}