#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n = 0;
	int input = 0;
	vector<int>v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.rbegin(), v.rend());

	for (int j = 0; j < n-2; j++) {
		if (v[j] >= v[j + 1] + v[j + 2]) {
			
			if (j == n - 3) {
				cout << -1 << "\n";
				break;
			}
		}
		else {
			
			int total = v[j] + v[j + 1] + v[j + 2];
			cout << total << "\n";
			break;
		}
	}
	return 0;
}