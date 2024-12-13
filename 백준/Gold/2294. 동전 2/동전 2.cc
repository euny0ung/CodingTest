#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int main() {
	int N = 0, K = 0;
	int coins[100] = { 0, };
	int dp[10000] = { 0, };

	fill(dp, dp + 10000, INF);
	dp[0] = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}

	for (auto coin : coins) {
		for (int i = coin; i <= K; i++) {
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}

	if (dp[K] == INF) cout << "-1" << "\n";
	else cout << dp[K] << "\n";

	return 0;
}