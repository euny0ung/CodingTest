#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N = 0;

	cin >> N;

	vector<long long>dp(N, 0);

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N - 1] << "\n";

	return 0;
}