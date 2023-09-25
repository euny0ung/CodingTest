#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n = 0, input=0;
	int ans = 0;

	cin >> n;

	int* dp = new int[n];
	int* arr = new int[n];
	dp[1] = 1;

	for (int i = 0; i < n; i++) {
		cin >> input;
		arr[i] = input;
	}

	for (int i = 0; i < n; i++) {
		int result = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				result = max(result, dp[j]);
			}
		}

		dp[i] = result + 1;
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}