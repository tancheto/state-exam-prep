#include <iostream>
using namespace std;

float findAverage(int i, int j, float img[][10], size_t M, size_t N) {

	float counter = 0;
	float sum = 0;

	for (int a = i * 2; a <= i * 2 + 1 && a < M; a++) {
		for (int b = j * 2; b <= j * 2 + 1 && b < N; b++) {
			sum += img[a][b];
			counter++;
		}
	}

	return (float) sum / counter;
}

void subsample(size_t M, size_t N, float img[][10]) {

	int newM = (M + 1) / 2;
	int newN = (N + 1) / 2;

	for (int i = 0; i < newM; i++) {
		for (int j = 0; j < newN; j++) {
			cout << findAverage(i, j, img, M, N) << " ";
		}
		cout << endl;
	}
}

int main() {

	float img[2][10] = {
		{1.0, 2.0, 3.0},
		{4.5, 6.5, 7.5}
	};

	subsample(2, 3, img);

	return 0;
}