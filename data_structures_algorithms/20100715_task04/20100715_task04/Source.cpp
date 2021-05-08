#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;
};

void findNumbers(Node* node, int numSoFar, int prevVal)
{
	if (node == nullptr)
	{
		cout << prevVal << ":" << numSoFar + 1 << endl;
		return;
	}

	if (prevVal == NULL || node->val == prevVal)
	{
		return findNumbers(node->next, numSoFar + 1, node->val);
	}

	cout << prevVal << ":" << numSoFar + 1 << endl;
	return findNumbers(node->next, 0, node->val);
}

void printLinkedList(Node* n)
{
	Node* cur = n;
	while (cur != nullptr)
	{
		cout << cur->val << "->";
		cur = cur->next;
	}
	cout << "null" << endl;
}

void printLinkedListRecursive(Node* n)
{
	while (n != nullptr)
	{
		cout << n->val << "->";
		return printLinkedList(n->next);
	}
	cout << "null" << endl;
}

int main()
{

	Node* n1 = new Node();
	Node* n2 = new Node();
	Node* n3 = new Node();
	Node* n4 = new Node();
	Node* n5 = new Node();
	Node* n6 = new Node();
	Node* n7 = new Node();

	n1->val = 5;
	n2->val = 5;
	n3->val = 10;
	n4->val = 7;
	n5->val = 5;
	n6->val = 10;
	n7->val = 69;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = nullptr;

	findNumbers(n1, 0, NULL);

	printLinkedList(n1);
	printLinkedListRecursive(n1);

	return 0;
}