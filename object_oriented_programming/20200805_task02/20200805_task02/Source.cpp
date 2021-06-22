#include<iostream>
using namespace std;

class Interval {
protected:
	int a;
	int k;
	int current;

public:
	Interval(int a, int k) {
		this->a = a;
		this->k = k;
		reset();
	}

	Interval() {
		this->a = -1;
		this->k = -1;
		reset();
	}

	int operator * () {
		return current;
	}

	//prefix
	Interval& operator ++() {
		if (!last()) current++;

		return *this;
	}

	//postfix
	Interval operator ++(int a) {
		if (!last()) current++;

		return *this;
	}

	void reset() {
		current = a;
	}

	bool last() {
		return current == a + k;
	}
};

class SquaredInterval : public Interval{
public:

	SquaredInterval() : Interval() {}

	SquaredInterval(int a, int k) : Interval(a,k) {}

	int operator * ()
	{
		return current * current;
	}

	int upperLimit() {
		return (a + k) * (a + k);
	}

	bool operator > (SquaredInterval other) {
		return upperLimit() > other.upperLimit();
	}
};

void sortIntervals(SquaredInterval* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {

			SquaredInterval temp;

			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {

	Interval i(0, 10);

	cout << *i << endl;

	do {
		++i;
		//i++;
		cout << *i << endl;
	} while (!i.last());

	SquaredInterval si(0, 10);

	cout << *si << endl;

	do {
		++si;
		//i++;
		cout << *si << endl;
	} while (!si.last());

	cout << endl;

	SquaredInterval si1(0, 4);
	SquaredInterval si2(0, 5);
	SquaredInterval si3(0, 6);
	SquaredInterval si4(0, 7);
	SquaredInterval si5(0, 8);

	SquaredInterval arr[6];
	arr[0] = si;
	arr[1] = si5;
	arr[2] = si4;
	arr[3] = si3;
	arr[4] = si2;
	arr[5] = si1;

	sortIntervals(arr, 6);

	for (int i = 0; i < 6; i++) {
		cout << arr[i].upperLimit() << " ";
	}

	return 0;
}