#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, input=0;

	cin >> N;

	vector<int>v(N,0);

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.rbegin(), v.rend());

	int ans = v[0] + N - 1;

	cout << ans << "\n";

	return 0;
}