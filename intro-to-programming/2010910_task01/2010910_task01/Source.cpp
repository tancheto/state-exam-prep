#include <iostream>
using namespace std;

bool find(int value, int* arr, size_t size) {
	if (size == 0) return false;

	size_t mid = size / 2;

	if (value == arr[mid]) return true;

	if (value < arr[mid])
		return find(value, arr, mid);
	else
		return find(value, arr + mid + 1, mid);
}

template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil)
{
	ReturnType result = nil;

	for (size_t i = 0; i < size; ++i)
		result = op(arr[i], result);

	return result;
}

int op(char Digit, int Result)
{
	return (Result * 10) + (Digit - '0');
}

int str_to_int(const char* str)
{
	return (str == nullptr) ? 0 : fold_left(str, strlen(str), op, 0);
}

int main() {

	int* foo = {};
	cout << find(3, foo, 0);

	int bar[] = {1};
	cout << find(1, bar, 1);
	cout << find(2, bar, 1);

	int foobar[] = { 1 , 2 };
	cout << find(2, foobar, 2);
	cout << find(1, foobar, 2);

	int foobarfoo[] = { 1 , 2, 3 };
	cout << find(2, foobarfoo, 3);
	cout << find(1, foobarfoo, 3);
	cout << find(3, foobarfoo, 3);
	cout << find(0, foobarfoo, 3);

	cout << endl;

	cout << str_to_int("8954102");

	return 0;
}