#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Circular{
private:
    Node* head;
    static Node* CreateNode(int);
public:
    Circular(){
    head = NULL;
}
    void Insert(int);
    void Delete();
    void Display();
    void Count();
    void Max();
    bool IsEmpty();
};

Node* Circular::CreateNode(int val){
    Node* newNode = new Node();
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}

bool Circular::IsEmpty(){
    return head == NULL;
}

void Circular::Insert(int val){
    if(IsEmpty()){
        Node* newNode = CreateNode(val);
        head = newNode;
        head ->next = head;
    }
    else{
        if(head->next == head){
            Node* newNode = CreateNode(val);
            head->next = newNode;
            newNode->next = head;
        }
        else{
            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            Node* newNode = CreateNode(val);
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

void Circular::Delete() {
    if(IsEmpty()){
        cout<<"List is already empty."<<endl;
    }
    else{
        Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        temp->next->next = NULL;
        temp->next = head;
    }
}

void Circular::Display() {
    if(IsEmpty())
        cout<<"List is already empty.";
    else{
        Node* temp = head;
        cout<<temp->data<<" ";
        while(temp->next != head){
            temp = temp->next;
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
}

void Circular::Count() {
    if(IsEmpty())
        cout<<"List is already empty.";
    else{
        int count = 1;
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
            count += 1;
        }
        cout<<"\nNumber of elements : "<<count<<endl;
    }
}

void Circular::Max() {
    if(IsEmpty())
        cout<<"List is already empty.";
    else{
        Node* temp = head;
        int max = temp->data;
        while(temp->next != head){
            temp = temp->next;
            if(temp->data > max)
                max = temp->data;
        }
        cout<<"\nMaximum : "<<max<<endl;
    }
}


int main() {
    Circular C;
    C.Insert(1);
    C.Insert(2);
    C.Display();
    C.Delete();
    C.Insert(3);
    C.Insert(5);
    C.Insert(0);
    C.Display();
    C.Max();
    C.Count();

}