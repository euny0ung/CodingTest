#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	else {
		int result_a = 0;
		int result_b = 0;

		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9') {

				result_a += a[i] - '0';
			}
			if (b[i] >= '0' && b[i] <= '9') {

				result_b += b[i] - '0';
			}
		}

		if (result_a != result_b) {
			return result_a < result_b;
		}
		else {
			return a < b;
		}
	}
}

int main() {
	string st_arr[50];
	int n = 0;
	string st;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st_arr[i];
	}

	sort(st_arr, st_arr+n, cmp);

	for (int i = 0; i < n; i++) {
		cout << st_arr[i] << endl;
	}
}