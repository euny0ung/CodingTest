#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	string st;
	int result = 0;
	vector<int>v;

	cin >> st;

	for (int i = 0; i < st.size(); i++) {
		v.push_back(st[i] - '0');
	}

	if (find(v.begin(), v.end(), 0) == v.end()) {
		cout << -1 << endl;
	}
	else {
		for (auto a : v) {
			result += a;
		}
		if (result % 3 == 0) {
			sort(v.rbegin(), v.rend());
			for (auto a : v) {
				cout << a;
			}
		}
		else {
			cout << -1 << endl;
		}

		
	}

	

	return 0;
}