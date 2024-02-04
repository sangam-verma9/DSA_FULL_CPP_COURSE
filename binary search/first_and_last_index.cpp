#include<iostream>
using namespace std;
int first_index(int *arr, int n , int key){
    int s=0, e=n-1;
    int mid=(s+e)/2;
    int a=-1;
    while(s<=e){
        if(arr[mid]==key){
            e=mid-1;
            a=mid;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return a;
}
int last_index(int *arr, int n, int key){
    int s=0, e=n-1;
    int mid=(s+e)/2;
    int a=-1;
    while (s<=e){
        if(arr[mid]==key){
            s=mid+1;
            a=mid;
        }
        else if (arr[mid]<key){
            s=mid+1;
        }
        else {
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return a;
}
int main() {
int arr[]={1,2};
int n=sizeof(arr)/sizeof(int);
cout<<"Enter a key value: ";
int key;
cin>>key;
cout<<first_index(arr,n,key)<<endl;
cout<<last_index(arr,n,key);

return 0;
}