#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int height = 0;

	vector<int>v;
	vector<int>v2;

	for (int i = 0; i < 9; i++) {
		cin >> height;
		v.push_back(height);
	}

	sort(v.begin(), v.end());


	do {
		int sum = 0;
		v2.clear();
		for (int i = 0; i < 7; i++) {
			sum += v[i];
			v2.push_back(v[i]);
		}
		if (sum == 100) {
			for (auto a : v2) {
				cout << a << ' ';
			}
			cout << endl;
			break;
		}
		
		
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}