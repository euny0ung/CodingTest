#include <iostream>
#define INF 1e9
using namespace std;

int T, K, input;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	while (T--) {

		cin >> K;

		int dp[501][501];
		int sum[501] = { 0, };

		for (int i = 0; i < 501; i++) {
			for (int j = 0; j < 501; j++) {
				dp[i][j] = 0;
			}
		}

		for (int i = 1; i <= K; i++) {
			cin >> input;
			sum[i] = sum[i - 1] + input;
		}

		sum[0] = 0;

		// 범위크기
		for (int i = 1; i <= K; i++) {
			// 시작위치
			for (int j = 1; j <= K-i; j++) {
				dp[j][j + i] = INF;
				// 중간점
				for (int k = j; k < i + j; k++) {
					dp[j][j + i] = min(dp[j][j+i], dp[j][k] + dp[k + 1][j + i] + sum[i + j]-sum[j-1]);
				}
			}
		}

		cout << dp[1][K] << "\n";
	}

	return 0;
}