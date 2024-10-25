#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, K = 0;
	int arr[100001] = { 0, };

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 첫 K개 계산
	int init = 0;
	for (int i = 0; i < K; i++) {
		init += arr[i];
	}

	int s = 0;
	int e = K;
	int maxValue = init;

	while (e < N) {
		init=init - arr[s] + arr[e]; // 범위 바로 이전 수를 빼고 바로 이후 수를 더함
		e++;
		s++;
		if (maxValue < init) maxValue = init;
	}

	cout << maxValue << "\n";

	return 0;
}