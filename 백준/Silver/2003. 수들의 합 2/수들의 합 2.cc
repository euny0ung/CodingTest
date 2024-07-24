#include <iostream>
using namespace std;

int ans = 0;

bool check(long sum, int target) {
	if (sum == target) {
		ans++;
		return true;
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int arr[10000] = { 0, };
	long M = 0, sum=0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0, end = 0;

	while (end < N) {
		while (sum <= M && end<N) {
			sum += arr[end];
			end++;

			if (check(sum, M)) break;
		}

		while(sum>=M){
			sum -= arr[start];
			start++;
			if (check(sum, M)) break;
		}
	}

	cout << ans << "\n";

	return 0;
}