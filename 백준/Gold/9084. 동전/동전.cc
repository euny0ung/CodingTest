#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;

	cin >> T;

	while (T--) {

		int N = 0, coin = 0, M = 0;
		int coins[20] = { 0, };

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> coins[i];
		}

		cin >> M;

		vector<long long>dp(M+1, 0);
		dp[0] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = coins[i]; j <= M; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}
		cout << dp[M] << "\n";
	}

	return 0;
}