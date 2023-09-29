#include <iostream>
using namespace std;

int main() {

	int n = 0;
	int result = 0;
	string input = "";

	cin >> n >> input;

	for (int i = 0; i < input.size(); i++) {
		result += input[i] - '0';
	}

	cout << result;

	return 0;
}