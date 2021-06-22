#include <iostream>
using namespace std;

void print_reverse_word(char* word) {
	for (int i = strlen(word) - 1; i >= 0; --i) {
		cout << word[i];
	}

	cout << " ";
}

void print_backwards(const char* begin, const char* end) {

	int size = end - begin;
	char* word = new char[size];
	int iter = 0;

	while (end >= begin) {
		if (*end <= 32) {

			word[iter] = '\0';
			print_reverse_word(word);
			end--;
			print_backwards(begin, end);
			break;
		}

		if (end == begin) {
			word[iter] = *begin;
			word[iter + 1] = '\0';
			print_reverse_word(word);
			break;
		}

		word[iter] = *end;
		iter++;
		end--;
	}
}

void print_backwards(const char* string) {
	print_backwards(&string[0], &string[strlen(string) - 1]);
	cout << endl;
	print_backwards(string, string + strlen(string) - 1);
}

int main() {

	print_backwards("I\tneed a break!");

	return 0;
}