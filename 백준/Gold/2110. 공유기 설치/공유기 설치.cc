#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, C = 0;
	int ans = 0;

	cin >> N >> C;

	vector<int>pos(N, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> pos[i];
	}

	sort(pos.begin(), pos.end());

	int start = 1, end = pos[N - 1]-pos[0];

	while (start <= end) {
		int now = pos[0];
		int router = 1;

		int distance = (start + end) / 2; // 가능한 최소 거리

		// 왜 now+1이 아니고 1부터지?
		for (int i = 1; i < N; i++) {
			if (pos[i] - now >= distance) {
				router++;
				now = pos[i];
			}
		}

		// 만약 개수 초과하면 거리 늘리기 (왜 같다는 조건도 들어가지?)
		if (router >= C) {
			start = distance + 1;
			ans = max(ans, distance);
		}
		else {
			end = distance - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}