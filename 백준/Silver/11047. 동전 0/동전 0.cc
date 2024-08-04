#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, input=0;
	int cnt = 0;
	long K = 0; // 최대 1억

	cin >> N >> K;

	vector<int>v(N + 1, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		v[i] = input;
	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < v.size(); i++) {
		while (K >= v[i]) {
			if (K == 0) break;
			K -= v[i];
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}