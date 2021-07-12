#include <iostream>
using namespace std;

char arr[100][100];
bool flag[100][100];
int curBest;
int best = 0;

void initFlag(int m, int n) {
	curBest = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			flag[i][j] = false;
		}
	}
}

void dfs(char arr[100][100], int i, int j, int m, int n) {

	if (i < 0 || i >= m || j < 0 || j >= n) return;

	if (arr[i][j] == '4' && !flag[i][j]) {
		curBest++;
		flag[i][j] = true;
		dfs(arr, i - 1, j, m, n);
		dfs(arr, i + 1, j, m, n);
		dfs(arr, i, j - 1, m, n);
		dfs(arr, i, j + 1, m, n);
	}
}

int biggestArea(char arr[100][100], int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '4') {
				initFlag(m, n);
				dfs(arr, i, j, m, n);
				if (best < curBest) best = curBest;
			}
		}
	}

	return best;
}

int main() {

	char arr[100][100] = {
		{'R', 'R', '1', '1', '2', '2'},
		{'1', 'R', 'R', 'R', '1', '2'},
		{'S', '1', 'R', 'R', '2', '3'},
		{'4', '4', 'S', 'S', 'R', 'R'}
	};

	char arr1[100][100] = {
		{'R', 'R', '1', '1', '4', '4'},
		{'1', 'R', 'R', 'R', '1', '4'},
		{'S', '4', 'R', 'R', '2', '4'},
		{'4', '4', '4', 'S', 'R', '4'}
	};

	char arr2[100][100] = {
	{'4', 'R', '1', '1', '4', '4'},
	{'4', 'R', 'R', 'R', '1', '4'},
	{'4', '4', 'R', 'R', '2', 'R'},
	{'4', '4', '4', 'S', 'R', '4'}
	};

	cout << biggestArea(arr, 4, 6) << endl; // expected: 2
	cout << biggestArea(arr1, 4, 6) << endl; // expected: 5
	cout << biggestArea(arr2, 4, 6) << endl; // expected: 7

	return 0;
}