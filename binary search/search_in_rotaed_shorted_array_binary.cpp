#include<iostream>
using namespace std;
int Binary_search(int *arr, int key,int s, int e){
    
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
cout<<"Enter key value: ";
int key;
cin>>key;
int p=find_pivote(arr,n);
if(key>=arr[p]&& key<=arr[n-1]){
cout<<Binary_search(arr,key,p,n-1);
}
else {
cout<<Binary_search(arr,key,0,p-1);
}

return 0;
}