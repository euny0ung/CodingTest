#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}

int main() {

	int T = 0, N = 0;

	vector<pair<int, int>>v;

	cin >> T;

	while (T--) {
		cin >> N;
		v.clear();
		
		int first = 0, second = 0;
		int ans = 1;

		for (int i = 0; i < N; i++) {
			cin >> first >> second;
			v.push_back({ first, second });
		}

		sort(v.begin(), v.end(), compare);

		int standard = v[0].second;

		for (int i = 0; i < N; i++) {
			if (v[i].second < standard) {
				ans++;
				standard = v[i].second;
			}
		}

		cout << ans << "\n";
	}

	

	return 0;
}