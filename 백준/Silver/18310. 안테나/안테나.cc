#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, input=0;
	vector<int>v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	int idx = floor((v.size() - 1) / 2);

	cout << v[idx] << "\n";

	return 0;
}