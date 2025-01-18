#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];
int r_dp[1001];

int main() {

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	fill(dp, dp + 1001, 1);
	fill(r_dp, r_dp + 1001, 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i]=max(dp[i] , dp[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N-1; j > i; j--) {
			if (arr[i] > arr[j]) {
				r_dp[i]=max(r_dp[i] , r_dp[j] + 1);
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i] + r_dp[i]);
	}

	cout << ans-1 << "\n";

	return 0;
}