#include<iostream>
#include<queue>
using namespace std;
int main() {
    deque<int>d;
    d.push_front(3);
    d.push_back(4);
    d.pop_front();
    // d.pop_back();
    cout<<d.front()<<endl;
    if(d.empty()){
        cout<<"deque is empty"<<endl;
    }
    else{
        cout<<"deque is not empty"<<endl;
    }
    
return 0;
}