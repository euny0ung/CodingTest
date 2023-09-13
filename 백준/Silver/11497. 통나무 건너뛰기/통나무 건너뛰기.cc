#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main() {

	int n = 0;
	int num = 0, input = 0;
	

	cin >> n;

	for (int i = 0; i < n; i++) {
		int mx = 0;

		cin >> num;
		vector<int>v;
		deque<int>dq;
		
		for (int j = 0; j < num; j++) {
			cin >> input;
			v.push_back(input);
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size() - 2; i++) {
			mx = max(mx, abs(v[i] - v[i + 2]));
		}

		int result = abs(v[v.size() - 2] - v[v.size() - 1]);
		if (mx < result) mx = result;
		
		cout << mx << endl;
	}

	return 0;
}