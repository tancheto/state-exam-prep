#include <iostream>
using namespace std;

char* reverseArr(char *arr, size_t n) {
	
	for (int i = 0; i < n / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;
	}

	return arr;
}

char* toCharArr(int a) {
	char* arr = new char[10];
	int i = 0;

	if (a == 0) {
		arr[0] = '0';
		arr[1] = '\0';
		return arr;
	}

	while (a > 0) {
		arr[i] = (a % 10) + '0';
		i++;
		a /= 10;
	}

	arr[i] = '\0';
	return reverseArr(arr, i);
}

bool isLessLex(int a, int b) {
	char* aCh = toCharArr(a);
	char* bCh = toCharArr(b);
	int i = 0;

	while (aCh[i] != '\0' && bCh[i] != '\0') {
		if (aCh[i] == bCh[i]) {
			i++;
			continue;
		}
		else if (aCh[i] < bCh[i]) return true;
		else return false;
	}

	if (aCh[i] == '\0') return true;

	return false;
}

void sortLex(int n, int* a) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (isLessLex(a[j], a[i])) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main() {

	int a[6] = { 13, 14, 7, 2018, 9, 0 };

	sortLex(6, a);

	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}

	return 0;
}