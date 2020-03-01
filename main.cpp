#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

void printList(Node *temp) {
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void insertAtEnd(int value, Node *head, Node *tail) {
	Node *temp = new Node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

void insertAtStart(int value, Node *head, Node *tail) {
	Node *temp = new Node;
	temp->data = value;
	temp->next = NULL;
	if (head = NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else {
		temp->next = head;
		head = temp;
	}
	cout << head->data << endl;
}

void insertOnPosition(int pos, int value, Node *head) {
	Node *prev = new Node;
	Node *cur = new Node;
	Node *temp = new Node;
	temp->data = value;
	cur = head;
	for (int i = 0; i < pos; i++) {
		prev = cur;
		cur = cur->next;
	}

	prev->next = temp;
	temp->next = cur;
}

void deleteFirst(Node *head) {
	Node *temp = head;
	head = head->next;
	delete[] temp;
}

void deleteLast(Node *head, Node *tail) {
	Node *cur = new Node;
	Node *prev = new Node;
	cur = head;
	while (cur->next != NULL) {
		prev = cur;
		cur = cur->next;
	}
	tail = prev;
	tail->next = NULL;
	delete[] cur;
}

void deleteOnPos(int pos, Node *head) {
	Node *cur = new Node;
	Node *prev = new Node;
	cur = head;
	for (int i = 0; i < pos; i++) {
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	delete[] cur;
}

bool searchX(int x, Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		if (temp->data == x) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int main() 
{
	Node *head = new Node;
	Node *second = new Node;
	Node *third = new Node;

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	insertOnPosition(2, 9, head);
	//deleteLast(head, third);

	cout << "Numbers in linked list: ";
	printList(head);
	cout << endl;

	if (searchX(8, head)) {
		cout << "Number 8 was found." << endl;
	}
	else {
		cout << "Number 8 was not found." << endl;
	}
	

	cout << endl;
	delete[] head;
	delete[] second;
	delete[] third;
	system("pause");
	return 0;
}