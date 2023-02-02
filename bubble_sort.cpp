#include<iostream>
using namespace std;
int main() {
int arr[]={12,34,10,56,17,39,46,22};
int n=sizeof(arr)/sizeof(int);
for (int i=1; i<n; i++){
    bool swapped=false;
    for (int j=0; j<n-i; j++){
        if (arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped=true;
        }
    }
    if (swapped=false){
        break;
    }
}
for (int i=0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}