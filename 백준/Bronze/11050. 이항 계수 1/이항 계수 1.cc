#include <iostream>
using namespace std;

int Factorial(int x) {
	if (x == 0 || x == 1) return 1;
	else return Factorial(x - 1)* x;
}

int main() {

	int n = 0, k = 0;

	cin >> n >> k;

	int result = Factorial(n) / (Factorial(k) * Factorial(n - k));

	cout << result << endl;

	return 0;
}