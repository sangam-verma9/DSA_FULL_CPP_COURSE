#include<bits/stdc++.h>
using namespace std;
class Stack {
    public:
    int* arr;
    int size;
    int top;
    Stack(int size){
        this->size=size;
        top=-1;
        arr=new int [size];
    }
    void push (int data){
        if (size-top>0){
            top++;
            arr[top]=data;
            
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop (){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else {
            cout<<"stack underflow"<<endl;
            return -1;
        }
    }
    bool isempty (){
        if(top<0){
            return true ;
        }
        else false;
    }
};


int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    cout<< s.peek()<<endl;
    s.push(3);
    s.push(4);
    cout<< s.peek()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<< s.peek()<<endl;
    if (s.isempty()){
        cout<<"stack is empty"<<endl;
    }
    else {
        cout<<"not empty"<<endl;
    }
  
return 0;
}