#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K;
	int arr[6][2] = { 0, };
	int cnt[5] = { 0, };
	int bSquare = 1;
	int sSquare = 1;

	cin >> K;

	for (int i = 0; i < 6; i++) {
		// 방향, 길이
		cin >> arr[i][0] >> arr[i][1];
		cnt[arr[i][0]]++;
	}

	for (int i = 0; i < 6; i++) {
		if (cnt[arr[i][0]] == 1) {
			bSquare *= arr[i][1];
		}

		if (arr[i][0] == arr[(i + 2) % 6][0]) {
			sSquare *= arr[(i + 1) % 6][1];
		}
	}

	cout << K * (bSquare - sSquare) << "\n";

	return 0;
}