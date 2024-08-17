#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, P = 0, cnt=0, rank=0;
	long input = 0;
	long score[50] = {};

	cin >> N >> input >> P;

	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}

	for (int i = 0; i < N; i++) {
		if (score[i] >= input) {
			cnt++;
			if (score[i] != input) rank++;
		}
	}

	if (cnt == P) cout << -1 << "\n";
	else cout << rank+1 << "\n";

	return 0;
}