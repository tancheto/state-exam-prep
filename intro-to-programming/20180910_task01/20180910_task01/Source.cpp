#include <iostream>
using namespace std;

bool checkRow(const char* a[], int n) {
	for (int i = 1; i < n; i++) {
		if (strcmp(a[i - 1], a[i]) > 0) {
			return false;
		}
	}
	return true;
}

void letterCount(const char* a) {
	int i = 0;
	int count = 0;
	while (a[i] != '\0') {
		if (a[i] == ' ') {
			cout << count << " ";
			count = 0;
		}
		else {
			count++;
		}
		i++;
	}
	cout << count << " ";
}

void revealPassword(const char* a[20][30], int m, int n) {
	for (int i = 0; i < m; i++) {
		if (checkRow(a[i], n)) {
			int mid = (n % 2) ? (n / 2) : (n / 2 + 1);
			if (mid >= 0) {
				letterCount(a[i][mid]);
			}
		}
	}
}

int main() {

	const char* a[20][30] = {
		{"Algebra", "Analytical Geom", "Calculus"},
		{"Intro to Progr", "OO P", "DSA"},
		{"Databases", "Izkustven intelekt", "KARH"}
	};

	revealPassword(a, 3, 3);

	return 0;
}