#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
	int num;
	Node* next;
	Node* nextK;

	Node(int num) {
		this->num = num;
		this->next = nullptr;
		this->nextK = nullptr;
	}
};

Node* readList(const char* path) {
	string line;
	ifstream file(path);

	if (file.is_open()) {
		getline(file, line);
	}
	else {
		return nullptr;
	}

	file.close();

	int i = 0;
	int count = 0;
	int arr[1024];
	int num;

	string curNum = "";

	for (int i = 0; i < line.size(); i++) {
		if (line[i] == ' ') {
			num = stoi(curNum);
			curNum = "";
			arr[count] = num;
			count++;
		}
		else
		{
			curNum += line[i];
		}
	}
	arr[count] = stoi(curNum);
	count++;

	Node* prev = nullptr;
	Node* prevK = nullptr;
	Node* head = nullptr;
	int j = 0;

	int sq = ceil(sqrt((double)count));

	while (j != count) {
		Node* newNode = new Node(arr[j]);
		if (prev == nullptr) {
			head = newNode;
		}
		else {
			prev->next = newNode;
		}
		prev = newNode;

		if (j % sq == 0) {
			if (prevK != nullptr) {
				prevK->nextK = newNode;
			}
			prevK = newNode;
		}
		j++;
	}

	return head;
}

bool member(Node* head, int num) {
	Node* cur = head;
	bool skip = true;
	Node* prevK = nullptr;

	while (cur != nullptr) {
		if (cur->num == num) {
			return true;
		}
		else if (cur->num < num && skip) {
			prevK = cur;
			cur = cur->nextK;
		}
		else if (cur->num > num && skip) {
			cur = prevK;
			skip = false;
		}
		else if (cur->num < num && !skip) {
			cur = cur->next;
		}
		else if (cur->num > num && !skip) {
			return false;
		}
	}

	// if gone outside the borders by skipping
	if (cur == nullptr && skip) {
		cur = prevK;
		while (cur != nullptr) {
			if (cur->num == num) {
				return true;
			}
			cur = cur->next;
		}
	}

	return false;
}

int main() {
	Node* head = readList("read_file.txt");

	cout << member(head, 1) << endl;// true
	cout << member(head, 2)<< endl;// true
	cout << member(head, 3) << endl;// true
	cout << member(head, 4) << endl;// true
	cout << member(head, 5) << endl;// false
	cout << member(head, 6) << endl;// true
	cout << member(head, 7) << endl;// true
	cout << member(head, 8) << endl;// true
	cout << member(head, 9) << endl;// false
	cout << member(head, 10) << endl;// true

	return 0;
}

