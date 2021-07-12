#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Node {
	int n;
	vector<Node*> children;

	Node(int n) {
		this->n = n;
		this->children = {};
	}
};

Node* buildTree(int K, int* A, size_t size) {
	if (size <= 0) return nullptr;

	Node* root = new Node(A[0]);
	queue<Node*> q;
	int index = 0;

	q.push(root);

	while (!q.empty() && index < size) {
		Node* cur = q.front();
		q.pop();
		for (int i = 0; i < K; i++) {
			index++;
			if (index >= size) break;

			Node* child = new Node(A[index]);
			cur->children.push_back(child);
			q.push(child);
		}
	}

	int nodes = 0, depth = 0;

	while (nodes <= size) {
		nodes += pow(K, depth);
		depth++;
	}

	cout << depth;

	return root;
}

void printTree(Node* root) {
	cout << root->n << " number of children:" << root->children.size() << endl;
	for (int i = 0; i < root->children.size(); i++) {
		printTree(root->children[i]);
	}
}

int main() {

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	Node* root = buildTree(3, arr, 10);

	cout << endl;

	printTree(root);

	return 0;
}