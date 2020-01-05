#include <iostream>
#define MAX 1000
using namespace std;


class Stack {
	
	int top;
	int a[MAX];
	bool IsEmpty();
	int count = 0;

public:
	

	Stack() {
		top = -1;
	}

	void push(int x);
	int pop();
	int peek();
	int DisplayCount();
	void ReverseOrder(Stack,Stack);
	
};

void Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << " Stack Overflow" << endl;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack\n" << endl;
	}
}

int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow" << endl;
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}

}

int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Emprty" << endl;
		return 0;
	}
	else {
		return a[top];
	}
}

bool Stack::IsEmpty() {
	return top == -1;
}

int Stack::DisplayCount() {

	while (top > -1) {
		pop();
		count += 1;
	}
	
	return count;
}

void Stack::ReverseOrder(Stack s2,Stack s1) {
	while (s1.top > -1) {
		s2.push(s1.pop());
	}
	
}

int main()
{
	Stack s;
	Stack s2;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<s.DisplayCount()<<endl;

	s.ReverseOrder(s2,s);

	cout<<s2.DisplayCount()<<endl;

	


}

