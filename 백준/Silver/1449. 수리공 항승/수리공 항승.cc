#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N = 0, L = 0, ans=0;
	int spot[1000] = {0,};

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> spot[i];
	}

	sort(spot, spot + N);

	int start = spot[0];

	for (int i = 1; i < N; i++) {
		if (L <= spot[i] - start) {
			start = spot[i];
			ans++;
		}
	}

	cout << ans+1 << "\n";

	return 0;
}