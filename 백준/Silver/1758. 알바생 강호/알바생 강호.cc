#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, input = 0;
	long long result=0;
	vector<long long>v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < N; i++) {
		if (v[i] - i > 0) {
			result += v[i] - i;
		}
		
	}

	cout << result << "\n";

	return 0;
}