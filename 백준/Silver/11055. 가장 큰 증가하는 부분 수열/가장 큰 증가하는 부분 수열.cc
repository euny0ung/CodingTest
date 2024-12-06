#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N = 0, ans=0, result=0;
	bool flag = false;
	int arr[1000] = { 0, };
	int dp[1000] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		result = 0;
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