#include <iostream>
using namespace std;

int dp[1500001];
int T[1500001];
int P[1500001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = 0; i < N; i++) {
		if(i+T[i]<=N) dp[i + T[i]] = max(dp[i] + P[i], dp[i + T[i]]);
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << dp[N] << "\n";

	return 0;
}