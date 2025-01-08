#include <iostream>
#include <algorithm>
using namespace std;

int unitNum[101];
int studyTime[101];
int dp[101][10001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, T = 0;

	cin >> N >> T;

	for (int i = 1; i <= N; i++) {
		cin >> studyTime[i] >> unitNum[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			if (j >= studyTime[i]) {
				dp[i][j] = max(dp[i - 1][j], unitNum[i] + dp[i - 1][j-studyTime[i]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][T] << "\n";

	return 0;
}