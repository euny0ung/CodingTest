#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 0;
	int x = 0, y = 0;
	vector<pair<int,int>>v;
	
	cin >> n;
	
	vector<int>cnt(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				cnt[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << cnt[i] << endl;
	}
	

	return 0;
}