#include <iostream>
using namespace std;

int main() {

	int N = 0;

	cin >> N;

	

	// 아.. N이 1이나 2일 경우도 고려해야함
	if (N < 3) {
		cout << N << "\n";
	}
	else {
		int* dp = new int[N+1]();
			dp[1] = 1;
			dp[2] = 2;

		for (int i = 3; i <= N; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
		}

		cout << dp[N] << "\n";

		delete[] dp;
	}
	

	return 0;
}