#include <iostream>
using namespace std;

const char* findDirectManager(const char* employee, const char* leaders[][2], size_t n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(leaders[i][0], employee) == 0) {
			return leaders[i][1];
		}
	}
	return "";
}

bool is_subordinate_help(const char* employee,
	const char* manager,
	const char* leaders[][2],
	size_t n,
	int iter) {

	if (strcmp(employee, manager) == 0 && iter != 0) {
		return true;
	}

	if ((strcmp(employee, manager) == 0 && iter == 0) ||
		strcmp (findDirectManager(employee, leaders, n), "") == 0) {
		return false;
	}

	return is_subordinate_help(findDirectManager(employee, leaders, n),
		manager,
		leaders,
		n,
		iter + 1);
}

bool is_subordinate(const char* employee,
	const char* manager,
	const char* leaders[][2],
	size_t n) {

	return is_subordinate_help(employee, manager, leaders, n, 0);
}

const char* the_big_boss(const char* leaders[][2], size_t n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(findDirectManager(leaders[i][1], leaders, n), "") == 0) {
			return  leaders[i][1];
		}
	}
}

int main() {

	const char* leaders[][2] = {
		{"Ivan Iv.", "Mariya"},
		{"Mariya", "Ivan Dr."},
		{"Ivan Dr.", "Stoyan"}
	};

	cout << is_subordinate("Ivan Iv.", "Mariya", leaders, 3) << endl; // true
	cout << is_subordinate("Ivan Iv.", "Ivan Dr.", leaders, 3) << endl; // true
	cout << is_subordinate("Ivan Iv.", "Stoyan", leaders, 3) << endl; // true

	cout << is_subordinate("Mariya", "Ivan Iv.", leaders, 3) << endl; // false
	cout << is_subordinate("Stoyan", "Mariya", leaders, 3) << endl; // false
	cout << is_subordinate("Mariya", "Mariya", leaders, 3) << endl; // false

	cout << "The big boss is: " << the_big_boss(leaders, 3);

	return 0;
}