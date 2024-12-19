#include <iostream>
#include <vector>
using namespace std;

vector<int>v;
int idx = 0;

int binarySearch(int input, int s, int e) {

	while (s < e) {
		int m = (s + e) / 2;
		if (input > v[m]) {
			idx = m + 1;
			s = m+1;
		}
		else {
			idx = m;
			e = m;
		}
	}

	return idx;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, lastNum = 0, input=0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input > lastNum) v.push_back(input);
		else {
			int idx=binarySearch(input, 0, v.size());
			v[idx] = input;
		}
		lastNum = v.back();
	}

	cout << v.size() << "\n";

	return 0;
}