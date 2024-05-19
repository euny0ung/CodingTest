#include <iostream>
#include <cmath>
using namespace std;

int main() {

	long long n = 0;
	long long result = 0;

	cin >> n;

	long long start = 0, end = n;

	while (start <= end) {
		long long middle = (start + end) / 2;

		if (pow(middle, 2) < n) start = middle + 1;
		else { 
			result = middle;
			end = middle - 1; 
		}
	}

	cout << result << endl;

	return 0;
}