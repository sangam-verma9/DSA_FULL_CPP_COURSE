#include<iostream>
using namespace std;
int peek_element(int *arr,int n){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=(s+e)/2;
    }  
     return s; 
}

int main() {
int arr[]={0,1,0};
int n=sizeof(arr)/sizeof(int);
cout<<peek_element(arr,n);
return 0;
}