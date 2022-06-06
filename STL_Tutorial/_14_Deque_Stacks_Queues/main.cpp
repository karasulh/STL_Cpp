#include <iostream>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main(){
    deque<int> transactions;

    transactions.push_front(100);
    transactions.push_front(300);
    transactions.push_back(500);
    transactions.push_back(800);

    cout<<"deque: ";
    for(unsigned int i=0;i<transactions.size();i++){
        cout<<transactions[i]<<" ";
    }
    cout <<endl;

    stack<int> stack;
    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.push(400);

    cout<<"stack: ";
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<endl;

    queue<int> queue;
    queue.push(100);
    queue.push(200);
    queue.push(300);
    queue.push(400);

    cout<<"queue: ";
    while(!queue.empty()){
        cout<<queue.front()<<" ";
        queue.pop();
    }
    cout<<endl;

    priority_queue<int> pqueue;
    pqueue.push(200);
    pqueue.push(600);
    pqueue.push(100);
    pqueue.push(400);
    pqueue.push(40);
    pqueue.push(3000);

    cout<<"pqueue: ";
    while(!pqueue.empty()){
        cout<<pqueue.top()<<" ";
        pqueue.pop();
    }
    cout<<endl;

    return 0;
}