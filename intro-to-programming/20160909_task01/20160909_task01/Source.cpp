#include <iostream>
using namespace std;

void getSymbols(const char* str) {
	int a, b;
	int distance = 0;
	int i = 0;
	int j;

	while (str[i] != '\0') {
		j = i + 1;
		while (str[j] != '\0') {
			if (str[i] == str[j] && (j - i > distance)) {
				distance = j - i;
				a = i;
				b = j;
			}
			j++;
		}
		i++;
	}

	cout << a << " " << b << endl;
}

int main() {

	getSymbols("this is just a simple example");

	return 0;
}