#include <iostream>
using namespace std;

int main() {

	int N = 0, M = 0, K = 0;
	int dp[16][16] = { 0, };

	cin >> N >> M >> K;

	int k_row = (K == 0) ? 0 : (K - 1) / M;
	int k_col = (K == 0) ? 0 : (K - 1) % M;

	for (int i = 0; i < N; i++) dp[i][0] = 1;

	for (int j = 0; j < M; j++) dp[0][j] = 1;

	for (int i = 1; i <= k_row; i++) {
		for (int j = 1; j <=k_col; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	for (int i = k_row + 1; i < N; i++) dp[i][k_col] = dp[k_row][k_col];
	for (int j = k_col + 1; j < M; j++) dp[k_row][j] = dp[k_row][k_col];

	for (int i = k_row + 1; i < N; i++) {
		for (int j = k_col + 1; j < M; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	cout << dp[N-1][M-1] << "\n";

	return 0;
}