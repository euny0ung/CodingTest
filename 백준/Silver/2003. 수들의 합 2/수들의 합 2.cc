#include <iostream>
using namespace std;

int main() {

	int N = 0, ans=0;
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
			if (sum == M) {
				ans++;
				break;
			}
		}

		while(sum>=M){
			sum -= arr[start];
			start++;
			if (sum == M) {
				ans++;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}