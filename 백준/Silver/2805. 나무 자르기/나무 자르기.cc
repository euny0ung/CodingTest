#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	int h = 0;
	int result = 0;
	unsigned long long total = 0;

	vector<int>v;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> h;
		v.push_back(h);
	}
	
	int start = 0;
	int end = *max_element(v.begin(),v.end());

	while (start <= end) {
		int mid = (start + end) / 2;

		for (auto a : v) {
			if (a > mid) total += a - mid; // mid는 자르는 부분
		}
		if (total < m) end = mid - 1;
		else {
			result = mid;
			start = mid + 1;
		}
		total = 0; // 한번 돌때마다 total 초기화 꼭!!!
	}

	cout << result << endl;

	return 0;
}