#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n = 0, m = 0;
	int input = 0;
	int cnt = 0;

	cin >> n >> m;

	vector<vector<int>>coord(n);

	for (int i = 0; i < n; i++) {
		vector<int>v;
		vector<int>temp;
		for (int j = 0; j < m; j++) {
			cin >> input;
			temp.push_back(input);
			v.push_back(input);
		}
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());

		for (int j = 0; j < v.size(); j++) {
			int idx = lower_bound(temp.begin(), temp.end(), v[j]) - temp.begin();
			coord[i].push_back(idx);
		}
	}

	

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (coord[i] == coord[j]) cnt++;
		}
		
	}

	cout << cnt << "\n";

	return 0;
}