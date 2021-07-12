#include<iostream>
using namespace std;

char res[100][100];

bool neighbours(char arr[100][100], int m, int n, int i, int j) {
	int count = 0;

	for (int di = -1; di <= 1; di++) {
		for (int dj = -1; dj <= 1; dj++) {
			if (di == 0 && dj == 0) continue;
			if (di + i < 0 || di + i >= m || dj + j < 0 || dj + j >= n) continue;

			if (arr[di + i][dj + j] == '4') {
				count++;
			}
		}
	}
	return count >= 3;
}

void findAfterTenYears(char arr[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'R' || arr[i][j] == 'S')
				res[i][j] = arr[i][j];
			else if (arr[i][j] == '1' || arr[i][j] == '2' || arr[i][j] == '3')
				res[i][j] = arr[i][j] + 1;
			else if (arr[i][j] == '4' && neighbours(arr, m, n, i, j))
				res[i][j] = '3';
			else
				res[i][j] = '4';
		}
	}

	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			arr[a][b] = res[a][b];
		}
	}
}

void findAfterHundredYears(char arr[100][100], int m, int n) {
	for (int i = 0; i < 10; i++) {
		findAfterTenYears(arr, m, n);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 6; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------" << endl;
	}
}

int main() {

	char arr[100][100] = {
		{'R', 'R', '1', '1', '2', '2'},
		{'1', 'R', 'R', 'R', '1', '2'},
		{'S', '1', 'R', 'R', '2', '3'},
		{'4', '4', 'S', 'S', 'R', 'R'}
	};

	findAfterHundredYears(arr, 4, 6);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}