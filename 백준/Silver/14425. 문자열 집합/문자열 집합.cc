#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {

	int n = 0, m = 0;
	int cnt = 0;
	string set_input = "";
	string find_input = "";
	set<string>s;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> set_input;
		s.insert(set_input);
	}

	for (int j = 0; j < m; j++) {
		cin >> find_input;
		if (s.find(find_input) != s.end()) {
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}