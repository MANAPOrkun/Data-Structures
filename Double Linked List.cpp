#include<iostream>
using namespace std;
	
struct Node
{
	int data;
	Node* next;
	Node* prev;
};

class DList
{
public:
	Node* head;
	DList()
	{
		head = NULL;
	}
	Node* CreateNode(int val);
	bool IsEmpty();// check if DList is empty
	void InsertLast(int);// inserts at last position from DList
	void InsertFirst(int);// inserts at first position from DList
	void InsertAtIndex(int, int);//insert data at a specific position from DList
	void RemoveLast(); // removes last element from DList
	void RemoveFirst(); // remove first element from DList
	void RemoveAtIndex(int);// remove at some position
	void Display(); // show all data in DList
	void DisplayReverse();
	int CountItems();// count the number of elements in DList
	void Find(int);// search for an element in the DList
	void ChangeList();
	void FindSum();
	int CheckDuplicate(int);
	void Square();
	void CountEvenAndOdd();
};

Node* DList::CreateNode(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

bool DList::IsEmpty() {
	return head == NULL;
}

void DList::InsertLast(int val) {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		Node* newNode = CreateNode(val);
		temp->next = newNode;
		newNode->prev = temp;
	}
	else {
		head->data = val;
	}
}

void DList::InsertFirst(int val) {
	if (!IsEmpty()) {
		Node* temp = head;
		Node* newNode = CreateNode(val);
		temp->prev = newNode;
		newNode->next = temp;
		head = newNode;
	}
	else {
		head = CreateNode(val);
	}
}

void DList::InsertAtIndex(int val, int index) {
	if (!IsEmpty()) {
		Node* temp = head;
		Node* newNode = CreateNode(val);
		for (int i = 0; i < index - 1; i++) {
			if (temp->next != NULL) {
				temp = temp->next;
			}
		}
		if (temp->next == NULL) {
			temp->next = newNode;
			newNode->prev = temp;
		}
		else {
			temp->next->prev = newNode;
			newNode->next = temp->next;
			temp->next = newNode;
			newNode->prev = temp;
		}
		
		

	}
	else
		cout << "Double Linked List is empty.";

}

void DList::RemoveLast() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->prev = NULL;
		temp->next = NULL;
		//delete temp;
	}
	else {
		cout << "Double List is empty.";
	}
}

void DList::RemoveFirst() {
	if (!IsEmpty()) {
		Node* temp = head;
		head = temp->next;
		temp->next = NULL;
		head->prev = NULL;
		//delete temp;
	}
	else {
		cout << "Double List is empty.";
	}
}

void DList::RemoveAtIndex(int index) {
	if (!IsEmpty()) {
		Node* temp = head;
		if (head->next == NULL) {
			head = NULL;
		}
		else {
			for (int i = 0; i < index; i++) {
				if (temp != NULL)
					temp = temp->next;
				else {
					cout << "Given index already empty.";
					break;
				}
			}
			if (temp == head) {
				temp->next->prev = NULL;
				head = temp->next;
				delete(temp);
			}
			else if (temp->next != NULL) {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			else {
				temp->prev->next = NULL;
				temp->prev = NULL;
			}
			//delete(temp);
		}
	}
	else
		cout << "List is empty";
}

void DList::Display() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	else {
		cout << "Double List is empty.";
	}
}

void DList::DisplayReverse() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
	}
	else {
		cout << "Double List is empty.";
	}
}

int DList::CountItems() {
	if (!IsEmpty()) {
		Node* temp = head;
		int count = 0;
		while (temp != NULL) {
			temp = temp->next;
			count += 1;
		}
		return count;
	}
	else {
		return 0;
	}
}

void DList::Find(int val) {
	if (!IsEmpty()) {
		Node* temp = head;
		int count = 0;
		while (temp->next != NULL) {
			if (temp->data == val) {
				count += 1;
			}
			temp = temp->next;
		}
		if (count != 0) {
			cout <<val<< " is found.\n";
		}
		else
			cout<<val<< " not found.\n";
	}
	else {
		cout << "List is empty";
	}
}

void DList::ChangeList() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		if (temp->data < head->data) {
			head->prev = temp->prev;
			temp->prev = NULL;
			head->prev->next = head;
			head->next->prev = temp;
			temp->next = head->next;
			head->next = NULL;
			head = temp;
		}


	}
	else {
		cout << "Item does not exist.";
	}
}

void DList::FindSum() {
	if (!IsEmpty()) {
		Node* temp = head;
		int sum = 0;
		while (temp != NULL) {
			sum += temp->data;
			temp = temp->next;
		}
		cout << "Sum : " << sum << endl;
	}
	else {
		cout << "List is empty.";
	}
}

int DList::CheckDuplicate(int val) {
	if (!IsEmpty()) {
		Node* temp = head;
		int count = 0;
		while (temp != NULL) {
			if (temp->data == val)
				count += 1;
			temp = temp->next;
		}
		return count;
	}
	else {
		return 0;
	}
}

void DList::Square() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp != NULL) {
			temp->data = temp->data * temp->data;
			temp = temp->next;
		}
	}
	else {
		cout << "List is empty." << endl;
	}
}

void DList::CountEvenAndOdd() {
	if (!IsEmpty()) {
		Node* temp = head;
		int odd = 0;
		int even = 0;
		while (temp != NULL) {
			if (temp->data % 2 == 0)
				even += 1;
			else
				odd += 1;
			temp = temp->next;
		}
		cout << "Odd : " << odd << endl << "Even : " << even << endl;
	}
	else {
		cout << "List is empty.";
	}
}

int main() {
	DList d;
	d.InsertFirst(1);
	d.InsertFirst(2);
	d.InsertLast(3);
	d.InsertAtIndex(4, 4);
	d.Display();
	cout << "\nReverse order: ";
	d.DisplayReverse();
	
	cout<<"\nNumber of items : "<< d.CountItems()<<endl;
	d.CountEvenAndOdd();
	cout << "Searching element:";
	d.Find(1);
	d.FindSum();
	d.InsertLast(0);
	cout << "0 Inserted last."<<endl;
	d.Display();
	d.ChangeList();
	cout <<endl<< "List changed: ";
	d.Display();
	d.InsertLast(1);
	cout << "\n1 Inserted last." << endl;
	cout<<"Duplicated elements checked : "<<d.CheckDuplicate(1);
	d.Square();
	cout << "\nList is squared : ";
	d.Display();
	d.RemoveLast();
	cout << "\nRemoved last: ";
	d.Display();
	d.RemoveFirst();
	cout << "\nRemoved first: ";
	d.Display();
	d.RemoveAtIndex(0);
	cout << "\nRemoved at index: ";
	d.Display();
	getchar();

}