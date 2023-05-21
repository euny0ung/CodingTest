#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n = 0;
	
	int max_result = 1;
	int min_result = 1;
	int max_cnt = 1;
	int min_cnt = 1;
	vector<int>v;

	int input = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < n-1; i++) {
		if (v[i] <= v[i + 1]) {
			max_cnt++;
			max_result = max(max_result, max_cnt);
		}
		else {
			max_cnt = 1;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (v[i] >= v[i + 1]) {
			min_cnt++;
			min_result = max(min_result, min_cnt);
		}
		else {
			min_cnt = 1;
		}
	}

	cout << max(max_result, min_result) << endl;

	return 0;
}