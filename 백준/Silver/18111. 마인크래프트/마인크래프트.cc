#include <iostream>
#include <limits.h>
using namespace std;

int N = 0, M = 0, ans = INT_MAX, best_height = 0;
long long B = 0;
int arr[501][501] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int standard = 0;

	for (standard = 0; standard <= 256; standard++) {
		int block = 0, time=0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] < standard) { 
					time += standard - arr[i][j];
					block -= standard - arr[i][j]; 
				}
				else if (arr[i][j] > standard) {
					time += (arr[i][j] - standard) * 2;
					block += arr[i][j] - standard; 
				}
			}
		}

		// 가능
		if(block + B >= 0) {
			// 최소 시간 구하기. 시간 같으면 땅 높이가 가장 높을 때
			if (time < ans || (time == ans && best_height < standard)) {
				ans = time;
				best_height = standard;
			}
		}
	}

	cout << ans <<" " << best_height << "\n";

	return 0;
}