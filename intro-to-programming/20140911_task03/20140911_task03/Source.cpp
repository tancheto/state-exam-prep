#include <iostream>
using namespace std;

double findSmallest(double* arr, int N) {
	double smallest;

	if (N > 0) {
		smallest = arr[0];
	}

	for (int i = 1; i < N; i++) {
		if (arr[i] < smallest) {
			smallest = arr[i];
		}
	}

	return smallest;
}

double findBiggest(double* arr, int N) {
	double biggest;

	if (N > 0) {
		biggest = arr[0];
	}

	for (int i = 1; i < N; i++) {
		if (arr[i] > biggest) {
			biggest = arr[i];
		}
	}

	return biggest;
}

void square(int N, double* X, double* Y) {
	double x1 = findSmallest(X, N);
	double x2 = findBiggest(X, N);
	double y1 = findSmallest(Y, N);
	double y2 = findBiggest(Y, N);

	double side;
	double diff;
	double xCenter, yCenter;

	if (x2 - x1 > y2 - y1) {
		side = x2 - x1;

		xCenter = (x2 + x1) / 2;

		diff = (x2 - x1) - (y2 - y1);
		yCenter = (y2 + diff + y1) / 2;
	}
	else {
		side = y2 - y1;

		yCenter = (y2 + y1) / 2;

		diff = (y2 - y1) - (x2 - x1);
		xCenter = (x2 + diff + x1) / 2;
	}

	cout << "x=" << xCenter << " y=" << yCenter << " side=" << side;
}

int main() {

	double X[5] = {1,2,3,4,6};
	double Y[5] = {1,2,3,4,5};

	square(5, X, Y);

	return 0;
}