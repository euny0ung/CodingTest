#include <iostream>
using namespace std;

int main() {

	int N = 0;
	int arr[1000] = { 0, };
	int dp[1000] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	fill(dp, dp + N, 1);

	int ans=0;

	for (int i = 0; i < N; i++) {
		int result = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				result = max(result, dp[j]);
			}
		}
		dp[i] += result;
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";

	return 0;
}