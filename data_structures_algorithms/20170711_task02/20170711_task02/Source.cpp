#include <iostream>
using namespace std;

struct Node {
	int n;
	Node* next;
	Node(int n) {
		this->n = n;
		this->next = nullptr;
	}
};

void sort(int* arr, int count) {
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

Node* constructList(int* arr, int count) {
	Node* head = nullptr;
	Node* cur = head;

	for (int i = 0; i < count; i++) {
		if (head == nullptr) {
			head = new Node(arr[i]);
			cur = head;
			continue;
		}
		cur->next = new Node(arr[i]);
		cur = cur->next;
	}
	return head;
}

Node* sortLinkedList(Node* head) {
	int count = 0;
	Node* cur = head;

	while (cur != nullptr) {
		count++;
		cur = cur->next;
	}

	cur = head;
	int* arr = new int[count];

	for (int i = 0; i < count; i++) {
		arr[i] = cur->n;
		cur = cur->next;
	}

	sort(arr, count);
	Node* newHead = constructList(arr, count);

	delete[] arr;

	return newHead;
}

int main() {

	Node* n1 = new Node(1);
	Node* n2 = new Node(5);
	Node* n3 = new Node(2);
	Node* n4 = new Node(9);
	Node* n5 = new Node(6);
	Node* n6 = new Node(0);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	Node* cur = sortLinkedList(n1);

	while (cur != nullptr) {
		cout << cur->n << " ";
		cur = cur->next;
	}

	return 0;
}

