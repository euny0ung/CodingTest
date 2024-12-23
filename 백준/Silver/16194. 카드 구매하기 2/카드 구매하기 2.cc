#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;

	int *arr = new int[N+1]();
	int* dp = new int[N+1]();

	fill(dp, dp + N + 1, 1e9);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + arr[j]);
		}
	}

	cout << dp[N] << "\n";

	delete []arr;
	delete []dp;

	return 0;
}