#include <iostream>
using namespace std;

int main() {

	bool arr[30] = { false };
	int input = 0;

	for (int i = 0; i < 28; i++) {
		cin >> input;
		arr[input - 1] = true;
	}

	for (int i = 0; i < 30; i++) {
		if (!arr[i]) cout << i + 1 << endl;
	}

	return 0;
}