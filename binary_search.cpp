#include<iostream>
using namespace std;

int Binary_search(int *arr,int n, int key){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    while(s<=e){
    if(arr[mid]==key){
        return mid;
    }
    else if (arr[mid]<key){
        s=mid+1;
    }
    else{
        e=mid-1;
    }
    mid=(s+e)/2;
    }
    return -1;

}
int main() {
int arr[]={2,4,7,9,13,45,67,89};
int n=sizeof(arr)/sizeof (int);
cout<<"Enter key that you find in array: ";
int key;
cin>>key;
cout<<Binary_search(arr,n,key);

return 0;
}