#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int x = 0, y = 0;
	vector<pair<int, int>>v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(pair<int, int>(x, y));
	}

	sort(v.begin(), v.end());

	for (auto a : v) {
		cout << a.first <<' ' << a.second << '\n';
	}

	return 0;
}

// 주의할 것 2차원 벡터를 정렬하려면 pair을 사용해야함