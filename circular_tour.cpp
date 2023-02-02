#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int balence=0;
       int start=0;
       int kami=0;
       for(int i=0; i<n; i++){
           balence+=p[i].petrol-p[i].distance;
           if(balence<0){
               start=i+1;
               kami+=balence;
               balence=0;
           }
       }
       if(balence+kami >=0){
           return start;
       }
       else{
           return -1;
       }
    }
};

int main() {

return 0;
}