#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	int rope = 0;
	int maxValue = 0;

	vector<int>v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> rope;
		maxValue = max(maxValue, rope);
		v.push_back(rope);
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 1; i < n; i++) {
		int sum = v[i] * (i + 1);
		if (maxValue < sum) maxValue = sum;
	}

	cout << maxValue<<"\n";

	return 0;
}