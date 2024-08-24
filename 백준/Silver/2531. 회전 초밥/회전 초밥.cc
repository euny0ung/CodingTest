#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, D = 0, K = 0, C = 0;
	int ans = 0;

	cin >> N >> D >> K >> C;

	vector<int>v(N, 0);
	int cnt[30001] = {};
	int type = 0;

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 초기 윈도우 (0~K)
	for (int i = 0; i < K; i++) {
		if (cnt[v[i]] == 0) type++;
		cnt[v[i]]++;
	}

	// 쿠폰 초밥 유무
	if (cnt[C] == 0) ans = type + 1;
	else ans = type;

	for (int i = 1; i < N; i++) {
		// 나가는 초밥
		int out = v[i - 1];
		// 초밥 나갔을 때 0되면 type-1
		if (--cnt[out] == 0) type--;

		// 들어오는 초밥
		int in = v[(i + K - 1)%N];
		// 초밥 들어올 때 기존에 없던거면 type+1
		if (cnt[in] == 0) type++;
		cnt[in]++;
		
		// 쿠폰 초밥 있는지 확인
		if (cnt[C] == 0) ans = max(ans, type + 1);
		else ans = max(ans, type);

	}

	cout << ans << "\n";
	
	return 0;
}