#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {

	int n = 0;
	long long int input = 0;
	int max = 0;
	long long int result = 0;

	map<long long int, int>mp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (mp.find(input) == mp.end()) {
			mp.insert({ input, 1 });
		}
		else {
			mp[input]++;
		}
	}

	for (pair<long long int, int>p : mp) {
		if (max < p.second) {
			max = p.second;
			result = p.first;
		}
	}

	cout << result << endl;

	return 0;
}