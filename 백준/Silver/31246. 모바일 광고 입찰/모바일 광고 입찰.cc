#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, K = 0;
	int a = 0, b = 0;
	int cnt = 0;

	vector<int>v;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (a >= b) cnt++; // 이미 낙찰
		else {
			int diff = b - a;
			v.push_back(diff);
		}
	}

	// 이미 입찰 끝났으면
	if (cnt >= K) cout << 0 << "\n";
	else {
		sort(v.begin(), v.end());

		int answer = v[K - cnt - 1];

		cout << answer << "\n";
	}

	

	return 0;
}