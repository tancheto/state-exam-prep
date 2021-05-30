#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

const int sizeArr = 27;
size_t counter = 0;

double a1[sizeArr], a2[sizeArr], a3[sizeArr], a4[sizeArr], a5[sizeArr];

void printNums(int row, double *arr)
{
	if (arr[row] != 0) {
		cout << right << setw(8) << fixed << setprecision(4) << arr[row];
		counter++;
		return;
	}
	cout << "        ";
}

int main()
{
	double k;
	double A[sizeArr];

	for (int i = 0; i < sizeArr; i++)
	{
		k = (double)rand() / RAND_MAX;
		A[i] = k * 4.9;
	}

	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

	for (int i = 0; i < sizeArr; i++)
	{
		if (A[i] >= 0 && A[i] < 1)
		{
			a1[c1] = A[i];
			c1++;
		}
		else if (A[i] >= 1 && A[i] < 2)
		{
			a2[c2] = A[i];
			c2++;
		}
		else if (A[i] >= 2 && A[i] < 3)
		{
			a3[c3] = A[i];
			c3++;
		}
		else if (A[i] >= 3 && A[i] < 4)
		{
			a4[c4] = A[i];
			c4++;
		}
		else if (A[i] >= 4 && A[i] < 5)
		{
			a5[c5] = A[i];
			c5++;
		}
	}

	cout << left << setw(8) << "Pod 1" << setw(8) << "Pod 2" << setw(8) << "Pod 3" << setw(8) << "Pod 4" << setw(8) << "Pod 5" << endl;
	
	int row = 0;

	while (counter < 27)
	{
		printNums(row, a1);
		printNums(row, a2);
		printNums(row, a3);
		printNums(row, a4);
		printNums(row, a5);
		cout << endl;

		row++;
	}

	return 0;
}