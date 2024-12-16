#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;

	int arr[101][101] = { 0, };
	long long dp[101][101] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] > 0 && arr[i][j] > 0) {
				int jump = arr[i][j];

				// 오른쪽 이동
				int ny = j + jump;
				if (ny < N) dp[i][ny] += dp[i][j];

				// 아래 이동
				int nx = i + jump;
				if (nx < N) dp[nx][j] += dp[i][j];
			}
		}
	}

	cout << dp[N - 1][N - 1] << "\n";

	return 0;
}