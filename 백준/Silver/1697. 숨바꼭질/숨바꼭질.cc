#include <iostream>
#include <cstring>
using namespace std;

int N, K;

int main() {

	cin >> N >> K;

	int* dp = new int[K + 10];
	fill(dp, dp+K+10, 0);

	if (N>K) {
		cout << N - K << "\n";
		return 0;
	}

	// N 앞부분
	for (int i = 0; i <= N; i++) {
		dp[i] = N - i;
	}

	// N 뒷부분
	for (int i = N + 1; i <= K; i++) {
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else {
			dp[i] = min(dp[(i + 1) / 2] + 2, dp[i - 1] + 1);
		}
	}

	cout << dp[K] << "\n";

	delete[] dp;

	return 0;
}