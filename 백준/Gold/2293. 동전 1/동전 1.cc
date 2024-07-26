#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N = 0, K = 0;
	long ans = 0;
	int arr[100] = { 0, };
	int dp[10001] = { 0, };

	dp[0] = 1;

	cin >> N >> K;

	for (int i = 0; i <N; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[K] << endl;

	return 0;
}