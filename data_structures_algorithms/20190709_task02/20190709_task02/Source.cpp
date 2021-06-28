#include<iostream>
#include<vector>
using namespace std;

struct Node {
	char c;
	int n;
	vector<Node*> children;
};

int acumSum;

void help(Node* u, Node* v, int branchSum) {
	if (u->children.size() == 0 && v->children.size() == 0) {
		acumSum += branchSum;
		return;
	}
	else if (u->children.size() > 0 &&
		v->children.size() > 0) {
		for (int i = 0; i < u->children.size(); i++) {
			for (int j = 0; j < v->children.size(); j++) {
				Node* curU = u->children[i];
				Node* curV = v->children[j];
				if (curU->c == curV->c) {
					help(curU, curV, curU->n + curV->n + branchSum);
				}
			}
		}
	}
}

int sumVal(Node* u, Node* v) {
	acumSum = 0;
	if (u != nullptr && v != nullptr && (u->c == v->c)) {
		help(u, v, u->n + v->n);
	}

	return acumSum;
}

int main() {
	Node* root = new Node;
	root->n = -1;
	root->c = ' ';

	Node* n1 = new Node;
	n1->n = 1;
	n1->c = 'a';
	Node* n2 = new Node;
	n2->n = 2;
	n2->c = 'a';

	Node* nn1 = new Node;
	nn1->n = 2;
	nn1->c = 'b';
	Node* nn2 = new Node;
	nn2->n = 1;
	nn2->c = 'b';

	Node* nnn1 = new Node;
	nnn1->n = 3;
	nnn1->c = 'c';
	Node* nnn2 = new Node;
	nnn2->n = 3;
	nnn2->c = 'c';

	nn1->children.push_back(nnn1);
	nn2->children.push_back(nnn2);

	n1->children.push_back(nn1);
	n2->children.push_back(nn2);

	root->children.push_back(n1);
	root->children.push_back(n2);

	cout << sumVal(n1, n2) << endl;
	cout << sumVal(nn1, nn2) << endl;
}