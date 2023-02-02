#include<iostream>
using namespace std;
int main() {
int arr[]={12,34,10,56,17,39,46,22};
int n=sizeof(arr)/sizeof(int);
for (int i=1; i<n; i++){
    int current=arr[i];
    int j;
    for ( j=i-1;j>=0; j--){
       if (current <arr[j]){
         arr[j+1]=arr[j];
       }
       else {
        break;
       }
       
    }
    arr[j+1]=current;
    
}
for (int i=0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}