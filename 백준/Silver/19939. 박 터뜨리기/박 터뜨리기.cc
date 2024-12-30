#include <iostream>
using namespace std;

int main() {

	int N = 0, K = 0, sum=0;

	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		sum += i;
	}

	if (sum > N) cout << -1 << "\n";
	else {
		if ((N - sum) % K == 0) cout << K - 1 << "\n";
		else cout << K << "\n";
	}

	return 0;
}