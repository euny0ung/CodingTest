#include <iostream>
using namespace std;

int main() {

	int year = 0;
	int e = 0, s=0, m = 0;
	int re_1 = 0, re_2 = 0, re_3 = 0;

	cin >> re_1 >> re_2 >> re_3;

	while (1) {

		if (e == re_1 && s == re_2 && m == re_3) break;

		year++;
		e++;
		s++;
		m++;

		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
	}


	cout << year << endl;

	return 0;
}