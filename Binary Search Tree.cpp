#include <iostream>
using namespace std;
#define COUNT 10

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* root;

class Tree{
public:
    Tree();
    static Node* create_node(int data); //Creates new Node and returns it
    static void insert(int data); //Insert data to the Binary Search Tree
    static int find_max(); //Returns maximum value in BST
    static int find_min();//Return minimum value in BST
    static int sum_max_min();//Returns sum of maximum and minimum values in BST
    static int sum_all(Node*);//Returns sum of all elements in BST
    static void even_odd(Node*);//Prints and count even and odd values in BST
    static void external(Node*);//Prints external nodes in BST
    static void internal(Node*);//Prints internal nodes in BST
    static void display(Node *temp);//Prints BST
    static void print(Node *temp, int space);//Draws BST
};

Tree::Tree() {
    root = nullptr;
}

Node *Tree::create_node(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
}

void Tree::insert(int data) {
    if(root == nullptr)
        root = create_node(data);
    else{
        Node* temp = root;
        Node *parent = nullptr;
        while(temp != nullptr){
            parent = temp;
            temp = temp->data < data ? temp->right : temp->left;
        }
        temp = create_node(data);
        if(parent->data > temp->data)
            parent->left = temp;
        else
            parent->right = temp;
    }
}

int Tree::find_max() {
    if(root != nullptr){
        Node* temp = root;
        while(temp->right != nullptr)
            temp = temp->right;
        return temp->data;
    } else return 0;
}

int Tree::find_min() {
    if(root!= nullptr){
        Node* temp = root;
        while(temp->left != nullptr)
            temp = temp->left;
        return temp->data;
    } else return 0;
}

int Tree::sum_max_min() {
    int sum = find_max() + find_min();
    return sum;
}
int sum = 0;
int Tree::sum_all(Node* temp) {
    if(temp == nullptr) return 0;
    sum += temp->data;
    sum_all(temp->left);
    sum_all(temp->right);
    return sum;
}

int even = 0;
int odd = 0;

void Tree::even_odd(Node* temp) {
    if(temp == nullptr)
        return;
    else if(temp->data % 2 == 0){
        even++;
        cout<<"Even : "<<temp->data<<" ";
    }

    else{
        odd++;
        cout<<"Odd : "<<temp->data<<" ";
    }

    even_odd(temp->left);
    even_odd(temp->right);
}

int externals = 0;

void Tree::external(Node* temp) {
    if(temp == nullptr)return;
    else if(temp->left == nullptr && temp->right == nullptr){
        cout<<temp->data<<" ";
        externals++;
    }

    external(temp->left);
    external(temp->right);
}
int internals = 0;
void Tree::internal(Node* temp) {
    if(temp == nullptr)return;
    if(temp->left != nullptr || temp->right != nullptr) {
        cout << temp->data << " ";
        internals++;
    }
    internal(temp->right);
    internal(temp->left);
}

void Tree::display(Node* temp) {
    if(temp == nullptr)return;
    cout<<temp->data<<" ";
    display(temp->left);
    display(temp->right);
}

void Tree::print(Node *temp, int space){
    if (temp == nullptr)
        return;
    space += COUNT;
    print(temp->right, space);
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout << temp->data << "\n";
    print(temp->left, space);
}


int main() {
    Tree t;
    t.insert(10);
    t.insert(20);
    t.insert(15);
    t.insert(5);
    t.insert(3);
    cout<<"Internals : ";
    t.internal(root);
    cout<<"Number of internals : "<<internals<<" ";
    cout<<"\nDraw of BST:"<<endl;
    t.print(root,0);
    cout<<"Max + Min = " <<t.sum_max_min()<<endl;
    cout<<"Sum = " <<t.sum_all(root)<<endl;
    cout<<"Even or Odd: "<<endl;
    t.even_odd(root);
    cout<<"\nNumber of Evens : "<<even<<"   Number of Odds: "<<odd<<endl;
    cout<<"Externals : ";
    t.external(root);
    cout<<"Number of externals : "<<externals<<endl;
    cout<<"Elements of BST : ";
    t.display(root);
    return 0;
}
