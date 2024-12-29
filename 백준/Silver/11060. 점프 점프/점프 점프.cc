#include <iostream>
#define MAX 1e9
using namespace std;

int main() {

	int N = 0;
	int arr[1001] = { 0, };
	int dp[1001];

	fill(dp, dp + 1001, MAX);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j < N) {
				dp[i + j] = min(dp[i] + 1, dp[i+j]);
			}
			
		}
	}

	if (dp[N - 1] == MAX) cout << "-1" << "\n";
	else cout << dp[N-1] << "\n";

	return 0;
}