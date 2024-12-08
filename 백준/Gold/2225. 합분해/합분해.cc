#include <iostream>
#define DIV 1000000000
using namespace std;

int dp[201][201] = { 0, };

int main() {

	// 0부터 N까지 정수 K개를 더해서 합이 N이 되는 경우의 수 구하기
	// 덧셈 순서가 다르면 다른거, 한개의 수를 여러번 쓸 수 있음
	// dp[i][j] = j를 i개의 수로 표현하는 경우의 수
	// dp[i][j] = dp[i-1][j-L], L은 0~j가 될 수 있음

	int N = 0, K = 0;
	cin >> N >> K;

	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	// N=2, K=3일때 (0, N) (1, N-L) + (2, ) + (3, (i는 1부터 K까지, L은 0부터 j까지, N은  
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] += dp[i - 1][j - l];
				dp[i][j] %= DIV;
			}
		}
	}

	cout << dp[K][N]<< "\n";

	return 0;
}