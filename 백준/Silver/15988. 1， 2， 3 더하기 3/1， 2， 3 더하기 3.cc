#include <iostream>
#include <vector>
using namespace std;

long long calc(int n, vector<long long> &dp) {
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] % 1000000009 + dp[i - 2] % 1000000009 + dp[i - 3] % 1000000009;
	}

	return dp[n];
}

int main() {

	ios_base::sync_with_stdio(false);

	int T = 0, N = 0;

	cin >> T;

	while (T--) {
		cin >> N;

		vector<long long>dp(N + 1, 1);

		dp[2] = 2;

		if (N < 3) cout << dp[N] << "\n";
		else cout << calc(N, dp) % 1000000009 << "\n";
	}

	return 0;
}