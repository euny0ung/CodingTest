#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000;
using namespace std;


int main() {

	int T = 0, K = 0, input = 0;
	int file[501];
	int dp[501][501] = { 0, };
	int sum[501] = { 0, };

	sum[0] = 0;

	cin >> T;

	while (T > 0) {
		T--;

		cin >> K;
	
		// 누적합
		for (int i = 1; i <= K; i++) {
			cin >> input;
			sum[i] = sum[i - 1] + input;
		}

		// 합치려는 범위
		for (int i = 1; i <= K; i++) {
			// 시작점
			for (int j = 1; j <= K-i; j++) {
				dp[j][j+i] = INF;
				// 나누는 지점
				for (int k = j; k < j+i; k++) {
					dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k + 1][j+i] + sum[j+i] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][K] << "\n";
	}
	


	return 0;
}