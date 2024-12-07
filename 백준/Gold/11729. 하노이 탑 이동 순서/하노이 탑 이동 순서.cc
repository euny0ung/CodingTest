#include <iostream>
using namespace std;


void hanoi(int N, int from, int temp, int to) {
	if (N == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	hanoi(N - 1, from, to, temp);
	cout << from << " " << to << "\n";
	hanoi(N - 1, temp, from, to);
}

int main() {

	int N = 0, K = 1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		K *= 2;
	}

	cout << K-1 << "\n";

	hanoi(N, 1, 2, 3);

	return 0;
}