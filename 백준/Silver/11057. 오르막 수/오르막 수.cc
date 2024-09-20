#include <iostream>
#define MOD 10007
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	long long dp[1001][10] = {0,};

	cin >> N;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 0; i <=N; i++) {
		dp[i][0] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j]%MOD + dp[i][j - 1]%MOD)%MOD;
		}
	}

	long sum = 0;

	for (int i = 0; i < 10; i++) {
		sum = (sum+dp[N][i])%MOD;
	}

	cout << sum << "\n";

	return 0;
}