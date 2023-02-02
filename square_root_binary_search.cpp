#include<iostream>
using namespace std;
int find_root(int s,int e){
    int mid=(s+e)/2;
    int n=e;
    int ans=0;
    while(s<=e){
      if(mid*mid<=n){
        s=mid+1;
        ans=mid;
      }
      else{
        e=mid-1;
      }
      mid=mid=(s+e)/2;
    }
    return ans;
}
int main() {
int n;
cin>>n;
cout<<find_root(0,n);
return 0;
}