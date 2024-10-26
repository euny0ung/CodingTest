#include <iostream>
using namespace std;

int main() {

	int result[10] = { 0, };
	int input = 0;
	int standard = 100;
	int min = 1e9;
	int ans = 0;

	for (int i = 0; i < 10; i++) {
		cin >> input;
		if (i == 0) result[i] = input;
		else result[i] = result[i - 1] + input;
	}

	for (int i = 9; i >= 0; i--) {
		if (abs(standard - result[i]) < min) {
			min = abs(standard - result[i]);
			ans = result[i];
		}
	}

	cout << ans << "\n";

	return 0;
}