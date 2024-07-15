#include <iostream>
#include <string>
using namespace std;

int countZero(int n) {
	int cnt = 0;

	for (int i = 5; n / i>=1; i *= 5) {
		cnt += n / i;
	}
	return cnt;
}

int main() {

	int N = 0;

	cin >> N;

	cout << countZero(N) << "\n";

	return 0;
}