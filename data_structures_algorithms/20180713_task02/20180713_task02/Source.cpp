#include <iostream>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

struct Node {
	char ch;
	Node* one;
	Node* two;
	Node* three;

	Node(char ch) {
		this->ch = ch;
		this->one = nullptr;
		this->two = nullptr;
		this->three = nullptr;
	}
};

string readLast(Node* root) {
	if (root == nullptr) return "";

	queue<Node*> q;
	q.push(root);
	string str = "";

	while (!q.empty()) {
		int size = q.size();
		str = "";

		for (int i = 0; i < size; i++) {
			Node* cur = q.front();
			q.pop();

			str += cur->ch;

			if (cur->one != nullptr) q.push(cur->one);
			if (cur->two != nullptr) q.push(cur->two);
			if (cur->three != nullptr) q.push(cur->three);
		}
	}

	return str;
}

string ser;

void helpSer(Node* root) {
	if (root == nullptr) {
		ser += '*';
		return;
	}

	ser += '(';
	ser += root->ch;
	ser += " ";

	helpSer(root->one); ser += " ";
	helpSer(root->two); ser += " ";
	helpSer(root->three);

	ser += ")";
}

void serialize(Node* root, const char* path) {
	ser = "";
	helpSer(root);

	//write to file
	ofstream file;
	file.open(path);

	if (file.is_open()) {
		file << ser;
		file.close();
	}
}

int main() {
	Node* root = new Node('b');
	Node* rootone = new Node('x');
	Node* roottwo = new Node('y');
	root->one = rootone;
	root->two = roottwo;

	Node* rootoneone = new Node('p');
	Node* rootonetwo = new Node('q');
	Node* rootonethree = new Node('r');
	rootone->one = rootoneone;
	rootone->two = rootonetwo;
	rootone->three = rootonethree;

	Node* roottwothree = new Node('s');
	roottwo->three = roottwothree;

	Node* rootonethreeone = new Node('c');
	Node* rootonethreethree = new Node('a');
	rootonethree->one = rootonethreeone;
	rootonethree->three = rootonethreethree;

	Node* roottwothreetwo = new Node('t');
	roottwothree->two = roottwothreetwo;

	cout << readLast(root);

	serialize(root, "serialize.txt");
}