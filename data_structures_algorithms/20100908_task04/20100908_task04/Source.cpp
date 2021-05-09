#include <iostream>
#include <string>
using namespace std;

struct Node
{
	char data;
	Node* next;
	Node* prev;
};

struct Stack
{
	Node* top;

	Stack() 
	{
		top = new Node();
		top->data = NULL;
		top->next = nullptr;
		top->prev = nullptr;
	}

	void push(char c)
	{
		Node* newNode = new Node();
		newNode->data = c;
		newNode->next = nullptr;
		newNode->prev = top;
		top->next = newNode;
		top = newNode;
	}

	char peek()
	{
		return top->data;
	}

	bool pop()
	{
		if (top->data == NULL)
		{
			return false;
		}
		char data = top->data;
		top = top->prev;
		delete top->next;
		top->next = nullptr;
		return true;
	}

	bool isEmpty()
	{
		return top->data == NULL;
	}
};

bool checkParentheses(string str)
{
	Stack stack;
	char c;
	bool isCorrectlyPopped = true;

	for (int i = 0; i < str.size(); i++)
	{
		c = str[i];
		if (c == '(')
		{
			stack.push(c);
		}
		if (c == ')')
		{
			isCorrectlyPopped = stack.pop();
			if (!isCorrectlyPopped) {
				return false;
			}
		}
	}

	return stack.isEmpty() && isCorrectlyPopped;
}

int main()
{
	Stack myStack;

	string str1("abc(abc(abc)");
	cout << checkParentheses(str1) << endl; // 0

	string str2("abc(abc(abc))");
	cout << checkParentheses(str2) << endl; // 1

	string str3("abc(abc(abc)))");
	cout << checkParentheses(str3) << endl; // 0

	string str4(")abc(abc(abc))");
	cout << checkParentheses(str4) << endl; // 0

	string str5(")(abc(abc(abc))");
	cout << checkParentheses(str5) << endl; // 0

	string str6("(");
	cout << checkParentheses(str6) << endl; // 0

	string str7("");
	cout << checkParentheses(str7) << endl; // 1

	string str8("()()()");
	cout << checkParentheses(str8) << endl; // 1

	return 0;
}