#include <iostream>
using namespace std;
#define max_size 5

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class Stack{
private:
    Node* top;
    int count;
public:
    Stack(){
        top = NULL;
        count = 0;
    }
    bool IsEmpty();
    void push(int);
    int pop();
};

bool Stack::IsEmpty() {
    return top == NULL;
}

void Stack::push(int val) {

    if(IsEmpty()){
        top = new Node;
        top->data = val;
        top->next = NULL;
        count++;
    }
    else{
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        count++;
    }
}

int Stack::pop() {
    if(IsEmpty())
        cout<<"Stack is empty.\n";
    else{
        Node* temp = top;
        top = top->next;
        count --;
        return temp->data;
    }

}

class Queue{
private:
    Node *front;
    Node* rear;
    int count;
    bool IsFull();
public:
    Queue(){
        front = NULL;
        rear = NULL;
        count = 0;
    }
    bool IsEmpty();
    void enqueue(int);
    void dequeue();
    void peek();
    void dispCount();
    void Reverse();
    int ReturnFront();
};

bool Queue::IsFull(){
    return count == max_size;
}

bool Queue::IsEmpty(){
    return count == 0;
}

void Queue::enqueue(int val) {
    if(IsFull()){
       cout<<"Queue is full.\n";
    }
    else{
        Node* newNode = new Node;
        newNode->data = val;
        if(IsEmpty()){
            rear = front = newNode;
        }
        else{
            newNode->next = rear;
            rear->prev = newNode;
            rear = newNode;
        }
        count ++;
    }
}

void Queue::dequeue() {
    if(IsEmpty()){
        cout<<"Queue is empty.\n";
    }
    else{
        front = front->prev;
        if(count != 1)
            front->next = NULL;
        count --;
    }
}

void Queue::peek() {
    if(IsEmpty()){
        cout<<"Queue is empty.\n";
    }
    else{
        cout<<"Rear's data : "<<rear->data<<endl;
    }
}

int Queue::ReturnFront() {
    return front->data;
}

void Queue::dispCount() {
    cout<<"Number of elements : "<<count<<endl;
}

void Queue::Reverse() {
    if(IsEmpty())
        cout<<"Queue is empty.";
    else if(count == 1);
    else{
        Stack s;
        while(!IsEmpty()){
            s.push(ReturnFront());
            dequeue();
        }
        while(!s.IsEmpty()){
            enqueue(s.pop());
        }
    }
}

int main() {
    Queue q;
    /*
    q.enqueue(10);
    cout<<"10 added."<<endl;
    q.enqueue(20);
    cout<<"20 added."<<endl;
    q.dispCount();
    cout<<"Rear's data : "<<q.peek()<<endl;
    q.dequeue();
    cout<<"Dequeue is done.\n";
    q.dispCount();
    cout<<"Rear's data : "<<q.peek()<<endl;
    q.dequeue();
    cout<<"Dequeue is done.\n";
*/
    cout<<"Inserting 6 elements to queue.\n";
    for (int i = 1; i < 6 ; i++){
        q.enqueue(i);
    }
    q.peek();
    q.dispCount();

    cout<<"\nQueue reversed."<<endl;
    q.Reverse();
    q.peek();
    q.dispCount();
    
    return 0;
}