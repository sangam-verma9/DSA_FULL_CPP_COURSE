#include<bits/stdc++.h>
using namespace std;
class Queue {
    public:
    int *arr;
    int size;
    int qfront;
    int rear;
    Queue(){
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }
    void push (int data){
        if(rear==size){
            cout<<"queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
    void pop() {
        if(qfront==rear){
            cout<<"queue if empty"<<endl;
        }
        else {
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
        }
    }
    void front(){
        if(qfront==rear){
            cout<<"queue is empty"<<endl;
        }
        else{
            cout<<arr[qfront]<<endl;
        }
    }
    bool isempty(){
        if(qfront==rear){
            return true;
        }
        else return false;
    }
    int qsize(){
        return rear-qfront;
    }

};
int main() {
    Queue q1;
    q1.push(3);
    q1.push(4);
    q1.push(6);
    q1.front();

    q1.front();
    cout<<q1.qsize();

return 0;
}