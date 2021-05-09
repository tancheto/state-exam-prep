#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data;
	vector<Node*> children;
};

bool member(Node* root, int x)
{
	if (root->data == x)
	{
		return true;
	}

	bool isFound = false;
	Node* cur;

	for (int i = 0; i < root->children.size(); i++)
	{
		cur = root->children[i];
		isFound = member(cur, x);
		if (isFound)
		{
			return true;
		}
	}
	return false;
}

void deleteTree(Node* root)
{
	for (int i = 0; i < root->children.size(); i++)
	{
		deleteTree(root->children[i]);
	}
	Node* oldRoot = root;
	delete oldRoot;
	root = new Node;
	root->data = NULL;
}

void filterOdd(Node* root)
{
	if (root->data % 2 == 1)
	{
		deleteTree(root);
	}
	for (int i = 0; i < root->children.size(); i++)
	{
		filterOdd(root->children[i]);
	}
}

void printTree(Node* root)
{
	if (root->data != NULL)
	{
		cout << root->data << " ";

		for (int i = 0; i < root->children.size(); i++)
		{
			printTree(root->children[i]);
		}
	}
}

int main()
{
	Node* root = new Node();
	Node* c1 = new Node();
	Node* c2 = new Node();
	Node* c3 = new Node();

	root->data = 5;
	c1->data = 1;
	c2->data = 2;
	c3->data = 3;

	vector<Node*> children;
	children.push_back(c1);
	children.push_back(c2);
	children.push_back(c3);

	root->children = children;

	cout << member(root, 5) << endl;
	cout << member(root, 3) << endl;
	cout << member(root, 8) << endl;

	printTree(root);
	cout << endl;
	filterOdd(root);
	printTree(root);

	cout << endl;

	Node* root2 = new Node();
	Node* c21 = new Node();
	Node* c22 = new Node();
	Node* c23 = new Node();

	root2->data = 8;
	c21->data = 2;
	c22->data = 3;
	c23->data = 5;

	vector<Node*> children2;
	children2.push_back(c21);
	children2.push_back(c22);
	children2.push_back(c23);

	root2->children = children2;

	printTree(root2);
	cout << endl;
	filterOdd(root2);
	printTree(root2);

	return 0;
}