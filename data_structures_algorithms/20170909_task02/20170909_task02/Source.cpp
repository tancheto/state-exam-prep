#include <iostream>
using namespace std;

struct Node {
	int n;
	Node* next;
	Node* nextChild;

	Node(int n) {
		this->n = n;
		this->next = nullptr;
		this->nextChild = nullptr;
	}
};

Node* res = nullptr;

void addToRes(Node* head) {
	Node* newRes = nullptr;
	Node* newCur = nullptr;

	while (head != nullptr && res != nullptr) {
		if (head->n < res->n) {
			Node* newNode = new Node(head->n);
			head = head->nextChild;
			if (newRes == nullptr) {
				newRes = newNode;
				newCur = newRes;
			}
			else {
				newCur->next = newNode;
				newCur = newCur->next;
			}
		}
		else {
			Node* newNode = new Node(res->n);
			res = res->next;
			if (newRes == nullptr) {
				newRes = newNode;
				newCur = newRes;
			}
			else {
				newCur->next = newNode;
				newCur = newCur->next;
			}
		}
	}

	if (head == nullptr) {
		while (res != nullptr) {
			Node* newNode = new Node(res->n);
			if (newRes == nullptr) {
				newRes = newNode;
				newCur = newRes;
			}
			else {
				newCur->next = newNode;
				newCur = newCur->next;
			}
			res = res->next;
		}
	}

	if (res == nullptr) {
		while (head != nullptr) {
			Node* newNode = new Node(head->n);
			if (newRes == nullptr) {
				newRes = newNode;
				newCur = newRes;
			}
			else {
				newCur->next = newNode;
				newCur = newCur->next;
			}
			head = head->nextChild;
		}
	}

	res = newRes;
}

bool isChildSorted(Node* head) {
	if (head == nullptr || head->nextChild == nullptr) return true;

	if (head->n > head->nextChild->n) return false;

	return isChildSorted(head->nextChild);
}

Node* mergeSorted(Node* head) {
	if (head == nullptr) {
		return res;
	}

	if (isChildSorted(head)) {
		addToRes(head);
	}

	mergeSorted(head->next);
}

int main() {

	Node* first = new Node(1);
	first->nextChild = new Node(2);
	first->nextChild->nextChild = new Node(6);
	
	Node* second = new Node(5);
	first->next = second;
	second->nextChild = new Node(4);
	second->nextChild->nextChild = new Node(2);

	Node* third = new Node(3);
	second->next = third;
	third->nextChild = new Node(2);
	third->nextChild->nextChild = new Node(7);

	Node* fourth = new Node(5);
	third->next = fourth;
	fourth->nextChild = new Node(8);
	fourth->nextChild->nextChild = new Node(9);

	Node* cur = mergeSorted(first);

	while (cur != nullptr) {
		cout << cur->n << " ";
		cur = cur->next;
	}

	return 0;
}