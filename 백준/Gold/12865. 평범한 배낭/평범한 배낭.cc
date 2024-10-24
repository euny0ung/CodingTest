#include <iostream>
#include <algorithm>
using namespace std;


int dp[101][100001] = {0,};
int W[101] = { 0, };
int V[101] = { 0, };

int main() {

	int N = 0, K = 0;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	// i는 입력의 인덱스, j는 수용 가능 무게 제한
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			// 수용 불가능일 경우 이전과 똑같은 값
			if (W[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			// 수용 가능한 경우
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}