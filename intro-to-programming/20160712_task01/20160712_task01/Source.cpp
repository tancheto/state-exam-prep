#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> findCoord(int x, int y) {
	vector <pair<int, int>> res;

	if (x == y || 10 - x == y) {
		res.push_back({ x, y });
		res.push_back({ 10 - x, 10 - y });
	}
	else {
		res.push_back({ x, y });
		res.push_back({ y, x });
		res.push_back({ 10 - x, 10 - y });
		res.push_back({ 10 - y, 10 - x });
	}

	return res;
}

double** changeMatrix(const double arr[11][11]) {
	double** newMatrix = new double* [11];
	for (int i = 0; i < 11; i++) {
		newMatrix[i] = new double[11];
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			newMatrix[i][j] = arr[i][j];
		}
	}

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y <= 10 - x; y++) {
			vector<pair<int, int>> coord = findCoord(x, y);

			double avg = 0;

			for (int a = 0; a < coord.size(); a++) {
				avg += arr[coord[a].first][coord[a].second];
			}

			avg = avg / coord.size();

			for (int a = 0; a < coord.size(); a++) {
				newMatrix[coord[a].first][coord[a].second] = avg;
			}
		}
	}

	return newMatrix;
}

int main() {

	double arr[11][11] = {
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11},
		{1,2,3,4,5,6,7,8,9,10,11}
	};

	double** newMatrix = changeMatrix(arr);

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << newMatrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}