#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct Node {
	char text;
	Node * left, * right;
};

void printText(Node * root) {

	queue<pair<Node*, int>> q;
	q.push({ root, 0 });

	Node* curNode = root;
	int curDepth = 0;
	int oldDepth = 0;

	while (!q.empty()) {

		oldDepth = curDepth;

		curNode = q.front().first;
		curDepth = q.front().second;
		q.pop();

		if (curDepth > oldDepth) {
			cout << "\n";
		}

		cout << curNode->text;

		if (curNode->text == ' ') {
			delete curNode;
			continue;
		}

		if (curNode->left != NULL) {
			q.push({ curNode->left , curDepth + 1});
		}
		else {
			Node* newNode = new Node;
			newNode->text = ' ';
			newNode->right = NULL;
			newNode->left = NULL;
			q.push({ newNode, curDepth + 1 });
		}

		if (curNode->right != NULL) {
			q.push({ curNode->right , curDepth + 1 });
		}
		else {
			Node* newNode = new Node;
			newNode->text = ' ';
			newNode->right = NULL;
			newNode->left = NULL;
			q.push({ newNode, curDepth + 1 });
		}
	}
}

int main() {

	Node* root = new Node;
	root->text = 'I';

	Node* l = new Node;
	l->text = 'a';
	Node* r = new Node;
	r->text = 'm';
	root->left = l;
	root->right = r;

	Node* ll = new Node;
	ll->text = 'c';
	Node* lr = new Node;
	lr->text = 'o';
	l->left = ll;
	l->right = lr;

	Node* rl = new Node;
	rl->text = 'o';
	Node* rr = new Node;
	rr->text = 'l';
	r->left = rl;
	r->right = rr;

	Node* llr = new Node;
	llr->text = '!';
	ll->right = llr;

	ll->left = NULL;
	lr->left = NULL;
	lr->right = NULL;
	rl->left = NULL;
	rl->right = NULL;
	rr->left = NULL;
	rr->right = NULL;
	llr->left = NULL;
	llr->right = NULL;

	printText(root);

	delete root, l, r, ll, lr, rl, rr, llr;

	return 0;
}