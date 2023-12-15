#include <iostream>
#include <algorithm>
#define INF 1000000001;
using namespace std;

struct INDEX {
	int start;
	int end;
};

bool compare(INDEX a, INDEX b) {
	if (a.start == b.start) return a.end < b.end;
	return a.start < b.start;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int ans = 0;
	int left = -INF; // 현재 시작점
	int right = -INF; // 현재 끝점

	INDEX idx[1000001] = {0,};

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> idx[i].start >> idx[i].end;
	}

	sort(idx, idx + N, compare);

	for (int i = 0; i < N; i++) {
		// 겹치는 경우
		if (idx[i].start < right) right = max(right, idx[i].end);
		
		// 겹치지 않는 경우
		else {
			// 이전에 연결된 값 더해주기
			ans += right - left;
			left = idx[i].start;
			right = idx[i].end;
		}
	}

	ans += right - left;

	cout << ans << "\n";

	return 0;
}