#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Node {
	int value;
	char label;
	vector<Node*> children;
};

void findBranches(Node* node, int sum, string word, vector<pair<int, string>>& res) {

	if (node->children.size() == 0) {
		res.push_back({ sum, word });
		return;
	}

	for (int i = 0; i < node->children.size(); i++) {
		Node* child = node->children[i];
		findBranches(child, sum + child->value, word + child->label, res);
	}
}

void commonBranches(Node* root, Node* u, Node* v, int k) {
	vector<pair<int, string>> uBranches, vBranches;
	findBranches(u, 0, "", uBranches);
	findBranches(v, 0, "", vBranches);

	for (int x = 0; x < uBranches.size(); x++) {
		for (int y = 0; y < vBranches.size(); y++) {
			if (uBranches[x].first + vBranches[y].first == k &&
				uBranches[x].second == vBranches[y].second) {
				cout << uBranches[x].second << endl;
			}
		}
	}
}

int main() {

	Node* root = new Node;
	root->value = -1;
	root->label = ' ';

	Node* n1 = new Node;
	n1->value = 1;
	n1->label = 'a';
	Node* n2 = new Node;
	n2->value = 2;
	n2->label = 'a';

	Node* nn1 = new Node;
	nn1->value = 2;
	nn1->label = 'b';
	Node* nn2 = new Node;
	nn2->value = 1;
	nn2->label = 'b';

	Node* nnn1 = new Node;
	nnn1->value = 3;
	nnn1->label = 'c';
	Node* nnn2 = new Node;
	nnn2->value = 3;
	nnn2->label = 'c';

	nn1->children.push_back(nnn1);
	nn2->children.push_back(nnn2);

	n1->children.push_back(nn1);
	n2->children.push_back(nn2);

	root->children.push_back(n1);
	root->children.push_back(n2);

	commonBranches(root, n1, n2, 9);

	return 0;
}