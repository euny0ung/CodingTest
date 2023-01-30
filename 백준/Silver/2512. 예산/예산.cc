#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {

	int n = 0;
	int input = 0, money = 0;
	long long total=0;
	vector<int>v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	cin >> money;

	int max = *max_element(v.begin(), v.end());
	int s = 0, e = max;
	long long m = 0;
	long long result = 0;

	while (s <= e) {
		m = (s + e) / 2;
		total = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] < m) {
				total += v[i];
			}
			else {
				total += m;
			}
		}
		if (total > money) e = m - 1;
		else {
			result = m;
			s = m + 1;
		}
	}

	cout << result << "\n";

	return 0;
}