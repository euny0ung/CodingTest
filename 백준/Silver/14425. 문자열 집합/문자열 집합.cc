#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {

	int n = 0, m = 0;
	int cnt = 0;
	string set_input = "";
	string find_input = "";
	map<string, int>ma;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> set_input;
		ma.insert({ set_input, 1 });
	}

	for (int j = 0; j < m; j++) {
		cin >> find_input;
		if (ma.find(find_input) != ma.end()) {
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}